#pragma once

#include "v8kernel/KernelIndex.h"

namespace RBX {
    class Point : public RBX::KernelIndex {
    private: 
        int numOwners;
    protected: 
        RBX::Body* body;
        G3D::Vector3 localPos;
        G3D::Vector3 worldPos;
        G3D::Vector3 force;
        Point(RBX::Body*);
        virtual ~Point();

    public: 
        int& getKernelIndex();
        Point(const RBX::Point&);
        void step();
        void accumulateForce(const G3D::Vector3&);
        void forceToBody();
        void setLocalPos(const G3D::Vector3&);
        void setWorldPos(const G3D::Vector3&);
        void setBody(RBX::Body*);
        RBX::Body* getBody();
        const G3D::Vector3& getWorldPos();
        RBX::Point& operator=(const RBX::Point&);
        static bool sameBodyAndOffset(const RBX::Point&, const RBX::Point&);
    };
}