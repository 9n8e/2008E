RBX::GuiResponse *__thiscall RBX::Workspace::process(
        RBX::Workspace *this,
        RBX::GuiResponse *result,
        const RBX::GuiEvent *event)
{
  RBX::Listener<RBX::Instance,RBX::AncestorChanged> **v4; // ecx
  RBX::MouseCommand *v5; // eax
  RBX::Listener<RBX::Instance,RBX::AncestorChanged> **Mylast; // ecx
  RBX::Listener<RBX::Instance,RBX::AncestorChanged> **v7; // ecx
  RBX::Listener<RBX::Instance,RBX::AncestorChanged> *v8; // eax
  RBX::Listener<RBX::Instance,RBX::AncestorChanged> **v9; // ecx
  RBX::RaiseRange *eventType; // eax
  RBX::GuiResponse *v11; // eax

  switch ( event->eventType )
  {
    case MOUSE_RIGHT_BUTTON_DOWN:
      LOBYTE(this->parent) = 1;
      event->userInput->setWrapMode(event->userInput, WRAP_CENTER);
      goto LABEL_15;
    case MOUSE_RIGHT_BUTTON_UP:
      LOBYTE(this->parent) = 0;
      event->userInput->setWrapMode(event->userInput, WRAP_AUTO);
      goto LABEL_15;
    case MOUSE_LEFT_BUTTON_DOWN:
      Mylast = this->RBX::DescribedNonCreatable<RBX::Workspace,RBX::RootInstance,&RBX::sWorkspace>::RBX::Reflection::Described<RBX::Workspace,&RBX::sWorkspace,RBX::NonFactoryProduct<RBX::RootInstance,&RBX::sWorkspace> >::RBX::NonFactoryProduct<RBX::RootInstance,&RBX::sWorkspace>::RBX::RootInstance::RBX::Reflection::Described<RBX::RootInstance,&RBX::sRootInstance,RBX::ModelInstance>::RBX::ModelInstance::RBX::DescribedCreatable<RBX::ModelInstance,RBX::PVInstance,&RBX::sModel>::RBX::Reflection::Described<RBX::ModelInstance,&RBX::sModel,RBX::FactoryProduct<RBX::ModelInstance,RBX::PVInstance,&RBX::sModel> >::RBX::FactoryProduct<RBX::ModelInstance,RBX::PVInstance,&RBX::sModel>::RBX::PVInstance::RBX::Reflection::Described<RBX::PVInstance,&RBX::sPVInstance,RBX::Instance>::RBX::Instance::RBX::Notifier<RBX::Instance,RBX::AncestorChanged>::listeners._Mylast;
      if ( *((_BYTE *)Mylast + 20) )
        goto LABEL_15;
      v5 = (RBX::MouseCommand *)((int (__stdcall *)(const RBX::GuiEvent *))(*Mylast)[1].__vftable)(event);
      goto LABEL_14;
    case MOUSE_LEFT_BUTTON_UP:
      v5 = (RBX::MouseCommand *)((int (__stdcall *)(const RBX::GuiEvent *))(*this->RBX::DescribedNonCreatable<RBX::Workspace,RBX::RootInstance,&RBX::sWorkspace>::RBX::Reflection::Described<RBX::Workspace,&RBX::sWorkspace,RBX::NonFactoryProduct<RBX::RootInstance,&RBX::sWorkspace> >::RBX::NonFactoryProduct<RBX::RootInstance,&RBX::sWorkspace>::RBX::RootInstance::RBX::Reflection::Described<RBX::RootInstance,&RBX::sRootInstance,RBX::ModelInstance>::RBX::ModelInstance::RBX::DescribedCreatable<RBX::ModelInstance,RBX::PVInstance,&RBX::sModel>::RBX::Reflection::Described<RBX::ModelInstance,&RBX::sModel,RBX::FactoryProduct<RBX::ModelInstance,RBX::PVInstance,&RBX::sModel> >::RBX::FactoryProduct<RBX::ModelInstance,RBX::PVInstance,&RBX::sModel>::RBX::PVInstance::RBX::Reflection::Described<RBX::PVInstance,&RBX::sPVInstance,RBX::Instance>::RBX::Instance::RBX::Notifier<RBX::Instance,RBX::AncestorChanged>::listeners._Mylast)[8].__vftable)(event);
      goto LABEL_14;
    case MOUSE_MOVE:
      v7 = this->RBX::DescribedNonCreatable<RBX::Workspace,RBX::RootInstance,&RBX::sWorkspace>::RBX::Reflection::Described<RBX::Workspace,&RBX::sWorkspace,RBX::NonFactoryProduct<RBX::RootInstance,&RBX::sWorkspace> >::RBX::NonFactoryProduct<RBX::RootInstance,&RBX::sWorkspace>::RBX::RootInstance::RBX::Reflection::Described<RBX::RootInstance,&RBX::sRootInstance,RBX::ModelInstance>::RBX::ModelInstance::RBX::DescribedCreatable<RBX::ModelInstance,RBX::PVInstance,&RBX::sModel>::RBX::Reflection::Described<RBX::ModelInstance,&RBX::sModel,RBX::FactoryProduct<RBX::ModelInstance,RBX::PVInstance,&RBX::sModel> >::RBX::FactoryProduct<RBX::ModelInstance,RBX::PVInstance,&RBX::sModel>::RBX::PVInstance::RBX::Reflection::Described<RBX::PVInstance,&RBX::sPVInstance,RBX::Instance>::RBX::Instance::RBX::Notifier<RBX::Instance,RBX::AncestorChanged>::listeners._Mylast;
      v8 = *v7;
      if ( *((_BYTE *)v7 + 20) )
        ((void (__stdcall *)(const RBX::GuiEvent *))v8[6].__vftable)(event);
      else
        ((void (__stdcall *)(const RBX::GuiEvent *))v8[3].__vftable)(event);
      goto LABEL_15;
    case MOUSE_DELTA:
      v9 = this->RBX::DescribedNonCreatable<RBX::Workspace,RBX::RootInstance,&RBX::sWorkspace>::RBX::Reflection::Described<RBX::Workspace,&RBX::sWorkspace,RBX::NonFactoryProduct<RBX::RootInstance,&RBX::sWorkspace> >::RBX::NonFactoryProduct<RBX::RootInstance,&RBX::sWorkspace>::RBX::RootInstance::RBX::Reflection::Described<RBX::RootInstance,&RBX::sRootInstance,RBX::ModelInstance>::RBX::ModelInstance::RBX::DescribedCreatable<RBX::ModelInstance,RBX::PVInstance,&RBX::sModel>::RBX::Reflection::Described<RBX::ModelInstance,&RBX::sModel,RBX::FactoryProduct<RBX::ModelInstance,RBX::PVInstance,&RBX::sModel> >::RBX::FactoryProduct<RBX::ModelInstance,RBX::PVInstance,&RBX::sModel>::RBX::PVInstance::RBX::Reflection::Described<RBX::PVInstance,&RBX::sPVInstance,RBX::Instance>::RBX::Instance::RBX::Notifier<RBX::Instance,RBX::AncestorChanged>::listeners._Mylast;
      if ( *((_BYTE *)v9 + 20) )
        ((void (__thiscall *)(RBX::Listener<RBX::Instance,RBX::AncestorChanged> **, const RBX::GuiEvent *))(*v9)[7].__vftable)(
          v9,
          event);
      goto LABEL_15;
    case KEY_DOWN:
      ((void (__thiscall *)(RBX::Listener<RBX::Instance,RBX::AncestorChanged> **, const RBX::GuiEvent *))(*this->RBX::DescribedNonCreatable<RBX::Workspace,RBX::RootInstance,&RBX::sWorkspace>::RBX::Reflection::Described<RBX::Workspace,&RBX::sWorkspace,RBX::NonFactoryProduct<RBX::RootInstance,&RBX::sWorkspace> >::RBX::NonFactoryProduct<RBX::RootInstance,&RBX::sWorkspace>::RBX::RootInstance::RBX::Reflection::Described<RBX::RootInstance,&RBX::sRootInstance,RBX::ModelInstance>::RBX::ModelInstance::RBX::DescribedCreatable<RBX::ModelInstance,RBX::PVInstance,&RBX::sModel>::RBX::Reflection::Described<RBX::ModelInstance,&RBX::sModel,RBX::FactoryProduct<RBX::ModelInstance,RBX::PVInstance,&RBX::sModel> >::RBX::FactoryProduct<RBX::ModelInstance,RBX::PVInstance,&RBX::sModel>::RBX::PVInstance::RBX::Reflection::Described<RBX::PVInstance,&RBX::sPVInstance,RBX::Instance>::RBX::Instance::RBX::Notifier<RBX::Instance,RBX::AncestorChanged>::listeners._Mylast)[5].__vftable)(
        this->RBX::DescribedNonCreatable<RBX::Workspace,RBX::RootInstance,&RBX::sWorkspace>::RBX::Reflection::Described<RBX::Workspace,&RBX::sWorkspace,RBX::NonFactoryProduct<RBX::RootInstance,&RBX::sWorkspace> >::RBX::NonFactoryProduct<RBX::RootInstance,&RBX::sWorkspace>::RBX::RootInstance::RBX::Reflection::Described<RBX::RootInstance,&RBX::sRootInstance,RBX::ModelInstance>::RBX::ModelInstance::RBX::DescribedCreatable<RBX::ModelInstance,RBX::PVInstance,&RBX::sModel>::RBX::Reflection::Described<RBX::ModelInstance,&RBX::sModel,RBX::FactoryProduct<RBX::ModelInstance,RBX::PVInstance,&RBX::sModel> >::RBX::FactoryProduct<RBX::ModelInstance,RBX::PVInstance,&RBX::sModel>::RBX::PVInstance::RBX::Reflection::Described<RBX::PVInstance,&RBX::sPVInstance,RBX::Instance>::RBX::Instance::RBX::Notifier<RBX::Instance,RBX::AncestorChanged>::listeners._Mylast,
        event);
      v4 = this->RBX::DescribedNonCreatable<RBX::Workspace,RBX::RootInstance,&RBX::sWorkspace>::RBX::Reflection::Described<RBX::Workspace,&RBX::sWorkspace,RBX::NonFactoryProduct<RBX::RootInstance,&RBX::sWorkspace> >::RBX::NonFactoryProduct<RBX::RootInstance,&RBX::sWorkspace>::RBX::RootInstance::RBX::Reflection::Described<RBX::RootInstance,&RBX::sRootInstance,RBX::ModelInstance>::RBX::ModelInstance::RBX::DescribedCreatable<RBX::ModelInstance,RBX::PVInstance,&RBX::sModel>::RBX::Reflection::Described<RBX::ModelInstance,&RBX::sModel,RBX::FactoryProduct<RBX::ModelInstance,RBX::PVInstance,&RBX::sModel> >::RBX::FactoryProduct<RBX::ModelInstance,RBX::PVInstance,&RBX::sModel>::RBX::PVInstance::RBX::Reflection::Described<RBX::PVInstance,&RBX::sPVInstance,RBX::Instance>::RBX::Instance::RBX::Notifier<RBX::Instance,RBX::AncestorChanged>::listeners._Mylast;
      if ( !*((_BYTE *)v4 + 20) )
        goto LABEL_27;
      v5 = (RBX::MouseCommand *)((int (__stdcall *)(const RBX::GuiEvent *))(*v4)[4].__vftable)(event);
LABEL_14:
      RBX::Workspace::setMouseCommand((RBX::Workspace *)((char *)this - 656), v5);
LABEL_15:
      eventType = (RBX::RaiseRange *)event->eventType;
      if ( event->eventType == MOUSE_RIGHT_BUTTON_DOWN
        || eventType == (RBX::RaiseRange *)2
        || eventType == (RBX::RaiseRange *)3
        || eventType == (RBX::RaiseRange *)4
        || eventType == (RBX::RaiseRange *)5
        || eventType == (RBX::RaiseRange *)6
        || eventType == (RBX::RaiseRange *)7 )
      {
        this->RBX::DescribedNonCreatable<RBX::Workspace,RBX::RootInstance,&RBX::sWorkspace>::RBX::Reflection::Described<RBX::Workspace,&RBX::sWorkspace,RBX::NonFactoryProduct<RBX::RootInstance,&RBX::sWorkspace> >::RBX::NonFactoryProduct<RBX::RootInstance,&RBX::sWorkspace>::RBX::RootInstance::RBX::Reflection::Described<RBX::RootInstance,&RBX::sRootInstance,RBX::ModelInstance>::RBX::ModelInstance::RBX::DescribedCreatable<RBX::ModelInstance,RBX::PVInstance,&RBX::sModel>::RBX::Reflection::Described<RBX::ModelInstance,&RBX::sModel,RBX::FactoryProduct<RBX::ModelInstance,RBX::PVInstance,&RBX::sModel> >::RBX::FactoryProduct<RBX::ModelInstance,RBX::PVInstance,&RBX::sModel>::RBX::PVInstance::RBX::Reflection::Described<RBX::PVInstance,&RBX::sPVInstance,RBX::Instance>::RBX::Instance::RBX::Notifier<RBX::Instance,RBX::AncestorChanged>::raiseRange = eventType;
        this->RBX::DescribedNonCreatable<RBX::Workspace,RBX::RootInstance,&RBX::sWorkspace>::RBX::Reflection::Described<RBX::Workspace,&RBX::sWorkspace,RBX::NonFactoryProduct<RBX::RootInstance,&RBX::sWorkspace> >::RBX::NonFactoryProduct<RBX::RootInstance,&RBX::sWorkspace>::RBX::RootInstance::RBX::Reflection::Described<RBX::RootInstance,&RBX::sRootInstance,RBX::ModelInstance>::RBX::ModelInstance::RBX::DescribedCreatable<RBX::ModelInstance,RBX::PVInstance,&RBX::sModel>::RBX::Reflection::Described<RBX::ModelInstance,&RBX::sModel,RBX::FactoryProduct<RBX::ModelInstance,RBX::PVInstance,&RBX::sModel> >::RBX::FactoryProduct<RBX::ModelInstance,RBX::PVInstance,&RBX::sModel>::RBX::PVInstance::RBX::Reflection::Described<RBX::PVInstance,&RBX::sPVInstance,RBX::Instance>::RBX::Instance::RBX::Notifier<RBX::Instance,RBX::PropertyChanged>::__vftable = (RBX::Notifier<RBX::Instance,RBX::PropertyChanged>_vtbl *)event->userInput;
        *(_DWORD *)&this->RBX::DescribedNonCreatable<RBX::Workspace,RBX::RootInstance,&RBX::sWorkspace>::RBX::Reflection::Described<RBX::Workspace,&RBX::sWorkspace,RBX::NonFactoryProduct<RBX::RootInstance,&RBX::sWorkspace> >::RBX::NonFactoryProduct<RBX::RootInstance,&RBX::sWorkspace>::RBX::RootInstance::RBX::Reflection::Described<RBX::RootInstance,&RBX::sRootInstance,RBX::ModelInstance>::RBX::ModelInstance::RBX::DescribedCreatable<RBX::ModelInstance,RBX::PVInstance,&RBX::sModel>::RBX::Reflection::Described<RBX::ModelInstance,&RBX::sModel,RBX::FactoryProduct<RBX::ModelInstance,RBX::PVInstance,&RBX::sModel> >::RBX::FactoryProduct<RBX::ModelInstance,RBX::PVInstance,&RBX::sModel>::RBX::PVInstance::RBX::Reflection::Described<RBX::PVInstance,&RBX::sPVInstance,RBX::Instance>::RBX::Instance::RBX::Notifier<RBX::Instance,RBX::PropertyChanged>::listeners._Alval.std::_Allocator_base<RBX::Listener<RBX::Instance,RBX::PropertyChanged> *> = event->key;
        this->RBX::DescribedNonCreatable<RBX::Workspace,RBX::RootInstance,&RBX::sWorkspace>::RBX::Reflection::Described<RBX::Workspace,&RBX::sWorkspace,RBX::NonFactoryProduct<RBX::RootInstance,&RBX::sWorkspace> >::RBX::NonFactoryProduct<RBX::RootInstance,&RBX::sWorkspace>::RBX::RootInstance::RBX::Reflection::Described<RBX::RootInstance,&RBX::sRootInstance,RBX::ModelInstance>::RBX::ModelInstance::RBX::DescribedCreatable<RBX::ModelInstance,RBX::PVInstance,&RBX::sModel>::RBX::Reflection::Described<RBX::ModelInstance,&RBX::sModel,RBX::FactoryProduct<RBX::ModelInstance,RBX::PVInstance,&RBX::sModel> >::RBX::FactoryProduct<RBX::ModelInstance,RBX::PVInstance,&RBX::sModel>::RBX::PVInstance::RBX::Reflection::Described<RBX::PVInstance,&RBX::sPVInstance,RBX::Instance>::RBX::Instance::RBX::Notifier<RBX::Instance,RBX::PropertyChanged>::listeners._Myfirst = (RBX::Listener<RBX::Instance,RBX::PropertyChanged> **)event->mod;
        this->RBX::DescribedNonCreatable<RBX::Workspace,RBX::RootInstance,&RBX::sWorkspace>::RBX::Reflection::Described<RBX::Workspace,&RBX::sWorkspace,RBX::NonFactoryProduct<RBX::RootInstance,&RBX::sWorkspace> >::RBX::NonFactoryProduct<RBX::RootInstance,&RBX::sWorkspace>::RBX::RootInstance::RBX::Reflection::Described<RBX::RootInstance,&RBX::sRootInstance,RBX::ModelInstance>::RBX::ModelInstance::RBX::DescribedCreatable<RBX::ModelInstance,RBX::PVInstance,&RBX::sModel>::RBX::Reflection::Described<RBX::ModelInstance,&RBX::sModel,RBX::FactoryProduct<RBX::ModelInstance,RBX::PVInstance,&RBX::sModel> >::RBX::FactoryProduct<RBX::ModelInstance,RBX::PVInstance,&RBX::sModel>::RBX::PVInstance::RBX::Reflection::Described<RBX::PVInstance,&RBX::sPVInstance,RBX::Instance>::RBX::Instance::RBX::Notifier<RBX::Instance,RBX::PropertyChanged>::listeners._Mylast = (RBX::Listener<RBX::Instance,RBX::PropertyChanged> **)event->windowSize;
        this->RBX::DescribedNonCreatable<RBX::Workspace,RBX::RootInstance,&RBX::sWorkspace>::RBX::Reflection::Described<RBX::Workspace,&RBX::sWorkspace,RBX::NonFactoryProduct<RBX::RootInstance,&RBX::sWorkspace> >::RBX::NonFactoryProduct<RBX::RootInstance,&RBX::sWorkspace>::RBX::RootInstance::RBX::Reflection::Described<RBX::RootInstance,&RBX::sRootInstance,RBX::ModelInstance>::RBX::ModelInstance::RBX::DescribedCreatable<RBX::ModelInstance,RBX::PVInstance,&RBX::sModel>::RBX::Reflection::Described<RBX::ModelInstance,&RBX::sModel,RBX::FactoryProduct<RBX::ModelInstance,RBX::PVInstance,&RBX::sModel> >::RBX::FactoryProduct<RBX::ModelInstance,RBX::PVInstance,&RBX::sModel>::RBX::PVInstance::RBX::Reflection::Described<RBX::PVInstance,&RBX::sPVInstance,RBX::Instance>::RBX::Instance::RBX::Notifier<RBX::Instance,RBX::AncestorChanged>::raiseRange = (RBX::RaiseRange *)7;
      }
      if ( !*((_BYTE *)this->RBX::DescribedNonCreatable<RBX::Workspace,RBX::RootInstance,&RBX::sWorkspace>::RBX::Reflection::Described<RBX::Workspace,&RBX::sWorkspace,RBX::NonFactoryProduct<RBX::RootInstance,&RBX::sWorkspace> >::RBX::NonFactoryProduct<RBX::RootInstance,&RBX::sWorkspace>::RBX::RootInstance::RBX::Reflection::Described<RBX::RootInstance,&RBX::sRootInstance,RBX::ModelInstance>::RBX::ModelInstance::RBX::DescribedCreatable<RBX::ModelInstance,RBX::PVInstance,&RBX::sModel>::RBX::Reflection::Described<RBX::ModelInstance,&RBX::sModel,RBX::FactoryProduct<RBX::ModelInstance,RBX::PVInstance,&RBX::sModel> >::RBX::FactoryProduct<RBX::ModelInstance,RBX::PVInstance,&RBX::sModel>::RBX::PVInstance::RBX::Reflection::Described<RBX::PVInstance,&RBX::sPVInstance,RBX::Instance>::RBX::Instance::RBX::Notifier<RBX::Instance,RBX::AncestorChanged>::listeners._Mylast
            + 20)
        || this == (RBX::Workspace *)656 )
      {
        v11 = result;
        result->response = USED;
        result->target = 0;
      }
      else
      {
        v11 = result;
        result->response = USED;
        result->target = (RBX::GuiTarget *)this;
      }
      break;
    default:
LABEL_27:
      v11 = result;
      result->target = 0;
      result->response = NOT_USED;
      break;
  }
  return v11;
}
