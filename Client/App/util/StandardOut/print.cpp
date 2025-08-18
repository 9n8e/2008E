void RBX::StandardOut::print(RBX::StandardOut *this, RBX::MessageType type, const char *format, ...)
{
  char **v3; // esi
  RBX::Log *v4; // eax
  char **v5; // esi
  char **v6; // esi
  RBX::Listener<RBX::StandardOut,RBX::StandardOutMessage> **Myfirst; // eax
  RBX::Listener<RBX::StandardOut,RBX::StandardOutMessage> **v8; // eax
  char **v9; // eax
  RBX::StandardOutMessage v10; // [esp-28h] [ebp-64h] BYREF
  boost::detail::thread::scoped_lock<boost::mutex> lock; // [esp+8h] [ebp-34h]
  std::string message; // [esp+10h] [ebp-2Ch] BYREF
  unsigned int v13; // [esp+2Ch] [ebp-10h]
  int v14; // [esp+38h] [ebp-4h]
  va_list argPtr; // [esp+4Ch] [ebp+10h] BYREF

  va_start(argPtr, format);
  G3D::vformat((std::string *)&message._Bx, format, argPtr);
  v14 = 0;
  if ( RBX::Log::provider && RBX::Log::provider->provideLog(RBX::Log::provider) )
  {
    switch ( type )
    {
      case MESSAGE_ERROR:
        v3 = (char **)*((_DWORD *)&message._Bx._Ptr + 1);
        if ( v13 < 0x10 )
          v3 = &message._Bx._Ptr + 1;
        if ( RBX::Log::provider )
        {
          v4 = (RBX::Log *)RBX::Log::provider->provideLog(RBX::Log::provider);
          HIDWORD(v10.time) = v3;
        }
        else
        {
          HIDWORD(v10.time) = v3;
          v4 = 0;
        }
        LODWORD(v10.time) = 2;
LABEL_24:
        RBX::Log::writeEntry(v4, v10.time, (const char *)HIDWORD(v10.time));
        break;
      case MESSAGE_WARNING:
        v5 = (char **)*((_DWORD *)&message._Bx._Ptr + 1);
        if ( v13 < 0x10 )
          v5 = &message._Bx._Ptr + 1;
        if ( RBX::Log::provider )
        {
          v4 = (RBX::Log *)RBX::Log::provider->provideLog(RBX::Log::provider);
          HIDWORD(v10.time) = v5;
        }
        else
        {
          HIDWORD(v10.time) = v5;
          v4 = 0;
        }
        LODWORD(v10.time) = 1;
        goto LABEL_24;
      case MESSAGE_INFO:
        v6 = (char **)*((_DWORD *)&message._Bx._Ptr + 1);
        if ( v13 < 0x10 )
          v6 = &message._Bx._Ptr + 1;
        if ( RBX::Log::provider )
          v4 = (RBX::Log *)RBX::Log::provider->provideLog(RBX::Log::provider);
        else
          v4 = 0;
        HIDWORD(v10.time) = v6;
        LODWORD(v10.time) = 0;
        goto LABEL_24;
    }
  }
  Myfirst = this->listeners._Myfirst;
  if ( Myfirst && this->listeners._Mylast - Myfirst )
  {
    *(_DWORD *)&lock.m_locked = &this->sync;
    boost::mutex::do_lock(&this->sync);
    message._Alval.std::_Allocator_base<char> = (std::_Allocator_base<char>)1;
    v8 = this->listeners._Myfirst;
    LOBYTE(v14) = 1;
    if ( v8 && this->listeners._Mylast - v8 )
    {
      v9 = (char **)*((_DWORD *)&message._Bx._Ptr + 1);
      if ( v13 < 0x10 )
        v9 = &message._Bx._Ptr + 1;
      v10.type = type;
      std::string::string(&v10.message, v9);
      __time64(&v10.time);
      RBX::Notifier<RBX::StandardOut,RBX::StandardOutMessage>::raise(this, v10);
    }
    LOBYTE(v14) = 0;
    boost::mutex::do_unlock(&this->sync);
  }
  v14 = -1;
  std::string::~string(&message._Bx);
}
