#include "G3D/Vector3.h"

namespace RBX {
    class Constants {
    private: 
        static const int JOINT_FORCE_DATA;
        static const float MAX_LEGO_JOINT_FORCES_THEORY[7];
        static const float MAX_LEGO_JOINT_FORCES_MEASURED[7];
    
        Constants();
    
        static const float LEGO_GRID_MASS();
        static const float LEGO_JOINT_K();
        static const float LEGO_DEFAULT_ELASTIC_K();
        static const float unitJointK();
        static const float getJointKMultiplier(const G3D::Vector3&, bool);
    public: static const int uiStepsPerSec();
        static const int worldStepsPerUiStep();
        static const int kernelStepsPerWorldStep();
        static const int worldStepsPerSec();
        static const int kernelStepsPerSec();
        static const int kernelStepsPerUiStep();
        static const float uiDt();
        static const float worldDt();
        static const float kernelDt();
        static const G3D::Vector3& getKmsGravity();
        static const float getKmsMaxJointForce(float, float);
        static const float getElasticMultiplier(float);
        static const float getJointK(const G3D::Vector3&, bool);
    };
}