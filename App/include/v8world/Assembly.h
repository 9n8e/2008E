#pragma once

#include <vector>

#include "v8kernel/Body.h"
#include "v8kernel/Kernel.h"
#include "v8kernel/SimBody.h"

#include "v8world/IPipelined.h"
#include "v8world/SleepStage.h"
#include "v8world/Primitive.h"
#include "v8world/Mechanism.h"
#include "v8world/MotorJoint.h"
#include "v8world/Joint.h"
#include "v8world/RigidJoint.h"

#include "util/ComputeProp.h"

namespace RBX {
    int fastRemoveShort(std::vector<RBX::SimJobTracker *> *vec, RBX::SimJobTracker **item) {}

    class Assembly : public RBX::IPipelined {
    private: 
        RBX::SleepInfo* sleepInfo;
        RBX::Primitive* rootPrimitive;
        RBX::Assembly* parent;
        std::vector<RBX::Assembly *,std::allocator<RBX::Assembly *> > children;
        RBX::Mechanism* mechanism;

        RBX::ComputeProp<float,RBX::Assembly> maxRadius;
        RBX::ComputeProp<bool,RBX::Assembly> canSleep;

        void removeChild(RBX::Assembly*);
        void addChild(RBX::Assembly*);
        float computeMaxRadius() const;
        bool computeCanSleep() const;
        void onPrimitivesChanged();
        void onPrimitiveRemoved(RBX::Primitive*);
        void onPrimitiveAdded(RBX::Primitive*);
        const RBX::Body* getRootBody() const;
        RBX::Body* getRootBody();
        const RBX::MotorJoint* getMotorImp(uint32_t&) const;
        static RBX::Joint* getJointToParent(RBX::Primitive*);
    public:
        Assembly(const RBX::Assembly&);
        Assembly(RBX::Primitive*);
        virtual ~Assembly();
        void setParent(RBX::Assembly*);
        RBX::Assembly* getParent();
        const RBX::Primitive* getClumpPrimitive() const;
        RBX::Primitive* getClumpPrimitive();
        RBX::Primitive* getAssemblyPrimitive();
        const RBX::Primitive* getAssemblyPrimitiveConst() const;
        RBX::Assembly* getRootAssembly();
        const RBX::Assembly* getRootAssemblyConst() const;
        RBX::Assembly* getRootClump();
        bool getAnchored() const;
        void notifyMoved();
        int getDof() const;
        virtual void putInKernel(RBX::Kernel*);
        virtual void removeFromKernel();
        void setMechanism(RBX::Mechanism*);
        RBX::Mechanism* getMechanism();
        void stepUi(int32_t);
        void setSleepInfo(RBX::SleepInfo*);
        RBX::SleepInfo* getSleepInfo();
        RBX::Sim::AssemblyState getSleepStatus() const;
        bool moving() const;
        bool getCanSleep();
        float getMaxRadius();
        void onPrimitiveCanSleepChanged(RBX::Primitive*);
        RBX::PrimIterator assemblyPrimBegin() const;
        RBX::PrimIterator assemblyPrimEnd() const;
        RBX::EdgeIterator externalEdgeBegin() const;
        RBX::EdgeIterator externalEdgeEnd() const;
        RBX::Assembly* otherAssembly(RBX::Edge*) const;
        uint32_t numMotors() const;
        RBX::MotorJoint* getMotor(uint32_t);
        const RBX::MotorJoint* getMotorConst(uint32_t) const;
        RBX::Assembly& operator=(const RBX::Assembly&);


        static void addRigidChild(RBX::Primitive*, RBX::RigidJoint*, RBX::Primitive*);
        static void addMotorChild(RBX::Primitive*, RBX::MotorJoint*, RBX::Primitive*);
        static void addGroundChild(RBX::Primitive*);
    }
}