#pragma once

#include "RenderLib/include/RenderLib/RenderScene.h"

#include "G3D/Stopwatch.h"

namespace RBX::Render {
    void RenderScene::classifyProxies() {
        if (this->proxyArray.length() > 0) {
            for (int v2 = 0; v2 < this->proxyArray.length(); v2++) {
                if (this->proxyArray[v2]->material != 0) {
                    if (this->proxyArray[v2]->material->mTransparent <= 0.0) {
                        this->diffuseProxyArray.append(this->proxyArray[v2]);
                        if (this->proxyArray[v2]->material->mReflect > 0.0) {
                            this->reflectProxyArray.append(this->proxyArray[v2]);
                        }
                    } else { // if no transparency (typically through 0,0,0/black)
                        this->transparentProxyArray.append(this->proxyArray[v2]);
                    }
                }
            }
        }
    }

    void RenderScene::computeShadowVolumeGeometry(
        G3D::Array<unsigned int>& indexArray,
        G3D::Array<G3D::Vector3>& shadowVertex,
        const G3D::GLight& light,
        bool generateLightCap,
        float shadowVertextDistance
    ) {
        this->renderStats.cpuShadow->tick();
        shadowVertex.resize(0, 0);
        indexArray.resize(0, 0);
    }
};