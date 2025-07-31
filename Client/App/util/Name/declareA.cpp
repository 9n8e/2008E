const RBX::Name *__cdecl RBX::Name::declare(const char *sName, int dictionaryIndex)
{
  boost::mutex *v3; // ebx
  std::_Tree<std::_Tmap_traits<std::string,unsigned char,std::less<std::string >,std::allocator<std::pair<std::string const ,unsigned char> >,0> > *v4; // eax
  std::_Tree_nod<std::_Tmap_traits<std::string,RBX::Name *,std::less<std::string >,std::allocator<std::pair<std::string const ,RBX::Name *> >,0> >::_Node *v5; // eax
  std::_Tree_nod<std::_Tmap_traits<std::string,RBX::Name *,std::less<std::string >,std::allocator<std::pair<std::string const ,RBX::Name *> >,0> >::_Node *Ptr; // esi
  boost::mutex *m_mutex; // ebp
  int v8; // edi
  std::map<int,RBX::Name *> *v9; // eax
  void *v10; // ebp
  RBX::Name *v11; // eax
  RBX::Name *v12; // esi
  std::map<std::string,enum RBX::SoundType> *v13; // eax
  std::map<int,RBX::Name *> *v14; // eax
  const std::string *v15; // [esp-Ch] [ebp-50h]
  std::_Tree<std::_Tmap_traits<std::string,RBX::Name *,std::less<std::string >,std::allocator<std::pair<std::string const ,RBX::Name *> >,0> >::iterator iter; // [esp+0h] [ebp-44h] BYREF
  boost::detail::thread::scoped_lock<boost::mutex> lock; // [esp+8h] [ebp-3Ch]
  char v18; // [esp+10h] [ebp-34h]
  boost::mutex *Parent; // [esp+18h] [ebp-2Ch]
  std::string _Keyval; // [esp+1Ch] [ebp-28h] BYREF
  int v21; // [esp+40h] [ebp-4h]

  if ( sName )
  {
    boost::call_once((void (__cdecl *)())initMoo, &flag_0);
    v3 = moo2();
    *(_DWORD *)&lock.m_locked = v3;
    boost::mutex::do_lock(v3);
    v18 = 1;
    v21 = 0;
    v15 = (const std::string *)std::string::string(&_Keyval, sName);
    LOBYTE(v21) = 1;
    v4 = (std::_Tree<std::_Tmap_traits<std::string,unsigned char,std::less<std::string >,std::allocator<std::pair<std::string const ,unsigned char> >,0> > *)RBX::Name::namMap();
    std::_Tree<std::_Tmap_traits<std::string,enum RBX::SpecialShape::MeshType,std::less<std::string>,std::allocator<std::pair<std::string const,enum RBX::SpecialShape::MeshType>>,0>>::find(
      v4,
      (std::_Tree<std::_Tmap_traits<std::string,unsigned char,std::less<std::string >,std::allocator<std::pair<std::string const ,unsigned char> >,0> >::iterator *)&iter._Ptr,
      v15);
    LOBYTE(v21) = 0;
    std::string::~string(&_Keyval);
    v5 = (std::_Tree_nod<std::_Tmap_traits<std::string,RBX::Name *,std::less<std::string >,std::allocator<std::pair<std::string const ,RBX::Name *> >,0> >::_Node *)RBX::Name::namMap();
    Ptr = iter._Ptr;
    Parent = (boost::mutex *)v5->_Parent;
    if ( !iter._Ptr || iter._Ptr != v5 )
      __invalid_parameter_noinfo();
    m_mutex = lock.m_mutex;
    if ( lock.m_mutex == Parent )
    {
      v11 = (RBX::Name *)operator new(0x20u);
      v12 = v11;
      LOBYTE(v21) = 2;
      if ( v11 )
      {
        v11->dictionaryIndex = dictionaryIndex;
        std::string::string(&v11->name, sName);
      }
      else
      {
        v12 = 0;
      }
      LOBYTE(v21) = 0;
      std::string::string(&_Keyval, sName);
      LOBYTE(v21) = 3;
      v13 = (std::map<std::string,enum RBX::SoundType> *)RBX::Name::namMap();
      *std::map<std::string,enum RBX::HopperBin::BinType>::operator[](v13, &_Keyval) = (RBX::SoundType)v12;
      LOBYTE(v21) = 0;
      std::string::~string(&_Keyval);
      v14 = RBX::Name::dictionary();
      *std::map<int,RBX::Name *>::operator[](v14, &dictionaryIndex) = v12;
      v21 = -1;
      boost::mutex::do_unlock(v3);
      return v12;
    }
    else
    {
      v8 = dictionaryIndex;
      if ( dictionaryIndex != -1 )
      {
        if ( !Ptr )
          __invalid_parameter_noinfo();
        if ( m_mutex == (boost::mutex *)Ptr->_Parent )
          __invalid_parameter_noinfo();
        *(_DWORD *)m_mutex[5].m_mutex = v8;
        if ( m_mutex == (boost::mutex *)Ptr->_Parent )
          __invalid_parameter_noinfo();
        v9 = RBX::Name::dictionary();
        *std::map<int,RBX::Name *>::operator[](v9, &dictionaryIndex) = (RBX::Name *)m_mutex[5].m_mutex;
      }
      if ( !Ptr )
        __invalid_parameter_noinfo();
      if ( m_mutex == (boost::mutex *)Ptr->_Parent )
        __invalid_parameter_noinfo();
      v10 = m_mutex[5].m_mutex;
      v21 = -1;
      boost::mutex::do_unlock(v3);
      return (const RBX::Name *)v10;
    }
  }
  else
  {
    boost::call_once(declareNullName, &flag_1);
    return nullName;
  }
}
