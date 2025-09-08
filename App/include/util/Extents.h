#pragma once

#include "util/NormalId.h"

#include "G3D/CoordinateFrame.h"
#include "G3D/Vector3.h"
#include "G3D/Plane.h"

namespace RBX {
    class Extents {
private: 
G3D::Vector3 low;
G3D::Vector3 high;
static float epsilon();

public: 
Extents(const RBX::Extents&);
Extents(const RBX::Vector3int32&, const RBX::Vector3int32&);
Extents(const G3D::Vector3&, const G3D::Vector3&);
Extents();
bool operator==(const RBX::Extents&) const;
bool operator!=(const RBX::Extents&) const;
RBX::Extents& operator=(const RBX::Extents&);
const G3D::Vector3& min() const;
const G3D::Vector3& max() const;
G3D::Vector3 getCorner(int32_t) const;
G3D::Vector3 size() const;
G3D::Vector3 center() const;
G3D::Vector3 bottomCenter() const;
G3D::Vector3 topCenter() const;
float longestSide() const;
float volume() const;
float areaXZ() const;
RBX::Extents toWorldSpace(const G3D::CoordinateFrame&);
RBX::Extents express(const G3D::CoordinateFrame&, const G3D::CoordinateFrame&);
G3D::Vector3 faceCenter(RBX::NormalId) const;
void getFaceCorners(RBX::NormalId, G3D::Vector3&, G3D::Vector3&, G3D::Vector3&, G3D::Vector3&) const;
G3D::Plane getPlane(RBX::NormalId) const;
G3D::Vector3 clip(const G3D::Vector3&) const;
G3D::Vector3 clamp(const RBX::Extents&) const;
RBX::NormalId closestFace(const G3D::Vector3&);
void unionWith(const RBX::Extents&);
void shift(const G3D::Vector3&);
void scale(float);
void expand(float);
G3D::Vector3& operator[](int32_t);
const G3D::Vector3& operator[](int32_t) const;
// G3D::Vector3* operator class G3D::Vector3 *();
// const G3D::Vector3* operator const class G3D::Vector3 *() const;
bool contains(const G3D::Vector3&) const;
bool overlapsOrTouches(const RBX::Extents&) const;
bool fuzzyContains(const G3D::Vector3&, float) const;
// bool containedByFrustum(const G3D::GCamera::Frustum&) const;
// bool partiallyContainedByFrustum(const G3D::GCamera::Frustum&) const;
bool separatedByMoreThan(const RBX::Extents&, float) const;
static RBX::Extents fromCenterCorner(const G3D::Vector3&, const G3D::Vector3&);
static RBX::Extents fromCenterRadius(const G3D::Vector3&, float);
static RBX::Extents vv(const G3D::Vector3&, const G3D::Vector3&);
static bool overlapsOrTouches(const RBX::Extents&, const RBX::Extents&);
static const RBX::Extents& zero();
static const RBX::Extents& unit();
static const RBX::Extents& infiniteExtents();
static const RBX::Extents& negativeInfiniteExtents();
    };
}