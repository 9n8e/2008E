void __thiscall RBX::Render::Mesh::Mesh(RBX::Render::Mesh *this)
{
  this->__vftable = (RBX::Render::Mesh_vtbl *)&G3D::ReferenceCountedObject::`vftable';
  this->ReferenceCountedObject_refCount._value = 0;
  this->ReferenceCountedObject_weakPointer = 0;
  this->__vftable = (RBX::Render::Mesh_vtbl *)&RBX::Render::Mesh::`vftable';
  this->levels.num = 0;
  this->levels.numAllocated = 0;
  this->levels.data = 0;
  RBX::Render::Mesh::ShadowSurface::ShadowSurface(&this->shadowSurface);
  if ( !init_0 )
  {
    RBX::Render::Mesh::initStatics();
    init_0 = 1;
  }
  this->debugBoundingRadius = 0.0;
}
