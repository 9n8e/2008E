std::map<int,RBX::Name *> *__cdecl RBX::Name::dictionary()
{
  if ( (_S2 & 1) == 0 )
  {
    _S2 |= 1u;
    d._Myhead = (std::_Tree_nod<std::_Tmap_traits<int,RBX::Name *,std::less<int>,std::allocator<std::pair<int const ,RBX::Name *> >,0> >::_Node *)std::_Tree<std::_Tmap_traits<RBX::Name const *,enum RBX::Debugable::AssertAction,std::less<RBX::Name const *>,std::allocator<std::pair<RBX::Name const * const,enum RBX::Debugable::AssertAction>>,0>>::_Buynode((std::_Tree<std::_Tmap_traits<RBX::Instance *,RBX::Render::Model *,std::less<RBX::Instance *>,std::allocator<std::pair<RBX::Instance * const,RBX::Render::Model *> >,0> > *)&d);
    d._Myhead->_Isnil = 1;
    d._Myhead->_Parent = d._Myhead;
    d._Myhead->_Left = d._Myhead;
    d._Myhead->_Right = d._Myhead;
    d._Mysize = 0;
    atexit(RBX::Name::dictionary_::_2_::_dynamic_atexit_destructor_for__d__);
  }
  return &d;
}
