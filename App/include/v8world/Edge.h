#pragma once

#include "v8world/IPipelined.h"

namespace RBX {
    class Edge : public IPipelined {
    private: 
        RBX::Sim::EdgeState edgeState;
        RBX::Primitive* prim0;
        RBX::Primitive* prim1;
        RBX::Edge* next0;
        RBX::Edge* next1;
        bool inEdgeList;
  
    public: 
        enum EdgeType {
            JOINT = 0x0000,
            CONTACT = 0x0001,
        };
        Edge(const RBX::Edge&);
        Edge(RBX::Primitive*, RBX::Primitive*);
        virtual ~Edge();
        bool getInEdgeList() const;
        void setInEdgeList(bool);
        virtual RBX::Edge::EdgeType getEdgeType() const;
        RBX::Sim::EdgeState getEdgeState() const;
        void setEdgeState(RBX::Sim::EdgeState);
        RBX::Primitive* getPrimitive(int32_t) const;
        RBX::Primitive* otherPrimitive(int32_t) const;
        RBX::Primitive* otherPrimitive(const RBX::Primitive*) const;
        int32_t getPrimitiveId(const RBX::Primitive*) const;
        RBX::Edge* getNext(const RBX::Primitive*) const;
        void setNext(RBX::Primitive*, RBX::Edge*);
        bool links(RBX::Primitive*, RBX::Primitive*) const;
        bool links(const RBX::Primitive*) const;
        virtual void setPrimitive(int32_t, RBX::Primitive*);
        RBX::Edge& operator=(const RBX::Edge&);
        virtual void* __vecDelDtor(uint32_t);
    };
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