#pragma once

#include "util/IndexArray.h"

#include "v8world/Contact.h"
#include "v8world/World.h"

namespace RBX {
    class CollisionStage {
    private: 
        int numContactsInStage;
        RBX::IndexArray<RBX::Contact,&RBX::Contact::steppingIndexFunc> stepping;

        bool getOkToSim(RBX::Contact*, bool&);
        bool confirmOneClumpHere(RBX::Edge*);
        RBX::Contact* getContactBetweenPrimitives(RBX::Joint*);
        void removeContactFromDownstreamStage(RBX::Contact*);
        void removeContact(RBX::Contact*);
        void updateContact(RBX::Contact*);
        void onJointAdded(RBX::Joint*);
        void onJointRemoved(RBX::Joint*);
    public: 
        // boost::scoped_ptr<RBX::Profiling::CodeProfiler> profilingCollision;
        CollisionStage(const RBX::CollisionStage&);
        CollisionStage(RBX::IStage*, RBX::World*);
        virtual ~CollisionStage();
        virtual RBX::IStage::StageType getStageType();
        virtual void stepWorld(int, int, bool);
        virtual void onEdgeAdded(RBX::Edge*);
        virtual void onEdgeRemoving(RBX::Edge*);
        virtual int getMetric(RBX::IWorldStage::MetricType);
        void onAssemblyAdded(RBX::Assembly*);
        void onAssemblyRemoving(RBX::Assembly*);
        void onPrimitiveCanCollideChanged(RBX::Primitive*);
        void onSleepChanged(const RBX::Assembly*);
        void onLosingContact(const G3D::Array<RBX::Contact *>&);
        RBX::CollisionStage& operator=(const RBX::CollisionStage&);
    };
}