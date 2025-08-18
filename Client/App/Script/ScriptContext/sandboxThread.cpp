void __cdecl RBX::ScriptContext::sandboxThread(lua_State *thread)
{
  lua_createtable(thread, 0, 0);
  lua_createtable(thread, 0, 0);
  lua_pushlstring(thread, "__index", 7u);
  lua_pushvalue(thread, -10002);
  lua_settable(thread, -3);
  lua_setmetatable(thread, -2);
  lua_replace(thread, -10002);
}
