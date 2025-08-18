void __thiscall RBX::Lighting::Lighting(RBX::Lighting *this)
{
  const G3D::Color3 *v2; // eax
  std::string s; // [esp+20h] [ebp-28h] BYREF
  int v4; // [esp+44h] [ebp-4h]

  RBX::DescribedCreatable<RBX::Lighting,RBX::Instance,&char * RBX::sLighting>::DescribedCreatable<RBX::Lighting,RBX::Instance,&char * RBX::sLighting>(this);
  v4 = 0;
  this->RBX::DescribedCreatable<RBX::Lighting,RBX::Instance,&RBX::sLighting>::RBX::Reflection::Described<RBX::Lighting,&RBX::sLighting,RBX::FactoryProduct<RBX::Lighting,RBX::Instance,&RBX::sLighting> >::RBX::FactoryProduct<RBX::Lighting,RBX::Instance,&RBX::sLighting>::RBX::Instance::RBX::GuidItem<RBX::Instance>::__vftable = (RBX::Lighting_vtbl *)&RBX::Lighting::`vftable'{for `RBX::GuidItem<RBX::Instance>'};
  this->RBX::DescribedCreatable<RBX::Lighting,RBX::Instance,&RBX::sLighting>::RBX::Reflection::Described<RBX::Lighting,&RBX::sLighting,RBX::FactoryProduct<RBX::Lighting,RBX::Instance,&RBX::sLighting> >::RBX::FactoryProduct<RBX::Lighting,RBX::Instance,&RBX::sLighting>::RBX::Instance::RBX::AbstractFactoryProduct<RBX::Instance>::RBX::Creatable<RBX::Instance>::RBX::Object::__vftable = (RBX::AbstractFactoryProduct<RBX::Instance>_vtbl *)&RBX::Lighting::`vftable'{for `RBX::AbstractFactoryProduct<RBX::Instance>'};
  this->RBX::DescribedCreatable<RBX::Lighting,RBX::Instance,&RBX::sLighting>::RBX::Reflection::Described<RBX::Lighting,&RBX::sLighting,RBX::FactoryProduct<RBX::Lighting,RBX::Instance,&RBX::sLighting> >::RBX::FactoryProduct<RBX::Lighting,RBX::Instance,&RBX::sLighting>::RBX::Instance::RBX::Reflection::Described<RBX::Instance,&RBX::sInstance,RBX::Reflection::DescribedBase>::RBX::Reflection::DescribedBase::RBX::Reflection::SignalSource::__vftable = (RBX::Reflection::Described<RBX::Instance,&RBX::sInstance,RBX::Reflection::DescribedBase>_vtbl *)&RBX::Lighting::`vftable'{for `RBX::Reflection::Described<RBX::Instance,&char const * const RBX::sInstance,RBX::Reflection::DescribedBase>'};
  this->RBX::DescribedCreatable<RBX::Lighting,RBX::Instance,&RBX::sLighting>::RBX::Reflection::Described<RBX::Lighting,&RBX::sLighting,RBX::FactoryProduct<RBX::Lighting,RBX::Instance,&RBX::sLighting> >::RBX::FactoryProduct<RBX::Lighting,RBX::Instance,&RBX::sLighting>::RBX::Instance::RBX::Debugable::__vftable = (RBX::Debugable_vtbl *)&RBX::Lighting::`vftable'{for `RBX::Debugable'};
  this->RBX::DescribedCreatable<RBX::Lighting,RBX::Instance,&RBX::sLighting>::RBX::Reflection::Described<RBX::Lighting,&RBX::sLighting,RBX::FactoryProduct<RBX::Lighting,RBX::Instance,&RBX::sLighting> >::RBX::FactoryProduct<RBX::Lighting,RBX::Instance,&RBX::sLighting>::RBX::Instance::RBX::Notifier<RBX::Instance,RBX::ChildAdded>::__vftable = (RBX::Notifier<RBX::Instance,RBX::ChildAdded>_vtbl *)&RBX::Lighting::`vftable'{for `RBX::Notifier<RBX::Instance,RBX::ChildAdded>'};
  this->RBX::DescribedCreatable<RBX::Lighting,RBX::Instance,&RBX::sLighting>::RBX::Reflection::Described<RBX::Lighting,&RBX::sLighting,RBX::FactoryProduct<RBX::Lighting,RBX::Instance,&RBX::sLighting> >::RBX::FactoryProduct<RBX::Lighting,RBX::Instance,&RBX::sLighting>::RBX::Instance::RBX::Notifier<RBX::Instance,RBX::ChildRemoved>::__vftable = (RBX::Notifier<RBX::Instance,RBX::ChildRemoved>_vtbl *)&RBX::Lighting::`vftable'{for `RBX::Notifier<RBX::Instance,RBX::ChildRemoved>'};
  this->RBX::DescribedCreatable<RBX::Lighting,RBX::Instance,&RBX::sLighting>::RBX::Reflection::Described<RBX::Lighting,&RBX::sLighting,RBX::FactoryProduct<RBX::Lighting,RBX::Instance,&RBX::sLighting> >::RBX::FactoryProduct<RBX::Lighting,RBX::Instance,&RBX::sLighting>::RBX::Instance::RBX::Notifier<RBX::Instance,RBX::DescendentAdded>::__vftable = (RBX::Notifier<RBX::Instance,RBX::DescendentAdded>_vtbl *)&RBX::Lighting::`vftable'{for `RBX::Notifier<RBX::Instance,RBX::DescendentAdded>'};
  this->RBX::DescribedCreatable<RBX::Lighting,RBX::Instance,&RBX::sLighting>::RBX::Reflection::Described<RBX::Lighting,&RBX::sLighting,RBX::FactoryProduct<RBX::Lighting,RBX::Instance,&RBX::sLighting> >::RBX::FactoryProduct<RBX::Lighting,RBX::Instance,&RBX::sLighting>::RBX::Instance::RBX::Notifier<RBX::Instance,RBX::DescendentRemoving>::__vftable = (RBX::Notifier<RBX::Instance,RBX::DescendentRemoving>_vtbl *)&RBX::Lighting::`vftable'{for `RBX::Notifier<RBX::Instance,RBX::DescendentRemoving>'};
  this->RBX::DescribedCreatable<RBX::Lighting,RBX::Instance,&RBX::sLighting>::RBX::Reflection::Described<RBX::Lighting,&RBX::sLighting,RBX::FactoryProduct<RBX::Lighting,RBX::Instance,&RBX::sLighting> >::RBX::FactoryProduct<RBX::Lighting,RBX::Instance,&RBX::sLighting>::RBX::Instance::RBX::Notifier<RBX::Instance,RBX::AncestorChanged>::__vftable = (RBX::Notifier<RBX::Instance,RBX::AncestorChanged>_vtbl *)&RBX::Lighting::`vftable'{for `RBX::Notifier<RBX::Instance,RBX::AncestorChanged>'};
  this->RBX::DescribedCreatable<RBX::Lighting,RBX::Instance,&RBX::sLighting>::RBX::Reflection::Described<RBX::Lighting,&RBX::sLighting,RBX::FactoryProduct<RBX::Lighting,RBX::Instance,&RBX::sLighting> >::RBX::FactoryProduct<RBX::Lighting,RBX::Instance,&RBX::sLighting>::RBX::Instance::RBX::Notifier<RBX::Instance,RBX::PropertyChanged>::__vftable = (RBX::Notifier<RBX::Instance,RBX::PropertyChanged>_vtbl *)&RBX::Lighting::`vftable'{for `RBX::Notifier<RBX::Instance,RBX::PropertyChanged>'};
  G3D::LightingParameters::LightingParameters(&this->skyParameters);
  this->ambientTop.r = 0.81960785;
  this->ambientTop.g = 0.81568629;
  this->ambientTop.b = 0.8509804;
  this->ambientBottom.r = 0.47843137;
  this->ambientBottom.g = 0.52549022;
  this->ambientBottom.b = 0.47058824;
  this->hasSky = 1;
  v2 = G3D::Color3::white();
  this->clearColor.r = v2->r;
  this->clearColor.g = v2->g;
  this->clearColor.b = v2->b;
  this->clearColor.a = 1.0;
  this->shadowColor.r = 0.5;
  this->shadowColor.g = 0.5;
  this->shadowColor.b = 0.5;
  this->shadowColor.a = 1.0;
  std::string::string(&s, "14:00:00");
  LOBYTE(v4) = 1;
  boost::date_time::str_from_delimited_time_duration<boost::posix_time::time_duration,char>(&this->timeOfDay, &s);
  LOBYTE(v4) = 0;
  std::string::~string(&s);
  this->sky.px = 0;
  this->sky.pn.pi_ = 0;
  this->skyParameters.lightColor.r = 0.59607846;
  this->skyParameters.lightColor.g = 0.53725493;
  LOBYTE(v4) = 2;
  this->skyParameters.lightColor.b = 0.40000001;
  G3D::LightingParameters::setTime(&this->skyParameters, (double)(int)(this->timeOfDay.ticks_.value_ / 1000000));
  std::string::string(&s, "Lighting");
  LOBYTE(v4) = 3;
  RBX::Instance::setName(this, &s);
  LOBYTE(v4) = 2;
  std::string::~string(&s);
}
