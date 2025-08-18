void __thiscall RBX::Lighting::setClearColor3(RBX::Lighting *this, G3D::Color3 value)
{
  G3D::Color4 v2; // [esp-10h] [ebp-10h]

  v2.r = value.r;
  v2.g = value.g;
  v2.b = value.b;
  v2.a = 1.0;
  RBX::Lighting::setClearColor(this, v2);
}
