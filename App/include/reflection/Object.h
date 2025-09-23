namespace RBX {
    class Object {
    public: 
        virtual ~Object();
        Object(const RBX::Object&);
        Object();
        RBX::Object& operator=(const RBX::Object&);
    };

    template<class F>
    class Creatable {
    protected: 
        Creatable<RBX::Instance>();
        virtual ~Creatable<RBX::Instance>();

    public:
        Creatable<RBX::Instance>(const RBX::Creatable<RBX::Instance>&);
        RBX::Creatable<RBX::Instance>& operator=(const RBX::Creatable<RBX::Instance>&);

    private: 
        static void* operator new(int);
        static void operator delete(void*);
    };
}