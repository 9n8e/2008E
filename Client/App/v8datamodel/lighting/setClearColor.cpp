void __thiscall RBX::Lighting::setClearColor(RBX::Lighting *this, G3D::Color4 value)
{
  double a; // st6
  double b; // st5
  double g; // rt0
  RBX::Reflection::Described<RBX::Instance,&RBX::sInstance,RBX::Reflection::DescribedBase> *v6; // eax
  RBX::Reflection::SignalInstance *SignalInstance; // eax
  RBX::RunService *v8; // eax

  a = value.a;
  b = value.b;
  if ( value.r != this->clearColor.r
    || this->clearColor.g != value.g
    || this->clearColor.b != b
    || this->clearColor.a != a )
  {
    g = value.g;
    this->clearColor.r = value.r;
    this->clearColor.g = g;
    this->clearColor.b = b;
    this->clearColor.a = a;
    RBX::Instance::raisePropertyChanged(this, &desc_ClearColor);
    if ( this )
      v6 = &this->RBX::Reflection::Described<RBX::Instance,&RBX::sInstance,RBX::Reflection::DescribedBase>;
    else
      v6 = 0;
    SignalInstance = RBX::Reflection::SignalDescriptor::findSignalInstance(&RBX::Lighting::event_LightingChanged, v6);
    if ( SignalInstance )
      boost::signal1<void,bool,boost::last_value<void>,int,std::less<int>,boost::function<void __cdecl (bool),std::allocator<void>>>::operator()(
        (boost::signal1<void,bool,boost::last_value<void>,int,std::less<int>,boost::function<void __cdecl(bool),std::allocator<void> > > *)&SignalInstance[1].source,
        (bool)&value);
    v8 = RBX::ServiceProvider::find<RBX::RunService>(this);
    if ( v8 )
      RBX::RunService::invalidateRunViews(v8);
  }
}
