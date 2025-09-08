namespace RBX {
    class Cofm {
    private:
        Body* body;
        bool dirty;
        G3D::Vector3 cofmInBody;
        float mass;
        G3D::Matrix3 moment;
        
        void updateIfDirty();
    public:
        Cofm(const Cofm&);
        Cofm(Body*);
        bool getIsDirty();
        void makeDirty();
        const G3D::Vector3& getCofmInBody();
        const float getMass();
        const G3D::Matrix3& getMoment();
        Cofm& operator=(const Cofm&);
    };
}