#pragma once

#include "util/NormalId.h"

#include "v8kernel/Body.h"
#include "v8kernel/Pair.h"

#include "G3D/Vector3.h"

namespace RBX {
    struct GeoPairData {
        union {
            public: RBX::NormalId normalID0;
            float radius0;
        };
        union {
            public: RBX::NormalId normalID1;
            float radiusSum;
        };
        union {
            public: RBX::NormalId planeID;
            int point0ID;
        };
    };
    enum GeoPairType {
        BALL_BALL_PAIR = 0x0000,
        BALL_POINT_PAIR = 0x0001,
        BALL_EDGE_PAIR = 0x0002,
        BALL_PLANE_PAIR = 0x0003,
        POINT_PLANE_PAIR = 0x0004,
        EDGE_EDGE_PLANE_PAIR = 0x0005,
        EDGE_EDGE_PAIR = 0x0006
    };
    class Geometry {};
    class GeoPair {
    private: 
        RBX::GeoPairType geoPairType;
        const G3D::Vector3* offset0;
        const G3D::Vector3* offset1;
        RBX::Body* body0;
        RBX::Body* body1;
        float edgeLength0;
        GeoPairData pairData;
        void computeBallBall(RBX::PairParams&);
        void computeBallPoint(RBX::PairParams&);
        void computeBallEdge(RBX::PairParams&);
        void computeBallPlane(RBX::PairParams&);
        void computePointPlane(RBX::PairParams&);
        void computeEdgeEdgePlane(RBX::PairParams&);
        void computeEdgeEdge(RBX::PairParams&);

    public: 
        bool match(RBX::Body*, RBX::Body*, RBX::GeoPairType, int32_t, int32_t);
        GeoPair();
        const RBX::Body* getBody(int32_t) const;
        RBX::Body* getBody(int32_t);
        void computeLengthNormalPosition(RBX::PairParams&);
        void computeNormalPerpVel(float&, G3D::Vector3&, const RBX::PairParams&);
        void forceToBodies(const G3D::Vector3&, const G3D::Vector3&);
        void setBallBall(RBX::Body*, RBX::Body*, float, float);
        void setBallBlock(RBX::Body*, RBX::Body*, float, const G3D::Vector3*, RBX::NormalId, RBX::GeoPairType);
        void setPointPlane(RBX::Body*, RBX::Body*, const G3D::Vector3*, const G3D::Vector3*, int32_t, RBX::NormalId);
        void setEdgeEdgePlane(RBX::Body*, RBX::Body*, const G3D::Vector3*, const G3D::Vector3*, RBX::NormalId, RBX::NormalId, RBX::NormalId, float);
        void setEdgeEdge(RBX::Body*, RBX::Body*, const G3D::Vector3*, const G3D::Vector3*, RBX::NormalId, RBX::NormalId);
    };
}