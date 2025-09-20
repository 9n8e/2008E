namespace RBX {

    template <class F, class B>
    class Notifier {
    private: 
        std::vector<RBX::Listener<F,B> *,std::allocator<RBX::Listener<F,B> *> > listeners;
        RBX::RaiseRange* raiseRange;

    protected: 
        Notifier<F,B>(const RBX::Notifier<F,B>&);
        Notifier<F,B>();
        RBX::Notifier<F,B>& operator=(const RBX::Notifier<F,B>&);
        virtual ~Notifier<F,B>();
        bool hasListeners() const;
        void raise(B, RBX::Listener<F,B>*) const;
        void raise(B) const;
        void raise() const;
        virtual void onAddListener(RBX::Listener<F,B>*) const;
        virtual void onRemoveListener(RBX::Listener<F,B>*) const;

    public: 
        void addListener(RBX::Listener<F,B>*) const;
        void removeListener(RBX::Listener<F,B>*) const;
    };
    
    class Service {};
};