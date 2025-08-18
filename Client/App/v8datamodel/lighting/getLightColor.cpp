G3D::Color3 *__thiscall RBX::Lighting::getLightColor(RBX::Lighting *this, G3D::Color3 *result)
{
  G3D::Color3 *v2; // eax

  v2 = result;
  *result = this->skyParameters.lightColor;
  return v2;
}
