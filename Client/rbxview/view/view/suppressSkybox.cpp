void __thiscall RBX::View::View::suppressSkybox(RBX::View::View *this)
{
  RBX::DataModel *px; // ecx
  RBX::Lighting *v3; // esi
  double g; // st7
  RBX::Render::RenderScene *Myptr; // ecx
  G3D::Sky *m_pointer; // eax
  G3D::Sky *v7; // ecx
  float *v8; // edi
  int v9; // [esp-114h] [ebp-13Ch] BYREF
  G3D::LightingParameters v10; // [esp-110h] [ebp-138h] BYREF
  G3D::Color3 v11; // [esp-18h] [ebp-40h] BYREF
  G3D::Color3 v12; // [esp-Ch] [ebp-34h] BYREF
  G3D::LightingParameters *v13; // [esp+8h] [ebp-20h]
  float r; // [esp+Ch] [ebp-1Ch]
  float v15; // [esp+10h] [ebp-18h]
  float b; // [esp+14h] [ebp-14h]
  float a; // [esp+18h] [ebp-10h]
  int v18; // [esp+24h] [ebp-4h]

  px = this->dataModel.px;
  if ( px )
    v3 = RBX::ServiceProvider::create<RBX::Lighting>(px);
  else
    v3 = 0;
  v12.r = v3->ambientBottom.r;
  v13 = (G3D::LightingParameters *)&v12;
  v12.g = v3->ambientBottom.g;
  v13 = (G3D::LightingParameters *)&v11;
  v12.b = v3->ambientBottom.b;
  v11.r = v3->ambientTop.r;
  g = v3->ambientTop.g;
  v13 = &v10;
  v11.g = g;
  v11.b = v3->ambientTop.b;
  G3D::LightingParameters::LightingParameters(&v10, &v3->skyParameters);
  v9 = 0;
  Myptr = (RBX::Render::RenderScene *)this->renderLibScene._Myptr;
  v13 = (G3D::LightingParameters *)&v9;
  v18 = -1;
  RBX::Render::RenderScene::presetLighting(Myptr, 0, v10, v11, v12);
  m_pointer = this->sky.m_pointer;
  if ( m_pointer )
  {
    if ( !InterlockedDecrement(&m_pointer->ReferenceCountedObject_refCount._value) )
    {
      G3D::ReferenceCountedObject::ReferenceCountedObject_zeroWeakPointers(this->sky.m_pointer);
      v7 = this->sky.m_pointer;
      if ( v7 )
        ((void (__thiscall *)(G3D::Sky *, int))v7->~G3D::Sky)(v7, 1);
    }
    this->sky.m_pointer = 0;
  }
  v8 = (float *)this->renderLibScene._Myptr;
  r = v3->clearColor.r;
  v8 += 188;
  v15 = v3->clearColor.g;
  b = v3->clearColor.b;
  a = v3->clearColor.a;
  *v8 = r;
  v8[1] = v15;
  v8[2] = b;
  v8[3] = a;
}
