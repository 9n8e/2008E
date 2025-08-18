void __thiscall RBX::View::View::updateLighting(RBX::View::View *this)
{
  bool v2; // zf
  RBX::DataModel *px; // ecx
  RBX::Lighting *v4; // esi
  G3D::Sky *v5; // eax
  G3D::Sky *v6; // ecx
  double g; // st7
  G3D::PixelProgram *v8; // eax
  RBX::Render::RenderScene *Myptr; // ecx
  RBX::Render::RenderScene *v10; // eax
  G3D::ReferenceCountedPointer<G3D::PixelProgram> v11; // [esp-118h] [ebp-158h] BYREF
  G3D::LightingParameters v12; // [esp-114h] [ebp-154h] BYREF
  G3D::Color3 v13; // [esp-1Ch] [ebp-5Ch] BYREF
  G3D::Color3 v14; // [esp-10h] [ebp-50h] BYREF
  RBX::Sky *m_pointer; // [esp-4h] [ebp-44h]
  int v16; // [esp+0h] [ebp-40h] BYREF
  float r; // [esp+Ch] [ebp-34h]
  int g_low; // [esp+10h] [ebp-30h]
  boost::shared_ptr<RBX::StandardOut> v19; // [esp+14h] [ebp-2Ch]
  boost::shared_ptr<RBX::StandardOut> result; // [esp+20h] [ebp-20h] BYREF
  RBX::View::View *v21; // [esp+28h] [ebp-18h]
  RBX::Lighting *lighting; // [esp+2Ch] [ebp-14h]
  int *v23; // [esp+30h] [ebp-10h]
  int v24; // [esp+3Ch] [ebp-4h]

  result.pn.pi_ = 0;
  v2 = !this->lightingValid;
  v23 = &v16;
  v21 = this;
  if ( v2 )
  {
    px = this->dataModel.px;
    if ( px )
    {
      v4 = RBX::ServiceProvider::create<RBX::Lighting>(px);
      lighting = v4;
    }
    else
    {
      v4 = 0;
      lighting = 0;
    }
    if ( v4->hasSky )
    {
      if ( !this->sky.m_pointer )
      {
        m_pointer = v4->sky.px;
        v24 = 0;
        m_pointer = (RBX::Sky *)RBX::Sky::getG3DSky((G3D::ReferenceCountedPointer<G3D::Sky> *)&result.pn, m_pointer)->m_pointer;
        LOBYTE(v24) = 1;
        G3D::ReferenceCountedPointer<G3D::VertexAndPixelShader>::setPointer(
          (G3D::ReferenceCountedPointer<G3D::PixelProgram> *)&this->sky,
          (G3D::PixelProgram *)m_pointer);
        LOBYTE(v24) = 0;
        G3D::ReferenceCountedPointer<G3D::Framebuffer>::~ReferenceCountedPointer<G3D::Framebuffer>((G3D::ReferenceCountedPointer<G3D::PixelProgram> *)&result.pn);
        v24 = -1;
      }
    }
    else
    {
      v5 = this->sky.m_pointer;
      if ( v5 )
      {
        if ( !InterlockedDecrement(&v5->ReferenceCountedObject_refCount._value) )
        {
          G3D::ReferenceCountedObject::ReferenceCountedObject_zeroWeakPointers(this->sky.m_pointer);
          v6 = this->sky.m_pointer;
          if ( v6 )
            ((void (__thiscall *)(G3D::Sky *, int))v6->~G3D::Sky)(v6, 1);
        }
        this->sky.m_pointer = 0;
      }
    }
    v14.r = v4->ambientBottom.r;
    result.pn.pi_ = (boost::detail::sp_counted_base *)&v14;
    v14.g = v4->ambientBottom.g;
    result.pn.pi_ = (boost::detail::sp_counted_base *)&v13;
    v14.b = v4->ambientBottom.b;
    v13.r = v4->ambientTop.r;
    g = v4->ambientTop.g;
    result.pn.pi_ = (boost::detail::sp_counted_base *)&v12;
    v13.g = g;
    v11.m_pointer = (G3D::PixelProgram *)&v4->skyParameters;
    v13.b = v4->ambientTop.b;
    G3D::LightingParameters::LightingParameters(&v12, &v4->skyParameters);
    v11.m_pointer = 0;
    v8 = (G3D::PixelProgram *)this->sky.m_pointer;
    v21 = (RBX::View::View *)&v11;
    v24 = 5;
    G3D::ReferenceCountedPointer<G3D::VertexAndPixelShader>::setPointer(&v11, v8);
    Myptr = (RBX::Render::RenderScene *)this->renderLibScene._Myptr;
    v24 = -1;
    RBX::Render::RenderScene::presetLighting(
      Myptr,
      (G3D::ReferenceCountedPointer<G3D::Sky>)v11.m_pointer,
      v12,
      v13,
      v14);
    v10 = (RBX::Render::RenderScene *)this->renderLibScene._Myptr;
    r = v4->clearColor.r;
    v10 = (RBX::Render::RenderScene *)((char *)v10 + 752);
    g_low = SLODWORD(v4->clearColor.g);
    *(float *)&v19.px = v4->clearColor.b;
    *(float *)&v19.pn.pi_ = v4->clearColor.a;
    *(float *)&v10->proxyArray.data = r;
    v10->proxyArray.num = g_low;
    *(boost::shared_ptr<RBX::StandardOut> *)&v10->proxyArray.numAllocated = v19;
    this->lightingValid = 1;
  }
}
