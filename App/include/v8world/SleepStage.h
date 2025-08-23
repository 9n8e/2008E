namespace RBX {
    class SleepStage {};
    class SleepInfo {
    private: 
        RBX::Sim::AssemblyState state;
        int sleepCount;
        RBX::RunningAverageState runningAverageState;
        static float sleepTolerance();
  
    public: 
        SleepInfo(const RBX::SleepInfo&);
        SleepInfo();
        ~SleepInfo();
        RBX::SleepInfo& operator=(const RBX::SleepInfo&);
        RBX::Sim::AssemblyState getState() {
            return this->state;
        }
    };
}