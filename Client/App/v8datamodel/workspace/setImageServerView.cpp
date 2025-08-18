void __thiscall RBX::Workspace::setImageServerView(RBX::Workspace *this, const G3D::Rect2D *viewPortRect)
{
  unsigned int v2; // esi
  std::vector<boost::shared_ptr<RBX::Instance>> *px; // edi
  boost::shared_ptr<RBX::Instance> *Myfirst; // ecx
  int v6; // eax
  std::vector<boost::shared_ptr<RBX::Instance>> *v7; // edi
  boost::shared_ptr<RBX::Instance> *v8; // eax
  int v9; // eax
  std::vector<boost::shared_ptr<RBX::Instance>> *v10; // edi
  void (__thiscall ***v11)(_DWORD, float *); // ebx
  boost::shared_ptr<RBX::Instance> *v12; // eax
  int v13; // eax
  RBX::Camera *v14; // eax
  RBX::StarterPackService *v15; // eax
  RBX::HopperBin *hopperBin; // [esp+8h] [ebp-38h]
  G3D::CoordinateFrame modelCoord; // [esp+Ch] [ebp-34h] BYREF

  v2 = 0;
  hopperBin = 0;
  if ( RBX::Instance::numChildren(this) )
  {
    do
    {
      px = this->children.object.px;
      Myfirst = px->_Myfirst;
      if ( !Myfirst || v2 >= px->_Mylast - Myfirst )
        __invalid_parameter_noinfo();
      v6 = __RTDynamicCast(
             px->_Myfirst[v2].px,
             0,
             &RBX::Instance `RTTI Type Descriptor',
             &RBX::HopperBin `RTTI Type Descriptor',
             0);
      v7 = this->children.object.px;
      LODWORD(modelCoord.rotation.elt[0][0]) = v6;
      v8 = v7->_Myfirst;
      if ( !v8 || v2 >= v7->_Mylast - v8 )
        __invalid_parameter_noinfo();
      v9 = __RTDynamicCast(
             v7->_Myfirst[v2].px,
             0,
             &RBX::Instance `RTTI Type Descriptor',
             &RBX::ILocation `RTTI Type Descriptor',
             0);
      v10 = this->children.object.px;
      v11 = (void (__thiscall ***)(_DWORD, float *))v9;
      v12 = v10->_Myfirst;
      if ( !v12 || v2 >= v10->_Mylast - v12 )
        __invalid_parameter_noinfo();
      v13 = __RTDynamicCast(
              v10->_Myfirst[v2].px,
              0,
              &RBX::Instance `RTTI Type Descriptor',
              &RBX::IRenderable `RTTI Type Descriptor',
              0);
      if ( v11 && v13 )
      {
        (**v11)(v11, &modelCoord.rotation.elt[0][1]);
        v14 = (RBX::Camera *)(*(int (__thiscall **)(_BYTE *))(*(_DWORD *)this->gap238 + 4))(this->gap238);
        RBX::Camera::setImageServerViewNoLerp(v14, (G3D::CoordinateFrame *)&modelCoord.rotation.elt[0][1], viewPortRect);
      }
      if ( LODWORD(modelCoord.rotation.elt[0][0]) )
        hopperBin = (RBX::HopperBin *)LODWORD(modelCoord.rotation.elt[0][0]);
      ++v2;
    }
    while ( v2 < RBX::Instance::numChildren(this) );
    if ( hopperBin )
    {
      v15 = RBX::ServiceProvider::create<RBX::StarterPackService>(this);
      RBX::Instance::setParent(hopperBin, v15);
    }
  }
  this->imageServerViewHack = this->imageServerViewHack <= 0;
}
