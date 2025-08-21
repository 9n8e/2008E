namespace RBX {
    template <class F, class B>
    class ComputeProp {
        private: 
        bool val;
        bool dirty;
        RBX::Assembly* object;
        bool (RBX::Assembly::* getFunc)();
        
    public: 
        void ComputeProp<bool,RBX::Assembly>(RBX::Assembly*, bool (RBX::Assembly::*)());
        bool getValue() const;
        bool operator bool() const;
        const bool* getValuePointer() const;
        const bool& getValueRef() const;
        bool setDirty() const;
    };
}