G3D::Color3 *__thiscall RBX::Lighting::getClearColor3(RBX::Lighting *this, G3D::Color3 *result)
{
  G3D::Color3 *v2; // eax

  v2 = result;
  result->r = this->clearColor.r;
  result->g = this->clearColor.g;
  result->b = this->clearColor.b;
  return v2;
}
