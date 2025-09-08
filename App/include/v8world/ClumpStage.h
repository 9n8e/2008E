#pragma once

#include "v8world/World.h"
#include "v8world/Primitive.h"
#include "v8world/IPipelined.h"

namespace RBX {
    class ClumpStage {
    public: 
        ClumpStage(const RBX::ClumpStage&);
        ClumpStage(RBX::IStage*, RBX::World*);
        virtual ~ClumpStage();
        virtual RBX::IStage::StageType getStageType();
        void onPrimitiveAdded(RBX::Primitive*);
        void onPrimitiveRemoving(RBX::Primitive*);
        virtual void stepWorld(int, int, bool);
        void stepUi(int);
        void process();
        void onPrimitiveAddedAnchor(RBX::Primitive*);
        void onPrimitiveRemovedAnchor(RBX::Primitive*);
        void onPrimitiveCanSleepChanged(RBX::Primitive*);
        void onPrimitiveCanCollideChanged(RBX::Primitive*);
        void onMotorAngleChanged(RBX::MotorJoint*);
        RBX::ClumpStage& operator=(const RBX::ClumpStage&);
    };
}