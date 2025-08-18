void __thiscall RBX::ScriptContext::executeInNewThread(
        RBX::ScriptContext *this,
        int identity,
        const char *script,
        const char *name,
        boost::function1<unsigned int,lua_State *,std::allocator<boost::function_base> > pushArguments,
        boost::function2<void,lua_State *,unsigned int,std::allocator<boost::function_base> > readResults)
{
  lua_State *v7; // eax
  lua_State *L; // ebp
  lua_State *v9; // edi
  RBX::StandardOut *px; // eax
  boost::detail::sp_counted_base *pi; // esi
  unsigned int v12; // eax
  const char *v13; // ecx
  const char *v14; // eax
  boost::shared_ptr<RBX::StandardOut> *v15; // eax
  const char *v16; // ecx
  boost::detail::sp_counted_base *v17; // esi
  boost::function1<unsigned int,lua_State *,std::allocator<boost::function_base> > v18; // [esp-40h] [ebp-D4h] BYREF
  boost::function2<void,lua_State *,unsigned int,std::allocator<boost::function_base> > v19; // [esp-20h] [ebp-B4h] BYREF
  boost::function2<void,lua_State *,unsigned int,std::allocator<boost::function_base> > *v20; // [esp+10h] [ebp-84h]
  boost::shared_ptr<RBX::StandardOut> result; // [esp+14h] [ebp-80h] BYREF
  int v22; // [esp+1Ch] [ebp-78h]
  std::string sName; // [esp+20h] [ebp-74h] BYREF
  std::string err; // [esp+3Ch] [ebp-58h] BYREF
  unsigned int v25; // [esp+58h] [ebp-3Ch]
  std::runtime_error pExceptionObject; // [esp+60h] [ebp-34h] BYREF
  int v27; // [esp+90h] [ebp-4h]

  v27 = 1;
  RBX::ScriptContext::openState(this);
  if ( identity == 3 )
  {
    if ( !this->commandLineSandbox.L )
    {
      v7 = lua_newthread(this->globalState);
      RBX::Lua::ThreadRef::ThreadRef((RBX::Lua::ThreadRef *)&err._Bx, v7);
      LOBYTE(v27) = 2;
      RBX::Lua::ThreadRef::operator=(&this->commandLineSandbox, (const RBX::Lua::ThreadRef *)&err._Bx);
      LOBYTE(v27) = 1;
      RBX::Lua::ThreadRef::~ThreadRef((RBX::Lua::ThreadRef *)&err._Bx);
      if ( !this->commandLineSandbox.L )
      {
        std::string::string(&err._Bx, "Unable to create trusted sandbox thread");
        LOBYTE(v27) = 3;
        std::runtime_error::runtime_error(&pExceptionObject, (const std::string *)&err._Bx);
        _CxxThrowException(&pExceptionObject, (_ThrowInfo *)&_TI2_AVruntime_error_std__);
      }
      RBX::ScriptContext::sandboxThread(this->commandLineSandbox.L);
      RBX::ScriptContext::setThreadIdentity(this->commandLineSandbox.L, 3);
      lua_settop(this->globalState, -2);
    }
    L = this->commandLineSandbox.L;
    v9 = lua_newthread(L);
  }
  else
  {
    L = this->globalState;
    v9 = lua_newthread(L);
    RBX::ScriptContext::sandboxThread(v9);
    RBX::ScriptContext::setThreadIdentity(v9, identity);
  }
  if ( !v9 )
  {
    px = RBX::StandardOut::singleton(&result)->px;
    LOBYTE(v27) = 4;
    RBX::StandardOut::print(px, MESSAGE_ERROR, "ScriptContext::execute: Unable to create a new thread");
    LOBYTE(v27) = 1;
    if ( result.pn.pi_ )
    {
      pi = result.pn.pi_;
      if ( !_InterlockedExchangeAdd(&result.pn.pi_->use_count_, 0xFFFFFFFF) )
      {
        pi->dispose(pi);
        if ( !_InterlockedExchangeAdd(&pi->weak_count_, 0xFFFFFFFF) )
          pi->destroy(pi);
      }
    }
    std::string::string(&err._Bx, "Unable to create a new thread");
    LOBYTE(v27) = 5;
    std::runtime_error::runtime_error(&pExceptionObject, (const std::string *)&err._Bx);
    _CxxThrowException(&pExceptionObject, (_ThrowInfo *)&_TI2_AVruntime_error_std__);
  }
  v22 = 1;
  *(_DWORD *)&sName._Alval.std::_Allocator_base<char> = L;
  LOBYTE(v27) = 6;
  std::string::string(&sName._Bx, "=");
  LOBYTE(v27) = 7;
  if ( name )
    *((_DWORD *)&v19.functor.data + 5) = name;
  else
    *((_DWORD *)&v19.functor.data + 5) = "Script";
  std::string::operator+=(&sName._Bx, *((_DWORD *)&v19.functor.data + 5));
  v12 = strlen(script);
  v13 = (const char *)*((_DWORD *)&sName._Bx._Ptr + 1);
  if ( *(_DWORD *)&err._Alval.std::_Allocator_base<char> < 0x10u )
    v13 = &sName._Bx._Buf[4];
  if ( luaL_loadbuffer(v9, script, v12, v13) )
  {
    v14 = RBX::Lua::safe_lua_tostring(v9, -1);
    std::string::string(&err._Bx, v14);
    LOBYTE(v27) = 8;
    lua_settop(v9, -2);
    v15 = RBX::StandardOut::singleton(&result);
    v16 = (const char *)*((_DWORD *)&err._Bx._Ptr + 1);
    LOBYTE(v27) = 9;
    if ( v25 < 0x10 )
      v16 = &err._Bx._Buf[4];
    RBX::StandardOut::print(v15->px, MESSAGE_ERROR, v16);
    LOBYTE(v27) = 8;
    if ( result.pn.pi_ )
    {
      v17 = result.pn.pi_;
      if ( !_InterlockedExchangeAdd(&result.pn.pi_->use_count_, 0xFFFFFFFF) )
      {
        v17->dispose(v17);
        if ( !_InterlockedExchangeAdd(&v17->weak_count_, 0xFFFFFFFF) )
          v17->destroy(v17);
      }
    }
    std::runtime_error::runtime_error(&pExceptionObject, (const std::string *)&err._Bx);
    _CxxThrowException(&pExceptionObject, (_ThrowInfo *)&_TI2_AVruntime_error_std__);
  }
  v19.vtable = 0;
  v20 = &v19;
  if ( readResults.vtable )
  {
    v19.vtable = readResults.vtable;
    readResults.vtable->manager(&readResults.functor, &v19.functor, clone_functor_tag);
  }
  v18.vtable = 0;
  LOBYTE(v27) = 10;
  result.px = (RBX::StandardOut *)&v18;
  if ( pushArguments.vtable )
  {
    v18.vtable = pushArguments.vtable;
    pushArguments.vtable->manager(&pushArguments.functor, &v18.functor, clone_functor_tag);
  }
  LOBYTE(v27) = 7;
  RBX::ScriptContext::resume(this, v9, v18, v19);
  LOBYTE(v27) = 6;
  std::string::~string(&sName._Bx);
  LOBYTE(v27) = 1;
  lua_settop(L, -2);
  LOBYTE(v27) = 0;
  if ( pushArguments.vtable && pushArguments.vtable->manager )
    pushArguments.vtable->manager(&pushArguments.functor, &pushArguments.functor, destroy_functor_tag);
  v27 = -1;
  if ( readResults.vtable && readResults.vtable->manager )
    readResults.vtable->manager(&readResults.functor, &readResults.functor, destroy_functor_tag);
}
