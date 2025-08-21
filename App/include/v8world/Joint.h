#pragma once

#include "v8world/Edge.h"

namespace RBX {
    class Joint : public Edge {
    private: 
        RBX::IJointOwner* jointOwner;
        static bool canBuildJoint(RBX::Primitive*, RBX::Primitive*, RBX::NormalId, RBX::NormalId, float, float);

    protected: 
        bool active;
        G3D::CoordinateFrame jointCoord0;
        G3D::CoordinateFrame jointCoord1;
        virtual RBX::Edge::EdgeType getEdgeType() const;
        void Joint(RBX::Primitive*, RBX::Primitive*, const G3D::CoordinateFrame&, const G3D::CoordinateFrame&);
        void Joint();
        static bool canBuildJointLoose(RBX::Primitive*, RBX::Primitive*, RBX::NormalId, RBX::NormalId);
        static bool canBuildJointTight(RBX::Primitive*, RBX::Primitive*, RBX::NormalId, RBX::NormalId);

    public: 
        enum JointType {
            NO_JOINT = 0x0000,
            ROTATE_JOINT = 0x0001,
            ROTATE_P_JOINT = 0x0002,
            ROTATE_V_JOINT = 0x0003,
            GLUE_JOINT = 0x0004,
            ANCHOR_JOINT = 0x0005,
            WELD_JOINT = 0x0006,
            SNAP_JOINT = 0x0007,
            MOTOR_JOINT = 0x0008,
            FREE_JOINT = 0x0009,
        };

        Joint(const RBX::Joint&);
        ~Joint();
        void setJointOwner(RBX::IJointOwner*);
        RBX::IJointOwner* getJointOwner() const;
        virtual void setPrimitive(int32_t, RBX::Primitive*);
        virtual RBX::Joint::JointType getJointType() const;
        virtual bool isBreakable() const;
        virtual bool isBroken() const;
        virtual bool joinsFace(RBX::Primitive*, RBX::NormalId) const;
        virtual bool isAligned();
        virtual G3D::CoordinateFrame align(RBX::Primitive*, RBX::Primitive*);
        virtual bool canStepUi() const;
        virtual void stepUi(int32_t);
        bool getActive() const;
        void setActive(bool);
        void setJointCoord(int32_t, const G3D::CoordinateFrame&);
        const G3D::CoordinateFrame& getJointCoord(int32_t) const;
        RBX::NormalId getNormalId(int32_t) const;
        RBX::Joint& operator=(const RBX::Joint&);
        void __local_vftable_ctor_closure();
        virtual void* __vecDelDtor(uint32_t);
        static JointType getJointType(RBX::Edge*);
        static bool isJoint(RBX::Edge*);
        static bool isAssemblyJoint(RBX::Edge*);
        static bool isGroundJoint(RBX::Joint*);
        static bool isAutoJoinJoint(RBX::Joint*);
    };
}