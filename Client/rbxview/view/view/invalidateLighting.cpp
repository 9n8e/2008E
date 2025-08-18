void __thiscall RBX::View::View::invalidateLighting(RBX::View::View *this, bool updateSkybox)
{
  G3D::Sky *m_pointer; // eax
  G3D::Sky *v4; // ecx

  this->lightingValid = 0;
  if ( updateSkybox )
  {
    m_pointer = this->sky.m_pointer;
    if ( m_pointer )
    {
      if ( !InterlockedDecrement(&m_pointer->ReferenceCountedObject_refCount._value) )
      {
        G3D::ReferenceCountedObject::ReferenceCountedObject_zeroWeakPointers(this->sky.m_pointer);
        v4 = this->sky.m_pointer;
        if ( v4 )
          ((void (__thiscall *)(G3D::Sky *, int))v4->~G3D::Sky)(v4, 1);
      }
      this->sky.m_pointer = 0;
    }
  }
}
