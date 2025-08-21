#include "v8kernel/Link.h"
#include "v8kernel/Body.h"

namespace RBX {
    void Link::dirty() {
        Body* body = this->body;
        if (body) {
            body->getRoot()->advanceStateIndex();
        }
    }

    void Link::setBody(RBX::Body* body) {
        this->body = body;
    }

    Link::Link() {
        this->body = &Body();
        this->parentCoord = G3D::CoordinateFrame();
        this->childCoord = G3D::CoordinateFrame();
        this->childCoordInverse = G3D::CoordinateFrame();
        this->childInParent = G3D::CoordinateFrame();
        this->stateIndex = body->getNextStateIndex();
    }

    const G3D::CoordinateFrame &Link::getChildInParent() {
        RBX::Body* parent = this->body->getParent();
        // parent->updatePV;
        int stateIndex = parent->getStateIndex();

        if (this->stateIndex != stateIndex) {
            this->computeChildInParent(this->childInParent);
            this->stateIndex = stateIndex;
            return this->childInParent;
        }

        return this->childInParent;
    }

    void Link::reset(const G3D::CoordinateFrame& parentC, const G3D::CoordinateFrame& childC) {
        G3D::CoordinateFrame result;

        this->parentCoord = parentC;
        this->childCoord = childC;
        this->childCoordInverse = childC.inverse();
    }
}