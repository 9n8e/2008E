// Players service as an example
RBX::Network::Players *__thiscall RBX::ServiceProvider::find<RBX::Network::Players>(RBX::ServiceProvider *this)
{
  unsigned int v2; // eax
  boost::shared_ptr<RBX::Instance> *Myfirst; // ecx
  std::vector<boost::shared_ptr<RBX::Instance>> *p_serviceArray; // esi
  unsigned int v5; // edi
  unsigned int v6; // eax
  boost::shared_ptr<RBX::Instance> *v7; // ecx
  RBX::Network::Players *result; // eax
  const RBX::Name *v9; // eax
  boost::detail::sp_counted_base *pi; // edx
  boost::shared_ptr<RBX::Instance> *v11; // ecx
  boost::detail::sp_counted_base *v12; // ebx
  boost::detail::shared_count *v13; // eax
  int v14; // [esp-8h] [ebp-2Ch] BYREF
  const boost::detail::shared_count *p_r; // [esp-4h] [ebp-28h]
  boost::shared_ptr<RBX::Instance> i; // [esp+Ch] [ebp-18h] BYREF
  boost::detail::shared_count r; // [esp+14h] [ebp-10h] BYREF
  int v18; // [esp+20h] [ebp-4h]

  boost::call_once(
    (void (__cdecl *)())RBX::ServiceProvider::callDoGetClassIndex<RBX::Network::Players>,
    &`RBX::ServiceProvider::getClassIndex<RBX::Network::Players>'::`2'::flag);
  v2 = RBX::ServiceProvider::doGetClassIndex<RBX::Network::Players>();
  Myfirst = this->serviceArray._Myfirst;
  p_serviceArray = &this->serviceArray;
  v5 = v2;
  if ( Myfirst )
    v6 = this->serviceArray._Mylast - Myfirst;
  else
    v6 = 0;
  if ( v5 + 1 > v6 )
  {
    i.px = (RBX::Instance *)&v14;
    std::vector<boost::shared_ptr<RBX::Instance>>::resize(&this->serviceArray, v5 + 1, 0i64);
LABEL_10:
    boost::call_once(
      (void (__cdecl *)())RBX::Name::callDoDeclare<&char * RBX::Network::sPlayers>,
      &`RBX::Name::declare<&char * RBX::Network::sPlayers>'::`2'::flag);
    v9 = RBX::Name::doDeclare<&char * RBX::Network::sPlayers>();
    RBX::ServiceProvider::findServiceByClassName(this, (boost::shared_ptr<RBX::Instance> *)&i.pn, v9);
    pi = i.pn.pi_;
    v18 = 0;
    if ( i.pn.pi_ )
    {
      v11 = this->serviceArray._Myfirst;
      v12 = i.pn.pi_;
      if ( !v11 || v5 >= p_serviceArray->_Mylast - v11 )
      {
        __invalid_parameter_noinfo();
        pi = i.pn.pi_;
      }
      v13 = (boost::detail::shared_count *)&p_serviceArray->_Myfirst[v5];
      p_r = &r;
      v13->pi_ = pi;
      boost::detail::shared_count::operator=(v13 + 1, p_r);
      v18 = -1;
      boost::shared_ptr<boost::recursive_mutex>::~shared_ptr<boost::recursive_mutex>((boost::shared_ptr<RBX::DataModel const > *)&i.pn);
      return (RBX::Network::Players *)v12;
    }
    else
    {
      v18 = -1;
      boost::shared_ptr<boost::recursive_mutex>::~shared_ptr<boost::recursive_mutex>((boost::shared_ptr<RBX::DataModel const > *)&i.pn);
      return 0;
    }
  }
  v7 = this->serviceArray._Myfirst;
  if ( !v7 || v5 >= this->serviceArray._Mylast - v7 )
    __invalid_parameter_noinfo();
  result = (RBX::Network::Players *)this->serviceArray._Myfirst[v5].px;
  if ( !result )
    goto LABEL_10;
  return result;
}
