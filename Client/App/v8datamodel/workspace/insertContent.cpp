boost::shared_ptr<std::vector<boost::shared_ptr<RBX::Instance>> const > *__thiscall RBX::Workspace::insertContent(
        RBX::Workspace *this,
        boost::shared_ptr<std::vector<boost::shared_ptr<RBX::Instance>> const > *result,
        RBX::ContentId contentId)
{
  boost::detail::sp_counted_base *v4; // eax
  boost::detail::sp_counted_base *v5; // esi
  boost::shared_ptr<RBX::Instance> *Myend; // edi
  boost::shared_ptr<RBX::Instance> *Mylast; // esi
  std::vector<boost::shared_ptr<RBX::Instance>> *i; // ebp
  boost::detail::sp_counted_base *v9; // esi
  bool v10; // zf
  RBX::ContentId v12; // [esp-2Ch] [ebp-68h] BYREF
  boost::shared_ptr<RBX::Instance> **p_Myfirst; // [esp-Ch] [ebp-48h]
  RBX::InsertMode v14; // [esp-8h] [ebp-44h]
  RBX::PromptMode v15; // [esp-4h] [ebp-40h]
  boost::shared_ptr<std::vector<boost::shared_ptr<RBX::Instance>> > values; // [esp+14h] [ebp-28h]
  std::vector<boost::shared_ptr<RBX::Instance>> items; // [esp+1Ch] [ebp-20h] BYREF
  int v18; // [esp+2Ch] [ebp-10h]
  int v19; // [esp+38h] [ebp-4h]

  values.px = 0;
  v19 = 2;
  items._Mylast = 0;
  items._Myend = 0;
  v18 = 0;
  v15 = SUPPRESS_PROMPTS;
  v14 = INSERT_TO_TREE;
  p_Myfirst = &items._Myfirst;
  values.pn.pi_ = (boost::detail::sp_counted_base *)&v12;
  std::string::string(&contentId);
  v12.mimeTypePtr = contentId.mimeTypePtr;
  RBX::Workspace::insertContent(this, v12, (std::vector<boost::shared_ptr<RBX::Instance>> *)p_Myfirst, v14, v15);
  v4 = (boost::detail::sp_counted_base *)operator new(0x10u);
  if ( v4 )
  {
    v4->use_count_ = 0;
    v4->weak_count_ = 0;
    v4[1].__vftable = 0;
    v5 = v4;
  }
  else
  {
    v5 = 0;
  }
  LOBYTE(v19) = 2;
  values.pn.pi_ = v5;
  boost::detail::shared_count::shared_count(
    (boost::detail::shared_count *)&items,
    (std::vector<boost::shared_ptr<RBX::Instance>> *)v5);
  RBX::Instance::onLastChildRemoved((const boost::detail::shared_count *)&items, v5, v5);
  Myend = items._Myend;
  LOBYTE(v19) = 4;
  if ( items._Mylast > items._Myend )
    __invalid_parameter_noinfo();
  Mylast = items._Mylast;
  if ( items._Mylast > items._Myend )
    __invalid_parameter_noinfo();
  for ( i = (std::vector<boost::shared_ptr<RBX::Instance>> *)values.pn.pi_; Mylast != Myend; ++Mylast )
    RBX::append(Mylast, i);
  v9 = *(boost::detail::sp_counted_base **)&items._Alval.std::_Allocator_base<boost::shared_ptr<RBX::Instance> >;
  v10 = *(_DWORD *)&items._Alval.std::_Allocator_base<boost::shared_ptr<RBX::Instance> > == 0;
  result->px = i;
  result->pn.pi_ = v9;
  if ( !v10 )
    _InterlockedExchangeAdd(&v9->use_count_, 1u);
  values.px = (std::vector<boost::shared_ptr<RBX::Instance>> *)1;
  LOBYTE(v19) = 2;
  if ( v9 )
  {
    if ( !_InterlockedExchangeAdd(&v9->use_count_, 0xFFFFFFFF) )
    {
      v9->dispose(v9);
      if ( !_InterlockedExchangeAdd(&v9->weak_count_, 0xFFFFFFFF) )
        v9->destroy(v9);
    }
  }
  LOBYTE(v19) = 1;
  if ( items._Mylast )
  {
    std::_Destroy_range<boost::shared_ptr<RBX::Instance>>(
      items._Mylast,
      items._Myend,
      (std::allocator<boost::shared_ptr<RBX::Instance> > *)&items._Myfirst,
      (std::_Nonscalar_ptr_iterator_tag)result);
    operator delete(items._Mylast);
  }
  items._Mylast = 0;
  items._Myend = 0;
  v18 = 0;
  LOBYTE(v19) = 0;
  std::string::~string(&contentId);
  return result;
}
