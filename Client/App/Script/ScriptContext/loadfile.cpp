int __cdecl RBX::ScriptContext::loadfile(lua_State *L)
{
  RBX::Security::Context *v1; // eax
  const char *v2; // eax
  const RBX::Instance *v3; // edi
  RBX::ContentProvider *v4; // eax
  const char *v5; // eax
  int v6; // esi
  RBX::ContentId v8; // [esp-20h] [ebp-74h] BYREF
  std::string file; // [esp+8h] [ebp-4Ch] BYREF
  RBX::ContentId contentId; // [esp+24h] [ebp-30h] BYREF
  const RBX::Name *v11; // [esp+44h] [ebp-10h]
  int v12; // [esp+50h] [ebp-4h]

  v1 = RBX::Security::Context::current();
  RBX::Security::Context::requirePermission(v1, Administrator, "loadfile");
  v2 = RBX::Lua::throwable_lua_tostring(L, -1);
  std::string::string(&contentId.id._Bx, v2);
  v12 = 0;
  v11 = RBX::Name::declare<0>();
  *(_DWORD *)&file._Alval.std::_Allocator_base<char> = &v8;
  v12 = 1;
  std::string::string(&contentId.id._Bx);
  v8.mimeTypePtr = v11;
  LOBYTE(v12) = 2;
  lua_pushlightuserdata(L, (void *)0x43);
  lua_gettable(L, -10002);
  v3 = (const RBX::Instance *)lua_touserdata(L, -1);
  lua_settop(L, -2);
  v4 = RBX::ServiceProvider::create<RBX::ContentProvider>(v3);
  LOBYTE(v12) = 1;
  RBX::ContentProvider::getFile(v4, (std::string *)&file._Bx, v8);
  v5 = (const char *)*((_DWORD *)&file._Bx._Ptr + 1);
  LOBYTE(v12) = 3;
  if ( *(_DWORD *)&contentId.id._Alval.std::_Allocator_base<char> < 0x10u )
    v5 = &file._Bx._Buf[4];
  if ( luaL_loadfile(L, v5) )
  {
    lua_pushnil(L);
    lua_insert(L, -2);
    v6 = 2;
  }
  else
  {
    v6 = 1;
  }
  LOBYTE(v12) = 1;
  std::string::~string(&file._Bx);
  v12 = -1;
  std::string::~string(&contentId.id._Bx);
  return v6;
}
