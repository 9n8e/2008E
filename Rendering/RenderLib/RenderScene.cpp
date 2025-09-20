#include "RenderLib/include/RenderLib/RenderScene.h"

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
                    } else {
                        this->transparentProxyArray.append(this->proxyArray[v2]);
                    }
                }
            }
        }
    }
};