#include "v8world/Joint.h"

namespace RBX {
    class RigidJoint : public Joint {
    private:
        virtual RBX::Joint::JointType getJointType() const;
        virtual bool isBroken() const;
        static bool jointIsRigid(RBX::Joint*);
    protected: 
        static void faceIdToCoords(RBX::Primitive*, RBX::Primitive*, RBX::NormalId, RBX::NormalId, G3D::CoordinateFrame&, G3D::CoordinateFrame&);
    public: 
        RigidJoint(const RBX::RigidJoint&);
        RigidJoint(RBX::Primitive*, RBX::Primitive*, const G3D::CoordinateFrame&, const G3D::CoordinateFrame&);
        RigidJoint();
        virtual ~RigidJoint();
        virtual bool isAligned();
        virtual G3D::CoordinateFrame align(RBX::Primitive*, RBX::Primitive*);
        G3D::CoordinateFrame getChildInParent(RBX::Primitive*, RBX::Primitive*);
        RBX::RigidJoint& operator=(const RBX::RigidJoint&);
        // velDecDtor && vtableClosure are handled by the compiler
        static bool isRigidJoint(RBX::Edge*);
    };
} 