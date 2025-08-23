#pragma once

#include "v8world/IPipelined.h"

#include "v8kernel/KernelData.h"

namespace RBX {
    class Kernel : public IStage {
    private: 
        bool inStepCode;
        RBX::KernelData* kernelData;
        G3D::Array<RBX::Connector *> realTimeConnectors;
        int maxBodies;
        int maxPoints;
        int maxConnectors;
        static int numKernels;

    public: 
        // TBD // boost::scoped_ptr<RBX::Profiling::CodeProfiler> profilingKernel;
        Kernel(const RBX::Kernel&);
        Kernel(RBX::IStage*);
        virtual ~Kernel();
        virtual RBX::IStage::StageType getStageType();
        virtual void stepWorld(int, int, bool);
        virtual RBX::Kernel* getKernel();
        void insertBody(RBX::Body*);
        void insertPoint(RBX::Point*);
        void insertConnector(RBX::Connector*);
        void insertConnector2ndPass(RBX::Connector*);
        void removeBody(RBX::Body*);
        void removePoint(RBX::Point*);
        void removeConnector(RBX::Connector*);
        void removeConnector2ndPass(RBX::Connector*);
        RBX::Point* newPoint(RBX::Body*, const G3D::Vector3&);
        void deletePoint(RBX::Point*);
        void report();
        float connectorSpringEnergy() const;
        float bodyPotentialEnergy() const;
        float bodyKineticEnergy() const;
        float totalEnergy() const;
        float totalKineticEnergy() const;
        int numBodies() const;
        int numPoints() const;
        int numConnectors() const;
        RBX::Kernel& operator=(const RBX::Kernel&);
    };
}