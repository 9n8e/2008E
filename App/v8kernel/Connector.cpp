#pragma once

#include "v8kernel/Connector.h"

namespace RBX {
    int& Connector::getKernelIndex() {
        return kernelIndex;
    }

    Connector::Connector() {

    }

    Connector::~Connector() {

    }

    void Connector::computeForce(const float, bool) {

    }

    bool Connector::canThrottle() const {

    }

    bool Connector::getBroken() {

    }

    float Connector::potentialEnergy() {

    }

    RBX::Connector& Connector::operator=(const RBX::Connector&) {

    }
}