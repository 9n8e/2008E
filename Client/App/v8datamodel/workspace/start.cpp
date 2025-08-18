void __thiscall RBX::Workspace::start(RBX::Workspace *this)
{
  int (__thiscall *v2)(_BYTE *); // edx
  RBX::Camera *v3; // eax
  std::_Tree_nod<std::_Tset_traits<RBX::Script *,std::less<RBX::Script *>,std::allocator<RBX::Script *>,0> >::_Node *Left; // ebx
  std::_Tree_nod<std::_Tset_traits<RBX::Script *,std::less<RBX::Script *>,std::allocator<RBX::Script *>,0> >::_Node *Myhead; // eax
  std::_Tree_nod<std::_Tset_traits<RBX::Script *,std::less<RBX::Script *>,std::allocator<RBX::Script *>,0> >::_Node **p_pendingScripts; // edi
  const boost::shared_ptr<RBX::Script> *v7; // eax
  boost::detail::sp_counted_base *pi; // edi
  boost::detail::sp_counted_base *v9; // edi
  std::_Tree_nod<std::_Tset_traits<RBX::Script *,std::less<RBX::Script *>,std::allocator<RBX::Script *>,0> >::_Node *v10; // eax
  RBX::ScriptContext *scriptContext; // esi
  boost::shared_ptr<RBX::Script> *Mylast; // eax
  boost::shared_ptr<RBX::Script> *Myfirst; // ecx
  std::_Vector_iterator<boost::shared_ptr<RBX::Script>> v14; // [esp-28h] [ebp-88h]
  std::_Vector_iterator<boost::shared_ptr<RBX::Script>> v15; // [esp-20h] [ebp-80h]
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,RBX::ScriptContext,RBX::Script *>,boost::_bi::list2<boost::_bi::value<RBX::ScriptContext *>,boost::_bi::bind_t<RBX::Script *,boost::_mfi::cmf0<RBX::Script *,boost::shared_ptr<RBX::Script> >,boost::_bi::list1<boost::arg<1> > > > > v16; // [esp-18h] [ebp-78h]
  boost::shared_ptr<RBX::Script> *v17; // [esp+10h] [ebp-50h]
  std::_Tree_nod<std::_Tset_traits<RBX::Script *,std::less<RBX::Script *>,std::allocator<RBX::Script *>,0> >::_Node *v18; // [esp+14h] [ebp-4Ch]
  std::_Tree<std::_Tset_traits<RBX::Script *,std::less<RBX::Script *>,std::allocator<RBX::Script *>,0> >::const_iterator iter; // [esp+18h] [ebp-48h] BYREF
  boost::shared_ptr<RBX::ScriptContext> result; // [esp+20h] [ebp-40h] BYREF
  std::vector<boost::shared_ptr<RBX::Script>> startScripts; // [esp+28h] [ebp-38h] BYREF
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,RBX::ScriptContext,RBX::Script *>,boost::_bi::list2<boost::_bi::value<RBX::ScriptContext *>,boost::_bi::bind_t<RBX::Script *,boost::_mfi::cmf0<RBX::Script *,boost::shared_ptr<RBX::Script> >,boost::_bi::list1<boost::arg<1> > > > > v22; // [esp+38h] [ebp-28h] BYREF
  int v23; // [esp+5Ch] [ebp-4h]

  v2 = *(int (__thiscall **)(_BYTE *))(*(_DWORD *)this->gap238 + 4);
  this->isSimulating = 1;
  v3 = (RBX::Camera *)v2(this->gap238);
  RBX::Camera::alwaysMode(v3);
  if ( this->scriptContext )
  {
    memset(&startScripts._Myfirst, 0, 12);
    v23 = 0;
    Left = this->pendingScripts._Myhead->_Left;
    Myhead = this->pendingScripts._Myhead;
    p_pendingScripts = (std::_Tree_nod<std::_Tset_traits<RBX::Script *,std::less<RBX::Script *>,std::allocator<RBX::Script *>,0> >::_Node **)&this->pendingScripts;
    iter._Mycont = &this->pendingScripts;
    iter._Ptr = Left;
    v18 = Myhead;
    while ( 1 )
    {
      if ( !p_pendingScripts
        || p_pendingScripts != (std::_Tree_nod<std::_Tset_traits<RBX::Script *,std::less<RBX::Script *>,std::allocator<RBX::Script *>,0> >::_Node **)&this->pendingScripts )
      {
        __invalid_parameter_noinfo();
      }
      if ( Left == v18 )
        break;
      if ( !p_pendingScripts )
        __invalid_parameter_noinfo();
      if ( Left == p_pendingScripts[1] )
        __invalid_parameter_noinfo();
      v7 = (const boost::shared_ptr<RBX::Script> *)RBX::shared_from<RBX::ModelInstance>(
                                                     &result,
                                                     (RBX::ScriptContext *)Left->_Myval);
      LOBYTE(v23) = 1;
      std::vector<boost::shared_ptr<RBX::Script>>::push_back(&startScripts, v7);
      pi = result.pn.pi_;
      LOBYTE(v23) = 0;
      if ( result.pn.pi_ && !_InterlockedExchangeAdd(&result.pn.pi_->use_count_, 0xFFFFFFFF) )
      {
        pi->dispose(pi);
        if ( !_InterlockedExchangeAdd(&pi->weak_count_, 0xFFFFFFFF) )
          pi->destroy(pi);
      }
      std::_Tree<std::_Tset_traits<RBX::Script *,std::less<RBX::Script *>,std::allocator<RBX::Script *>,0>>::const_iterator::_Inc((std::_Tree<std::_Tset_traits<RBX::Instance const *,std::less<RBX::Instance const *>,std::allocator<RBX::Instance const *>,0> >::const_iterator *)&iter);
      Left = iter._Ptr;
      p_pendingScripts = (std::_Tree_nod<std::_Tset_traits<RBX::Script *,std::less<RBX::Script *>,std::allocator<RBX::Script *>,0> >::_Node **)iter._Mycont;
    }
    std::_Tree<std::_Tset_traits<RBX::IMoving *,std::less<RBX::IMoving *>,std::allocator<RBX::IMoving *>,0>>::_Erase(
      (std::_Tree<std::_Tset_traits<RBX::Instance const *,std::less<RBX::Instance const *>,std::allocator<RBX::Instance const *>,0> > *)&this->pendingScripts,
      (std::_Tree_nod<std::_Tset_traits<RBX::Instance const *,std::less<RBX::Instance const *>,std::allocator<RBX::Instance const *>,0> >::_Node *)this->pendingScripts._Myhead->_Parent);
    v9 = result.pn.pi_;
    this->pendingScripts._Myhead->_Parent = this->pendingScripts._Myhead;
    v10 = this->pendingScripts._Myhead;
    this->pendingScripts._Mysize = 0;
    v10->_Left = v10;
    this->pendingScripts._Myhead->_Right = this->pendingScripts._Myhead;
    scriptContext = this->scriptContext;
    Mylast = startScripts._Mylast;
    Myfirst = startScripts._Myfirst;
    v22.l_.a2_.f_.f_ = boost::shared_ptr<RBX::Script>::get;
    v17 = startScripts._Mylast;
    if ( startScripts._Myfirst > startScripts._Mylast )
    {
      __invalid_parameter_noinfo();
      Mylast = startScripts._Mylast;
      Myfirst = startScripts._Myfirst;
    }
    iter._Mycont = (const std::_Container_base *)Myfirst;
    if ( Myfirst > Mylast )
      __invalid_parameter_noinfo();
    v16.f_.f_ = RBX::ScriptContext::addScript;
    *((_DWORD *)&v16.f_.f_ + 1) = 0;
    *(_QWORD *)&v16.l_.a1_.t_ = __PAIR64__((unsigned int)v22.l_.a2_.f_.f_, (unsigned int)scriptContext);
    *(_QWORD *)&v16.l_.a2_.l_.boost::_bi::storage1<boost::arg<1> > = __PAIR64__(
                                                                       *((unsigned int *)&v22.l_ + 3),
                                                                       (unsigned int)v9);
    v15._Myptr = v17;
    v15._Mycont = &startScripts;
    v14._Myptr = (boost::shared_ptr<RBX::Script> *)iter._Mycont;
    v14._Mycont = &startScripts;
    std::for_each<std::_Vector_iterator<boost::shared_ptr<RBX::Script>>,boost::_bi::bind_t<void,boost::_mfi::mf1<void,RBX::ScriptContext,RBX::Script *>,boost::_bi::list2<boost::_bi::value<RBX::ScriptContext *>,boost::_bi::bind_t<RBX::Script *,boost::_mfi::cmf0<RBX::Script *,boost::shared_ptr<RBX::Script>>,boost::_bi::list1<boost::arg<1>>>>>>(
      &v22,
      v14,
      v15,
      v16);
    v23 = -1;
    if ( startScripts._Myfirst )
    {
      std::_Destroy_range<boost::shared_ptr<RBX::Script>>(
        startScripts._Myfirst,
        startScripts._Mylast,
        &startScripts._Alval,
        (std::_Nonscalar_ptr_iterator_tag)iter._Mycont);
      operator delete(startScripts._Myfirst);
    }
  }
}
