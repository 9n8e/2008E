#pragma once

#include "G3D/CoordinateFrame.h"
#include "G3D/Vector3.h"

namespace RBX {
    class RunningAverageState {
    private: 
        G3D::Vector3 position;
        RBX::Quaternion angles; // oh no
        static float weight();

    public: 
        RunningAverageState(const RBX::RunningAverageState&);
        RunningAverageState();
        void update(const G3D::CoordinateFrame&, float);
        bool withinTolerance(const G3D::CoordinateFrame&, float, float);
        RBX::RunningAverageState& operator=(const RBX::RunningAverageState&);
        static int stepsToSleep();
    };

}