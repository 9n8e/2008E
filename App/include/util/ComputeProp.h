namespace RBX {
    template <class F, class B>
    class ComputeProp {
    private: 
        bool val;
        bool dirty;
        B* object;
        F (B::* getFunc)();
    public: 
        ComputeProp<F,B>(B*, F (B::*)());
        bool getValue() const;
        bool operator bool() const;
        const bool* getValuePointer() const;
        const bool& getValueRef() const;
        bool setDirty() const;
    };
}