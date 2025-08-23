#pragma once

#include <set>

#include "v8kernel/SimBody.h"

#include "v8world/Primitive.h"
#include "v8world/Clump.h"
#include "v8world/SleepStage.h"
#include "v8world/ContactManager.h"
#include "v8world/JointStage.h"

namespace RBX {
    struct AutoDestroy {
        RBX::Joint* joint;
        AutoDestroy(RBX::Joint*);
    };

    struct AutoJoin {
        RBX::Joint* joint;
        AutoJoin(RBX::Joint*);
    };

    struct RaiseRange {
    public: 
        int index;
        int upper;
        RBX::RaiseRange* previous;

        void removeIndex(int);
    };

    template<class F, class B>
    class Listener {
    protected: 
        virtual void onEvent(const F*, B);
        RBX::Listener<F,B>& operator=(const RBX::Listener<F,B>&);
        virtual ~Listener<F,B>();
    public: 
        Listener<F,B>(const RBX::Listener<F,B>&);
        Listener<F,B>();
    };

    template<class F, class B>
    class Notifier {
    private: 
        std::vector<RBX::Listener<F, B> *,std::allocator<RBX::Listener<F, B> *> > listeners;
        RBX::RaiseRange* raiseRange;

    protected: 
        Notifier<F, B>(const RBX::Notifier<F, B>&);
        Notifier<F, B>();
        RBX::Notifier<F, B>& operator=(const RBX::Notifier<F, B>&);
        virtual ~Notifier<F, B>();
        bool hasListeners() const;
        void raise(B, RBX::Listener<F, B>*) const;
        void raise(B) const;
        void raise() const;
        virtual void onAddListener(RBX::Listener<F, B>*) const;
        virtual void onRemoveListener(RBX::Listener<F, B>*) const;

    public: 
        void addListener(RBX::Listener<F, B>*) const;
        void removeListener(RBX::Listener<F, B>*) const;
    };

    class World : public RBX::Notifier<RBX::World, RBX::AutoJoin>, public RBX::Notifier<RBX::World, RBX::AutoDestroy> {
    private: 
        RBX::ContactManager* contactManager;
        RBX::JointStage* jointStage;
        G3D::Array<RBX::Primitive *> touch;
        G3D::Array<RBX::Primitive *> touchOther;
        bool canThrottle;
        bool inStepCode;
        bool inJointNotification;
        int worldStepId;
        RBX::IndexArray<RBX::Primitive,&RBX::Primitive::worldIndexFunc> primitives;
        std::set<RBX::Joint *,std::less<RBX::Joint *>,std::allocator<RBX::Joint *> > breakableJoints;
        int numJoints;
        int numContacts;
        int numLinkCalls;
        G3D::Array<RBX::Primitive *> tempPrimitives;
        // TBD
        // boost::scoped_ptr<RBX::Profiling::CodeProfiler> profilingWorldStep;
        // boost::scoped_ptr<RBX::Profiling::CodeProfiler> profilingUiStep;
        // boost::scoped_ptr<RBX::Profiling::CodeProfiler> profilingBroadphase;
        void destroyJoints(RBX::Primitive*, std::set<RBX::Primitive *,std::less<RBX::Primitive *>,std::allocator<RBX::Primitive *> >*);
        void destroyJoint(RBX::Joint*);
        void removeFromBreakable(RBX::Joint*);
        void doBreakJoints();
        void createJoints(RBX::Primitive*, std::set<RBX::Primitive *,std::less<RBX::Primitive *>,std::allocator<RBX::Primitive *> >*);

    public:
        static bool disableEnvironmentalThrottle;
        void createJoints(RBX::Primitive*);
        void destroyJoints(RBX::Primitive*);
        World(const RBX::World&);
        World();
        virtual ~World();
        void assertNotInStep();
        void assertInStep();
        void addedBodyForce();
        void setCanThrottle(bool);
        RBX::ContactManager& getContactManager();
        RBX::ClumpStage* getClumpStage();
        const RBX::CollisionStage* getCollisionStage() const;
        RBX::CollisionStage* getCollisionStage();
        const RBX::SleepStage* getSleepStage() const;
        RBX::SleepStage* getSleepStage();
        RBX::SimJobStage& getSimJobStage();
        const RBX::Kernel& getKernel() const;
        RBX::Kernel& getKernel();
        const G3D::Array<RBX::Primitive *>& getTouch() const;
        const G3D::Array<RBX::Primitive *>& getTouchOther() const;
        void computeFallen(G3D::Array<RBX::Primitive *>&) const;
        const G3D::Array<RBX::Primitive *>& getPrimitives() const;
        float step(float);
        void update();
        void reset();
        int getWorldStepId();
        void insertPrimitive(RBX::Primitive*);
        void removePrimitive(RBX::Primitive*);
        void ticklePrimitive(RBX::Primitive*, bool);
        void joinAll();
        void createJointsToWorld(const G3D::Array<RBX::Primitive *>&);
        void destroyJointsToWorld(const G3D::Array<RBX::Primitive *>&);
        void insertJoint(RBX::Joint*);
        void removeJoint(RBX::Joint*);
        int getMetric(RBX::IWorldStage::MetricType) const;
        int getNumBodies() const;
        int getNumPoints() const;
        int getNumConstraints() const;
        int getNumHashNodes() const;
        int getMaxBucketSize() const;
        int getNumLinkCalls() const;
        int getNumContacts() const;
        int getNumJoints() const;
        int getNumPrimitives() const;
        const RBX::Profiling::CodeProfiler& getProfileWorldStep() const;
        RBX::Profiling::CodeProfiler& getProfileWorldStep();
        const RBX::Profiling::CodeProfiler& getProfileBroadphase() const;
        const RBX::Profiling::CodeProfiler& getProfileUiStep() const;
        void onPrimitiveAddedAnchor(RBX::Primitive*);
        void onPrimitiveRemovedAnchor(RBX::Primitive*);
        void onPrimitiveExtentsChanged(RBX::Primitive*);
        void onAssemblyExtentsChanged(RBX::Assembly*);
        void onPrimitiveContactParametersChanged(RBX::Primitive*);
        void onPrimitiveCanCollideChanged(RBX::Primitive*);
        void onPrimitiveCanSleepChanged(RBX::Primitive*);
        void onPrimitiveGeometryTypeChanged(RBX::Primitive*);
        void onPrimitiveTouched(RBX::Primitive*, RBX::Primitive*);
        void onMotorAngleChanged(RBX::MotorJoint*);
        void onJointPrimitiveNulling(RBX::Joint*, RBX::Primitive*);
        void onJointPrimitiveSet(RBX::Joint*, RBX::Primitive*);
        void insertContact(RBX::Contact*);
        void destroyContact(RBX::Contact*);
        RBX::World& operator=(const RBX::World&);
    };
}