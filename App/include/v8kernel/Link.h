namespace RBX {
    class Link {
    protected:
        Body* body;
        G3D::CoordinateFrame parentCoord;
        G3D::CoordinateFrame childCoord;
        G3D::CoordinateFrame childCoordInverse;
        G3D::CoordinateFrame childInParent;
        int stateIndex;
        
        virtual void computeChildInParent(G3D::CoordinateFrame&) const;
        void dirty();
    public:
        Link(const Link&);
        Link();
        ~Link();
        const G3D::CoordinateFrame& getChildInParent();
        Body* getBody() const;
        void setBody(Body*);
        void reset(const G3D::CoordinateFrame&, const G3D::CoordinateFrame&);
        Link& operator=(const Link&);
    };
}