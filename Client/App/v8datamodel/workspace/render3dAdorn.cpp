void __thiscall RBX::Workspace::render3dAdorn(RBX::Workspace *this, RBX::Adorn *adorn)
{
  G3D::Rect2D *v4; // eax
  double x; // st7
  std::vector<boost::shared_ptr<RBX::Instance>> *px; // edi
  boost::shared_ptr<RBX::Instance> *Mylast; // ebp
  std::vector<boost::shared_ptr<RBX::Instance>> *v8; // ecx
  void (__thiscall **p_setObjectToWorldMatrix)(RBX::Adorn *, const G3D::CoordinateFrame *); // edi
  const G3D::CoordinateFrame *v10; // eax
  const G3D::Color3 *v11; // eax
  const G3D::Color3 *v12; // eax
  const G3D::Color3 *v13; // eax
  double b; // st7
  RBX::Adorn_vtbl *v15; // eax
  void (__thiscall **v16)(RBX::Adorn *, const G3D::CoordinateFrame *); // edi
  const G3D::CoordinateFrame *v17; // eax
  void (__thiscall **p_box)(RBX::Adorn *, const G3D::AABox *, const G3D::Color4 *, const G3D::Color4 *); // edi
  const G3D::Color4 *v19; // eax
  volatile signed __int32 *v20; // esi
  boost::_bi::bind_t<void,void (__cdecl*)(boost::shared_ptr<RBX::Instance>,RBX::Adorn *,enum RBX::SelectState,RBX::Workspace *),boost::_bi::list4<boost::arg<1>,boost::_bi::value<RBX::Adorn *>,boost::_bi::value<enum RBX::SelectState>,boost::_bi::value<RBX::Workspace *> > > v21; // [esp-4h] [ebp-8Ch]
  RBX::ServiceClient<RBX::Selection> sel; // [esp+1Ch] [ebp-6Ch] BYREF
  volatile signed __int32 *v23; // [esp+28h] [ebp-60h]
  G3D::CoordinateFrame v24; // [esp+2Ch] [ebp-5Ch] BYREF
  float v25[4]; // [esp+5Ch] [ebp-2Ch] BYREF
  boost::_bi::bind_t<void,void (__cdecl*)(boost::shared_ptr<RBX::Instance>,RBX::Adorn *,enum RBX::SelectState,RBX::Workspace *),boost::_bi::list4<boost::arg<1>,boost::_bi::value<RBX::Adorn *>,boost::_bi::value<enum RBX::SelectState>,boost::_bi::value<RBX::Workspace *> > > result; // [esp+6Ch] [ebp-1Ch] BYREF
  int v27; // [esp+84h] [ebp-4h]
  RBX::Adorn *adorna; // [esp+8Ch] [ebp+4h]

  v4 = adorn->getViewport(adorn, v25);
  *(float *)this->IsControllable.gapC = v4->min.x;
  *(float *)&this->IsControllable.gapC[4] = v4->min.y;
  sel.service.px = (RBX::Selection *)(&this[-1].WorldGridExtents.getFunc + 1);
  x = v4->max.x;
  sel.service.pn.pi_ = 0;
  *(float *)&this->IsControllable.gapC[8] = x;
  v23 = 0;
  *(float *)&this->IsTopFlag.val = v4->max.y;
  v27 = 0;
  if ( RBX::ServiceClient<RBX::Selection>::createService((RBX::ServiceClient<RBX::Selection> *)&sel.service, 1) )
  {
    result.l_.a3_.t_ = SELECT_NORMAL;
    result.l_.a4_.t_ = (RBX::Workspace *)((char *)this - 360);
    px = RBX::ServiceClient<RBX::Selection>::createService((RBX::ServiceClient<RBX::Selection> *)&sel.service, 1)->selection.object.px;
    Mylast = px->_Mylast;
    if ( px->_Myfirst > Mylast )
      __invalid_parameter_noinfo();
    v8 = RBX::ServiceClient<RBX::Selection>::createService((RBX::ServiceClient<RBX::Selection> *)&sel.service, 1)->selection.object.px;
    adorna = (RBX::Adorn *)v8;
    sel.context = (RBX::Instance *)v8->_Myfirst;
    if ( sel.context > (RBX::Instance *)v8->_Mylast )
    {
      __invalid_parameter_noinfo();
      v8 = (std::vector<boost::shared_ptr<RBX::Instance>> *)adorna;
    }
    v21.f_ = RBX::DrawAdorn;
    v21.l_.a2_.t_ = adorn;
    *(_QWORD *)&v21.l_.a3_.t_ = *(_QWORD *)&result.l_.a3_.t_;
    std::for_each<std::_Vector_const_iterator<boost::shared_ptr<RBX::Instance>>,boost::_bi::bind_t<void,void (__cdecl *)(boost::shared_ptr<RBX::Instance>,RBX::Adorn *,enum RBX::SelectState,RBX::Workspace *),boost::_bi::list4<boost::arg<1>,boost::_bi::value<RBX::Adorn *>,boost::_bi::value<enum RBX::SelectState>,boost::_bi::value<RBX::Workspace *>>>>(
      &result,
      (std::_Vector_const_iterator<boost::shared_ptr<RBX::Instance>>)__PAIR64__(
                                                                       (unsigned int)sel.context,
                                                                       (unsigned int)v8),
      (std::_Vector_const_iterator<boost::shared_ptr<RBX::Instance>>)__PAIR64__((unsigned int)Mylast, (unsigned int)px),
      v21);
  }
  RBX::IRenderableBucket::render3dAdornItems((RBX::IRenderableBucket *)this->modelInPrimary.rotation.elt[2], adorn);
  if ( RBX::Workspace::showWorldCoord )
  {
    p_setObjectToWorldMatrix = &adorn->setObjectToWorldMatrix;
    G3D::CoordinateFrame::CoordinateFrame(&v24);
    (*p_setObjectToWorldMatrix)(adorn, v10);
    v11 = G3D::Color3::blue();
    v24.rotation.elt[0][0] = v11->r;
    v24.rotation.elt[0][1] = v11->g;
    v24.rotation.elt[0][2] = v11->b;
    v24.rotation.elt[1][0] = 1.0;
    v12 = G3D::Color3::green();
    v25[0] = v12->r;
    v25[1] = v12->g;
    v25[2] = v12->b;
    v25[3] = 1.0;
    v13 = G3D::Color3::red();
    *(float *)&result.f_ = v13->r;
    *(float *)&result.l_.a2_.t_ = v13->g;
    b = v13->b;
    v15 = adorn->__vftable;
    *(float *)&result.l_.a3_.t_ = b;
    *(float *)&result.l_.a4_.t_ = 1.0;
    ((void (__thiscall *)(RBX::Adorn *, boost::_bi::bind_t<void,void (__cdecl*)(boost::shared_ptr<RBX::Instance>,RBX::Adorn *,enum RBX::SelectState,RBX::Workspace *),boost::_bi::list4<boost::arg<1>,boost::_bi::value<RBX::Adorn *>,boost::_bi::value<enum RBX::SelectState>,boost::_bi::value<RBX::Workspace *> > > *, float *, G3D::CoordinateFrame *, _DWORD))v15->axes)(
      adorn,
      &result,
      v25,
      &v24,
      50.0);
  }
  if ( RBX::Workspace::showHashGrid )
  {
    v16 = &adorn->setObjectToWorldMatrix;
    G3D::CoordinateFrame::CoordinateFrame(&v24);
    (*v16)(adorn, v17);
    *(float *)&result.f_ = 1.0;
    p_box = &adorn->box;
    *(float *)&result.l_.a2_.t_ = 0.2;
    *(float *)&result.l_.a3_.t_ = 0.2;
    *(float *)&result.l_.a4_.t_ = 0.5;
    v24.rotation.elt[0][0] = 28.0;
    v24.rotation.elt[0][1] = 4.0;
    v24.rotation.elt[0][2] = 12.0;
    v24.rotation.elt[1][0] = 32.0;
    v24.rotation.elt[1][1] = 8.0;
    v24.rotation.elt[1][2] = 16.0;
    v19 = G3D::Color4::clear();
    (*p_box)(adorn, (const G3D::AABox *)&v24, (const G3D::Color4 *)&result, v19);
  }
  v20 = v23;
  v27 = -1;
  if ( v23 && !_InterlockedExchangeAdd(v23 + 1, 0xFFFFFFFF) )
  {
    (*(void (__thiscall **)(volatile signed __int32 *))(*v20 + 4))(v20);
    if ( !_InterlockedExchangeAdd(v20 + 2, 0xFFFFFFFF) )
      (*(void (__thiscall **)(volatile signed __int32 *))(*v20 + 8))(v20);
  }
}
