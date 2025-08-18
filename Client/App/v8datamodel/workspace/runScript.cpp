void __thiscall RBX::Workspace::runScript(RBX::Workspace *this, RBX::Script *script, RBX::ScriptContext *context)
{
  std::pair<std::_Tree<std::_Tset_traits<RBX::Instance *,std::less<RBX::Instance *>,std::allocator<RBX::Instance *>,0> >::iterator,bool> result; // [esp+4h] [ebp-Ch] BYREF

  if ( !RBX::Network::Players::backendProcessing((RBX::Workspace *)((char *)this - 704), 1)
    || *(_BYTE *)&this->RBX::DescribedNonCreatable<RBX::Workspace,RBX::RootInstance,&RBX::sWorkspace>::RBX::Reflection::Described<RBX::Workspace,&RBX::sWorkspace,RBX::NonFactoryProduct<RBX::RootInstance,&RBX::sWorkspace> >::RBX::NonFactoryProduct<RBX::RootInstance,&RBX::sWorkspace>::RBX::RootInstance::RBX::Reflection::Described<RBX::RootInstance,&RBX::sRootInstance,RBX::ModelInstance>::RBX::ModelInstance::RBX::DescribedCreatable<RBX::ModelInstance,RBX::PVInstance,&RBX::sModel>::RBX::Reflection::Described<RBX::ModelInstance,&RBX::sModel,RBX::FactoryProduct<RBX::ModelInstance,RBX::PVInstance,&RBX::sModel> >::RBX::FactoryProduct<RBX::ModelInstance,RBX::PVInstance,&RBX::sModel>::RBX::PVInstance::RBX::Reflection::Described<RBX::PVInstance,&RBX::sPVInstance,RBX::Instance>::RBX::Instance::RBX::Notifier<RBX::Instance,RBX::AncestorChanged>::listeners._Alval.std::_Allocator_base<RBX::Listener<RBX::Instance,RBX::AncestorChanged> *> )
  {
    RBX::ScriptContext::addScript(context, script);
  }
  else
  {
    std::_Tree<std::_Tset_traits<RBX::IMoving *,std::less<RBX::IMoving *>,std::allocator<RBX::IMoving *>,0>>::insert(
      (std::_Tree<std::_Tset_traits<RBX::Instance *,std::less<RBX::Instance *>,std::allocator<RBX::Instance *>,0> > *)&this->RBX::DescribedNonCreatable<RBX::Workspace,RBX::RootInstance,&RBX::sWorkspace>::RBX::Reflection::Described<RBX::Workspace,&RBX::sWorkspace,RBX::NonFactoryProduct<RBX::RootInstance,&RBX::sWorkspace> >::RBX::NonFactoryProduct<RBX::RootInstance,&RBX::sWorkspace>::RBX::RootInstance::RBX::Reflection::Described<RBX::RootInstance,&RBX::sRootInstance,RBX::ModelInstance>::RBX::ModelInstance::RBX::DescribedCreatable<RBX::ModelInstance,RBX::PVInstance,&RBX::sModel>::RBX::Reflection::Described<RBX::ModelInstance,&RBX::sModel,RBX::FactoryProduct<RBX::ModelInstance,RBX::PVInstance,&RBX::sModel> >::RBX::FactoryProduct<RBX::ModelInstance,RBX::PVInstance,&RBX::sModel>::RBX::PVInstance::RBX::Reflection::Described<RBX::PVInstance,&RBX::sPVInstance,RBX::Instance>::RBX::Instance::RBX::Notifier<RBX::Instance,RBX::AncestorChanged>::listeners._Myfirst,
      &result,
      &script);
  }
}
