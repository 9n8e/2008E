#pragma once

#include "v8world/Edge.h"

namespace RBX {
    class Joint : public Edge {
    public:
        enum JointType {
            NO_JOINT = 0x0000,
            ROTATE_JOINT = 0x0001,
            ROTATE_P_JOINT = 0x0002,
            ROTATE_V_JOINT = 0x0003,
            GLUE_JOINT = 0x0004,
            ANCHOR_JOINT = 0x0005,
            WELD_JOINT = 0x0006,
            SNAP_JOINT = 0x0007,
            MOTOR_JOINT = 0x0008,
            FREE_JOINT = 0x0009,
        }
    };
}