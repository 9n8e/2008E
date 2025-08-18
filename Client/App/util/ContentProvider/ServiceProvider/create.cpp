// Players as an example
RBX::Network::Players *__thiscall RBX::ServiceProvider::create<RBX::Network::Players>(RBX::ServiceProvider *this)
{
  RBX::Network::Players *result; // eax
  boost::detail::sp_counted_base *pi; // ebx
  unsigned int v4; // eax
  boost::shared_ptr<RBX::Instance> *Myfirst; // ecx
  unsigned int v6; // edi
  boost::shared_ptr<RBX::Instance> *v7; // eax
  boost::detail::sp_counted_base *v8; // esi
  boost::shared_ptr<RBX::Network::Players> s; // [esp+0h] [ebp-18h] BYREF
  boost::detail::shared_count r; // [esp+8h] [ebp-10h] BYREF
  int v11; // [esp+14h] [ebp-4h]

  result = RBX::ServiceProvider::find<RBX::Network::Players>(this);
  if ( !result )
  {
    RBX::Creatable<RBX::Instance>::create<RBX::Network::Players>((boost::shared_ptr<RBX::Network::Players> *)&s.pn);
    pi = s.pn.pi_;
    v11 = 0;
    boost::call_once(
      (void (__cdecl *)())RBX::ServiceProvider::callDoGetClassIndex<RBX::Network::Players>,
      &`RBX::ServiceProvider::getClassIndex<RBX::Network::Players>'::`2'::flag);
    v4 = RBX::ServiceProvider::doGetClassIndex<RBX::Network::Players>();
    Myfirst = this->serviceArray._Myfirst;
    v6 = v4;
    if ( !Myfirst || v4 >= this->serviceArray._Mylast - Myfirst )
      __invalid_parameter_noinfo();
    v7 = &this->serviceArray._Myfirst[v6];
    v7->px = (RBX::Instance *)s.pn.pi_;
    boost::detail::shared_count::operator=(&v7->pn, &r);
    RBX::Instance::setParent((RBX::Instance *)pi, this);
    v8 = r.pi_;
    v11 = -1;
    if ( r.pi_ && !_InterlockedExchangeAdd(&r.pi_->use_count_, 0xFFFFFFFF) )
    {
      v8->dispose(v8);
      if ( !_InterlockedExchangeAdd(&v8->weak_count_, 0xFFFFFFFF) )
        v8->destroy(v8);
    }
    return (RBX::Network::Players *)pi;
  }
  return result;
}
