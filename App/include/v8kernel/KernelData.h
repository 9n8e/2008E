#pragma once

#include "util/IndexArray.h"

#include "v8kernel/Body.h"

namespace RBX {
    class KernelData {
    public: 
        RBX::IndexArray<RBX::Body,&RBX::Body::getKernelIndex> bodies;
        RBX::IndexArray<RBX::Point,{RBX::Point::getKernelIndex,0}> points;
        RBX::IndexArray<RBX::Connector,{RBX::Connector::getKernelIndex,0}> connectors;
        RBX::IndexArray<RBX::Connector,{RBX::Connector::getKernelIndex,0}> connectors2ndPass;

        KernelData(const RBX::KernelData&);
        KernelData();
        ~KernelData();
        RBX::KernelData& operator=(const RBX::KernelData&);
    };
}