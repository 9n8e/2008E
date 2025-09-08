namespace RBX {
    class IPipelined {
    private: 
        RBX::IStage* currentStage;
        void removeFromStage(RBX::IStage::StageType);
        RBX::IStage* getStage(RBX::IStage::StageType) const;

    public: 
        void removeFromStage(RBX::IStage*);
        IPipelined(const RBX::IPipelined&);
        IPipelined();
        virtual ~IPipelined();
        void putInPipeline(RBX::IStage*);
        void removeFromPipeline(RBX::IStage*);
        void putInStage(RBX::IStage*);
        bool inPipeline() const;
        bool inStage(RBX::IStage*) const;
        bool inStage(RBX::IStage::StageType) const;
        bool inOrDownstreamOfStage(RBX::IStage*) const;
        bool downstreamOfStage(RBX::IStage*) const;
        bool inKernel() const;
        RBX::Kernel* getKernel() const;
        virtual void putInKernel(RBX::Kernel*);
        virtual void removeFromKernel();
        RBX::World* getWorld();
        RBX::IPipelined& operator=(const RBX::IPipelined&);
    };
    class IStage {
    public:
        enum StageType {};
    };
}