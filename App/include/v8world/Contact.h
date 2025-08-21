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
    class ContactConnector : public Contact {
    protected: 
        RBX::GeoPair geoPair;
        float k;
        float kFriction;
        float kNeg;
        float firstApproach;
        float threshold;
        float forceMagLast;
        G3D::Vector3 frictionOffset;

    public: 
        ContactConnector(const RBX::ContactConnector&);
        ContactConnector(float, float, float);
        void reset();
        void setBallBall(RBX::Body*, RBX::Body*, float, float);
        void setBallBlock(RBX::Body*, RBX::Body*, float, const G3D::Vector3*, RBX::NormalId, RBX::GeoPairType);
        void setPointPlane(RBX::Body*, RBX::Body*, const G3D::Vector3*, const G3D::Vector3*, int32_t, RBX::NormalId);
        void setEdgeEdgePlane(RBX::Body*, RBX::Body*, const G3D::Vector3*, const G3D::Vector3*, RBX::NormalId, RBX::NormalId, RBX::NormalId, float);
        void setEdgeEdge(RBX::Body*, RBX::Body*, const G3D::Vector3*, const G3D::Vector3*, RBX::NormalId, RBX::NormalId);
        bool match(RBX::Body*, RBX::Body*, RBX::GeoPairType, int32_t, int32_t);
        virtual void computeForce(const float, bool);
        virtual bool canThrottle() const;
        virtual ~ContactConnector();
        RBX::ContactConnector& operator=(const RBX::ContactConnector&);
        virtual void* __vecDelDtor(uint32_t);
    };
}