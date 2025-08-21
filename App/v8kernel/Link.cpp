namespace RBX {
    class Link {
    protected:
        RBX::Body* body;
        G3D::CoordinateFrame parentCoord; // childCoord childCordInverse childInParent
        G3D::CoordinateFrame childCoord;
        G3D::CoordinateFrame childCoordInverse;
        G3D::CoordinateFrame childInParent;
        int stateIndex;

        void dirty() {
            RBX::Body body = this->body;
            if (body) {
                body->root->advanceStateIndex();
            }
        }

        void setBody(RBX::Body* body) {
            this->body = body;
        }

        Link* Link() {
            this->body = NULL;
            this->parentCoord = new G3D::CoordinateFrame;
            this->childCoord = new G3D::CoordinateFrame;
            this->childCoordInverse = new G3D::CoordinateFrame;
            this->childInParent = new G3D::CoordinateFrame;
            this->stateIndex = RBX::Body::getNextStateIndex();
        }

        const G3D::CoordinateFrame getChildInParent() {
            RBX::Body parent = this->body->parent;
            parent->updatePV;
            int stateIndex = parent->stateIndex;

            if (this->stateIndex != stateIndex) {
                this->computeChildInParent(this, &this->childInParent);
                this->stateIndex = stateIndex;
                return &this->childInParent;
            }

            return &this->childInParent;
        }

        void reset(const G3D::CoordinateFrame* parentC, G3D::CoordinateFrame* childC) {
            G3D::CoordinateFrame result;

            this->parentCoord = parentC;
            this->childCoord = childC;
            this->childCoordInverse = G3D::CoordinateFrame::inverse(childC, &result);
        }
    }
}