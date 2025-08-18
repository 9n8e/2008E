void __thiscall RBX::Render::Mesh::Level::Level(RBX::Render::Mesh::Level *this, G3D::RenderDevice::Primitive primitive)
{
  this->__vftable = (RBX::Render::Mesh::Level_vtbl *)&G3D::ReferenceCountedObject::`vftable';
  this->ReferenceCountedObject_refCount._value = 0;
  this->ReferenceCountedObject_weakPointer = 0;
  this->__vftable = (RBX::Render::Mesh::Level_vtbl *)&RBX::Render::Mesh::Level::`vftable';
  this->indexArray.num = 0;
  this->indexArray.numAllocated = 0;
  this->indexArray.data = 0;
  this->primitive = primitive;
}
