#pragma once

#include "v8world/Joint.h"

namespace RBX {
    class MotorJoint : public Joint {
    private:
        RBX::RevoluteLink* link;
        float currentAngle;
        virtual RBX::Joint::JointType getJointType() const;
        virtual bool isBroken() const;
        virtual bool isAligned();
        int32_t getParentId() const;
        void setJointAngle(float);
    public: 
        float maxVelocity;
        float desiredAngle;
        float getCurrentAngle() const;
        void setCurrentAngle(float);
        G3D::CoordinateFrame getMeInOther(RBX::Primitive*);
        virtual void stepUi(int32_t);
        MotorJoint(const RBX::MotorJoint&);
        MotorJoint();
        virtual ~MotorJoint();
        uint32_t hashCode() const;
        RBX::RevoluteLink* resetLink();
        RBX::MotorJoint& operator=(const RBX::MotorJoint&);
        void __local_vftable_ctor_closure();
        static bool isMotorJoint(RBX::Edge*);
    };
}