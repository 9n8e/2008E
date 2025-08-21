#include "G3D/Vector3.h"

namespace RBX {
    class Pair {};
    class PairParams {
    public: 
        G3D::Vector3 normal;

        union {
        public: 
            float length;
            float rotation;
        };

        G3D::Vector3 position;
        float rotVel;

        PairParams(const RBX::PairParams&);
        PairParams();
        RBX::PairParams& operator=(const RBX::PairParams&);
    };
}