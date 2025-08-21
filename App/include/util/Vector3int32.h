#include "G3D/Vector3.h"

namespace RBX {
    class Vector3int32 {
        public: 
        int x;
        int y;
        int z;
        
        Vector3int32(int, int, int);
        Vector3int32();
        int& operator[](int);
        const int& operator[](int) const;
        RBX::Vector3int32 operator+(const RBX::Vector3int32&) const;
        bool operator==(const RBX::Vector3int32&) const;
        bool operator!=(const RBX::Vector3int32&) const;
        G3D::Vector3 toVector3() const;
        
        static RBX::Vector3int32 floor(const G3D::Vector3&);
    };
}