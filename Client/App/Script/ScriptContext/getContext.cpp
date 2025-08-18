RBX::ScriptContext *__cdecl RBX::ScriptContext::getContext(lua_State *thread)
{
  void *v1; // edi

  lua_pushlightuserdata(thread, (void *)0x43);
  lua_gettable(thread, -10002);
  v1 = lua_touserdata(thread, -1);
  lua_settop(thread, -2);
  return (RBX::ScriptContext *)v1;
}
