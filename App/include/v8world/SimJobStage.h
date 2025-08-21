namespace RBX {
    class SimJob {};
    class SimJobStage {};
    class SimJobTracker {
    private: 
        RBX::SimJob* simJob;
        bool containedBy(RBX::SimJob*);
        void stopTracking();

    public: 
        SimJobTracker();
        ~SimJobTracker();
        bool tracking();
        void setSimJob(RBX::SimJob*);
        RBX::SimJob* getSimJob();
        static void transferTrackers(RBX::SimJob*, RBX::SimJob*);
    };
}