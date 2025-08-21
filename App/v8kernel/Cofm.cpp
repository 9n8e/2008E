#include "v8kernel/Body.h"

namespace RBX {
    class Cofm { // Coordinate Frame
    private:
        RBX::Body* body;
        bool dirty; // true = requires recalculation
        G3D::Vector3 cofmInBody;
        float mass;
        G3D::Matrix3 moment;

        void updateIfDirty() {
            if (this->dirty) {
                G3D::Vector3* BranchCofmPos;
                G3D::Vector3* cofmWorld;
                G3D::Matrix3* iWorld;
                G3D::Matrix3* BranchIWorldAtPoint;
                RBX::Body* body = this->body;
                this->mass = this->body->mass;
                float mass = body->mass;
                int index = 0;

                body->updatePV();
                if (body->children.array.num > 0) {
                    do {
                        RBX::Body first = body->children.array.data[0];
                        RBX::Cofm firstCofm = first->cofm;
                        if (cofm) {
                            firstCofm->updateIfDirty;
                            float firstMass = firstCofm->mass;
                        } else {
                            float firstMass = first->mass;
                        }

                        this->mass = firstMass + this->mass;
                        if (cofm) {
                            firstCofm->updateIfDirty;
                            float firstMass = firstCofm->mass;
                        } else {
                            float firstMass = first->mass;
                        }

                        mass = firstMass;
                        BranchCofmPos = first->getBranchCofmPos(&BranchCofmPos);
                        ++index;

                        cofmWorld.y = BranchCofmPos->x*  mass + cofmWorld.y;
                        cofmWorld.z = BranchCofmPos->y*  mass + cofmWorld.z;
                    } while (index < body->children.array.num);
                }
                index = 0;

                G3D::Vector3 cofmWorldBase = G3D::Vector3::operator/(G3D::Vector3(&cofmWorld.y, &result, this->mass));
                cofmWorld.y = cofmWorldBase->x;
                cofmWorld.z = cofmWorldBase->y;
                body->updatePV();

                // MATH BLOCK OF THE UNKNOWN
                v18 = cofmWorld.y - body->pv.position.translation.x;
                v19 = cofmWorld.z - body->pv.position.translation.y;
                v20 = v30 - body->pv.position.translation.z;
                v21 = body->pv.position.rotation.elt[2][1]*  v20
                    + body->pv.position.rotation.elt[1][1]*  v19
                    + body->pv.position.rotation.elt[0][1]*  v18;
                v22 = body->pv.position.rotation.elt[2][0]*  v20
                    + body->pv.position.rotation.elt[1][0]*  v19
                    + body->pv.position.rotation.elt[0][0]*  v18;
                v23 = v18*  body->pv.position.rotation.elt[0][2]
                    + v19*  body->pv.position.rotation.elt[1][2]
                    + v20*  body->pv.position.rotation.elt[2][2];
                this->cofmInBody.x = v22;
                this->cofmInBody.y = v21;
                this->cofmInBody.z = v23;
                //

                body->getIWorldAtPoint(&iWorld, &cofmWorld.y);

                if (body->children.array.num > 0) {
                    do {
                        BranchIWorldAtPoint = body->getBranchIWorldAtPoint(body->children.array.data[index], &BranchIWorldAtPoint, &cofmWorld.y);
                        ++index;
                        iWorld = G3D::Matrix3::operator+(&iWorld, BranchIWorldAtPoint);
                    } while (index < body->children.array.num);
                }

                body->updatePV();
                &this->moment = RBX::Math::momentToObjectSpace(&iWorld, &body->pv.position.rotation);
                this->dirty = false;
            }
        }
    public:
        Cofm* Cofm(RBX::Body* body) {
            this->body = body;
            this->dirty = true;
            this->cofmInBody.x = 0.0;
            this->cofmInBody.y = 0.0;
            this->cofmInBody.z = 0.0;
        }

        double getMass() {
            updateIfDirty();
            return this->mass;
        }

        G3D::Vector3 getCofmInBody() {
            updateIfDirty();
            return &this->cofmInBody;
        }

        G3D::Matrix3 getMoment() {
            updateIfDirty();
            return &this->moment;
        }
    }
}