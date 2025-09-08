namespace RBX {
    class SimBody {
    private:
        Body* body;
        bool dirty;
        PV pv;
        Quaternion qOrientation;
        G3D::Vector3 angMomentum;
        G3D::Vector3 momentRecip;
        float massRecip;
        float constantForceY;
        G3D::Vector3 force;
        G3D::Vector3 torque;

        void clearAccumulators();
        //void update();
        void updateIfDirty();

    public:
        SimBody(const SimBody&);
        SimBody(Body*);
        ~SimBody();

        void update();
        void step(float);
        void makeDirty();
        bool getDirty() const;
        const PV& getPV() const;
        PV getOwnerPV();
        void accumulateForceCofm(const G3D::Vector3);
        void accumulateForce(const G3D::Vector3, const G3D::Vector3);
        void accumulateTorque(const G3D::Vector3);
        void resetAccumulators();
        float getConstantForceY();
        const G3D::Vector3& getForce() const;
        const G3D::Vector3& getTorque() const;
        
        SimBody& operator=(const SimBody&);
    };
    class Sim {
    public:
        enum AssemblyState {
            ANCHORED = 0x0000,
            RECURSIVE_WAKE_PENDING = 0x0001,
            WAKE_PENDING = 0x0002,
            AWAKE = 0x0003,
            SLEEPING_CHECKING = 0x0004,
            SLEEPING_DEEPLY = 0x0005,
        };
        enum EdgeState {
            UNDEFINED = 0x0000,
            STEPPING = 0x0001,
            SLEEPING = 0x0002,
            TOUCHING = 0x0003,
            TOUCHING_SLEEPING = 0x0004,
        };
    }
}