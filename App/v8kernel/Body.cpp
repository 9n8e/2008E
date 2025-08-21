#pragma once
#include "v8kernel/Body.h"

namespace RBX { 
        Body::Body() {
            this->kernelIndex;
            this->root;
            this->parent;
            this->index = -1;
            this->children;
            this->cofm;
            this->simBody;
            this->canThrottle = 1;
            this->link = 0;
            this->meInParent = new G3D::CoordinateFrame;
            this->moment = new G3D::Matrix3;
            this->mass = 0.0;

            advanceStateIndex();

            this->pv = PV(G3D::CoordinateFrame(), Velocity());
            this->root = this;
            this->simBody = new RBX::SimBody(this);
        }

        Body::~Body() {
            RBXASSERT(!link);
            RBXASSERT(simBody);

            if (cofm) {
                delete cofm;
                cofm = NULL;
            }

            delete simBody;
            simBody = NULL;
            
            RBXASSERT(!cofm);
            RBXASSERT(root == this);
        }

        Body* Body::calcRoot() {
            Body* result;
            Body* current = this;

            do {
                result = current;
                current = current->parent;
            } while (this);

            return result;
        }

        int Body::getNextStateIndex() const {
            int state = this->index;

            if (!state) {
                return 0;
            }

            ++state;

            if (state == 0x7FFFFFFF) {
                state = 1;
            }

            return state;
        }

        IndexArray<Body, Body::getIndex> Body::getChildren() {
            return children;
        }

        void Body::advanceStateIndex() {
            int state = this->index;
            ++state;

            if (state == 0x7FFFFFFF) {
                state = 1;
            }

            this->stateIndex = state;
        }

        void Body::makeCofmDirty() {
            RBX::Cofm* cofm = this->cofm;
            if (!cofm || !cofm->getIsDirty()) {
                RBX::Body* parent = this->parent;
                if (parent) {
                    parent->makeCofmDirty();
                } else {
                    RBX::SimBody* simBody = this->simBody;
                    if (simBody) {
                        simBody->makeDirty();
                    }
                    if (cofm) {
                        cofm->makeDirty();
                    }
                }
            }
        }

        void Body::step(float dt, bool throttling) {
            PV OwnerPV;
            if (throttling && this->canThrottle) {
                this->simBody->resetAccumulators();
            } else {
                this->simBody->step(dt);
                if (this->cofm) {
                    PV OwnerPV = this->simBody->getOwnerPV();
                } else {
                    PV OwnerPV = this->simBody->getPV();
                }

                RBX::PV thisPV = this->getPV();
                thisPV.velocity.rotational.z = OwnerPV.velocity.rotational.z;
                advanceStateIndex();
            }
        }

        void Body::setPv(const RBX::PV& _pv) {
            if (!this->parent) {
                RBX::SimBody* simBody = this->simBody;
                if (simBody) {
                    simBody->makeDirty();
                } 
                advanceStateIndex();
            }
        }

        void Body::setVelocity(const Velocity& worldVelocity) {
            if (!this->parent) {
                this->pv.velocity.linear = worldVelocity.linear;
                this->pv.velocity.rotational = worldVelocity.rotational;

                advanceStateIndex();

                RBX::SimBody* simBody = this->simBody;
                if (simBody) {
                    simBody->makeDirty();
                }
            }
        }

        void Body::setMass(float _mass) {
            if (_mass != this->mass) {
                RBX::Cofm* cofm = this->cofm;
                if (!cofm || !cofm->getIsDirty()) {
                    RBX::Body* parent = this->parent;
                    if (parent) {
                        parent->makeCofmDirty();
                    } else {
                        RBX::SimBody* simBody = this->simBody;
                        if (simBody) {
                            simBody->makeDirty();
                        }
                    }
                    if (cofm) {
                        cofm->makeDirty();
                    }
                }
                this->mass = _mass;
            }
        }

        void Body::setMoment(const G3D::Matrix3& _momentInBody) {
            G3D::Matrix3* p_moment = this->moment;
            //if (G3D::Matrix3::operator!=(&this->moment, _momentInBody)) {
            if (p_moment->operator!=(_momentInBody)) {
                RBX::Cofm* cofm = this->cofm;
                if (!cofm || !cofm->getIsDirty()) {
                    RBX::Body* parent = this->parent;
                    if (parent) {
                        parent->makeCofmDirty();
                    } else {
                        RBX::SimBody* simBody = this->simBody;
                        if (simBody) {
                            simBody->makeDirty();
                        }
                    }
                    if (cofm) {
                        cofm->makeDirty();
                    }
                }

                *p_moment = _momentInBody; // qmemcpy(p_moment, _momentInBody, sizeof(G3D::Matrix3));
            }
        }

        void Body::setMeInParent(const G3D::CoordinateFrame& _meInParent) {
            RBX::Link* link = this->link;
            if (link) {
                link->setBody(NULL);
                this->link = NULL;
            }

            if (this->parent) {
                this->setMeInParent(_meInParent);
                RBX::Cofm* cofm = this->cofm;
                if (!cofm || !cofm->getIsDirty()) {
                    RBX::Body* parent = this->parent;
                    if (parent) {
                        parent->makeCofmDirty();
                    } else {
                        RBX::SimBody* simBody = this->simBody;
                        if (simBody) {
                            simBody->makeDirty();
                        }
                    }

                    if (cofm) {
                        cofm->makeDirty();
                    }
                }

                RBX::Body* root = this->root;
                advanceStateIndex();
            }
        }

        void Body::setMeInParent(RBX::Link* _link) {
            RBX::Link* link = this->link;
            if (link && link != _link) {
                link->setBody(NULL);
            }
            if (this->parent) {
                this->link = _link;
                _link->setBody(this);
                RBX::Cofm* cofm = this->cofm;
                if (!cofm || !cofm->getIsDirty()) {
                    RBX::Body* parent = this->parent;
                    if (parent) {
                        parent->makeCofmDirty();
                    } else {
                        RBX::SimBody* simBody = this->simBody;
                        if (simBody) {
                            simBody->makeDirty();
                        }
                        if (cofm) {
                            cofm->makeDirty();
                        }
                    }
                    RBX::Body* root = this->root;
                    advanceStateIndex();
                }
            }
        }

        void Body::setCoordinateFrame(const G3D::CoordinateFrame& worldCoord) {
            updatePV();
            RBX::PV* newPV = new PV;
            newPV->position.rotation = worldCoord.rotation;
            newPV->position.translation = worldCoord.translation;

            newPV->velocity.linear = this->pv.velocity.linear;
            newPV->velocity.rotational = this->pv.velocity.rotational;
            setPv(*newPV);
        }

        G3D::Vector3 Body::getBranchCofmPos() {
            G3D::Vector3 p_translation;
            if (this->cofm) {
                updatePV();
                G3D::Vector3 CofmInBody = this->cofm->getCofmInBody();
                G3D::Vector3 p_translation = CofmInBody; // yea this makes no sense but i'll fix it later prob
            } else {
                updatePV();
                G3D::Vector3 p_translation = this->pv.position.translation;
            }

            G3D::Vector3* result;
            result->x = p_translation.x;
            result->y = p_translation.y;
            result->z = p_translation.z;
            return *result;
        }

        G3D::CoordinateFrame Body::getBranchCofmCoordinateFrame() {
            updatePV();
            G3D::Vector3 BranchCofmPos = getBranchCofmPos();

            G3D::CoordinateFrame* result;
            result->rotation = this->pv.position.rotation;
            result->translation *= BranchCofmPos;
            
            return *result;
        }

        void Body::resetRoot(RBX::Body* newRoot) {
            int index = 0;
            this->root = newRoot;
            G3D::Array<RBX::Body *>& array = children.underlyingArray();

            if (array.size() > 0) {
                do {
                    children[index++]->resetRoot(newRoot);
                } while (index < array.size());
            }
        }

        G3D::Matrix3 Body::getIWorldAtPoint(const G3D::Vector3& point) {
            float mass = this->mass;
            updatePV();

            G3D::Matrix3* iBody = this->moment;
            G3D::Matrix3 iWorldAtCofm = RBX::Math::momentToWorldSpace(*iBody, this->pv.position.rotation);

            updatePV();
            
            return RBX::Math::getIWorldAtPoint(this->pv.position.translation, point, iWorldAtCofm, mass);
        }

        G3D::Matrix3 Body::getBranchIWorldAtPoint(const G3D::Vector3& point) {
            RBX::Cofm* cofm = this->cofm;
            float mass;

            if (cofm) {
                mass = cofm->getMass();
            } else {
                mass = this->mass;
            }

            updatePV();
            G3D::Matrix3 Moment;
            if (cofm) {
                Moment = cofm->getMoment();
            } else {
                Moment = *this->moment;
            }

            G3D::Matrix3 iBody = G3D::Matrix3(Moment);
            G3D::Matrix3 iWorldAtCofm = RBX::Math::momentToWorldSpace(iBody, this->pv.position.rotation);;
            G3D::Vector3 BranchCofmPos = this->getBranchCofmPos();;

            return RBX::Math::getIWorldAtPoint(BranchCofmPos, point, iWorldAtCofm, mass);
        }

        float Body::kineticEnergy() {
            updatePV();

            G3D::Matrix3 result;
            G3D::Matrix3 iBody = *this->moment;
            G3D::Matrix3 result = RBX::Math::momentToWorldSpace(iBody, this->pv.position.rotation);

            return ((this->pv.velocity.rotational.y*  result[0][1]
            + this->pv.velocity.rotational.x*  result[0][0]
            + result[0][2]*  this->pv.velocity.rotational.z)
           *  this->pv.velocity.rotational.x
            + (this->pv.velocity.rotational.y*  result[1][1]
            + this->pv.velocity.rotational.x*  result[1][0]
            + result[1][2]*  this->pv.velocity.rotational.z)
           *  this->pv.velocity.rotational.y
            + (this->pv.velocity.rotational.y*  result[2][1]
            + this->pv.velocity.rotational.x*  result[2][0]
            + result[2][2]*  this->pv.velocity.rotational.z)
           *  this->pv.velocity.rotational.z
            + (this->pv.velocity.linear.z*  this->pv.velocity.linear.z
            + this->pv.velocity.linear.y*  this->pv.velocity.linear.y
            + this->pv.velocity.linear.x*  this->pv.velocity.linear.x)
           *  this->mass)
           *  0.5;
        }

        void Body::onChildRemoved(RBX::Body* child) {
            int index = this->index;
            G3D::Array<Body *> data = children.underlyingArray();
            RBX::Body* v5 = data[index];
            v5->index = index;
            children.underlyingArray().resize(children.underlyingArray().size() - 1, false);
            child->index = -1;
            if (!this->children.underlyingArray().size()) {
                delete this->cofm;
                this->cofm = NULL;
            }
            RBX::Cofm* cofm = this->cofm;
            if (!cofm || !cofm->getIsDirty()) {
                RBX::Body* parent = this->parent;
                if (parent) {
                    parent->makeCofmDirty();
                } else {
                    RBX::SimBody* simBody = this->simBody;
                    if (simBody) {
                        simBody->makeDirty();
                    }
                }
                if (cofm) {
                    cofm->makeDirty();
                }
            }
        }

        void Body::onChildAdded(RBX::Body* child) {
            RBX::Cofm* cofm = this->cofm;
            if (!cofm || !cofm->getIsDirty()) {
                RBX::Body* parent = this->parent;
                if (parent) {
                    parent->makeCofmDirty();
                } else {
                    RBX::SimBody* simBody = this->simBody;
                    if (simBody) {
                        simBody->makeDirty();
                    }
                }
                if (cofm) {
                    cofm->makeDirty();
                }
            }

            child->index = children.underlyingArray().size();
            this->children.underlyingArray().append(child);
            //G3D::Array<RBX::Body* >::append(&this->children.array, &child);
            if (!this->cofm) {
                RBX::Body* child = new RBX::Body;
                if (child) {
                    *child->cofm = Cofm(child);
                    *this->cofm = Cofm(this);
                } else {
                    this->cofm = NULL;
                }
            }
        }

        void Body::resetAccumulators() {
            RBX::Body* root = this->root;
            RBX::SimBody* simBody = this->simBody;
            if (simBody) {
                if (simBody->getDirty()) {
                    root->simBody->update();
                }
                float constantForceY = simBody->getConstantForceY();
                G3D::Vector3 simForce = simBody->getForce();
                G3D::Vector3 simTorque = simBody->getTorque();
                simForce.x = 0.0;
                simForce.z = 0.0;
                simForce.y = constantForceY;
                simTorque.z = 0.0;
                simTorque.y = 0.0;
                simTorque.z = 0.0;
            }
        }

        void Body::accumulateTorque(const G3D::Vector3& torque) {
            RBX::Body* root = this->root;
            RBX::SimBody* simBody = this->simBody;
            if (simBody) {
                if (simBody->getDirty()) {
                    root->simBody->update();
                }

                G3D::Vector3 simTorque = simBody->getTorque();
                simTorque.x = simTorque.x + torque.x;
                simTorque.y = torque.y + simTorque.y;
                simTorque.z = torque.z + simTorque.z;
            }
        }

        float Body::getBranchMass() {
            RBX::Cofm* cofm = this->cofm;
            if (cofm) {
                return cofm->getMass();
            }
            return this->mass;
        }

        G3D::Vector3 Body::getBranchIBodyV3() {
            Cofm* cofm = this->cofm;
            const G3D::Matrix3* Moment;
            if (cofm) {
                Moment = &cofm->getMoment();
            } else {
                Moment = this->moment;
            }
            G3D::Matrix3 m(*Moment);
            G3D::Vector3 diagonal = Math::toDiagonal(m);
            return diagonal;
        }

        void Body::accumulateForceAtBranchCofm(const G3D::Vector3& force) {
            RBX::Body* root = this->root;
            RBX::SimBody* simBody = this->simBody;

            if (simBody) {
                if (simBody->getDirty()) {
                    simBody->update();
                }

                G3D::Vector3 simForce = simBody->getForce();
                simForce.x = simForce.x + force.x;
                simForce.y = force.y + simForce.y;
                simForce.z = force.z + simForce.z;
            }
        }

        const G3D::Vector3& Body::getBranchForce() const {
            RBX::SimBody* simBody = this->simBody;
            if (simBody) {
                return simBody->getForce();
            }

            static G3D::Vector3 termVector(0.0, 0.0, 0.0);
            return termVector;
        }

        const G3D::Vector3& Body::getBranchTorque() const {
            RBX::SimBody* simBody = this->simBody;
            if (simBody) {
                return simBody->getTorque();
            }

            static G3D::Vector3 termVector(0.0, 0.0, 0.0);
            return termVector;
        }
}