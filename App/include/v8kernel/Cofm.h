namespace RBX {
    class Cofm {
    private:
        Body* body;
        bool dirty;
        G3D::Vector3 cofmInBody;
        float mass;
        G3D::Matrix3 moment;
        
        void updateIfDirty() const;
    public:
        Cofm(const Cofm&);
        Cofm(Body*);
        bool getIsDirty() const;
        void makeDirty();
        const G3D::Vector3& getCofmInBody();
        const float getMass() const;
        const G3D::Matrix3& getMoment() const;
        Cofm& operator=(const Cofm&);
    };
}