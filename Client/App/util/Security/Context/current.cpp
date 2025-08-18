RBX::Security::Context *__cdecl RBX::Security::Context::current()
{
  boost::thread_specific_ptr<RBX::Security::Context> *v0; // eax
  RBX::Security::Context *result; // eax
  _DWORD *v2; // eax
  void *v3; // esi
  boost::thread_specific_ptr<RBX::Security::Context> *v4; // edi
  void *v5; // ebx

  v0 = RBX::Security::Context::ptr();
  result = (RBX::Security::Context *)boost::detail::tss::get(&v0->m_tss);
  if ( !result )
  {
    v2 = operator new(4u);
    if ( v2 )
    {
      *v2 = 0;
      v3 = v2;
    }
    else
    {
      v3 = 0;
    }
    v4 = RBX::Security::Context::ptr();
    v5 = boost::detail::tss::get(&v4->m_tss);
    if ( v5 != v3 )
    {
      boost::detail::tss::set(&v4->m_tss, v3);
      if ( v5 )
        boost::detail::tss::cleanup(&v4->m_tss, v5);
    }
    return (RBX::Security::Context *)v3;
  }
  return result;
}
