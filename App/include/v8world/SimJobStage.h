#pragma once

#include <list>

#include "v8world/World.h"

namespace RBX {
    class SimJob {
    private: 
        std::set<RBX::Assembly *,std::less<RBX::Assembly *>,std::allocator<RBX::Assembly *> > assemblies;
        std::vector<RBX::SimJobTracker *,std::allocator<RBX::SimJobTracker *> > trackers;

    public: 
        std::list<RBX::SimJob *,std::allocator<RBX::SimJob *> >::iterator myIt;
        ~SimJob();
        const std::set<RBX::Assembly *,std::less<RBX::Assembly *>,std::allocator<RBX::Assembly *> >& getAssemblies() const;
        std::set<RBX::Assembly *,std::less<RBX::Assembly *>,std::allocator<RBX::Assembly *> >& getAssemblies();
        void notifyMovingPrimitives();
        void insertAssembly(RBX::Assembly*);
        void removeAssembly(RBX::Assembly*);
        void absorb(RBX::SimJob*);
        SimJob(const RBX::SimJob&);
        SimJob();
        RBX::SimJob& operator=(const RBX::SimJob&);

        static RBX::SimJob* getSimJobFromPrimitive(const RBX::Primitive*);
    };

    class SimJobStage {
    private: 
        std::list<RBX::SimJob *,std::allocator<RBX::SimJob *> > simJobs;
        void combineSimJobs(RBX::Edge*);
        void insertSimJob(RBX::SimJob*);
        void destroySimJob(RBX::SimJob*);
        void splitSimJobs(RBX::Assembly*, RBX::Assembly*);
        bool validateEdge(RBX::Edge*);

    public: 
        RBX::SimJob* nextSimJob(std::list<RBX::SimJob *,std::allocator<RBX::SimJob *> >&, const RBX::SimJob*);
        SimJobStage(const RBX::SimJobStage&);
        SimJobStage(RBX::IStage*, RBX::World*);
        virtual ~SimJobStage();
        virtual RBX::IStage::StageType getStageType();
        virtual void onEdgeAdded(RBX::Edge*);
        virtual void onEdgeRemoving(RBX::Edge*);
        void onAssemblyAdded(RBX::Assembly*);
        void onAssemblyRemoving(RBX::Assembly*);
        void notifyMovingPrimitives();
        RBX::SimJobStage& operator=(const RBX::SimJobStage&);
    };
    
    class SimJobTracker {
    private: 
        RBX::SimJob* simJob;
        bool containedBy(RBX::SimJob*);
        void stopTracking();

    public: 
        SimJobTracker();
        ~SimJobTracker();
        bool tracking();
        void setSimJob(RBX::SimJob*);
        RBX::SimJob* getSimJob();
        static void transferTrackers(RBX::SimJob*, RBX::SimJob*);
    };
}