void __thiscall RBX::Workspace::Workspace(RBX::Workspace *this, RBX::IDataState *dataState, int a3)
{
  int v4; // eax
  std::_Tree_nod<std::_Tset_traits<RBX::Script *,std::less<RBX::Script *>,std::allocator<RBX::Script *>,0> >::_Node *v5; // eax
  RBX::Profiling::CodeProfiler *v6; // eax
  RBX::Profiling::CodeProfiler *v7; // eax
  RBX::Profiling::CodeProfiler *v8; // eax
  RBX::Profiling::CodeProfiler *v9; // eax
  RBX::Profiling::CodeProfiler *v10; // eax
  RBX::Profiling::CodeProfiler *v11; // eax
  RBX::Profiling::ThreadProfiler *v12; // eax
  RBX::Profiling::ThreadProfiler *v13; // eax
  std::string value; // [esp+14h] [ebp-28h] BYREF
  int v15; // [esp+38h] [ebp-4h]

  if ( a3 )
  {
    *(_DWORD *)this->gapFC = &RBX::Workspace::`vbtable'{for `RBX::DescribedCreatable<RBX::ModelInstance,RBX::PVInstance,&char * RBX::sModel>'};
    *(_DWORD *)&this->gap374[28] = &RBX::Seat::`vbtable'{for `RBX::ICameraSubject'};
  }
  RBX::DescribedNonCreatable<RBX::Workspace,RBX::RootInstance,&char * RBX::sWorkspace>::DescribedNonCreatable<RBX::Workspace,RBX::RootInstance,&char * RBX::sWorkspace>(this);
  v15 = 0;
  *(_DWORD *)this->gap290 = &RBX::GuiTarget::`vftable';
  RBX::VerbContainer::VerbContainer((RBX::VerbContainer *)&this->gap290[4], 0);
  this->renderable2ds.array.num = 0;
  this->renderable2ds.array.numAllocated = 0;
  this->renderable2ds.array.data = 0;
  this->renderable3ds.array.num = 0;
  this->renderable3ds.array.numAllocated = 0;
  this->renderable3ds.array.data = 0;
  LOBYTE(v15) = 3;
  RBX::IMovingManager::IMovingManager((RBX::IMovingManager *)&this->gap290[24]);
  this->RBX::Notifier<RBX::Workspace,RBX::DrawChanged>::listeners._Myfirst = 0;
  this->RBX::Notifier<RBX::Workspace,RBX::DrawChanged>::listeners._Mylast = 0;
  this->RBX::Notifier<RBX::Workspace,RBX::DrawChanged>::listeners._Myend = 0;
  this->RBX::Notifier<RBX::Workspace,RBX::DrawChanged>::raiseRange = 0;
  this->RBX::Notifier<RBX::Workspace,RBX::ToolChanged>::listeners._Myfirst = 0;
  this->RBX::Notifier<RBX::Workspace,RBX::ToolChanged>::listeners._Mylast = 0;
  this->RBX::Notifier<RBX::Workspace,RBX::ToolChanged>::listeners._Myend = 0;
  this->RBX::Notifier<RBX::Workspace,RBX::ToolChanged>::raiseRange = 0;
  v4 = *(_DWORD *)this->gapFC;
  this->RBX::DescribedNonCreatable<RBX::Workspace,RBX::RootInstance,&RBX::sWorkspace>::RBX::Reflection::Described<RBX::Workspace,&RBX::sWorkspace,RBX::NonFactoryProduct<RBX::RootInstance,&RBX::sWorkspace> >::RBX::NonFactoryProduct<RBX::RootInstance,&RBX::sWorkspace>::RBX::RootInstance::RBX::Reflection::Described<RBX::RootInstance,&RBX::sRootInstance,RBX::ModelInstance>::RBX::ModelInstance::RBX::DescribedCreatable<RBX::ModelInstance,RBX::PVInstance,&RBX::sModel>::RBX::Reflection::Described<RBX::ModelInstance,&RBX::sModel,RBX::FactoryProduct<RBX::ModelInstance,RBX::PVInstance,&RBX::sModel> >::RBX::FactoryProduct<RBX::ModelInstance,RBX::PVInstance,&RBX::sModel>::RBX::PVInstance::RBX::Reflection::Described<RBX::PVInstance,&RBX::sPVInstance,RBX::Instance>::RBX::Instance::RBX::GuidItem<RBX::Instance>::__vftable = (RBX::Workspace_vtbl *)&RBX::Workspace::`vftable'{for `RBX::GuidItem<RBX::Instance>'};
  this->RBX::DescribedNonCreatable<RBX::Workspace,RBX::RootInstance,&RBX::sWorkspace>::RBX::Reflection::Described<RBX::Workspace,&RBX::sWorkspace,RBX::NonFactoryProduct<RBX::RootInstance,&RBX::sWorkspace> >::RBX::NonFactoryProduct<RBX::RootInstance,&RBX::sWorkspace>::RBX::RootInstance::RBX::Reflection::Described<RBX::RootInstance,&RBX::sRootInstance,RBX::ModelInstance>::RBX::ModelInstance::RBX::DescribedCreatable<RBX::ModelInstance,RBX::PVInstance,&RBX::sModel>::RBX::Reflection::Described<RBX::ModelInstance,&RBX::sModel,RBX::FactoryProduct<RBX::ModelInstance,RBX::PVInstance,&RBX::sModel> >::RBX::FactoryProduct<RBX::ModelInstance,RBX::PVInstance,&RBX::sModel>::RBX::PVInstance::RBX::Reflection::Described<RBX::PVInstance,&RBX::sPVInstance,RBX::Instance>::RBX::Instance::RBX::AbstractFactoryProduct<RBX::Instance>::RBX::Creatable<RBX::Instance>::RBX::Object::__vftable = (RBX::AbstractFactoryProduct<RBX::Instance>_vtbl *)&RBX::Workspace::`vftable'{for `RBX::AbstractFactoryProduct<RBX::Instance>'};
  this->RBX::DescribedNonCreatable<RBX::Workspace,RBX::RootInstance,&RBX::sWorkspace>::RBX::Reflection::Described<RBX::Workspace,&RBX::sWorkspace,RBX::NonFactoryProduct<RBX::RootInstance,&RBX::sWorkspace> >::RBX::NonFactoryProduct<RBX::RootInstance,&RBX::sWorkspace>::RBX::RootInstance::RBX::Reflection::Described<RBX::RootInstance,&RBX::sRootInstance,RBX::ModelInstance>::RBX::ModelInstance::RBX::DescribedCreatable<RBX::ModelInstance,RBX::PVInstance,&RBX::sModel>::RBX::Reflection::Described<RBX::ModelInstance,&RBX::sModel,RBX::FactoryProduct<RBX::ModelInstance,RBX::PVInstance,&RBX::sModel> >::RBX::FactoryProduct<RBX::ModelInstance,RBX::PVInstance,&RBX::sModel>::RBX::PVInstance::RBX::Reflection::Described<RBX::PVInstance,&RBX::sPVInstance,RBX::Instance>::RBX::Instance::RBX::Reflection::Described<RBX::Instance,&RBX::sInstance,RBX::Reflection::DescribedBase>::RBX::Reflection::DescribedBase::RBX::Reflection::SignalSource::__vftable = (RBX::Reflection::Described<RBX::Instance,&RBX::sInstance,RBX::Reflection::DescribedBase>_vtbl *)&RBX::Workspace::`vftable'{for `RBX::Reflection::Described<RBX::Instance,&char const * const RBX::sInstance,RBX::Reflection::DescribedBase>'};
  this->RBX::DescribedNonCreatable<RBX::Workspace,RBX::RootInstance,&RBX::sWorkspace>::RBX::Reflection::Described<RBX::Workspace,&RBX::sWorkspace,RBX::NonFactoryProduct<RBX::RootInstance,&RBX::sWorkspace> >::RBX::NonFactoryProduct<RBX::RootInstance,&RBX::sWorkspace>::RBX::RootInstance::RBX::Reflection::Described<RBX::RootInstance,&RBX::sRootInstance,RBX::ModelInstance>::RBX::ModelInstance::RBX::DescribedCreatable<RBX::ModelInstance,RBX::PVInstance,&RBX::sModel>::RBX::Reflection::Described<RBX::ModelInstance,&RBX::sModel,RBX::FactoryProduct<RBX::ModelInstance,RBX::PVInstance,&RBX::sModel> >::RBX::FactoryProduct<RBX::ModelInstance,RBX::PVInstance,&RBX::sModel>::RBX::PVInstance::RBX::Reflection::Described<RBX::PVInstance,&RBX::sPVInstance,RBX::Instance>::RBX::Instance::RBX::Debugable::__vftable = (RBX::Debugable_vtbl *)&RBX::Workspace::`vftable'{for `RBX::Debugable'};
  this->RBX::DescribedNonCreatable<RBX::Workspace,RBX::RootInstance,&RBX::sWorkspace>::RBX::Reflection::Described<RBX::Workspace,&RBX::sWorkspace,RBX::NonFactoryProduct<RBX::RootInstance,&RBX::sWorkspace> >::RBX::NonFactoryProduct<RBX::RootInstance,&RBX::sWorkspace>::RBX::RootInstance::RBX::Reflection::Described<RBX::RootInstance,&RBX::sRootInstance,RBX::ModelInstance>::RBX::ModelInstance::RBX::DescribedCreatable<RBX::ModelInstance,RBX::PVInstance,&RBX::sModel>::RBX::Reflection::Described<RBX::ModelInstance,&RBX::sModel,RBX::FactoryProduct<RBX::ModelInstance,RBX::PVInstance,&RBX::sModel> >::RBX::FactoryProduct<RBX::ModelInstance,RBX::PVInstance,&RBX::sModel>::RBX::PVInstance::RBX::Reflection::Described<RBX::PVInstance,&RBX::sPVInstance,RBX::Instance>::RBX::Instance::RBX::Notifier<RBX::Instance,RBX::ChildAdded>::__vftable = (RBX::Notifier<RBX::Instance,RBX::ChildAdded>_vtbl *)&RBX::Workspace::`vftable'{for `RBX::Notifier<RBX::Instance,RBX::ChildAdded>'};
  this->RBX::DescribedNonCreatable<RBX::Workspace,RBX::RootInstance,&RBX::sWorkspace>::RBX::Reflection::Described<RBX::Workspace,&RBX::sWorkspace,RBX::NonFactoryProduct<RBX::RootInstance,&RBX::sWorkspace> >::RBX::NonFactoryProduct<RBX::RootInstance,&RBX::sWorkspace>::RBX::RootInstance::RBX::Reflection::Described<RBX::RootInstance,&RBX::sRootInstance,RBX::ModelInstance>::RBX::ModelInstance::RBX::DescribedCreatable<RBX::ModelInstance,RBX::PVInstance,&RBX::sModel>::RBX::Reflection::Described<RBX::ModelInstance,&RBX::sModel,RBX::FactoryProduct<RBX::ModelInstance,RBX::PVInstance,&RBX::sModel> >::RBX::FactoryProduct<RBX::ModelInstance,RBX::PVInstance,&RBX::sModel>::RBX::PVInstance::RBX::Reflection::Described<RBX::PVInstance,&RBX::sPVInstance,RBX::Instance>::RBX::Instance::RBX::Notifier<RBX::Instance,RBX::ChildRemoved>::__vftable = (RBX::Notifier<RBX::Instance,RBX::ChildRemoved>_vtbl *)&RBX::Workspace::`vftable'{for `RBX::Notifier<RBX::Instance,RBX::ChildRemoved>'};
  this->RBX::DescribedNonCreatable<RBX::Workspace,RBX::RootInstance,&RBX::sWorkspace>::RBX::Reflection::Described<RBX::Workspace,&RBX::sWorkspace,RBX::NonFactoryProduct<RBX::RootInstance,&RBX::sWorkspace> >::RBX::NonFactoryProduct<RBX::RootInstance,&RBX::sWorkspace>::RBX::RootInstance::RBX::Reflection::Described<RBX::RootInstance,&RBX::sRootInstance,RBX::ModelInstance>::RBX::ModelInstance::RBX::DescribedCreatable<RBX::ModelInstance,RBX::PVInstance,&RBX::sModel>::RBX::Reflection::Described<RBX::ModelInstance,&RBX::sModel,RBX::FactoryProduct<RBX::ModelInstance,RBX::PVInstance,&RBX::sModel> >::RBX::FactoryProduct<RBX::ModelInstance,RBX::PVInstance,&RBX::sModel>::RBX::PVInstance::RBX::Reflection::Described<RBX::PVInstance,&RBX::sPVInstance,RBX::Instance>::RBX::Instance::RBX::Notifier<RBX::Instance,RBX::DescendentAdded>::__vftable = (RBX::Notifier<RBX::Instance,RBX::DescendentAdded>_vtbl *)&RBX::Workspace::`vftable'{for `RBX::Notifier<RBX::Instance,RBX::DescendentAdded>'};
  this->RBX::DescribedNonCreatable<RBX::Workspace,RBX::RootInstance,&RBX::sWorkspace>::RBX::Reflection::Described<RBX::Workspace,&RBX::sWorkspace,RBX::NonFactoryProduct<RBX::RootInstance,&RBX::sWorkspace> >::RBX::NonFactoryProduct<RBX::RootInstance,&RBX::sWorkspace>::RBX::RootInstance::RBX::Reflection::Described<RBX::RootInstance,&RBX::sRootInstance,RBX::ModelInstance>::RBX::ModelInstance::RBX::DescribedCreatable<RBX::ModelInstance,RBX::PVInstance,&RBX::sModel>::RBX::Reflection::Described<RBX::ModelInstance,&RBX::sModel,RBX::FactoryProduct<RBX::ModelInstance,RBX::PVInstance,&RBX::sModel> >::RBX::FactoryProduct<RBX::ModelInstance,RBX::PVInstance,&RBX::sModel>::RBX::PVInstance::RBX::Reflection::Described<RBX::PVInstance,&RBX::sPVInstance,RBX::Instance>::RBX::Instance::RBX::Notifier<RBX::Instance,RBX::DescendentRemoving>::__vftable = (RBX::Notifier<RBX::Instance,RBX::DescendentRemoving>_vtbl *)&RBX::Workspace::`vftable'{for `RBX::Notifier<RBX::Instance,RBX::DescendentRemoving>'};
  this->RBX::DescribedNonCreatable<RBX::Workspace,RBX::RootInstance,&RBX::sWorkspace>::RBX::Reflection::Described<RBX::Workspace,&RBX::sWorkspace,RBX::NonFactoryProduct<RBX::RootInstance,&RBX::sWorkspace> >::RBX::NonFactoryProduct<RBX::RootInstance,&RBX::sWorkspace>::RBX::RootInstance::RBX::Reflection::Described<RBX::RootInstance,&RBX::sRootInstance,RBX::ModelInstance>::RBX::ModelInstance::RBX::DescribedCreatable<RBX::ModelInstance,RBX::PVInstance,&RBX::sModel>::RBX::Reflection::Described<RBX::ModelInstance,&RBX::sModel,RBX::FactoryProduct<RBX::ModelInstance,RBX::PVInstance,&RBX::sModel> >::RBX::FactoryProduct<RBX::ModelInstance,RBX::PVInstance,&RBX::sModel>::RBX::PVInstance::RBX::Reflection::Described<RBX::PVInstance,&RBX::sPVInstance,RBX::Instance>::RBX::Instance::RBX::Notifier<RBX::Instance,RBX::AncestorChanged>::__vftable = (RBX::Notifier<RBX::Instance,RBX::AncestorChanged>_vtbl *)&RBX::Workspace::`vftable'{for `RBX::Notifier<RBX::Instance,RBX::AncestorChanged>'};
  this->RBX::DescribedNonCreatable<RBX::Workspace,RBX::RootInstance,&RBX::sWorkspace>::RBX::Reflection::Described<RBX::Workspace,&RBX::sWorkspace,RBX::NonFactoryProduct<RBX::RootInstance,&RBX::sWorkspace> >::RBX::NonFactoryProduct<RBX::RootInstance,&RBX::sWorkspace>::RBX::RootInstance::RBX::Reflection::Described<RBX::RootInstance,&RBX::sRootInstance,RBX::ModelInstance>::RBX::ModelInstance::RBX::DescribedCreatable<RBX::ModelInstance,RBX::PVInstance,&RBX::sModel>::RBX::Reflection::Described<RBX::ModelInstance,&RBX::sModel,RBX::FactoryProduct<RBX::ModelInstance,RBX::PVInstance,&RBX::sModel> >::RBX::FactoryProduct<RBX::ModelInstance,RBX::PVInstance,&RBX::sModel>::RBX::PVInstance::RBX::Reflection::Described<RBX::PVInstance,&RBX::sPVInstance,RBX::Instance>::RBX::Instance::RBX::Notifier<RBX::Instance,RBX::PropertyChanged>::__vftable = (RBX::Notifier<RBX::Instance,RBX::PropertyChanged>_vtbl *)&RBX::Workspace::`vftable'{for `RBX::Notifier<RBX::Instance,RBX::PropertyChanged>'};
  this->RBX::DescribedNonCreatable<RBX::Workspace,RBX::RootInstance,&RBX::sWorkspace>::RBX::Reflection::Described<RBX::Workspace,&RBX::sWorkspace,RBX::NonFactoryProduct<RBX::RootInstance,&RBX::sWorkspace> >::RBX::NonFactoryProduct<RBX::RootInstance,&RBX::sWorkspace>::RBX::RootInstance::RBX::Reflection::Described<RBX::RootInstance,&RBX::sRootInstance,RBX::ModelInstance>::RBX::ModelInstance::RBX::DescribedCreatable<RBX::ModelInstance,RBX::PVInstance,&RBX::sModel>::RBX::Reflection::Described<RBX::ModelInstance,&RBX::sModel,RBX::FactoryProduct<RBX::ModelInstance,RBX::PVInstance,&RBX::sModel> >::RBX::FactoryProduct<RBX::ModelInstance,RBX::PVInstance,&RBX::sModel>::RBX::PVInstance::RBX::IControllable::__vftable = (RBX::IControllable_vtbl *)&RBX::Workspace::`vftable'{for `RBX::IControllable'};
  *((_DWORD *)&this->legacyOffset + 1) = &RBX::Workspace::`vftable'{for `RBX::Reflection::Described<RBX::RootInstance,&char * RBX::sRootInstance,RBX::ModelInstance>'};
  *(_DWORD *)this->gap238 = &RBX::Workspace::`vftable'{for `RBX::ICameraOwner'};
  *(_DWORD *)this->gap290 = &RBX::Workspace::`vftable'{for `RBX::GuiTarget'};
  *(_DWORD *)&this->gap290[4] = &RBX::Workspace::`vftable'{for `RBX::VerbContainer'};
  *(_DWORD *)&this->gap290[24] = &RBX::Workspace::`vftable'{for `RBX::IMovingManager'};
  this->RBX::IScriptOwner::__vftable = (RBX::IScriptOwner_vtbl *)&RBX::Workspace::`vftable'{for `RBX::IScriptOwner'};
  this->RBX::Notifier<RBX::Workspace,RBX::DrawChanged>::__vftable = (RBX::Notifier<RBX::Workspace,RBX::DrawChanged>_vtbl *)&RBX::Workspace::`vftable'{for `RBX::Notifier<RBX::Workspace,RBX::DrawChanged>'};
  this->RBX::Notifier<RBX::Workspace,RBX::ToolChanged>::__vftable = (RBX::Notifier<RBX::Workspace,RBX::ToolChanged>_vtbl *)&RBX::Workspace::`vftable'{for `RBX::Notifier<RBX::Workspace,RBX::ToolChanged>'};
  this->RBX::Listener<RBX::RunService,RBX::Heartbeat>::__vftable = (RBX::Listener<RBX::RunService,RBX::Heartbeat>_vtbl *)&RBX::Workspace::`vftable'{for `RBX::Listener<RBX::RunService,RBX::Heartbeat>'};
  *(_DWORD *)&this->gapFC[*(_DWORD *)(v4 + 4)] = &RBX::Workspace::`vftable'{for `RBX::IPrimaryPart'};
  *(_DWORD *)&this->gapFC[*(_DWORD *)(*(_DWORD *)this->gapFC + 8)] = &RBX::Workspace::`vftable'{for `RBX::ILocation'};
  *(_DWORD *)&this->gapFC[*(_DWORD *)(*(_DWORD *)this->gapFC + 12)] = &RBX::Workspace::`vftable'{for `RBX::ICameraSubject'};
  *(RBX::IControllable_vtbl **)((char *)&this->RBX::DescribedNonCreatable<RBX::Workspace,RBX::RootInstance,&RBX::sWorkspace>::RBX::Reflection::Described<RBX::Workspace,&RBX::sWorkspace,RBX::NonFactoryProduct<RBX::RootInstance,&RBX::sWorkspace> >::RBX::NonFactoryProduct<RBX::RootInstance,&RBX::sWorkspace>::RBX::RootInstance::RBX::Reflection::Described<RBX::RootInstance,&RBX::sRootInstance,RBX::ModelInstance>::RBX::ModelInstance::RBX::DescribedCreatable<RBX::ModelInstance,RBX::PVInstance,&RBX::sModel>::RBX::Reflection::Described<RBX::ModelInstance,&RBX::sModel,RBX::FactoryProduct<RBX::ModelInstance,RBX::PVInstance,&RBX::sModel> >::RBX::FactoryProduct<RBX::ModelInstance,RBX::PVInstance,&RBX::sModel>::RBX::PVInstance::RBX::IControllable::__vftable
                              + *(_DWORD *)(*(_DWORD *)this->gapFC + 4)) = (RBX::IControllable_vtbl *)(*(_DWORD *)(*(_DWORD *)this->gapFC + 4) - 640);
  *(RBX::IControllable_vtbl **)((char *)&this->RBX::DescribedNonCreatable<RBX::Workspace,RBX::RootInstance,&RBX::sWorkspace>::RBX::Reflection::Described<RBX::Workspace,&RBX::sWorkspace,RBX::NonFactoryProduct<RBX::RootInstance,&RBX::sWorkspace> >::RBX::NonFactoryProduct<RBX::RootInstance,&RBX::sWorkspace>::RBX::RootInstance::RBX::Reflection::Described<RBX::RootInstance,&RBX::sRootInstance,RBX::ModelInstance>::RBX::ModelInstance::RBX::DescribedCreatable<RBX::ModelInstance,RBX::PVInstance,&RBX::sModel>::RBX::Reflection::Described<RBX::ModelInstance,&RBX::sModel,RBX::FactoryProduct<RBX::ModelInstance,RBX::PVInstance,&RBX::sModel> >::RBX::FactoryProduct<RBX::ModelInstance,RBX::PVInstance,&RBX::sModel>::RBX::PVInstance::RBX::IControllable::__vftable
                              + *(_DWORD *)(*(_DWORD *)this->gapFC + 8)) = (RBX::IControllable_vtbl *)(*(_DWORD *)(*(_DWORD *)this->gapFC + 8) - 648);
  *(RBX::IControllable_vtbl **)((char *)&this->RBX::DescribedNonCreatable<RBX::Workspace,RBX::RootInstance,&RBX::sWorkspace>::RBX::Reflection::Described<RBX::Workspace,&RBX::sWorkspace,RBX::NonFactoryProduct<RBX::RootInstance,&RBX::sWorkspace> >::RBX::NonFactoryProduct<RBX::RootInstance,&RBX::sWorkspace>::RBX::RootInstance::RBX::Reflection::Described<RBX::RootInstance,&RBX::sRootInstance,RBX::ModelInstance>::RBX::ModelInstance::RBX::DescribedCreatable<RBX::ModelInstance,RBX::PVInstance,&RBX::sModel>::RBX::Reflection::Described<RBX::ModelInstance,&RBX::sModel,RBX::FactoryProduct<RBX::ModelInstance,RBX::PVInstance,&RBX::sModel> >::RBX::FactoryProduct<RBX::ModelInstance,RBX::PVInstance,&RBX::sModel>::RBX::PVInstance::RBX::IControllable::__vftable
                              + *(_DWORD *)(*(_DWORD *)this->gapFC + 12)) = (RBX::IControllable_vtbl *)(*(_DWORD *)(*(_DWORD *)this->gapFC + 12) - 656);
  this->statsItem.px = 0;
  this->statsItem.pn.pi_ = 0;
  this->dataState = dataState;
  this->arrowCameraControls = 0;
  this->currentCommand._Myptr = 0;
  this->stickyCommand._Myptr = 0;
  this->idleMouseEvent.eventType = NO_EVENT;
  this->idleMouseEvent.userInput = 0;
  this->idleMouseEvent.mousePosition.x = 0;
  this->idleMouseEvent.mousePosition.y = 0;
  this->idleMouseEvent.mouseDelta.x = 0;
  this->idleMouseEvent.mouseDelta.y = 0;
  this->idleMouseEvent.windowSize.x = 0;
  this->idleMouseEvent.windowSize.y = 0;
  this->currentCamera.px = 0;
  this->currentCamera.pn.pi_ = 0;
  LOBYTE(v15) = 10;
  this->flySteps = 0;
  this->isSimulating = 0;
  v5 = (std::_Tree_nod<std::_Tset_traits<RBX::Script *,std::less<RBX::Script *>,std::allocator<RBX::Script *>,0> >::_Node *)std::_Tree<std::_Tset_traits<RBX::Assembly *,std::less<RBX::Assembly *>,std::allocator<RBX::Assembly *>,0>>::_Buynode((std::_Tree<std::_Tset_traits<RBX::Instance const *,std::less<RBX::Instance const *>,std::allocator<RBX::Instance const *>,0> > *)&this->pendingScripts);
  this->pendingScripts._Myhead = v5;
  v5->_Isnil = 1;
  this->pendingScripts._Myhead->_Parent = this->pendingScripts._Myhead;
  this->pendingScripts._Myhead->_Left = this->pendingScripts._Myhead;
  this->pendingScripts._Myhead->_Right = this->pendingScripts._Myhead;
  this->pendingScripts._Mysize = 0;
  this->scriptContext = 0;
  this->inMouselookMode = 0;
  v6 = (RBX::Profiling::CodeProfiler *)operator new(0x40u);
  LOBYTE(v15) = 12;
  if ( v6 )
    RBX::Profiling::CodeProfiler::CodeProfiler(v6, "DataModel Step");
  else
    v7 = 0;
  this->profileWorkspaceStep.ptr = v7;
  v8 = (RBX::Profiling::CodeProfiler *)operator new(0x40u);
  LOBYTE(v15) = 14;
  if ( v8 )
    RBX::Profiling::CodeProfiler::CodeProfiler(v8, "RunService Stepped");
  else
    v9 = 0;
  this->profileRunServiceStepped.ptr = v9;
  v10 = (RBX::Profiling::CodeProfiler *)operator new(0x40u);
  LOBYTE(v15) = 16;
  if ( v10 )
    RBX::Profiling::CodeProfiler::CodeProfiler(v10, "RunService Heartbeat");
  else
    v11 = 0;
  this->profileRunServiceHeartbeat.ptr = v11;
  v12 = (RBX::Profiling::ThreadProfiler *)operator new(0x40u);
  LOBYTE(v15) = 18;
  if ( v12 )
    RBX::Profiling::ThreadProfiler::ThreadProfiler(v12, "Run Thread");
  else
    v13 = 0;
  this->profileRun.ptr = v13;
  LOBYTE(v15) = 19;
  this->imageServerViewHack = 0;
  std::string::string(&value, "Workspace");
  LOBYTE(v15) = 20;
  RBX::Instance::setName(this, &value);
  LOBYTE(v15) = 19;
  std::string::~string(&value);
  this->world._Myptr->profilingWorldStep.ptr->parent = this->profileWorkspaceStep.ptr;
  this->profileRunServiceStepped.ptr->parent = this->profileWorkspaceStep.ptr;
  this->profileRunServiceHeartbeat.ptr->parent = this->profileWorkspaceStep.ptr;
}
