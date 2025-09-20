#pragma once

#include "G3D/Array.h"

namespace RBX::Render {
    class RenderScene {
    private: 
        G3D::Array<RBX::Render::RenderSurface> proxyArray;
        G3D::Array<RBX::Render::RenderSurface *> diffuseProxyArray;
        G3D::Array<RBX::Render::RenderSurface *> reflectProxyArray;
        G3D::Array<RBX::Render::RenderSurface *> transparentProxyArray;
        G3D::Array<RBX::Render::RenderSurface> shadowProxyArray;
        G3D::Array<G3D::ReferenceCountedPointer<RBX::Render::Chunk> > shadowCachingChunkArray;
        G3D::VAR shadowVAR;
        G3D::ReferenceCountedPointer<G3D::VARArea> shadowVARArea;
        RBX::Render::EffectSettings effectSettings;
        G3D::ReferenceCountedPointer<G3D::Lighting> desiredLighting;
        G3D::ReferenceCountedPointer<G3D::Lighting> lighting;
        float shadingQuality;
        float meshDetail;
        bool shadows;
        float cameraDistance;
        G3D::Array<G3D::ReferenceCountedPointer<RBX::Render::Chunk> > chunkArray;
        G3D::Array<unsigned int> shadowIndexArray;

        void updateShadowVAR(const G3D::Array<G3D::Vector3>&);
        void computeShadowVolumeGeometry(G3D::Array<unsigned int>&, G3D::Array<G3D::Vector3>&, const G3D::GLight&, bool, float);
        void clearProxyArrays();
        void allocateProxies(G3D::RenderDevice*, const G3D::GCamera&);
        void classifyProxies();
        void sortProxies();
        void computeProxyArrays(G3D::RenderDevice*, const G3D::GCamera&);
        void sendDiffuseProxyMeshGeometry(G3D::RenderDevice*) const;
        void markStencilShadows(G3D::RenderDevice*, const G3D::GCamera&, const G3D::GLight&);
        void sendShadowProxyMeshGeometry(G3D::RenderDevice*, const G3D::GLight&) const;
        void turnOnLights(G3D::RenderDevice*, bool) const;
        void diffusePass(G3D::RenderDevice*);
        void reflectionPass(G3D::RenderDevice*);
        void transparentPass(G3D::RenderDevice*);
        void debugShowTextures(G3D::RenderDevice*, const G3D::GCamera&);
        void renderShadowVolumeGeometry(G3D::RenderDevice*, const G3D::GLight&, bool, float);

    public: 
        RenderStats renderStats;
        bool debugShadowVolumes;
        G3D::ReferenceCountedPointer<G3D::Sky> sky;
        G3D::Color4 colorClearValue;
        G3D::LightingParameters desiredSkyParameters;
        G3D::LightingParameters skyParameters;

        RenderScene(const RBX::Render::RenderScene&);
        RenderScene();
        ~RenderScene();
        void presetLighting(G3D::ReferenceCountedPointer<G3D::Sky>, G3D::LightingParameters, G3D::Color3, G3D::Color3);
        void setLighting(const G3D::ReferenceCountedPointer<G3D::Lighting>&);
        void setThrottle(float, float, bool, float);
        float getShadingQuality() const;
        float getMeshDetail() const;
        void render(G3D::RenderDevice*, const G3D::GCamera&);
        RBX::Render::RenderScene& operator=(const RBX::Render::RenderScene&);
    };
};