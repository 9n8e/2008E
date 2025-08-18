PluginReceiveResult __thiscall RBX::Network::Server::ClientProxy::OnReceive(
        RBX::Network::Server::ClientProxy *this,
        RakPeerInterface *peer,
        RBX::Instance *packet)
{
  unsigned __int8 *v5; // ecx
  std::string *v6; // esi
  boost::shared_ptr<RBX::StandardOut> *v7; // eax
  bool v8; // cf
  const char *Ptr; // edi
  RBX::StandardOut *px; // esi
  boost::enable_shared_from_this<RBX::Instance> *v11; // eax
  boost::shared_ptr<RBX::Network::Player> *v12; // eax
  RBX::Network::Player *v13; // ebx
  std::string *v14; // eax
  const char *Buf; // esi
  const char *v16; // eax
  unsigned int index; // [esp-8h] [ebp-118h]
  const std::string *v18; // [esp-4h] [ebp-114h]
  int v19; // [esp+0h] [ebp-110h] BYREF
  std::string v20; // [esp+10h] [ebp-100h] BYREF
  std::string v21; // [esp+2Ch] [ebp-E4h] BYREF
  std::runtime_error v22; // [esp+48h] [ebp-C8h] BYREF
  std::runtime_error pExceptionObject; // [esp+70h] [ebp-A0h] BYREF
  std::string result; // [esp+98h] [ebp-78h] BYREF
  std::string _Message; // [esp+B4h] [ebp-5Ch] BYREF
  boost::shared_ptr<RBX::StandardOut> v26; // [esp+D0h] [ebp-40h] BYREF
  boost::shared_ptr<RBX::Network::Player> v27; // [esp+D8h] [ebp-38h] BYREF
  RBX::Guid::Data id; // [esp+ECh] [ebp-24h] BYREF
  RBX::Instance *instance[2]; // [esp+F4h] [ebp-1Ch] BYREF
  SystemAddress *p_registeredGuid; // [esp+FCh] [ebp-14h]
  int *v31; // [esp+100h] [ebp-10h]
  int v32; // [esp+10Ch] [ebp-4h]
  RakNet::BitStream inBitstream; // [esp+110h] [ebp+0h] BYREF

  v31 = &v19;
  instance[1] = packet;
  p_registeredGuid = (SystemAddress *)&packet->registeredGuid;
  if ( SystemAddress::operator!=(
         (SystemAddress *)&packet->registeredGuid,
         (const SystemAddress *)(&this->classNames.strings[124]._Bx._Ptr + 3)) )
  {
    return RBX::Network::Replicator::OnReceive(this, peer, (Packet *)packet);
  }
  v5 = (unsigned __int8 *)packet->RBX::Reflection::Described<RBX::Instance,&RBX::sInstance,RBX::Reflection::DescribedBase>::RBX::Reflection::DescribedBase::RBX::Reflection::SignalSource::__vftable;
  if ( *v5 != 76 )
    return RBX::Network::Replicator::OnReceive(this, peer, (Packet *)packet);
  index = packet->guid.data.index;
  v32 = 0;
  RakNet::BitStream::BitStream(&inBitstream, v5, index, 0);
  LOBYTE(v32) = 1;
  RakNet::BitStream::IgnoreBits(&inBitstream, 8);
  if ( !RBX::Network::IdSerializer::deserializeInstanceRef(
          (RBX::Network::Server::ClientProxy *)((char *)this - 3876),
          &inBitstream,
          instance,
          &id) )
  {
    v14 = RBX::Guid::Data::readableString(&id, &v21, 4);
    v8 = v14->_Myres < 0x10;
    LOBYTE(v32) = 6;
    if ( v8 )
      Buf = v14->_Bx._Buf;
    else
      Buf = v14->_Bx._Ptr;
    v16 = SystemAddress::ToString(p_registeredGuid, 1);
    v18 = G3D::format(&v20, "Couldn't resolve remotePlayer %s from %s", Buf, v16);
    LOBYTE(v32) = 7;
    std::runtime_error::runtime_error(&v22, v18);
    _CxxThrowException(&v22, (_ThrowInfo *)&_TI2_AVruntime_error_std__);
  }
  if ( RBX::GlobalSettingsItem<RBX::NetworkSettings,&char const * const RBX::sNetworkSettings>::singleton()->printInstances )
  {
    v6 = RBX::Guid::Data::readableString(&id, &result, 4);
    LOBYTE(v32) = 2;
    v7 = RBX::StandardOut::singleton(&v26);
    v8 = v6->_Myres < 0x10;
    LOBYTE(v32) = 3;
    if ( v8 )
      Ptr = v6->_Bx._Buf;
    else
      Ptr = v6->_Bx._Ptr;
    px = v7->px;
    SystemAddress::ToString(p_registeredGuid, 1);
    RBX::StandardOut::print(
      px,
      MESSAGE_INFO,
      "Received remotePlayer %s from %s",
      &this[-1].classNames.strings[125]._Bx._Buf[12],
      Ptr);
    LOBYTE(v32) = 2;
    boost::shared_ptr<boost::recursive_mutex>::~shared_ptr<boost::recursive_mutex>((boost::shared_ptr<RBX::DataModel const > *)&v26);
    LOBYTE(v32) = 1;
    std::string::~string(&result);
  }
  if ( instance[0] )
    v11 = &instance[0]->boost::enable_shared_from_this<RBX::Instance>;
  else
    v11 = 0;
  v12 = RBX::shared_from_dynamic_cast<RBX::Network::Player,RBX::Instance>(&v27, v11);
  *(_DWORD *)&this->classNames.strings[125]._Alval.std::_Allocator_base<char> = v12->px;
  LOBYTE(v32) = 4;
  boost::detail::shared_count::operator=((boost::detail::shared_count *)&this->classNames.strings[125]._Bx, &v12->pn);
  LOBYTE(v32) = 1;
  boost::shared_ptr<RBX::ForceField>::~shared_ptr<RBX::ForceField>((boost::shared_ptr<RBX::Network::Server::ClientProxy> *)&v27);
  v13 = *(RBX::Network::Player **)&this->classNames.strings[125]._Alval.std::_Allocator_base<char>;
  if ( !v13 )
  {
    std::string::string(&_Message, "remotePlayer is NULL");
    LOBYTE(v32) = 5;
    std::runtime_error::runtime_error(&pExceptionObject, &_Message);
    _CxxThrowException(&pExceptionObject, (_ThrowInfo *)&_TI2_AVruntime_error_std__);
  }
  RBX::Network::Player::loadCharacter(v13);
  LOBYTE(v32) = 0;
  RakNet::BitStream::~BitStream(&inBitstream);
  return 0;
}
