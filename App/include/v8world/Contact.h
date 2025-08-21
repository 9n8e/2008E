#pragma once
#include "v8world/Edge.h"
#include "v8world/Primitive.h"

#include "v8kernel/Body.h"
#include "v8kernel/Kernel.h"

namespace RBX {
    class Contact {
    private: 
        int lastContactStep; 
        int steppingIndex;
        float jointK;
        float elasticJointK;
        float kFriction;
        static bool ignoreBool;
        virtual void putInKernel(RBX::Kernel*);
        virtual void removeFromKernel();
        virtual RBX::Edge::EdgeType getEdgeType() const;

    protected: 
        RBX::Body* getBody(int32_t) const;
        RBX::ContactConnector* createConnector();
        void deleteConnector(RBX::ContactConnector*&);
        virtual void deleteAllConnectors();
        virtual bool stepContact();
        static int contactPairMatches;
        static int contactPairMisses;

    public:
        Contact(const RBX::Contact&);
        Contact(RBX::Primitive*, RBX::Primitive*);
        virtual ~Contact();
        int& steppingIndexFunc();
        virtual bool computeIsColliding(float);
        bool computeIsAdjacent(float);
        void onPrimitiveContactParametersChanged();
        bool step(int);
        RBX::Contact& operator=(const RBX::Contact&);
        static bool isContact(RBX::Edge*);
    };
}