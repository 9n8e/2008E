int __cdecl RBX::ScriptContext::dofile(lua_State *L)
{
  RBX::Security::Context *v1; // eax
  const char *v2; // edi
  int v3; // ebp
  const RBX::Instance *v4; // edi
  RBX::ContentProvider *v5; // eax
  const char *v6; // eax
  int v7; // esi
  RBX::ContentId v9; // [esp-20h] [ebp-78h] BYREF
  std::string file; // [esp+Ch] [ebp-4Ch] BYREF
  RBX::ContentId contentId; // [esp+28h] [ebp-30h] BYREF
  const RBX::Name *v12; // [esp+48h] [ebp-10h]
  int v13; // [esp+54h] [ebp-4h]

  v1 = RBX::Security::Context::current();
  RBX::Security::Context::requirePermission(v1, Administrator, "dofile");
  v2 = luaL_optlstring(L, 1, 0, 0);
  v3 = lua_gettop(L);
  std::string::string(&contentId.id._Bx, v2);
  v13 = 0;
  v12 = RBX::Name::declare<0>();
  *(_DWORD *)&file._Alval.std::_Allocator_base<char> = &v9;
  v13 = 1;
  std::string::string(&contentId.id._Bx);
  v9.mimeTypePtr = v12;
  LOBYTE(v13) = 2;
  lua_pushlightuserdata(L, (void *)0x43);
  lua_gettable(L, -10002);
  v4 = (const RBX::Instance *)lua_touserdata(L, -1);
  lua_settop(L, -2);
  v5 = RBX::ServiceProvider::create<RBX::ContentProvider>(v4);
  LOBYTE(v13) = 1;
  RBX::ContentProvider::getFile(v5, (std::string *)&file._Bx, v9);
  v6 = (const char *)*((_DWORD *)&file._Bx._Ptr + 1);
  LOBYTE(v13) = 3;
  if ( *(_DWORD *)&contentId.id._Alval.std::_Allocator_base<char> < 0x10u )
    v6 = &file._Bx._Buf[4];
  if ( luaL_loadfile(L, v6) )
    lua_error(L);
  lua_call(L, 0, -1);
  v7 = lua_gettop(L) - v3;
  LOBYTE(v13) = 1;
  std::string::~string(&file._Bx);
  v13 = -1;
  std::string::~string(&contentId.id._Bx);
  return v7;
}
