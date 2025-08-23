#pragma once

#include "v8kernel/KernelData.h"

namespace RBX {
    class Connector : public KernelData {
    private: 
        int32_t& getKernelIndex();
        
    public: 
        Connector(const RBX::Connector&);
        Connector();
        virtual ~Connector();
        virtual void computeForce(const float, bool);
        virtual bool canThrottle() const;
        virtual bool getBroken();
        virtual float potentialEnergy();
        RBX::Connector& operator=(const RBX::Connector&);
    }
}