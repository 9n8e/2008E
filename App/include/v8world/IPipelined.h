namespace RBX {
    class IPipelined {
    private:
        IStage* currentStage;
        
        void removeFromStage(IStage*);
        void removeFromStage(IStage::StageType);
        IStage* getStage(IStage::StageType) const;
    };
    class IStage {
    public:
        enum StageType {};
    };
}