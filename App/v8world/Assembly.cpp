#pragma once

#include "v8world/Assembly.h"
#include "v8world/Clump.h"

#include "util/Debug.h"

namespace RBX {
    // note: list initializer - did not exist in c98, added in c11
    Assembly::Assembly(RBX::Primitive* root) {
        // this->currentStage = NULL;
        // this->sleepInfo = NULL;
        this->rootPrimitive = root;
        // this->parent = NULL;
        // this->children._Myfirst = 0;
        // this->children._Mylast = 0;
        // this->children._Myend = 0;
        // this->simJob = 0;
        // this->maxRadius.getFunc = &computeMaxRadius();
        // this->maxRadius.setDirty();
        // this->maxRadius.object = this;
        //* ((_DWORD* )&this->maxRadius.getFunc + 1) = 0; - signals that .getFunc takes a reference to a function
        // this->canSleep.setDirty();
        // this->canSleep.object = this;
        // this->canSleep.getFunc = &computeCanSleep();
        //* ((_DWORD* )&this->canSleep.getFunc + 1) = 0;
        // root->setClump(this);
    }

    void Assembly::addChild(RBX::Assembly* child) {
        std::vector<RBX::Assembly *, std::allocator<RBX::Assembly *>> p_children = this->children;

        RBXASSERT(p_children.begin() > p_children.end());

        this->children.push_back(child);
        /* TBD
        std::sort(
            p_children.begin(),
            p_children.end(),
            p_children.begin() - p_children.end(),
            RBX::lessAssembly
        ); */
    }

    void Assembly::addGroundChild(RBX::Primitive* p) {
        RBX::Body* body = p->getBody();
        RBX::Clump* clump = p->getClump();
        body->setParent(NULL);

        RBX::Assembly* parent = clump->parent;
        if (parent) {
            p = dynamic_cast<RBX::Primitive*>(clump);
            //RBX::fastRemoveShort<RBX::Assembly* >(&parent->children, &p);
            RBX::fastRemoveShort(&parent->children, &p);

            parent->maxRadius.setDirty();
            parent->canSleep.setDirty();
            if (parent->parent) {
                parent->parent->onPrimitivesChanged();
            }

            clump->parent = NULL;
            clump->maxRadius.setDirty();
            clump->canSleep.setDirty();
            if (clump->parent) {
                clump->parent->onPrimitivesChanged();
            }
        }
    }

    void Assembly::addMotorChild(RBX::Primitive* parent, RBX::MotorJoint* m, RBX::Primitive* child) {
        RBX::Clump* clump = parent->getClump();
        child->setClumpDepth(parent->getClumpDepth() + 1); 
        child->getClump()->setParent(clump);

        child->getBody()->setParent(parent->getBody());
        RBX::Body* body = child->getBody();

        RBX::RevoluteLink* rLink = m->resetLink();
        body->setMeInParent(rLink);
    }

    void Assembly::addRigidChild(RBX::Primitive* parent, RBX::RigidJoint* r, RBX::Primitive* child) {
        RBX::Clump* clump = parent->getClump();
        child->setClump(clump);
        child->setClumpDepth(parent->getClumpDepth() + 1); ;
        child->getBody()->setParent(parent->getBody());
        RBX::Body* body = child->getBody();

        G3D::CoordinateFrame* result;
        G3D::CoordinateFrame* ChildInParent = r->getChildInParent( parent, child);
        body->setMeInParent(ChildInParent);

        clump->maxRadius.dirty = true;
        clump->canSleep.dirty = true;
        if (clump->parent) {
            onPrimitivesChanged(clump->parent);
        }
    }

    RBX::PrimIterator assemblyPrimBegin(RBX::PrimIterator* result) {
        result->primitive = this->rootPrimitive;
        result->searchType = RBX::PrimIterator::SearchType::IN_ASSEMBLY;
        return result;
    }

    RBX::PrimIterator assemblyPrimEnd(RBX::PrimIterator* result) {
        result->primitive = NULL;
        result->searchType = RBX::PrimIterator::SearchType::IN_ASSEMBLY;
        return result;
    }

    bool computeCanSleep() {
        RBX::PrimIterator it = RBX::PrimIterator::begin(this->rootPrimitive, RBX::PrimIterator::IN_ASSEMBLY);

        while (it != RBX::PrimIterator::end(RBX::PrimIterator::IN_ASSEMBLY)) {
            ++it;
            if (it.searchType == RBX::PrimIterator::SearchType::IN_CLUMP) {
                return true;
            }
        }
    }

    double computeMaxRadius() {
        float offset = 0.0;
        RBX::PrimIterator it = RBX::PrimIterator::begin(this->rootPrimitive, RBX::PrimIterator::IN_ASSEMBLY);
        RBX::PrimIterator end = RBX::PrimIterator::end(RBX::PrimIterator::IN_ASSEMBLY);
        G3D::Vector3 centerOfMass;
        this->rootPrimitive->body->getBranchCofmPos(centerOfMass);

        for (it; it != end; ++it) {
            RBX::Primitive* primitive =* it;

            RBX::Body* body = primitive->body;
            body->updatePV();

            const G3D::Vector3& pos = body->pv.position.translation;
            G3D::Vector3 offsetCenter(
                pos.x - centerOfMass.x,
                pos.y - centerOfMass.y,
                pos.z - centerOfMass.z
            );

            G3D::Vector3 absOffset;
            RBX::Math::vector3Abs(absOffset, offsetCenter);

            const RBX::Extents& extents = primitive->getExtentsWorld();
            const G3D::Vector3 size = extents->size();

            float hx = size.x*  0.5;
            float hy = size.y*  0.5;
            float hz = size.z*  0.5;

            float dx = absOffset.x + hx;
            float dy = absOffset.y + hy;
            float dz = absOffset.z + hz;

            float radius = std::sqrt(dx*  dx + dy*  dy + dz*  dz);

            if (radius > offset) {
                offset = radius;
            }
        }

        return offset;
    }

    RBX::EdgeIterator externalEdgeBegin(RBX::EdgeIterator* result) {
        result->begin(this->rootPrimitive);
        return result;
    }

    RBX::EdgeIterator externalEdgeEnd(RBX::EdgeIterator* result) {
        //tbd here
        result->primitive = result->end();
        result->edge = new RBX::Edge;
        return result;
    }

    bool getAnchored() {
        RBX::Assembly* RootAssembly = this;
        if (this->parent) {
            RootAssembly = this->parent->getRootAssembly();
        }

        return RootAssembly->rootPrimitive->getAnchored != 0;
    }

    const RBX::Primitive getAssemblyPrimitiveConst() {
        if (this->parent) {
            return this->parent->getRootAssembly()->rootPrimitive;
        }

        return this->rootPrimitive;
    }

    RBX::Contact getJointToParent(RBX::Primitive* p) {
        RBX::Primitive prim0;
        RBX::Contact jointOwner = RBX::Joint::getJointOwner(p);
        if (!jointOwner) {
            return false;
        }

        while (true) {
            if (LOBYTE(result->steppingIndex)) {
                prim0 = result->prim0; // inherited from RBX::Edge
                if (p == prim0) {
                    prim0 = result->prim1;
                }

                if (!prim0 || p->body->parent == prim0->body) {
                    break;
                }
            }

            jointOwner = p->getNextContact(jointOwner);
            if (!jointOwner) {
                return false;
            }
        }

        return jointOwner;
    }

    RBX::MotorJoint getMotorConst(int motorId) {
        return this->getMotorImp(&motorId);
    }

    const RBX::MotorJoint getMotorImp(int motorId) {
        RBX::Contact* jointToParent = this->getJointToParent();
        if (jointToParent->getEdgeType() == RBX::Edge::EdgeType::JOINT
        && (int)jointToParent->deleteAllConnectors() == 8) {
            if (!*motorId) {
                return jointToParent;
            }
            --*motorId;
        } 

        for (i = 0; i; ++i) {
            RBX::Assembly* first = this->children.begin();
            if (!first || i >= this->children.end() - first) {
                break;
            }

            const RBX::MotorJoint motor = this->children.begin()[i]->getMotorImp(motorId);
            if (motor) {
                return motor;
            }
        }
    }

    RBX::Assembly getRootAssembly() {
        RBX::Assembly* result = this;
        do {
            result = this;
            this = this->parent
        } while (this);

        return result;
    }

    RBX::SimJob getSimJob() {
        return this->simJob;
    }

    RBX::Sim::AssemblyState getSleepStatus() {
        RBX::Assembly i;

        for (i = this->parent; i; i = i->parent) {
            this = i;
        }

        RBX::SleepInfo* sleepInfo = this->sleepInfo;
        if (sleepInfo) {
            return sleepInfo->state;
        }
    }

    void RBX::Assembly::notifyMoved() {
        RBX::PrimIterator it = RBX::PrimIterator::begin(this->rootPrimitive, RBX::PrimIterator::SearchType::IN_ASSEMBLY);

        while (it != RBX::PrimIterator::end(RBX::PrimIterator::SearchType::IN_ASSEMBLY)) {
            RBX::Primitive* prim =* it;

            RBX::IMoving* movingInterface = static_cast<RBX::IMoving*>(prim->body);
            if (movingInterface) {
                movingInterface->notifyMoved();
            }

            ++it;
        }
    }

    int numMotors() {
        int count = 0;
        RBX::Contact* jointToParent = this->rootPrimitive->getJointToParent();

        if (jointToParent->getEdgeType = RBX::Edge::EdgeType::JOINT) {
            count = 1;
        }

        for (size_t i = 0; i < this->children.size(); ++i) {
            count += this->children[i]->numMotors();
        }

        return count;
    }

    void onPrimitivesCanSleepChanged(RBX::Primitive* p) {
        this->canSleep.dirty = true;
    }

    void onPrimitivesChanged() {
        this->maxRadius.dirty = true;
        this->canSleep.dirty = true;
        for (RBX::Assembly i = this->parent; i; i = i->parent) {
            i->maxRadius.dirty = true;
            i->canSleep.dirty = true;
        }
    }

    RBX::Assembly = otherAssembly(RBX::Edge* edge) {
        RBX::Assembly* assembly = edge->prim0->getAssembly();
        RBX::Assembly* assembly2 = edge->prim1->getAssembly();

        if (assembly != this) {
            return assembly;
        }

        return assembly2;
    }

    void putInKernel(RBX::Kernel* kernel) {
        this->putInStage(kernel); // inherited from IPipelined
        kernel->insertBody(this->rootPrimitive->body);
    }

    void removeFromKernel() {
        RBX::Body* body = this->rootPrimitive->body;
        RBX::Kernel* kernel = this->getKernel() // inherited from IPipelined
        kernel->removeBody(body);
        RBX::IPipelined::removeFromKernel(this);
    }

    void setParent(RBX::Assembly* newParent) {
        RBX::Assembly* parent = this->parent;
        if (newParent != parent) {
            if (parent) {
                newParent = this;
                RBX::fastRemoveShort<RBX::Assembly* >(&parent->children, &newParent);
                parent.maxRadius.dirty = true;
                parent.canSleep.dirty = true;
                if (parent->parent) {
                    parent->parent->onPrimitivesChanged();
                }
            }

            this->parent = newParent;
            if (newParent) {
                newParent->addChild(this);
            }

            this->maxRadius.dirty = true;
            this->canSleep.dirty = true

            if (this->parent) {
                this->parent->onPrimitivesChanged();
            }
        }
    }

    void stepUi(int uiStepId) {
        int motors = this->numMotors();
        int count = 0;
        RBX::MotorJoint motorImp;

        if (motors) {
            int stepId = uiStepId;
            do {
                uiStepId = count;
                motorImp = this->getMotorImp(&uiStepId);
                motorImp->stepUi(motorImp, stepId)
                ++count;
            } while (count < motors);
        }
    }

    ~Assembly() {
        RBX::PrimIterator it = RBX::PrimIterator::begin(this->rootPrimitive, RBX::PrimIterator::IN_ASSEMBLY);
        while (it != RBX::PrimIterator::end(RBX::PrimIterator::IN_ASSEMBLY)) {
            RBX::Primitive* prim =* it;
            prim->setClump(NULL);
            prim->clumpDepth = -1;
            ++it;
        }

        if (this->parent) {
            RBX::fastRemoveShort<RBX::Assembly*>(
                this->parent->children,
                this
            );
        }

        this->parent = NULL;

        for (size_t j = 0; j < this->children.size(); ++j) {
            this->children[j]->parent = NULL;
        }

        if (!this->children.empty()) {
            delete(this->children.data());
        }

        this->children.begin() = NULL;
        this->children.end() = NULL;
    }
}