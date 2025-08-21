namespace RBX {
    class IPipelined {
    private:
        RBX::IStage currentStage;
    public:
        bool downstreamOfStage(RBX::IStage* iStage) {
            IStage::StageType* stageType = this->currentStage->getStageType();
            return stageType > iStage->getStageType();
        }

        RBX::Kernel getKernel() {
            return this->getStage(IStage::StageType::KERNEL_STAGE);
        }

        RBX::IStage getStage(RBX::IStage::StageType stageType) {
            RBX::IStage* currentStage = this->currentStage;
            while (currentStage->getStageType() != stageType) {
                if (currentStage->getStageType() <= stageType) {
                    currentStage = currentStage->downstream;
                } else {
                    currentStage = currentStage->upstream;
                }
            }

            return currentStage;
        }

        void putInStage(RBX::IStage* stage) {
            this->currentStage = stage;
        }

        virtual void removeFromKernel() {
            this->currentStage = this->currentStage->upstream;
        }

        void removeFromPipeline() {
            this->currentStage = RBX::StageType::JOINT_STAGE;
        }

        void removeFromStage() {
            this->currentStage = this->currentStage->upstream;
        }
    }
    class IStage {
        enum StageType {
            JOINT_STAGE = 0x0000,
            CLUMP_STAGE = 0x0001,
            TREE_STAGE = 0x0002,
            ASSEMBLY_STAGE = 0x0003,
            COLLISION_STAGE = 0x0004,
            SLEEP_STAGE = 0x0005,
            SEPARATE_STAGE = 0x0006,
            SIMJOB_STAGE = 0x0007,
            KERNEL_STAGE = 0x0008,
        }

    private:
        RBX::IStage* upstream;
        RBX::IStage* downstream;

    public:
        RBX::Kernel getKernel() {
            return this->downstream->getKernel();
        }

        void stepWorld(int worldStepId, int uiStepId, bool throttling) {
            this->downstream->stepWorld(worldStepId, uiStepId, throttling);
        }
    }
}