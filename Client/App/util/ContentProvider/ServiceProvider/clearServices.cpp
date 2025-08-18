void __thiscall RBX::ServiceProvider::clearServices(RBX::ServiceProvider *this)
{
  boost::shared_ptr<RBX::Instance> *Mylast; // ebx
  std::vector<boost::shared_ptr<RBX::Instance>> *p_serviceArray; // esi
  boost::shared_ptr<RBX::Instance> *Myfirst; // ebp
  std::_Tree_nod<std::_Tmap_traits<RBX::Name const *,boost::shared_ptr<RBX::Instance>,std::less<RBX::Name const *>,std::allocator<std::pair<RBX::Name const * const,boost::shared_ptr<RBX::Instance> > >,0> >::_Node *Myhead; // eax
  std::_Vector_iterator<boost::shared_ptr<RBX::Instance>> result; // [esp+10h] [ebp-8h] BYREF

  Mylast = this->serviceArray._Mylast;
  p_serviceArray = &this->serviceArray;
  if ( this->serviceArray._Myfirst > Mylast )
    __invalid_parameter_noinfo();
  Myfirst = p_serviceArray->_Myfirst;
  if ( Myfirst > p_serviceArray->_Mylast )
    __invalid_parameter_noinfo();
  std::vector<boost::shared_ptr<RBX::Instance>>::erase(
    p_serviceArray,
    &result,
    (std::_Vector_iterator<boost::shared_ptr<RBX::Instance>>)__PAIR64__(
                                                               (unsigned int)Myfirst,
                                                               (unsigned int)p_serviceArray),
    (std::_Vector_iterator<boost::shared_ptr<RBX::Instance>>)__PAIR64__(
                                                               (unsigned int)Mylast,
                                                               (unsigned int)p_serviceArray));
  std::_Tree<std::_Tmap_traits<RBX::Name const *,boost::shared_ptr<RBX::Instance>,std::less<RBX::Name const *>,std::allocator<std::pair<RBX::Name const * const,boost::shared_ptr<RBX::Instance>>>,0>>::_Erase(
    (std::_Tree<std::_Tmap_traits<RBX::Reflection::PropertyDescriptor const *,boost::shared_ptr<RBX::Network::SharedStringDictionary>,std::less<RBX::Reflection::PropertyDescriptor const *>,std::allocator<std::pair<RBX::Reflection::PropertyDescriptor const * const,boost::shared_ptr<RBX::Network::SharedStringDictionary> > >,0> > *)&this->serviceMap,
    (std::_Tree_nod<std::_Tmap_traits<RBX::Reflection::PropertyDescriptor const *,boost::shared_ptr<RBX::Network::SharedStringDictionary>,std::less<RBX::Reflection::PropertyDescriptor const *>,std::allocator<std::pair<RBX::Reflection::PropertyDescriptor const * const,boost::shared_ptr<RBX::Network::SharedStringDictionary> > >,0> >::_Node *)this->serviceMap._Myhead->_Parent);
  this->serviceMap._Myhead->_Parent = this->serviceMap._Myhead;
  Myhead = this->serviceMap._Myhead;
  this->serviceMap._Mysize = 0;
  Myhead->_Left = Myhead;
  this->serviceMap._Myhead->_Right = this->serviceMap._Myhead;
}
