#pragma once

#include "v8world/IPipelined.h"

namespace RBX {
    class Edge : public IPipelined {};
    class EdgeIterator {
    private: 
        RBX::Primitive* primitive;
        RBX::Edge* edge;
        static bool isExternalEdge(RBX::Primitive*, const RBX::Edge*);
        static RBX::Edge* getNextExternalUtil(RBX::Primitive*, RBX::Edge*);
        static RBX::Edge* getFirstExternalEdge(RBX::Primitive*);
        static RBX::Edge* getNextExternalEdge(RBX::Primitive*, RBX::Edge*);
        void findEdgeOnNextPrimitive();

    public: 
        EdgeIterator(RBX::Primitive*, RBX::Edge*);
        RBX::Edge* operator*() const;
        bool operator==(const RBX::EdgeIterator&) const;
        bool operator!=(const RBX::EdgeIterator&) const;
        RBX::EdgeIterator& operator++();
        static RBX::EdgeIterator begin(RBX::Primitive*);
        static RBX::EdgeIterator& end();
    };
}