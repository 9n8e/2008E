RBX::Name::NamMap *__cdecl RBX::Name::namMap()
{
  if ( (_S3 & 1) == 0 )
  {
    _S3 |= 1u;
    n._Myhead = (std::_Tree_nod<std::_Tmap_traits<std::string,RBX::Name *,std::less<std::string >,std::allocator<std::pair<std::string const ,RBX::Name *> >,0> >::_Node *)std::_Tree<std::_Tset_traits<RBX::ContentId,std::less<RBX::ContentId>,std::allocator<RBX::ContentId>,0>>::_Buynode((std::_Tree<std::_Tmap_traits<unsigned char,std::string,std::less<unsigned char>,std::allocator<std::pair<unsigned char const ,std::string > >,0> > *)&n);
    n._Myhead->_Isnil = 1;
    n._Myhead->_Parent = n._Myhead;
    n._Myhead->_Left = n._Myhead;
    n._Myhead->_Right = n._Myhead;
    n._Mysize = 0;
    atexit(RBX::Name::namMap_::_2_::_dynamic_atexit_destructor_for__n__);
  }
  return &n;
}
