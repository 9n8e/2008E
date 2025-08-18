void __thiscall RBX::Network::Replicator::Replicator(
        RBX::Network::Replicator *this,
        SystemAddress remotePlayerId,
        RakPeerInterface *peer)
{
  std::_Tree_nod<std::_Tmap_traits<RBX::Reflection::PropertyDescriptor const *,boost::shared_ptr<RBX::Network::SharedStringDictionary>,std::less<RBX::Reflection::PropertyDescriptor const *>,std::allocator<std::pair<RBX::Reflection::PropertyDescriptor const * const,boost::shared_ptr<RBX::Network::SharedStringDictionary> > >,0> >::_Node *v4; // eax
  std::_Tree_nod<std::_Tmap_traits<RBX::Instance const *,RBX::Network::Replicator::ReplicationData,std::less<RBX::Instance const *>,std::allocator<std::pair<RBX::Instance const * const,RBX::Network::Replicator::ReplicationData> >,0> >::_Node *v5; // eax
  std::_Tree_nod<std::_Tset_traits<RBX::Instance const *,std::less<RBX::Instance const *>,std::allocator<RBX::Instance const *>,0> >::_Node *v6; // eax
  std::_Tree_nod<std::_Tset_traits<RBX::Instance const *,std::less<RBX::Instance const *>,std::allocator<RBX::Instance const *>,0> >::_Node *v7; // eax
  std::_Tree_nod<std::_Tmap_traits<RBX::Name const *,boost::shared_ptr<RBX::Instance>,std::less<RBX::Name const *>,std::allocator<std::pair<RBX::Name const * const,boost::shared_ptr<RBX::Instance> > >,0> >::_Node *v8; // eax
  RBX::Profiling::CodeProfiler *v9; // eax
  RBX::Profiling::CodeProfiler *v10; // eax
  RBX::Profiling::CodeProfiler *v11; // eax
  RBX::Profiling::CodeProfiler *v12; // eax
  RBX::Profiling::CodeProfiler *v13; // eax
  RBX::Profiling::CodeProfiler *v14; // eax
  RBX::Profiling::CodeProfiler *v15; // eax
  RBX::Profiling::CodeProfiler *v16; // eax
  RBX::Profiling::CodeProfiler *v17; // eax
  RBX::Profiling::CodeProfiler *v18; // eax
  RBX::Profiling::CodeProfiler *v19; // eax
  RBX::Profiling::CodeProfiler *v20; // eax
  RakPeerInterface *v21; // ecx
  unsigned int binaryAddress; // eax
  void (__thiscall *AttachPlugin)(RakPeerInterface *, PluginInterface *); // edx
  char *v24; // eax
  std::string value; // [esp+1Ch] [ebp-28h] BYREF
  int v26; // [esp+40h] [ebp-4h]

  RBX::DescribedNonCreatable<RBX::Network::Replicator,RBX::Network::IdSerializer,&char const * const RBX::Network::sReplicator>::DescribedNonCreatable<RBX::Network::Replicator,RBX::Network::IdSerializer,&char const * const RBX::Network::sReplicator>(this);
  v26 = 0;
  PluginInterface::PluginInterface(&this->PluginInterface);
  this->RBX::DescribedNonCreatable<RBX::Network::Replicator,RBX::Network::IdSerializer,&RBX::Network::sReplicator>::RBX::Reflection::Described<RBX::Network::Replicator,&RBX::Network::sReplicator,RBX::NonFactoryProduct<RBX::Network::IdSerializer,&RBX::Network::sReplicator> >::RBX::NonFactoryProduct<RBX::Network::IdSerializer,&RBX::Network::sReplicator>::RBX::Network::IdSerializer::RBX::Instance::RBX::GuidItem<RBX::Instance>::__vftable = (RBX::Network::Replicator_vtbl *)&RBX::Network::Replicator::`vftable'{for `RBX::GuidItem<RBX::Instance>'};
  this->RBX::DescribedNonCreatable<RBX::Network::Replicator,RBX::Network::IdSerializer,&RBX::Network::sReplicator>::RBX::Reflection::Described<RBX::Network::Replicator,&RBX::Network::sReplicator,RBX::NonFactoryProduct<RBX::Network::IdSerializer,&RBX::Network::sReplicator> >::RBX::NonFactoryProduct<RBX::Network::IdSerializer,&RBX::Network::sReplicator>::RBX::Network::IdSerializer::RBX::Instance::RBX::AbstractFactoryProduct<RBX::Instance>::RBX::Creatable<RBX::Instance>::RBX::Object::__vftable = (RBX::AbstractFactoryProduct<RBX::Instance>_vtbl *)&RBX::Network::Replicator::`vftable'{for `RBX::AbstractFactoryProduct<RBX::Instance>'};
  this->RBX::DescribedNonCreatable<RBX::Network::Replicator,RBX::Network::IdSerializer,&RBX::Network::sReplicator>::RBX::Reflection::Described<RBX::Network::Replicator,&RBX::Network::sReplicator,RBX::NonFactoryProduct<RBX::Network::IdSerializer,&RBX::Network::sReplicator> >::RBX::NonFactoryProduct<RBX::Network::IdSerializer,&RBX::Network::sReplicator>::RBX::Network::IdSerializer::RBX::Instance::RBX::Reflection::Described<RBX::Instance,&RBX::sInstance,RBX::Reflection::DescribedBase>::RBX::Reflection::DescribedBase::RBX::Reflection::SignalSource::__vftable = (RBX::Reflection::Described<RBX::Instance,&RBX::sInstance,RBX::Reflection::DescribedBase>_vtbl *)&RBX::Network::Replicator::`vftable'{for `RBX::Reflection::Described<RBX::Instance,&char const * const RBX::sInstance,RBX::Reflection::DescribedBase>'};
  this->RBX::DescribedNonCreatable<RBX::Network::Replicator,RBX::Network::IdSerializer,&RBX::Network::sReplicator>::RBX::Reflection::Described<RBX::Network::Replicator,&RBX::Network::sReplicator,RBX::NonFactoryProduct<RBX::Network::IdSerializer,&RBX::Network::sReplicator> >::RBX::NonFactoryProduct<RBX::Network::IdSerializer,&RBX::Network::sReplicator>::RBX::Network::IdSerializer::RBX::Instance::RBX::Debugable::__vftable = (RBX::Debugable_vtbl *)&RBX::Network::Replicator::`vftable'{for `RBX::Debugable'};
  this->RBX::DescribedNonCreatable<RBX::Network::Replicator,RBX::Network::IdSerializer,&RBX::Network::sReplicator>::RBX::Reflection::Described<RBX::Network::Replicator,&RBX::Network::sReplicator,RBX::NonFactoryProduct<RBX::Network::IdSerializer,&RBX::Network::sReplicator> >::RBX::NonFactoryProduct<RBX::Network::IdSerializer,&RBX::Network::sReplicator>::RBX::Network::IdSerializer::RBX::Instance::RBX::Notifier<RBX::Instance,RBX::ChildAdded>::__vftable = (RBX::Notifier<RBX::Instance,RBX::ChildAdded>_vtbl *)&RBX::Network::Replicator::`vftable'{for `RBX::Notifier<RBX::Instance,RBX::ChildAdded>'};
  this->RBX::DescribedNonCreatable<RBX::Network::Replicator,RBX::Network::IdSerializer,&RBX::Network::sReplicator>::RBX::Reflection::Described<RBX::Network::Replicator,&RBX::Network::sReplicator,RBX::NonFactoryProduct<RBX::Network::IdSerializer,&RBX::Network::sReplicator> >::RBX::NonFactoryProduct<RBX::Network::IdSerializer,&RBX::Network::sReplicator>::RBX::Network::IdSerializer::RBX::Instance::RBX::Notifier<RBX::Instance,RBX::ChildRemoved>::__vftable = (RBX::Notifier<RBX::Instance,RBX::ChildRemoved>_vtbl *)&RBX::Network::Replicator::`vftable'{for `RBX::Notifier<RBX::Instance,RBX::ChildRemoved>'};
  this->RBX::DescribedNonCreatable<RBX::Network::Replicator,RBX::Network::IdSerializer,&RBX::Network::sReplicator>::RBX::Reflection::Described<RBX::Network::Replicator,&RBX::Network::sReplicator,RBX::NonFactoryProduct<RBX::Network::IdSerializer,&RBX::Network::sReplicator> >::RBX::NonFactoryProduct<RBX::Network::IdSerializer,&RBX::Network::sReplicator>::RBX::Network::IdSerializer::RBX::Instance::RBX::Notifier<RBX::Instance,RBX::DescendentAdded>::__vftable = (RBX::Notifier<RBX::Instance,RBX::DescendentAdded>_vtbl *)&RBX::Network::Replicator::`vftable'{for `RBX::Notifier<RBX::Instance,RBX::DescendentAdded>'};
  this->RBX::DescribedNonCreatable<RBX::Network::Replicator,RBX::Network::IdSerializer,&RBX::Network::sReplicator>::RBX::Reflection::Described<RBX::Network::Replicator,&RBX::Network::sReplicator,RBX::NonFactoryProduct<RBX::Network::IdSerializer,&RBX::Network::sReplicator> >::RBX::NonFactoryProduct<RBX::Network::IdSerializer,&RBX::Network::sReplicator>::RBX::Network::IdSerializer::RBX::Instance::RBX::Notifier<RBX::Instance,RBX::DescendentRemoving>::__vftable = (RBX::Notifier<RBX::Instance,RBX::DescendentRemoving>_vtbl *)&RBX::Network::Replicator::`vftable'{for `RBX::Notifier<RBX::Instance,RBX::DescendentRemoving>'};
  this->RBX::DescribedNonCreatable<RBX::Network::Replicator,RBX::Network::IdSerializer,&RBX::Network::sReplicator>::RBX::Reflection::Described<RBX::Network::Replicator,&RBX::Network::sReplicator,RBX::NonFactoryProduct<RBX::Network::IdSerializer,&RBX::Network::sReplicator> >::RBX::NonFactoryProduct<RBX::Network::IdSerializer,&RBX::Network::sReplicator>::RBX::Network::IdSerializer::RBX::Instance::RBX::Notifier<RBX::Instance,RBX::AncestorChanged>::__vftable = (RBX::Notifier<RBX::Instance,RBX::AncestorChanged>_vtbl *)&RBX::Network::Replicator::`vftable'{for `RBX::Notifier<RBX::Instance,RBX::AncestorChanged>'};
  this->RBX::DescribedNonCreatable<RBX::Network::Replicator,RBX::Network::IdSerializer,&RBX::Network::sReplicator>::RBX::Reflection::Described<RBX::Network::Replicator,&RBX::Network::sReplicator,RBX::NonFactoryProduct<RBX::Network::IdSerializer,&RBX::Network::sReplicator> >::RBX::NonFactoryProduct<RBX::Network::IdSerializer,&RBX::Network::sReplicator>::RBX::Network::IdSerializer::RBX::Instance::RBX::Notifier<RBX::Instance,RBX::PropertyChanged>::__vftable = (RBX::Notifier<RBX::Instance,RBX::PropertyChanged>_vtbl *)&RBX::Network::Replicator::`vftable'{for `RBX::Notifier<RBX::Instance,RBX::PropertyChanged>'};
  //this->PluginInterface::__vftable = (PluginInterface_vtbl *)&RBX::Network::Replicator::`vftable';
  this->lastSendTime = G3D::System::getLocalTime();
  this->jobStagePos.simJob = 0;
  this->lastCharacterSendTime = G3D::System::getLocalTime();
  this->statsItem.px = 0;
  this->statsItem.pn.pi_ = 0;
  LOBYTE(v26) = 3;
  v4 = std::_Tree<std::_Tmap_traits<enum RBX::SoundType,boost::shared_ptr<RBX::Soundscape::SoundChannel>,std::less<enum RBX::SoundType>,std::allocator<std::pair<enum RBX::SoundType const,boost::shared_ptr<RBX::Soundscape::SoundChannel>>>,0>>::_Buynode(&this->strings);
  this->strings._Myhead = v4;
  v4->_Isnil = 1;
  this->strings._Myhead->_Parent = this->strings._Myhead;
  this->strings._Myhead->_Left = this->strings._Myhead;
  this->strings._Myhead->_Right = this->strings._Myhead;
  this->strings._Mysize = 0;
  RBX::Network::SharedStringDictionary::SharedStringDictionary(&this->classNames);
  RBX::Network::SharedStringDictionary::SharedStringDictionary(&this->propNames);
  LOBYTE(v26) = 6;
  v5 = std::_Tree<std::_Tmap_traits<RBX::ContentId,RBX::ContentProvider::CachedContent,std::less<RBX::ContentId>,std::allocator<std::pair<RBX::ContentId const,RBX::ContentProvider::CachedContent>>,0>>::_Buynode(&this->replicationContainers);
  this->replicationContainers._Myhead = v5;
  v5->_Isnil = 1;
  this->replicationContainers._Myhead->_Parent = this->replicationContainers._Myhead;
  this->replicationContainers._Myhead->_Left = this->replicationContainers._Myhead;
  this->replicationContainers._Myhead->_Right = this->replicationContainers._Myhead;
  this->replicationContainers._Mysize = 0;
  this->topReplicationContainers._Myfirst = 0;
  this->topReplicationContainers._Mylast = 0;
  this->topReplicationContainers._Myend = 0;
  this->players = 0;
  this->pendingItems._Myhead = std::list<boost::shared_ptr<RBX::Network::Replicator::Item>>::_Buynode(&this->pendingItems);
  this->pendingItems._Mysize = 0;
  LOBYTE(v26) = 9;
  v6 = std::_Tree<std::_Tset_traits<RBX::Assembly *,std::less<RBX::Assembly *>,std::allocator<RBX::Assembly *>,0>>::_Buynode(&this->pendingNewInstances);
  this->pendingNewInstances._Myhead = v6;
  v6->_Isnil = 1;
  this->pendingNewInstances._Myhead->_Parent = this->pendingNewInstances._Myhead;
  this->pendingNewInstances._Myhead->_Left = this->pendingNewInstances._Myhead;
  this->pendingNewInstances._Myhead->_Right = this->pendingNewInstances._Myhead;
  this->pendingNewInstances._Mysize = 0;
  LOBYTE(v26) = 10;
  v7 = std::_Tree<std::_Tset_traits<RBX::Assembly *,std::less<RBX::Assembly *>,std::allocator<RBX::Assembly *>,0>>::_Buynode(&this->pendingDeleteInstances);
  this->pendingDeleteInstances._Myhead = v7;
  v7->_Isnil = 1;
  this->pendingDeleteInstances._Myhead->_Parent = this->pendingDeleteInstances._Myhead;
  this->pendingDeleteInstances._Myhead->_Left = this->pendingDeleteInstances._Myhead;
  this->pendingDeleteInstances._Myhead->_Right = this->pendingDeleteInstances._Myhead;
  this->pendingDeleteInstances._Mysize = 0;
  this->sendPhysicsEnabled = 0;
  this->deserializingProperty = 0;
  this->removingInstance = 0;
  this->incomingMarkers.c._Map = 0;
  this->incomingMarkers.c._Mapsize = 0;
  this->incomingMarkers.c._Myoff = 0;
  this->incomingMarkers.c._Mysize = 0;
  LOBYTE(v26) = 12;
  v8 = (std::_Tree_nod<std::_Tmap_traits<RBX::Name const *,boost::shared_ptr<RBX::Instance>,std::less<RBX::Name const *>,std::allocator<std::pair<RBX::Name const * const,boost::shared_ptr<RBX::Instance> > >,0> >::_Node *)std::_Tree<std::_Tmap_traits<enum RBX::SoundType,boost::shared_ptr<RBX::Soundscape::SoundChannel>,std::less<enum RBX::SoundType>,std::allocator<std::pair<enum RBX::SoundType const,boost::shared_ptr<RBX::Soundscape::SoundChannel>>>,0>>::_Buynode((std::_Tree<std::_Tmap_traits<RBX::Reflection::PropertyDescriptor const *,boost::shared_ptr<RBX::Network::SharedStringDictionary>,std::less<RBX::Reflection::PropertyDescriptor const *>,std::allocator<std::pair<RBX::Reflection::PropertyDescriptor const * const,boost::shared_ptr<RBX::Network::SharedStringDictionary> > >,0> > *)&this->defaultObjects);
  this->defaultObjects._Myhead = v8;
  v8->_Isnil = 1;
  this->defaultObjects._Myhead->_Parent = this->defaultObjects._Myhead;
  this->defaultObjects._Myhead->_Left = this->defaultObjects._Myhead;
  this->defaultObjects._Myhead->_Right = this->defaultObjects._Myhead;
  this->defaultObjects._Mysize = 0;
  v9 = (RBX::Profiling::CodeProfiler *)operator new(0x40u);
  LOBYTE(v26) = 14;
  if ( v9 )
    RBX::Profiling::CodeProfiler::CodeProfiler(v9, "Replication");
  else
    v10 = 0;
  this->profileReplication.ptr = v10;
  v11 = (RBX::Profiling::CodeProfiler *)operator new(0x40u);
  LOBYTE(v26) = 16;
  if ( v11 )
    RBX::Profiling::CodeProfiler::CodeProfiler(v11, "Data Listening");
  else
    v12 = 0;
  this->profileDataListening.ptr = v12;
  v13 = (RBX::Profiling::CodeProfiler *)operator new(0x40u);
  LOBYTE(v26) = 18;
  if ( v13 )
    RBX::Profiling::CodeProfiler::CodeProfiler(v13, "Data In");
  else
    v14 = 0;
  this->profileDataIn.ptr = v14;
  v15 = (RBX::Profiling::CodeProfiler *)operator new(0x40u);
  LOBYTE(v26) = 20;
  if ( v15 )
    RBX::Profiling::CodeProfiler::CodeProfiler(v15, "Data Out");
  else
    v16 = 0;
  this->profileDataOut.ptr = v16;
  v17 = (RBX::Profiling::CodeProfiler *)operator new(0x40u);
  LOBYTE(v26) = 22;
  if ( v17 )
    RBX::Profiling::CodeProfiler::CodeProfiler(v17, "Physics In");
  else
    v18 = 0;
  this->profilePhysicsIn.ptr = v18;
  v19 = (RBX::Profiling::CodeProfiler *)operator new(0x40u);
  LOBYTE(v26) = 24;
  if ( v19 )
    RBX::Profiling::CodeProfiler::CodeProfiler(v19, "Physics Out");
  else
    v20 = 0;
  this->profilePhysicsOut.ptr = v20;
  v21 = peer;
  binaryAddress = remotePlayerId.binaryAddress;
  *(_DWORD *)&this->remotePlayerId.port = *(_DWORD *)&remotePlayerId.port;
  this->receivedGlobals = 0;
  this->disconnected = 0;
  this->peer = v21;
  this->remotePlayerId.binaryAddress = binaryAddress;
  AttachPlugin = v21->AttachPlugin;
  LOBYTE(v26) = 25;
  AttachPlugin(v21, &this->PluginInterface);
  v24 = SystemAddress::ToString(&remotePlayerId, 1);
  std::string::string(&value, v24);
  LOBYTE(v26) = 26;
  RBX::Instance::setName(this, &value);
  LOBYTE(v26) = 25;
  std::string::~string(&value);
  this->profileDataListening.ptr->parent = this->profileReplication.ptr;
  this->profileDataIn.ptr->parent = this->profileReplication.ptr;
  this->profileDataOut.ptr->parent = this->profileReplication.ptr;
  this->profilePhysicsIn.ptr->parent = this->profileReplication.ptr;
  this->profilePhysicsOut.ptr->parent = this->profileReplication.ptr;
}
