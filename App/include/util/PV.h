namespace RBX {
    class PV {
    public:
        G3D::CoordinateFrame position;
        Velocity velocity;

        bool operator==(const PV&) const;
        bool operator!=(const PV&) const;

        PV(const PV&);
        PV(const G3D::CoordinateFrame&, const Velocity&);
        PV();

        ~PV();

        PV inverse();
        PV toObjectSpace(const PV&);
        G3D::Vector3 linearVelocityAtPoint(const G3D::Vector3&);
        Velocity velocityAtPoint(const G3D::Vector3&);
        Velocity velocityAtLocalOffset(const G3D::Vector3&);
        void setVelocity(const Velocity&);
        void setPosition(const G3D::Vector3&);
        PV pvAtLocalOffset(const G3D::Vector3&);
        PV pvAtLocalCoord(const G3D::CoordinateFrame&);
        PV operator*(const PV&) const;
        PV& operator=(const PV&);
    };
}