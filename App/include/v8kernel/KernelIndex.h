namespace RBX {
    class KernelIndex {
    protected:
        int kernelIndex;
    public:
        bool inKernel() const;
        KernelIndex();
        ~KernelIndex();
    };
}