#pragma once

#include "util/Velocity.h"
#include "util/NormalId.h"

#include "G3D/Vector3.h"
#include "G3D/CoordinateFrame.h"
#include "G3D/Ray.h"
#include "G3D/Line.h"

namespace RBX {
    class Math {
    public: 
        static const int32_t maxOrientationId;
        static const int32_t minOrientationId;
    
        static const float pi();
        static const float piHalf();
        static const float twoPi();
        static const float& inf();
        static int32_t iRound(float);
        static int32_t iFloor(float);
        static float polarity(float);
        static float sign(float);
        static bool isDenormal(float);
        static bool isNanInfDenorm(float);
        static bool isNanInfDenormVector3(const G3D::Vector3&);
        static bool isNanInfDenormMatrix3(const G3D::Matrix3&);
        static bool fixDenorm(G3D::Vector3&);
        static bool fixDenorm(float&);
        static bool fuzzyEq(const G3D::CoordinateFrame&, const G3D::CoordinateFrame&, float, float);
        static bool fuzzyEq(const G3D::Matrix3&, const G3D::Matrix3&, float);
        static bool fuzzyEq(const G3D::Vector3&, const G3D::Vector3&, float);
        static bool fuzzyEq(float, float, float);
        static bool fuzzyAxisAligned(const G3D::Matrix3&, const G3D::Matrix3&, float);
        static bool isEven(int32_t);
        static bool isOdd(int32_t);
        static int32_t nextEven(int32_t);
        static int32_t nextOdd(int32_t);
        static float angleToE0(const G3D::Vector2&);
        static uint32_t hash(const G3D::Vector3&);
        static bool isIntegerVector3(const G3D::Vector3&);
        static G3D::Vector3 iRoundVector3(const G3D::Vector3&);
        static float angle(const G3D::Vector3&, const G3D::Vector3&);
        static float smallAngle(const G3D::Vector3&, const G3D::Vector3&);
        static float elevationAngle(const G3D::Vector3&);
        static G3D::Vector3 vector3Abs(const G3D::Vector3&);
        static float volume(const G3D::Vector3&);
        static float maxAxisLength(const G3D::Vector3&);
        static G3D::Vector3 sortVector3(const G3D::Vector3&);
        static Velocity calcTrajectory(const G3D::Vector3&, const G3D::Vector3&, float);
        static G3D::Vector3 toGrid(const G3D::Vector3&, float);
        static G3D::Vector3 toGrid(const G3D::Vector3&, const G3D::Vector3&);
        static bool lessThan(const G3D::Vector3&, const G3D::Vector3&);
        static float longestVector3Component(const G3D::Vector3&);
        static float planarSize(const G3D::Vector3&);
        static float taxiCabMagnitude(const G3D::Vector3&);
        static const G3D::Plane& yPlane();
        static G3D::Vector3 closestPointOnRay(const G3D::Ray&, const G3D::Ray&);
        static bool cameraSeesPoint(const G3D::Vector3&, const G3D::GCamera&);
        static bool legalCameraCoord(const G3D::CoordinateFrame&);
        static G3D::Vector3 toSmallAngles(const G3D::Matrix3&);
        static G3D::Matrix3 snapToAxes(const G3D::Matrix3&);
        static bool isOrthonormal(const G3D::Matrix3&);
        static bool orthonormalizeIfNecessary(G3D::Matrix3&);
        static G3D::Vector3 toFocusSpace(const G3D::Vector3&, const G3D::CoordinateFrame&);
        static G3D::Vector3 fromFocusSpace(const G3D::Vector3&, const G3D::CoordinateFrame&);
        static G3D::Vector3 toDiagonal(const G3D::Matrix3&);
        static G3D::Matrix3 fromDiagonal(const G3D::Vector3&);
        static G3D::Vector3 getColumn(const G3D::Matrix3&, int32_t);
        static unsigned char rotationToByte(float);
        static float rotationFromByte(unsigned char);
        static bool isAxisAligned(const G3D::Matrix3&);
        static int32_t getOrientId(const G3D::Matrix3&);
        static void idToMatrix3(int32_t, G3D::Matrix3&);
        static const G3D::Matrix3& matrixRotateY();
        static const G3D::Matrix3& matrixRotateNegativeY();
        static const G3D::Matrix3& matrixTiltZ();
        static const G3D::Matrix3& matrixTiltNegativeZ();
        static const G3D::Matrix3 matrixTiltQuadrant(int32_t);
        static void rotateMatrixAboutX90(G3D::Matrix3&, int32_t);
        static void rotateMatrixAboutY90(G3D::Matrix3&, int32_t);
        static void rotateMatrixAboutZ90(G3D::Matrix3&);
        static G3D::Matrix3 rotateAboutZ(const G3D::Matrix3&, float);
        static G3D::Matrix3 momentToObjectSpace(const G3D::Matrix3&, const G3D::Matrix3&);
        static G3D::Matrix3 momentToWorldSpace(const G3D::Matrix3&, const G3D::Matrix3&);
        static G3D::Matrix3 getIWorldAtPoint(const G3D::Vector3&, const G3D::Vector3&, const G3D::Matrix3&, float);
        static void rotateAboutYLocal(G3D::CoordinateFrame&, float);
        static void rotateAboutYGlobal(G3D::CoordinateFrame&, float);
        static G3D::CoordinateFrame snapToGrid(const G3D::CoordinateFrame&, const G3D::Vector3&);
        static G3D::CoordinateFrame snapToGrid(const G3D::CoordinateFrame&, float);
        static float zAxisAngle(const G3D::CoordinateFrame&);
        static void pan(const G3D::Vector3&, G3D::CoordinateFrame&, float);
        static int32_t radiansToQuadrant(float);
        static int32_t radiansToOctant(float);
        static float radiansToDegrees(float);
        static float degreesToRadians(float);
        static float getHeading(const G3D::Vector3&);
        static float getElevation(const G3D::Vector3&);
        static void getHeadingElevation(const G3D::CoordinateFrame&, float&, float&);
        static void setHeadingElevation(G3D::CoordinateFrame&, float, float);
        static G3D::CoordinateFrame getFocusSpace(const G3D::CoordinateFrame&);
        static int32_t toYAxisQuadrant(const G3D::CoordinateFrame&);
        static G3D::Matrix3 alignAxesClosest(const G3D::Matrix3&, const G3D::Matrix3&);
        static NormalId getClosestObjectNormalId(const G3D::Vector3&, const G3D::Matrix3&);
        static G3D::Vector3 getWorldNormal(NormalId, const G3D::CoordinateFrame&);
        static G3D::Vector3 getWorldNormal(NormalId, const G3D::Matrix3&);
        static float radWrap(float);
        static const G3D::Matrix3& getAxisRotationMatrix(int32_t);
        static G3D::Vector3 vectorToObjectSpace(const G3D::Vector3&, const G3D::Matrix3&);
        static bool clipRay(G3D::Vector3&, G3D::Vector3&, G3D::Vector3*, G3D::Vector3&);
        static bool intersectLinePlane(const G3D::Line&, const G3D::Plane&, G3D::Vector3&);
        static bool intersectRayPlane(const G3D::Ray&, const G3D::Plane&, G3D::Vector3&);
        static float computeLaunchAngle(float, float, float, float);
    };
}