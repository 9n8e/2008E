#pragma once

#include "v8world/Primitive.h"

namespace RBX {
    class HitTestFilter {
    public:
        enum Result {
            STOP_TEST = 0x0000,
            IGNORE_PRIM = 0x0001,
            INCLUDE_PRIM = 0x0002,
        };

        virtual Result filterResult(const RBX::Primitive*) const;
        HitTestFilter(const RBX::HitTestFilter&);
        HitTestFilter();
        RBX::HitTestFilter& operator=(const RBX::HitTestFilter&);
    };
}