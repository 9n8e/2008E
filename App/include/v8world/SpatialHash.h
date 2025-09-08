#pragma once

#include <vector>

#include "v8world/World.h"
#include "v8world/ContactManager.h"
#include "util/Vector3int32.h"

namespace RBX {
    class SpatialNode {
    public: 
        RBX::Primitive* primitive;
        RBX::SpatialNode* nextHashLink;
        RBX::SpatialNode* nextPrimitiveLink;
        RBX::SpatialNode* prevPrimitiveLink;
        int hashId;
        RBX::Vector3int32 gridId;

        SpatialNode();
    };

    class SpatialHash {
    private: 
        RBX::World* world;
        RBX::ContactManager* contactManager;
        std::vector<RBX::SpatialNode *,std::allocator<RBX::SpatialNode *> > nodes;
        RBX::SpatialNode* extraNodes;
        int nodesOut;
        int maxBucket;

        RBX::SpatialNode* newNode();
        void returnNode(RBX::SpatialNode*);
        bool shareCommonGrid(RBX::Primitive*, RBX::Primitive*);
        bool hashHasPrimitive(RBX::Primitive*, int, const RBX::Vector3int32&);
        RBX::SpatialNode* findNode(RBX::Primitive*, const RBX::Vector3int32&);
        void removeNodeFromHash(RBX::SpatialNode*);
        void insertNodeToPrimitive(RBX::SpatialNode*, RBX::Primitive*, const RBX::Vector3int32&, int);
        void removeNodeFromPrimitive(RBX::SpatialNode*);
        void addNode(RBX::Primitive*, const RBX::Vector3int32&);
        void destroyNode(RBX::SpatialNode*);
        void changeMinMax(RBX::Primitive*, const RBX::Extents&, const RBX::Extents&, const RBX::Extents&);
        void primitiveExtentsChanged(RBX::Primitive*);
        int numNodes(int) const;
        static float hashGridSize();
        static float hashGridRecip();
        static int numBuckets();
        static int numBits();
        static int getHash(const RBX::Vector3int32&);
        static RBX::Extents computeMinMax(const RBX::Extents&);
        static void computeMinMax(const RBX::Extents&, RBX::Vector3int32&, RBX::Vector3int32&);
        static void computeMinMax(const RBX::Primitive*, RBX::Vector3int32&, RBX::Vector3int32&);

    public: 
        SpatialHash(const RBX::SpatialHash&);
        SpatialHash(RBX::World*, RBX::ContactManager*);
        ~SpatialHash();
        void onPrimitiveAdded(RBX::Primitive*);
        void onPrimitiveRemoved(RBX::Primitive*);
        void onPrimitiveExtentsChanged(RBX::Primitive*);
        void onAllPrimitivesMoved();
        void getPrimitivesInGrid(const RBX::Vector3int32&, G3D::Array<RBX::Primitive *>&);
        bool getNextGrid(RBX::Vector3int32&, const G3D::Ray&, float);
        void getPrimitivesTouchingExtents(const RBX::Extents&, const RBX::Primitive*, G3D::Array<RBX::Primitive *>&);
        int getNodesOut() const;
        int getMaxBucket() const;
        void doStats() const;
        RBX::SpatialHash& operator=(const RBX::SpatialHash&);

        static RBX::Vector3int32 realToHashGrid(const G3D::Vector3&);
        static G3D::Vector3 hashGridToReal(const G3D::Vector3&);
        static RBX::Extents hashGridToRealExtents(const G3D::Vector3&);
    };
}