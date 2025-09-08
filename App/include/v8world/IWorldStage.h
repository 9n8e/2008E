#pragma once

#include "v8world/World.h"

namespace RBX {
    class IWorldStage : public RBX::IStage {
    private: 
        RBX::World* world;
    
    public: 
        enum MetricType {
            NUM_CONTACTSTAGE_CONTACTS = 0x0000,
            NUM_STEPPING_CONTACTS = 0x0001,
            NUM_TOUCHING_CONTACTS = 0x0002,
            MAX_TREE_DEPTH = 0x0003,
        };

        IWorldStage(const RBX::IWorldStage&);
        IWorldStage(RBX::IStage*, RBX::IStage*, RBX::World*);
        RBX::IWorldStage* getUpstreamWS();
        RBX::IWorldStage* getDownstreamWS();
        RBX::World* getWorld();
        virtual void onEdgeAdded(RBX::Edge*);
        virtual void onEdgeRemoving(RBX::Edge*);
        virtual int getMetric(RBX::IWorldStage::MetricType);
        virtual ~IWorldStage();
        RBX::IWorldStage& operator=(const RBX::IWorldStage&);
    };
}