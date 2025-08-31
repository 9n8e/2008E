#pragma once

#include "v8kernel/Connector.h"

namespace RBX {
    int& Connector::getKernelIndex() {
        return this->kernelIndex;
    }

    Connector::Connector() {
        
    }
}