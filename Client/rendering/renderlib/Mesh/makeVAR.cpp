void __cdecl RBX::Render::Mesh::makeVAR()
{
  G3D::VARArea **v0; // eax
  G3D::VARArea **v1; // esi
  G3D::VARArea *v2; // edi
  G3D::VARArea **v3; // eax
  G3D::VARArea **v4; // esi
  G3D::VARArea *v5; // edi
  G3D::VARArea **v6; // eax
  G3D::VARArea **v7; // esi
  G3D::VARArea *v8; // edi
  G3D::VARArea **v9; // eax
  G3D::VARArea **v10; // esi
  G3D::VARArea *v11; // edi
  G3D::ReferenceCountedPointer<G3D::PixelProgram> v12[5]; // [esp+8h] [ebp-4Ch] BYREF
  G3D::ReferenceCountedPointer<G3D::VARArea> result; // [esp+20h] [ebp-34h] BYREF
  G3D::ReferenceCountedPointer<G3D::PixelProgram> *v14; // [esp+24h] [ebp-30h]
  G3D::VAR v15; // [esp+28h] [ebp-2Ch] BYREF
  int v16; // [esp+50h] [ebp-4h]

  if ( RBX::Render::Mesh::varDirty )
  {
    G3D::VARArea::create(&result, 44 * RBX::Render::Mesh::visibleGeometry.vertexArray.num + 1024, WRITE_ONCE);
    v12[0].m_pointer = 0;
    v14 = v12;
    v16 = 0;
    G3D::ReferenceCountedPointer<G3D::VertexAndPixelShader>::setPointer(v12, (G3D::PixelProgram *)result.m_pointer);
    G3D::VAR::VAR(
      &v15,
      &RBX::Render::Mesh::visibleGeometry.vertexArray,
      (G3D::ReferenceCountedPointer<G3D::VARArea>)v12[0].m_pointer);
    v1 = v0;
    v2 = *v0;
    LOBYTE(v16) = 1;
    if ( v2 != RBX::Render::Mesh::vertexVAR.area.m_pointer )
    {
      if ( RBX::Render::Mesh::vertexVAR.area.m_pointer )
      {
        if ( !InterlockedDecrement(&RBX::Render::Mesh::vertexVAR.area.m_pointer->ReferenceCountedObject_refCount._value) )
        {
          G3D::ReferenceCountedObject::ReferenceCountedObject_zeroWeakPointers(RBX::Render::Mesh::vertexVAR.area.m_pointer);
          if ( RBX::Render::Mesh::vertexVAR.area.m_pointer )
            ((void (__thiscall *)(G3D::VARArea *, int))RBX::Render::Mesh::vertexVAR.area.m_pointer->~G3D::VARArea)(
              RBX::Render::Mesh::vertexVAR.area.m_pointer,
              1);
        }
        RBX::Render::Mesh::vertexVAR.area.m_pointer = 0;
      }
      if ( v2 )
      {
        RBX::Render::Mesh::vertexVAR.area.m_pointer = v2;
        InterlockedIncrement(&v2->ReferenceCountedObject_refCount._value);
      }
    }
    RBX::Render::Mesh::vertexVAR._pointer = v1[1];
    RBX::Render::Mesh::vertexVAR.elementSize = (unsigned int)v1[2];
    RBX::Render::Mesh::vertexVAR.numElements = (int)v1[3];
    RBX::Render::Mesh::vertexVAR.generation = *((_QWORD *)v1 + 2);
    RBX::Render::Mesh::vertexVAR.underlyingRepresentation = (unsigned int)v1[6];
    RBX::Render::Mesh::vertexVAR._maxSize = (unsigned int)v1[7];
    LOBYTE(v16) = 0;
    if ( v15.area.m_pointer )
    {
      if ( !InterlockedDecrement(&v15.area.m_pointer->ReferenceCountedObject_refCount._value) )
      {
        G3D::ReferenceCountedObject::ReferenceCountedObject_zeroWeakPointers(v15.area.m_pointer);
        if ( v15.area.m_pointer )
          ((void (__thiscall *)(G3D::VARArea *, int))v15.area.m_pointer->~G3D::VARArea)(v15.area.m_pointer, 1);
      }
    }
    v12[0].m_pointer = 0;
    v14 = v12;
    G3D::ReferenceCountedPointer<G3D::VertexAndPixelShader>::setPointer(v12, (G3D::PixelProgram *)result.m_pointer);
    G3D::VAR::VAR(
      &v15,
      &RBX::Render::Mesh::visibleGeometry.normalArray,
      (G3D::ReferenceCountedPointer<G3D::VARArea>)v12[0].m_pointer);
    v4 = v3;
    v5 = *v3;
    LOBYTE(v16) = 2;
    if ( v5 != RBX::Render::Mesh::normalVAR.area.m_pointer )
    {
      if ( RBX::Render::Mesh::normalVAR.area.m_pointer )
      {
        if ( !InterlockedDecrement(&RBX::Render::Mesh::normalVAR.area.m_pointer->ReferenceCountedObject_refCount._value) )
        {
          G3D::ReferenceCountedObject::ReferenceCountedObject_zeroWeakPointers(RBX::Render::Mesh::normalVAR.area.m_pointer);
          if ( RBX::Render::Mesh::normalVAR.area.m_pointer )
            ((void (__thiscall *)(G3D::VARArea *, int))RBX::Render::Mesh::normalVAR.area.m_pointer->~G3D::VARArea)(
              RBX::Render::Mesh::normalVAR.area.m_pointer,
              1);
        }
        RBX::Render::Mesh::normalVAR.area.m_pointer = 0;
      }
      if ( v5 )
      {
        RBX::Render::Mesh::normalVAR.area.m_pointer = v5;
        InterlockedIncrement(&v5->ReferenceCountedObject_refCount._value);
      }
    }
    RBX::Render::Mesh::normalVAR._pointer = v4[1];
    RBX::Render::Mesh::normalVAR.elementSize = (unsigned int)v4[2];
    RBX::Render::Mesh::normalVAR.numElements = (int)v4[3];
    RBX::Render::Mesh::normalVAR.generation = *((_QWORD *)v4 + 2);
    RBX::Render::Mesh::normalVAR.underlyingRepresentation = (unsigned int)v4[6];
    RBX::Render::Mesh::normalVAR._maxSize = (unsigned int)v4[7];
    LOBYTE(v16) = 0;
    if ( v15.area.m_pointer )
    {
      if ( !InterlockedDecrement(&v15.area.m_pointer->ReferenceCountedObject_refCount._value) )
      {
        G3D::ReferenceCountedObject::ReferenceCountedObject_zeroWeakPointers(v15.area.m_pointer);
        if ( v15.area.m_pointer )
          ((void (__thiscall *)(G3D::VARArea *, int))v15.area.m_pointer->~G3D::VARArea)(v15.area.m_pointer, 1);
      }
    }
    v12[0].m_pointer = 0;
    v14 = v12;
    G3D::ReferenceCountedPointer<G3D::VertexAndPixelShader>::setPointer(v12, (G3D::PixelProgram *)result.m_pointer);
    G3D::VAR::VAR(&v15, &RBX::Render::Mesh::texCoordArray, (G3D::ReferenceCountedPointer<G3D::VARArea>)v12[0].m_pointer);
    v7 = v6;
    v8 = *v6;
    LOBYTE(v16) = 3;
    if ( v8 != RBX::Render::Mesh::texCoordVAR.area.m_pointer )
    {
      if ( RBX::Render::Mesh::texCoordVAR.area.m_pointer )
      {
        if ( !InterlockedDecrement(&RBX::Render::Mesh::texCoordVAR.area.m_pointer->ReferenceCountedObject_refCount._value) )
        {
          G3D::ReferenceCountedObject::ReferenceCountedObject_zeroWeakPointers(RBX::Render::Mesh::texCoordVAR.area.m_pointer);
          if ( RBX::Render::Mesh::texCoordVAR.area.m_pointer )
            ((void (__thiscall *)(G3D::VARArea *, int))RBX::Render::Mesh::texCoordVAR.area.m_pointer->~G3D::VARArea)(
              RBX::Render::Mesh::texCoordVAR.area.m_pointer,
              1);
        }
        RBX::Render::Mesh::texCoordVAR.area.m_pointer = 0;
      }
      if ( v8 )
      {
        RBX::Render::Mesh::texCoordVAR.area.m_pointer = v8;
        InterlockedIncrement(&v8->ReferenceCountedObject_refCount._value);
      }
    }
    RBX::Render::Mesh::texCoordVAR._pointer = v7[1];
    RBX::Render::Mesh::texCoordVAR.elementSize = (unsigned int)v7[2];
    RBX::Render::Mesh::texCoordVAR.numElements = (int)v7[3];
    RBX::Render::Mesh::texCoordVAR.generation = *((_QWORD *)v7 + 2);
    RBX::Render::Mesh::texCoordVAR.underlyingRepresentation = (unsigned int)v7[6];
    RBX::Render::Mesh::texCoordVAR._maxSize = (unsigned int)v7[7];
    LOBYTE(v16) = 0;
    if ( v15.area.m_pointer )
    {
      if ( !InterlockedDecrement(&v15.area.m_pointer->ReferenceCountedObject_refCount._value) )
      {
        G3D::ReferenceCountedObject::ReferenceCountedObject_zeroWeakPointers(v15.area.m_pointer);
        if ( v15.area.m_pointer )
          ((void (__thiscall *)(G3D::VARArea *, int))v15.area.m_pointer->~G3D::VARArea)(v15.area.m_pointer, 1);
      }
    }
    v12[0].m_pointer = 0;
    v14 = v12;
    G3D::ReferenceCountedPointer<G3D::VertexAndPixelShader>::setPointer(v12, (G3D::PixelProgram *)result.m_pointer);
    G3D::VAR::VAR(&v15, &RBX::Render::Mesh::tangentArray, (G3D::ReferenceCountedPointer<G3D::VARArea>)v12[0].m_pointer);
    v10 = v9;
    v11 = *v9;
    LOBYTE(v16) = 4;
    if ( v11 != RBX::Render::Mesh::tangentVAR.area.m_pointer )
    {
      if ( RBX::Render::Mesh::tangentVAR.area.m_pointer )
      {
        if ( !InterlockedDecrement(&RBX::Render::Mesh::tangentVAR.area.m_pointer->ReferenceCountedObject_refCount._value) )
        {
          G3D::ReferenceCountedObject::ReferenceCountedObject_zeroWeakPointers(RBX::Render::Mesh::tangentVAR.area.m_pointer);
          if ( RBX::Render::Mesh::tangentVAR.area.m_pointer )
            ((void (__thiscall *)(G3D::VARArea *, int))RBX::Render::Mesh::tangentVAR.area.m_pointer->~G3D::VARArea)(
              RBX::Render::Mesh::tangentVAR.area.m_pointer,
              1);
        }
        RBX::Render::Mesh::tangentVAR.area.m_pointer = 0;
      }
      if ( v11 )
      {
        RBX::Render::Mesh::tangentVAR.area.m_pointer = v11;
        InterlockedIncrement(&v11->ReferenceCountedObject_refCount._value);
      }
    }
    RBX::Render::Mesh::tangentVAR._pointer = v10[1];
    RBX::Render::Mesh::tangentVAR.elementSize = (unsigned int)v10[2];
    RBX::Render::Mesh::tangentVAR.numElements = (int)v10[3];
    RBX::Render::Mesh::tangentVAR.generation = *((_QWORD *)v10 + 2);
    RBX::Render::Mesh::tangentVAR.underlyingRepresentation = (unsigned int)v10[6];
    RBX::Render::Mesh::tangentVAR._maxSize = (unsigned int)v10[7];
    LOBYTE(v16) = 0;
    if ( v15.area.m_pointer )
    {
      if ( !InterlockedDecrement(&v15.area.m_pointer->ReferenceCountedObject_refCount._value) )
      {
        G3D::ReferenceCountedObject::ReferenceCountedObject_zeroWeakPointers(v15.area.m_pointer);
        if ( v15.area.m_pointer )
          ((void (__thiscall *)(G3D::VARArea *, int))v15.area.m_pointer->~G3D::VARArea)(v15.area.m_pointer, 1);
      }
      v15.area.m_pointer = 0;
    }
    RBX::Render::Mesh::varDirty = 0;
    v16 = -1;
    if ( result.m_pointer && !InterlockedDecrement(&result.m_pointer->ReferenceCountedObject_refCount._value) )
    {
      G3D::ReferenceCountedObject::ReferenceCountedObject_zeroWeakPointers(result.m_pointer);
      if ( result.m_pointer )
        ((void (__thiscall *)(G3D::VARArea *, int))result.m_pointer->~G3D::VARArea)(result.m_pointer, 1);
    }
  }
}
