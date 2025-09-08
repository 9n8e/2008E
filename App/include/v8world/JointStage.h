#pragma once

#include <set>
#include <map>

#include "v8world/Joint.h"
#include "v8world/Primitive.h"
#include "v8world/World.h"
#include "v8world/Edge.h"
#include "v8world/IWorldStage.h"
#include "v8world/ClumpStage.h"

namespace RBX {
    class JointStage : public RBX::IWorldStage {
    private:
        std::set<RBX::Joint *,std::less<RBX::Joint *>,std::allocator<RBX::Joint *> > incompleteJoints;
        std::multimap<RBX::Primitive *,RBX::Joint *,std::less<RBX::Primitive *>,std::allocator<std::pair<RBX::Primitive * const,RBX::Joint *> > > jointMap;

        RBX::ClumpStage* getClumpStage();
        void moveEdgeToDownstream(RBX::Edge*);
        void removeEdgeFromDownstream(RBX::Edge*);
        void moveJointToDownstream(RBX::Joint*);
        void removeJointFromDownstream(RBX::Joint*);
        bool jointInList(RBX::Joint*);
        void removeFromList(RBX::Joint*);
        void insertToList(RBX::Joint*);
        bool pairInMap(RBX::Joint*, RBX::Primitive*);
        void insertToMap(RBX::Joint*, RBX::Primitive*);
        void removeFromMap(RBX::Joint*, RBX::Primitive*);
        bool edgeHasPrimitivesDownstream(RBX::Edge*);

    public: 
        JointStage(const RBX::JointStage&);
        JointStage(RBX::IStage*, RBX::World*);
        virtual ~JointStage();
        virtual RBX::IStage::StageType getStageType();
        virtual void onEdgeAdded(RBX::Edge*);
        virtual void onEdgeRemoving(RBX::Edge*);
        void onPrimitiveAdded(RBX::Primitive*);
        void onPrimitiveRemoving(RBX::Primitive*);
        void onJointPrimitiveNulling(RBX::Joint*, RBX::Primitive*);
        void onJointPrimitiveSet(RBX::Joint*, RBX::Primitive*);
        RBX::JointStage& operator=(const RBX::JointStage&);
    };
}