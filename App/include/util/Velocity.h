namespace RBX {
    class Velocity {
    public:
        G3D::Vector3 linear;
        G3D::Vector3 rotational;

        Velocity();
        ~Velocity();
        
        bool operator==(const RBX::Velocity&) const;
        bool operator!=(const RBX::Velocity&) const;
    };
}