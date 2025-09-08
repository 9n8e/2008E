namespace RBX {
    class Quaternion {
    public:
        float x;
        float y;
        float z;
        float w;

        Quaternion(const G3D::Matrix3&);
        Quaternion();
        Quaternion(const G3D::Vector3&, float);
        Quaternion(float, float, float, float);
        RBX::Quaternion& operator=(const RBX::Quaternion&);
        G3D::Vector3& imag();
        const G3D::Vector3& imag() const;
        void toRotationMatrix(G3D::Matrix3&) const;
        float dot(const RBX::Quaternion&) const;
        float magnitude() const;
        float maxComponent() const;
        float& operator[](int) const;

        // leaving these problems for later
        // float* operator float *();
        // const float* operator const float *() const;
        RBX::Quaternion operator*(float) const;
        RBX::Quaternion operator*(const RBX::Quaternion&) const;
        RBX::Quaternion operator+(const RBX::Quaternion&) const;
        RBX::Quaternion operator-(const RBX::Quaternion&) const;
        RBX::Quaternion& operator*=(float);
        RBX::Quaternion& operator+=(const RBX::Quaternion&);
        void normalize();
    };
}