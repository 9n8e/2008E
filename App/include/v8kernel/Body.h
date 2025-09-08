#pragma once

#include "v8kernel/KernelIndex.h"
#include "v8kernel/Cofm.h"
#include "v8kernel/SimBody.h"
#include "v8kernel/Link.h"

#include "util/IndexArray.h"
#include "util/PV.h"
#include "util/Velocity.h"
#include "util/Quaternion.h"
#include "util/Math.h"
#include "util/Debug.h"

#include "v8world/Assembly.h"
#include "v8world/IPipelined.h"

#include "G3D/CoordinateFrame.h"
#include "G3D/Matrix.h"
#include "G3D/Vector3.h"

namespace RBX {
    class Body : public KernelIndex {
    private:
        Body* root;
        Body* parent;
        int index = -1;
        Cofm* cofm;
        RBX::SimBody* simBody;
        bool canThrottle = true;
        Link* link;
        G3D::CoordinateFrame* meInParent;
        G3D::Matrix3* moment;
        int stateIndex;
        PV pv;
        float mass;

        int& getIndex() {
            return this->index;
        };

        IndexArray<Body, Body::getIndex> children;
        const SimBody* getRootSimBody() const;
        void resetRoot(Body*);
        bool validateParentCofmDirty();
        const G3D::CoordinateFrame& getMeInParent() const;
        void updatePV() {
            if (this->parent) {
                Body* root = this->root;
                updatePV();
                if (this->stateIndex != root->stateIndex) {
                    Body* parent = this->parent;
                    parent->updatePV();

                    Link* link = this->link;
                    PV* p_pv = &parent->pv;
                    G3D::CoordinateFrame ChildInParent;
                    if (link) {
                        ChildInParent = link->getChildInParent();
                    } else {
                        ChildInParent = *this->meInParent;
                    }

                    this->pv = p_pv->pvAtLocalCoord(ChildInParent);
                    this->root->updatePV();
                    this->stateIndex = this->root->stateIndex;
                }
            }
        };
        void onChildAdded(Body*);
        void onChildRemoved(Body*);
        const Body* calcRootConst() const;
        Body* calcRoot();
    public:
        Body(const Body&);
        Body();
        virtual ~Body();

        int& getKernelIndex();
        void step(float, bool);
        IndexArray<Body, Body::getIndex> getChildren();
        bool cofmIsClean();
        Cofm getCofm() {return *cofm;};
        void makeCofmDirty();
        void advanceStateIndex();
        void makeStateDirty();
        int getStateIndex() const;
        int getNextStateIndex() const;
        int numChildren() const;
        Body* getChild(int) const;
        Body* getParent() const;
        Link* getLink() const;
        const Body* getRootConst() const;
        Body* getRoot();
        const G3D::Vector3& getCofmOffset();
        G3D::CoordinateFrame getMeInDescendant(const Body*) const;
        G3D::CoordinateFrame getMeInRoot() const;
        float getMass();
        G3D::Matrix3 getIBody();
        G3D::Vector3 getIBodyV3();
        G3D::Matrix3 getIWorld();
        G3D::Matrix3 getIWorldAtPoint(const G3D::Vector3&);
        float getBranchMass();
        G3D::Matrix3 getBranchIBody();
        G3D::Vector3 getBranchIBodyV3();
        G3D::Matrix3 getBranchIWorld();
        G3D::Matrix3 getBranchIWorldAtPoint(const G3D::Vector3&);
        G3D::Vector3 getBranchCofmPos();
        G3D::CoordinateFrame getBranchCofmCoordinateFrame();

        const G3D::Vector3& getPos();
        const G3D::CoordinateFrame& getCoordinateFrame();
        const Velocity& getVelocity();
        const PV& getPV();
        const bool getCanThrottle();
        
        void accumulateForceAtBranchCofm(const G3D::Vector3&);
        void accumulateForce(const G3D::Vector3&, const G3D::Vector3&);
        void accumulateTorque(const G3D::Vector3&);
        void resetAccumulators();
        const G3D::Vector3& getBranchForce() const;
        const G3D::Vector3& getBranchTorque() const;
        const Velocity& getBranchVelocity() const;
        void setParent(Body*);
        void setMeInParent(Link*);
        void setMeInParent(const G3D::CoordinateFrame&);
        void setMass(float);
        void setMoment(const G3D::Matrix3&);
        void setPv(const PV&);
        void setCoordinateFrame(const G3D::CoordinateFrame&);
        void setVelocity(const Velocity&);
        void setCanThrottle(bool);
        float kineticEnergy();
        float potentialEnergy() const;
        Body& operator=(const Body&);
    };
}