#pragma once

#include "v8world/World.h"
#include "v8world/Primitive.h"
#include "v8world/Contact.h"
#include "v8world/SpatialHash.h"

#include "util/Extents.h"

namespace RBX {
    class ContactManager {
    private: 
        RBX::SpatialHash* spatialHash;
        RBX::World* world;
        static bool ignoreBool;
        RBX::Contact* createContact(RBX::Primitive*, RBX::Primitive*);
        void stepBroadPhase();
        RBX::Primitive* getSlowHit(const G3D::Array<RBX::Primitive *>&, const G3D::Ray&, const G3D::Array<RBX::Primitive const *>*, const RBX::HitTestFilter*, G3D::Vector3&, float, bool&, bool&) const;
        RBX::Primitive* getFastHit(const G3D::Ray&, const G3D::Array<RBX::Primitive const *>*, const RBX::HitTestFilter*, G3D::Vector3&, bool&, bool&) const;

    public: 
        ContactManager(RBX::World*);
        ~ContactManager();
        const RBX::SpatialHash& getSpatialHash();
        RBX::Primitive* getHit(const G3D::Ray&, const std::vector<RBX::Primitive const *,std::allocator<RBX::Primitive const *> >*, const RBX::HitTestFilter*, G3D::Vector3&, bool&) const;
        RBX::Primitive* getHit(const G3D::Ray&, const G3D::Array<RBX::Primitive const *>*, const RBX::HitTestFilter*, G3D::Vector3&, bool&) const;
        void getPrimitivesTouchingExtents(const RBX::Extents&, const RBX::Primitive*, G3D::Array<RBX::Primitive *>&);
        bool intersectingOthers(RBX::Primitive*, const std::set<RBX::Primitive *,std::less<RBX::Primitive *>,std::allocator<RBX::Primitive *> >&, float);
        bool intersectingOthers(const G3D::Array<RBX::Primitive *>&, float);
        bool intersectingOthers(RBX::Primitive*, float);
        void onNewPair(RBX::Primitive*, RBX::Primitive*);
        void onReleasePair(RBX::Primitive*, RBX::Primitive*);
        void onPrimitiveAdded(RBX::Primitive*);
        void onPrimitiveRemoved(RBX::Primitive*);
        void onPrimitiveExtentsChanged(RBX::Primitive*);
        void onPrimitiveGeometryTypeChanged(RBX::Primitive*);
        void stepWorld();
        RBX::Primitive* getHitLegacy(const G3D::Ray&, const RBX::Primitive*, const RBX::HitTestFilter*, G3D::Vector3&, float&, const float&) const;
    };
}