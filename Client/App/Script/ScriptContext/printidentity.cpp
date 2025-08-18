int __cdecl RBX::ScriptContext::printidentity(lua_State *thread)
{
  RBX::StandardOut *px; // esi
  const char *v2; // eax
  boost::detail::sp_counted_base *pi; // esi
  bool v4; // zf
  RBX::StandardOut *v5; // esi
  RBX::Security::Context *v6; // eax
  RBX::Security::Identities identity; // [esp-4h] [ebp-2Ch]
  boost::shared_ptr<RBX::StandardOut> result; // [esp+Ch] [ebp-1Ch] BYREF
  boost::shared_ptr<RBX::StandardOut> v10; // [esp+14h] [ebp-14h] BYREF
  int v11; // [esp+24h] [ebp-4h]

  if ( lua_isstring(thread, -1) )
  {
    px = RBX::StandardOut::singleton(&result)->px;
    v11 = 0;
    identity = RBX::Security::Context::current()->identity;
    v2 = lua_tolstring(thread, -1, 0);
    RBX::StandardOut::print(px, MESSAGE_OUTPUT, "%s %d", v2, identity);
    v11 = -1;
    if ( !result.pn.pi_ )
      return 0;
    pi = result.pn.pi_;
    if ( _InterlockedExchangeAdd(&result.pn.pi_->use_count_, 0xFFFFFFFF) )
      return 0;
    pi->dispose(pi);
    v4 = _InterlockedExchangeAdd(&pi->weak_count_, 0xFFFFFFFF) == 0;
  }
  else
  {
    v5 = RBX::StandardOut::singleton(&v10)->px;
    v11 = 1;
    v6 = RBX::Security::Context::current();
    RBX::StandardOut::print(v5, MESSAGE_OUTPUT, "Current identity is %d", v6->identity);
    v11 = -1;
    if ( !v10.pn.pi_ )
      return 0;
    pi = v10.pn.pi_;
    if ( _InterlockedExchangeAdd(&v10.pn.pi_->use_count_, 0xFFFFFFFF) )
      return 0;
    pi->dispose(pi);
    v4 = _InterlockedExchangeAdd(&pi->weak_count_, 0xFFFFFFFF) == 0;
  }
  if ( v4 )
    pi->destroy(pi);
  return 0;
}
