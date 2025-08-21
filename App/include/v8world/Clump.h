#include "v8world/Assembly.h"
#include "v8world/Primitive.h"

namespace RBX {
    class Clump : public Assembly {
    public: 
        Clump(const RBX::Clump&);
        Clump(RBX::Primitive*);
        virtual ~Clump();
        RBX::Clump& operator=(const RBX::Clump&);
    };
}