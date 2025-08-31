#pragma once

#include "util/Debug.h"

using namespace RBX;

void Debugable::doCrash() {
    if (doCrash) {
        int* MEMORY = nullptr;
        MEMORY[0] = MEMORY[4];
    }
}