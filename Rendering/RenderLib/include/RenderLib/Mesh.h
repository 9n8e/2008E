#pragma once

#include "G3D/ReferenceCount.h"
#include "G3D/Array.h"
#include "G3D/MeshAlg.h"
#include "G3D/Pointer.h"

namespace RBX::Render {
    namespace Mesh {
        class Level {
        public: 
            G3D::Array<unsigned int> indexArray;
            G3D::RenderDevice::Primitive primitive;

            void appendVertex(const G3D::Vector3&, const G3D::Vector3&, const G3D::Vector2&);
            Level(const RBX::Render::Mesh::Level&);
            Level();
            Level(G3D::RenderDevice::Primitive);
            virtual ~Level();
            RBX::Render::Mesh::Level& operator=(const RBX::Render::Mesh::Level&);
        };
        class ShadowSurface {
        public: 
            G3D::Array<G3D::MeshAlg::Edge> edgeArray;
            G3D::Array<G3D::Vector3> faceNormalArray;
            G3D::Array<G3D::MeshAlg::Face> faceArray;
            G3D::Array<G3D::Vector3> geometry;
            G3D::ReferenceCountedPointer<Mesh::Level> dropShadowGeometry;

            ShadowSurface(const Mesh::ShadowSurface&);
            ShadowSurface();
            ~ShadowSurface();
            Mesh::ShadowSurface& operator=(const Mesh::ShadowSurface&);
        };
    };

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
        static int findVertex(const G3D::Array<int>&, const G3D::Vector3&, const G3D::Vector3&, const G3D::Vector2&);
        static void toFindGridCoords(const G3D::Vector3&, int&, int&, int&);
        static void makeVAR();
        static void computeAABounds(const std::vector<G3D::ReferenceCountedPointer<RBX::Render::Chunk>,std::allocator<G3D::ReferenceCountedPointer<RBX::Render::Chunk> > >&, G3D::Vector3&, G3D::Vector3&);

    protected: 
        G3D::Array<G3D::ReferenceCountedPointer<Mesh::Level> > levels;
        Mesh::ShadowSurface shadowSurface;
        int detailIndex(double) const;
        void computeShadowSurface(const G3D::ReferenceCountedPointer<Mesh::Level>&);
        Mesh();
        static void initStatics();

    public:
        Mesh(const Mesh&);
        virtual ~Mesh();
        float debugBoundingRadius;
        G3D::ReferenceCountedPointer<Mesh::Level> dropShadowMesh();
        const G3D::ReferenceCountedPointer<Mesh::Level> detailLevel(float) const;
        void computeDirectionalShadowVolume(const G3D::CoordinateFrame&, const G3D::Vector3&, G3D::Array<unsigned int>&, G3D::Array<G3D::Vector3>&, bool) const;
        Mesh& operator=(const Mesh&);
        static void flushVAR();
        static int allocVertex(int, int);
        static int allocVertex(const G3D::Vector3&, const G3D::Vector3&, const G3D::Vector2&, bool);
        static G3D::ReferenceCountedPointer<Mesh> aggregate(const std::vector<G3D::ReferenceCountedPointer<RBX::Render::Chunk>,std::allocator<G3D::ReferenceCountedPointer<RBX::Render::Chunk> > >&, G3D::CoordinateFrame&, float&);
        static void freeVertex(int);
        static int findVertex(const G3D::Vector3&, const G3D::Vector3&, const G3D::Vector2&);
        static void setShadowVertex(const G3D::Vector3&);
        static void beginRender(G3D::RenderDevice*, bool, bool);
        static void sendGeometry(const Mesh::Level*, G3D::RenderDevice*);
        static void endRender(G3D::RenderDevice*);
    }; 
};