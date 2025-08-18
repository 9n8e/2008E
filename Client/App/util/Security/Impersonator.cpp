void __thiscall RBX::Security::Impersonator::Impersonator(
        RBX::Security::Impersonator *this,
        RBX::Security::Identities identity)
{
  _DWORD *v3; // eax
  void *v4; // ebx
  boost::thread_specific_ptr<RBX::Security::Context> *v5; // edi
  RBX::Security::Context *v6; // esi
  boost::thread_specific_ptr<RBX::Security::Context> *v7; // esi
  void *v8; // edi

  v3 = operator new(4u);
  if ( v3 )
  {
    *v3 = identity;
    v4 = v3;
  }
  else
  {
    v4 = 0;
  }
  v5 = RBX::Security::Context::ptr();
  v6 = (RBX::Security::Context *)boost::detail::tss::get(&v5->m_tss);
  if ( v6 )
    boost::detail::tss::set(&v5->m_tss, 0);
  this->previous = v6;
  v7 = RBX::Security::Context::ptr();
  v8 = boost::detail::tss::get(&v7->m_tss);
  if ( v8 != v4 )
  {
    boost::detail::tss::set(&v7->m_tss, v4);
    if ( v8 )
      boost::detail::tss::cleanup(&v7->m_tss, v8);
  }
}
