void __thiscall RBX::View::View::View(RBX::View::View *this, boost::shared_ptr<RBX::DataModel> dataModel)
{
  std::_Tree_nod<std::_Tmap_traits<RBX::Instance *,RBX::Render::Model *,std::less<RBX::Instance *>,std::allocator<std::pair<RBX::Instance * const,RBX::Render::Model *> >,0> >::_Node *v3; // eax
  void (__thiscall *v4)(RBX::View::View *, bool); // eax
  const RBX::Render::RenderScene *v5; // eax
  void (__thiscall *v6)(RBX::View::View *, bool); // eax
  const G3D::TextureManager *v7; // eax
  void (__thiscall *v8)(RBX::View::View *, bool); // eax
  const RBX::Render::SceneManager *v9; // eax
  const RBX::Render::SceneManager *Myptr; // ecx
  void (__thiscall *v11)(RBX::View::View *, bool); // eax
  const RBX::View::MaterialFactory *v12; // eax
  void (__thiscall *v13)(RBX::View::View *, bool); // ecx
  RBX::Reflection::SignalSource *v14; // eax
  const boost::signals::connection *v15; // eax
  RBX::Workspace *px; // eax
  RBX::Reflection::SignalSource *v17; // eax
  const boost::signals::connection *v18; // eax
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,RBX::View::View,boost::shared_ptr<RBX::Instance> >,boost::_bi::list2<boost::_bi::value<RBX::View::View *>,boost::arg<1> > > _C; // [esp+Ch] [ebp-6Ch]
  const RBX::Render::SceneManager *v20; // [esp+24h] [ebp-54h]
  const RBX::View::MaterialFactory *v21; // [esp+24h] [ebp-54h]
  RBX::Lighting *v22; // [esp+24h] [ebp-54h]
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,RBX::View::View,bool>,boost::_bi::list2<boost::_bi::value<RBX::View::View *>,boost::arg<1> > > f; // [esp+28h] [ebp-50h] BYREF
  RBX::View::View *v24; // [esp+30h] [ebp-48h]
  boost::signals::connection result; // [esp+34h] [ebp-44h] BYREF
  boost::slot<boost::function<void __cdecl(bool),std::allocator<void> > > slot; // [esp+44h] [ebp-34h] BYREF
  int v27; // [esp+74h] [ebp-4h]

  v24 = this;
  v27 = 0;
  this->__vftable = (RBX::View::View_vtbl *)&RBX::View::View::`vftable';
  this->sky.m_pointer = 0;
  this->dataModel = dataModel;
  if ( dataModel.pn.pi_ )
    _InterlockedExchangeAdd(&dataModel.pn.pi_->use_count_, 1u);
  LOBYTE(v27) = 3;
  v3 = std::_Tree<std::_Tmap_traits<RBX::Name const *,enum RBX::Debugable::AssertAction,std::less<RBX::Name const *>,std::allocator<std::pair<RBX::Name const * const,enum RBX::Debugable::AssertAction>>,0>>::_Buynode(&this->models);
  this->models._Myhead = v3;
  v3->_Isnil = 1;
  this->models._Myhead->_Parent = this->models._Myhead;
  this->models._Myhead->_Left = this->models._Myhead;
  this->models._Myhead->_Right = this->models._Myhead;
  this->models._Mysize = 0;
  this->lightingChangedConnection.con.px = 0;
  this->lightingChangedConnection.con.pn.pi_ = 0;
  this->lightingChangedConnection.controlling_connection = 0;
  this->lightingChangedConnection.released = 0;
  this->workspaceDescendentAddedConnection.con.px = 0;
  this->workspaceDescendentAddedConnection.con.pn.pi_ = 0;
  this->workspaceDescendentAddedConnection.controlling_connection = 0;
  this->workspaceDescendentAddedConnection.released = 0;
  this->lightingValid = 0;
  this->sceneManager._Myptr = 0;
  v4 = (void (__thiscall *)(RBX::View::View *, bool))operator new(0x4F0u);
  f.f_.f_ = v4;
  LOBYTE(v27) = 8;
  if ( v4 )
    RBX::Render::RenderScene::RenderScene((RBX::Render::RenderScene *)v4);
  else
    v5 = 0;
  this->renderLibScene._Myptr = v5;
  v6 = (void (__thiscall *)(RBX::View::View *, bool))operator new(0x18u);
  f.f_.f_ = v6;
  LOBYTE(v27) = 10;
  if ( v6 )
    G3D::TextureManager::TextureManager((G3D::TextureManager *)v6, 0xA00000u);
  else
    v7 = 0;
  this->textureManager._Myptr = v7;
  this->materialFactory._Myptr = 0;
  v8 = (void (__thiscall *)(RBX::View::View *, bool))operator new(0x2Cu);
  f.f_.f_ = v8;
  LOBYTE(v27) = 13;
  if ( v8 )
  {
    RBX::Render::AggregatingSceneManager::AggregatingSceneManager(
      (RBX::Render::AggregatingSceneManager *)v8,
      (RBX::Render::RenderScene *)this->renderLibScene._Myptr);
    v20 = v9;
  }
  else
  {
    v20 = 0;
  }
  Myptr = this->sceneManager._Myptr;
  LOBYTE(v27) = 12;
  if ( v20 != Myptr && Myptr )
    ((void (__thiscall *)(const RBX::Render::SceneManager *, int))Myptr->~RBX::Render::SceneManager)(Myptr, 1);
  this->sceneManager._Myptr = v20;
  v11 = (void (__thiscall *)(RBX::View::View *, bool))operator new(0x28u);
  f.f_.f_ = v11;
  LOBYTE(v27) = 14;
  if ( v11 )
  {
    RBX::View::MaterialFactory::MaterialFactory(
      (RBX::View::MaterialFactory *)v11,
      (G3D::TextureManager *)this->textureManager._Myptr);
    v21 = v12;
  }
  else
  {
    v21 = 0;
  }
  v13 = (void (__thiscall *)(RBX::View::View *, bool))this->materialFactory._Myptr;
  LOBYTE(v27) = 12;
  f.f_.f_ = v13;
  if ( v21 != (const RBX::View::MaterialFactory *)v13 && v13 )
  {
    RBX::View::MaterialFactory::~MaterialFactory((RBX::View::MaterialFactory *)v13);
    operator delete(f.f_.f_);
  }
  this->materialFactory._Myptr = v21;
  RBX::Render::RenderScene::setThrottle((RBX::Render::RenderScene *)this->renderLibScene._Myptr, 0.0, 0.0, 0, 0.0);
  if ( dataModel.px )
    v22 = RBX::ServiceProvider::create<RBX::Lighting>(dataModel.px);
  else
    v22 = 0;
  f.f_.f_ = (void (__thiscall *)(RBX::View::View *, bool)) __thiscall RBX::View::View::`vcall'{40,{flat}};
  f.l_.a1_.t_ = this;
  boost::slot<boost::function<void __cdecl (bool),std::allocator<void>>>::slot<boost::function<void __cdecl (bool),std::allocator<void>>>(
    &slot,
    &f);
  LOBYTE(v27) = 15;
  if ( v22 )
    v14 = &v22->RBX::Reflection::Described<RBX::Instance,&RBX::sInstance,RBX::Reflection::DescribedBase>;
  else
    v14 = 0;
  v15 = RBX::Reflection::TSignalDesc<void __cdecl (bool)>::connect(
          &RBX::Lighting::event_LightingChanged,
          &result,
          v14,
          &slot,
          10);
  LOBYTE(v27) = 16;
  boost::signals::scoped_connection::operator=(&this->lightingChangedConnection, v15);
  LOBYTE(v27) = 15;
  boost::signals::connection::~connection(&result);
  LOBYTE(v27) = 12;
  boost::slot<boost::function<void __cdecl (G3D::CoordinateFrame),std::allocator<void>>>::~slot<boost::function<void __cdecl (G3D::CoordinateFrame),std::allocator<void>>>((boost::slot<boost::function<void __cdecl(float),std::allocator<void> > > *)&slot);
  _C.l_.a1_.t_ = this;
  _C.f_.f_ = (void (__thiscall *)(RBX::View::View *, boost::shared_ptr<RBX::Instance>)) __thiscall RBX::View::View::`vcall'{32,{flat}};
  RBX::Instance::visitDescendents<boost::_bi::bind_t<void,boost::_mfi::mf1<void,RBX::View::View,boost::shared_ptr<RBX::Instance>>,boost::_bi::list2<boost::_bi::value<RBX::View::View *>,boost::arg<1>>>>(
    dataModel.px->workspace.px,
    _C);
  f.f_.f_ = (void (__thiscall *)(RBX::View::View *, bool)) __thiscall RBX::View::View::`vcall'{32,{flat}};
  f.l_.a1_.t_ = this;
  boost::slot<boost::function<void __cdecl (boost::shared_ptr<RBX::Instance>),std::allocator<void>>>::slot<boost::function<void __cdecl (boost::shared_ptr<RBX::Instance>),std::allocator<void>>>(
    (boost::slot<boost::function<void __cdecl(boost::shared_ptr<RBX::Instance>),std::allocator<void> > > *)&slot,
    (const boost::_bi::bind_t<void,boost::_mfi::mf1<void,RBX::View::View,boost::shared_ptr<RBX::Instance> >,boost::_bi::list2<boost::_bi::value<RBX::View::View *>,boost::arg<1> > > *)&f);
  px = dataModel.px->workspace.px;
  LOBYTE(v27) = 17;
  if ( px )
    v17 = &px->RBX::Reflection::Described<RBX::Instance,&RBX::sInstance,RBX::Reflection::DescribedBase>;
  else
    v17 = 0;
  v18 = RBX::Reflection::TSignalDesc<void __cdecl (boost::shared_ptr<RBX::Instance>)>::connect(
          &RBX::Instance::event_descendentAdded,
          &result,
          v17,
          (const boost::slot<boost::function<void __cdecl(boost::shared_ptr<RBX::Instance>),std::allocator<void> > > *)&slot,
          10);
  LOBYTE(v27) = 18;
  boost::signals::scoped_connection::operator=(&this->workspaceDescendentAddedConnection, v18);
  LOBYTE(v27) = 17;
  boost::signals::connection::~connection(&result);
  LOBYTE(v27) = 12;
  boost::slot<boost::function<void __cdecl (G3D::CoordinateFrame),std::allocator<void>>>::~slot<boost::function<void __cdecl (G3D::CoordinateFrame),std::allocator<void>>>((boost::slot<boost::function<void __cdecl(float),std::allocator<void> > > *)&slot);
  v27 = -1;
  if ( dataModel.pn.pi_ && !_InterlockedExchangeAdd(&dataModel.pn.pi_->use_count_, 0xFFFFFFFF) )
  {
    dataModel.pn.pi_->dispose(dataModel.pn.pi_);
    if ( !_InterlockedExchangeAdd(&dataModel.pn.pi_->weak_count_, 0xFFFFFFFF) )
      dataModel.pn.pi_->destroy(dataModel.pn.pi_);
  }
}
