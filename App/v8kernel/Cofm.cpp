#include "v8kernel/Body.h"

namespace RBX {
    RBX::Body* body;
    bool dirty; // true = requires recalculation
    G3D::Vector3 cofmInBody;
    float mass;
    G3D::Matrix3 moment;

    void Cofm::updateIfDirty() {
        if (this->dirty) {
            G3D::Vector3* BranchCofmPos;
            G3D::Vector3* cofmWorld;
            G3D::Matrix3* iWorld;
            G3D::Matrix3* BranchIWorldAtPoint;
            RBX::Body* body = this->body;
            this->mass = this->body->getMass();
            float mass = body->getMass();
            float firstMass;
            int index = 0;

            //body->updatePV();
            if (body->getChildren().underlyingArray().size() > 0) {
                do {
                    Body* first = body->getChildren().underlyingArray()[0];
                    Cofm firstCofm = first->getCofm();
                    if (&firstCofm) {
                        firstCofm.updateIfDirty();
                        firstMass = firstCofm.getMass();
                    } else {
                        firstMass = first->getMass();
                    }

                    this->mass = firstMass + this->mass;
                    if (&firstCofm) {
                        firstCofm.updateIfDirty();
                        float firstMass = firstCofm.getMass();
                    } else {
                        float firstMass = first->getMass();
                    }

                    mass = firstMass;
                    *BranchCofmPos = first->getBranchCofmPos();
                    ++index;

                    cofmWorld->y = BranchCofmPos->x*  mass + cofmWorld->y;
                    cofmWorld->z = BranchCofmPos->y*  mass + cofmWorld->z;
                } while (index < body->getChildren().size());
            }
            index = 0;

            G3D::Vector3 cofmWorldBase = *cofmWorld / this->mass; // G3D::Vector3::operator/(G3D::Vector3(&cofmWorld.y, &result, this->mass));
            cofmWorld->y = cofmWorldBase.x;
            cofmWorld->z = cofmWorldBase.y;
            //body->updatePV();

            // MATH BLOCK OF THE UNKNOWN
            float v18;
            float v19;
            float v20;
            float v21;
            float v22;
            float v23;
            float v30;

            v18 = cofmWorld->y - body->getPV().position.translation.x;
            v19 = cofmWorld->z - body->getPV().position.translation.y;
            v20 = v30 - body->getPV().position.translation.z;
            v21 = body->getPV().position.rotation[2][1]*  v20
                + body->getPV().position.rotation[1][1]*  v19
                + body->getPV().position.rotation[0][1]*  v18;
            v22 = body->getPV().position.rotation[2][0]*  v20
                + body->getPV().position.rotation[1][0]*  v19
                + body->getPV().position.rotation[0][0]*  v18;
            v23 = v18*  body->getPV().position.rotation[0][2]
                + v19*  body->getPV().position.rotation[1][2]
                + v20*  body->getPV().position.rotation[2][2];
            this->cofmInBody.x = v22;
            this->cofmInBody.y = v21;
            this->cofmInBody.z = v23;
            //

            body->getIWorldAtPoint(*cofmWorld);

            if (body->getChildren().underlyingArray().size() > 0) {
                do {
                    *BranchIWorldAtPoint = body->getBranchIWorldAtPoint(*cofmWorld);
                    ++index;
                    *iWorld += *BranchIWorldAtPoint;//G3D::Matrix3::operator+(&iWorld, BranchIWorldAtPoint);
                } while (index < body->getChildren().underlyingArray().size());
            }

            //body->updatePV();
            this->moment = RBX::Math::momentToObjectSpace(*iWorld, body->getPV().position.rotation);
            this->dirty = false;
        }
    }

    Cofm::Cofm(RBX::Body* body) {
        this->body = body;
        this->dirty = true;
        this->cofmInBody.x = 0.0;
        this->cofmInBody.y = 0.0;
        this->cofmInBody.z = 0.0;
    }

    const float Cofm::getMass() {
        updateIfDirty();
        return this->mass;
    }

    const G3D::Vector3 &Cofm::getCofmInBody() {
        updateIfDirty();
        return this->cofmInBody;
    }

    const G3D::Matrix3 &Cofm::getMoment() {
        updateIfDirty();
        return this->moment;
    }
}