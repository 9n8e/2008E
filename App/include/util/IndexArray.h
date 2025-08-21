namespace RBX {
    template <class F, int& (F::*B)()>
    class IndexArray {
    private:
        G3D::Array<F *> array;
        int indexOf(F*) const {
            return F->*getIndex();
        };
    public:
        void fastAppend(F*);
        void fastRemove(F*);
        bool fastContains(F*) const;
        G3D::Array<F *>& underlyingArray() {
            return array;
        };
        F* operator[](int) const;
        int size() const {
            return array.size();
        };
        IndexArray(const IndexArray&);
        IndexArray();
        ~IndexArray();
        IndexArray operator=(const IndexArray&);
    };
}