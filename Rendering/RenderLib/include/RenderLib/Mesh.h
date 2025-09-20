#pragma once

#include "G3D/ReferenceCount.h"
#include "G3D/Array.h"
#include "G3D/MeshAlg.h"
#include "G3D/Pointer.h"

namespace RBX::Render {
    class Mesh : public G3D::ReferenceCountedObject {
    private: 
        static G3D::MeshAlg::Geometry visibleGeometry;
        static G3D::Array<G3D::Vector2> texCoordArray;
        static G3D::Array<G3D::Vector3> tangentArray;
        static G3D::Array<int> vertexRefCounts;
        static G3D::Array<int> freeList;
        static G3D::VAR vertexVAR;
        static G3D::VAR normalVAR;
        static G3D::VAR texCoordVAR;
        static G3D::VAR tangentVAR;
        static bool varDirty;
        static G3D::Vector3 findScale;
        static G3D::Array<int> findGrid[32][32][32];
        static G3D::Array<int>& getFindGridCell(const G3D::Vector3&);
        static uint32_t findVertex(const G3D::Array<int>&, const G3D::Vector3&, const G3D::Vector3&, const G3D::Vector2&);
        static void toFindGridCoords(const G3D::Vector3&, int32_t&, int32_t&, int32_t&);
        static void makeVAR();
        static void computeAABounds(const std::vector<G3D::ReferenceCountedPointer<RBX::Render::Chunk>,std::allocator<G3D::ReferenceCountedPointer<RBX::Render::Chunk> > >&, G3D::Vector3&, G3D::Vector3&);

    protected: 
        G3D::Array<G3D::ReferenceCountedPointer<RBX::Render::Mesh::Level> > levels;
        RBX::Render::Mesh::ShadowSurface shadowSurface;
        int32_t detailIndex(double) const;
        void computeShadowSurface(const G3D::ReferenceCountedPointer<RBX::Render::Mesh::Level>&);
        Mesh();
        static void initStatics();

    public:
        Mesh(const RBX::Render::Mesh&);
        virtual ~Mesh();
        float debugBoundingRadius;
        G3D::ReferenceCountedPointer<RBX::Render::Mesh::Level> dropShadowMesh();
        const G3D::ReferenceCountedPointer<RBX::Render::Mesh::Level> detailLevel(float) const;
        void computeDirectionalShadowVolume(const G3D::CoordinateFrame&, const G3D::Vector3&, G3D::Array<unsigned int>&, G3D::Array<G3D::Vector3>&, bool) const;
        RBX::Render::Mesh& operator=(const RBX::Render::Mesh&);
        void __local_vftable_ctor_closure();
        virtual void* __vecDelDtor(uint32_t);
        static void flushVAR();
        static uint32_t allocVertex(uint32_t, uint32_t);
        static uint32_t allocVertex(const G3D::Vector3&, const G3D::Vector3&, const G3D::Vector2&, bool);
        static G3D::ReferenceCountedPointer<RBX::Render::Mesh> aggregate(const std::vector<G3D::ReferenceCountedPointer<RBX::Render::Chunk>,std::allocator<G3D::ReferenceCountedPointer<RBX::Render::Chunk> > >&, G3D::CoordinateFrame&, float&);
        static void freeVertex(uint32_t);
        static uint32_t findVertex(const G3D::Vector3&, const G3D::Vector3&, const G3D::Vector2&);
        static void setShadowVertex(const G3D::Vector3&);
        static void beginRender(G3D::RenderDevice*, bool, bool);
        static void sendGeometry(const RBX::Render::Mesh::Level*, G3D::RenderDevice*);
        static void endRender(G3D::RenderDevice*);
    }; 

    namespace Mesh {
        class ShadowSurface {
        public: 
            G3D::Array<G3D::MeshAlg::Edge> edgeArray;
            G3D::Array<G3D::Vector3> faceNormalArray;
            G3D::Array<G3D::MeshAlg::Face> faceArray;
            G3D::Array<G3D::Vector3> geometry;
            G3D::ReferenceCountedPointer<RBX::Render::Mesh::Level> dropShadowGeometry;

            ShadowSurface(const RBX::Render::Mesh::ShadowSurface&);
            ShadowSurface();
            ~ShadowSurface();
            RBX::Render::Mesh::ShadowSurface& operator=(const RBX::Render::Mesh::ShadowSurface&);
        };
    };
};