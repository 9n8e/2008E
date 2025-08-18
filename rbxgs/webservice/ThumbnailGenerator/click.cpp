std::string *__thiscall ThumbnailGenerator::click(
        ThumbnailGenerator *this,
        std::string *result,
        std::string fileType,
        std::ostreambuf_iterator<char> _To)
{
  const char *v4; // esi
  boost::shared_ptr<RBX::StandardOut> *v5; // eax
  std::string::_Bxty *Ptr; // ecx
  unsigned int v7; // edi
  const std::_Container_base *Mycont; // ebx
  boost::detail::sp_counted_base *pi; // esi
  const char *Myptr; // esi
  ThumbnailGenerator *v11; // ecx
  RBX::ContentProvider *v12; // eax
  ThumbnailGenerator *v13; // ecx
  size_t v14; // esi
  std::string::_Bxty *p_Bx; // eax
  unsigned int v16; // ebx
  int *v17; // esi
  _DWORD *v18; // eax
  int v19; // edx
  base64<char,std::char_traits<char> > *v20; // ecx
  boost::shared_ptr<RBX::StandardOut> *v21; // eax
  boost::detail::sp_counted_base *v22; // esi
  std::string *v23; // esi
  _BYTE v25[32]; // [esp-30h] [ebp-108h] BYREF
  __int128 v26; // [esp-10h] [ebp-E8h] BYREF
  base64<char,std::char_traits<char> >::noline v27; // [esp+0h] [ebp-D8h] BYREF
  std::basic_stringstream<char,std::char_traits<char>,std::allocator<char> > encodedResult; // [esp+10h] [ebp-C8h] BYREF
  char v29[8]; // [esp+98h] [ebp-40h] BYREF
  std::ostreambuf_iterator<char> _Out; // [esp+A0h] [ebp-38h]
  std::string *v31; // [esp+B0h] [ebp-28h]
  int v32; // [esp+B4h] [ebp-24h]
  std::_String_iterator<char,std::char_traits<char>,std::allocator<char> > v33; // [esp+B8h] [ebp-20h] BYREF
  boost::shared_ptr<RBX::StandardOut> v34; // [esp+C0h] [ebp-18h] BYREF
  base64<char,std::char_traits<char> >::noline *v35; // [esp+C8h] [ebp-10h]
  int v36; // [esp+D4h] [ebp-4h]
  G3D::BinaryOutput binaryOutput; // [esp+D8h] [ebp+0h] BYREF
  std::string resulta; // [esp+120h] [ebp+48h] BYREF

  v35 = &v27;
  v33._Myptr = (const char *)this;
  v31 = result;
  v32 = 0;
  v36 = 2;
  v4 = "true";
  if ( !LOBYTE(_To._Strbuf) )
    v4 = "false";
  v5 = RBX::StandardOut::singleton(&v34);
  LOBYTE(v36) = 3;
  Ptr = (std::string::_Bxty *)fileType._Bx._Ptr;
  if ( fileType._Myres < 0x10 )
    Ptr = &fileType._Bx;
  v7 = *(_DWORD *)&_To._Failed;
  Mycont = _To._Mycont;
  RBX::StandardOut::print(
    v5->px,
    MESSAGE_INFO,
    "ThumbnailGenerator::click(%s, %d, %d, %s)",
    Ptr->_Buf,
    _To._Mycont,
    *(_DWORD *)&_To._Failed,
    v4);
  LOBYTE(v36) = 2;
  pi = v34.pn.pi_;
  if ( v34.pn.pi_ )
  {
    if ( !_InterlockedExchangeAdd(&v34.pn.pi_->use_count_, 0xFFFFFFFF) )
    {
      pi->dispose(pi);
      if ( !_InterlockedExchangeAdd(&pi->weak_count_, 0xFFFFFFFF) )
        pi->destroy(pi);
    }
  }
  G3D::BinaryOutput::BinaryOutput(&binaryOutput);
  LOBYTE(v36) = 4;
  G3D::BinaryOutput::setEndian(&binaryOutput, G3D_LITTLE_ENDIAN);
  *((_QWORD *)&v26 + 1) = (unsigned int)_To._Strbuf;
  *(_QWORD *)&v26 = __PAIR64__(v7, (unsigned int)Mycont);
  v34.pn.pi_ = (boost::detail::sp_counted_base *)&v25[4];
  std::string::string(&fileType);
  Myptr = v33._Myptr;
  *(_DWORD *)v25 = v33._Myptr;
  ThumbnailGenerator::doClick(
    v11,
    *(std::string *)v25,
    *(int *)&v25[28],
    v26,
    SBYTE4(v26),
    (G3D::BinaryOutput *)DWORD2(v26));
  v12 = RBX::ServiceProvider::create<RBX::ContentProvider>((const RBX::Instance *)Myptr);
  v34.pn.pi_ = (boost::detail::sp_counted_base *)((char *)&v26 + 8);
  RBX::shared_from<RBX::DataModel>((boost::shared_ptr<RBX::ContentProvider> *)&v26 + 1, v12);
  waitForContent(*((boost::shared_ptr<RBX::ContentProvider> *)&v26 + 1));
  *((_QWORD *)&v26 + 1) = __PAIR64__(&binaryOutput, (unsigned int)_To._Strbuf);
  *(_QWORD *)&v26 = __PAIR64__(v7, (unsigned int)Mycont);
  v34.pn.pi_ = (boost::detail::sp_counted_base *)&v25[4];
  std::string::string(&fileType);
  *(_DWORD *)v25 = Myptr;
  ThumbnailGenerator::doClick(
    v13,
    *(std::string *)v25,
    *(int *)&v25[28],
    v26,
    SBYTE4(v26),
    (G3D::BinaryOutput *)DWORD2(v26));
  v14 = binaryOutput.bufferLen + binaryOutput.alreadyWritten;
  std::string::string(&resulta);
  LOBYTE(v36) = 5;
  std::string::resize(&resulta, v14);
  p_Bx = (std::string::_Bxty *)resulta._Bx._Ptr;
  if ( resulta._Myres < 0x10 )
    p_Bx = &resulta._Bx;
  memcpy(p_Bx, binaryOutput.buffer, v14);
  std::basic_stringstream<char,std::char_traits<char>,std::allocator<char>>::basic_stringstream<char,std::char_traits<char>,std::allocator<char>>(
    &encodedResult,
    3,
    1);
  LOBYTE(v36) = 6;
  v16 = *(_DWORD *)&encodedResult.gap8[*(_DWORD *)(*(_DWORD *)encodedResult.gap8 + 4) + 40];
  _Out._Failed = 0;
  LOBYTE(v33._Myptr) = 0;
  v17 = (int *)std::string::end(&resulta, &v34);
  v18 = (_DWORD *)std::string::begin(&resulta, v29);
  LODWORD(v26) = 0;
  DWORD1(v26) = *(_DWORD *)&_Out._Failed;
  v19 = *v17;
  *((_QWORD *)&v26 + 1) = __PAIR64__((unsigned int)v33._Myptr, v16);
  *(_DWORD *)&v25[28] = v17[1];
  v20 = (base64<char,std::char_traits<char> > *)v18[1];
  *(_DWORD *)&v25[24] = v19;
  base64<char,std::char_traits<char>>::put<std::_String_iterator<char,std::char_traits<char>,std::allocator<char>>,std::ostreambuf_iterator<char>,int,base64<char,std::char_traits<char>>::noline>(
    v20,
    &v33,
    (std::_String_iterator<char,std::char_traits<char>,std::allocator<char> >)__PAIR64__((unsigned int)v20, *v18),
    *(std::_String_iterator<char,std::char_traits<char>,std::allocator<char> > *)&v25[24],
    (std::ostreambuf_iterator<char>)v26,
    (int *)v33._Myptr,
    v27);
  v21 = RBX::StandardOut::singleton(&v34);
  LOBYTE(v36) = 7;
  RBX::StandardOut::print(v21->px, MESSAGE_INFO, "ThumbnailGenerator::click() success");
  LOBYTE(v36) = 6;
  v22 = v34.pn.pi_;
  if ( v34.pn.pi_ )
  {
    if ( !_InterlockedExchangeAdd(&v34.pn.pi_->use_count_, 0xFFFFFFFF) )
    {
      v22->dispose(v22);
      if ( !_InterlockedExchangeAdd(&v22->weak_count_, 0xFFFFFFFF) )
        v22->destroy(v22);
    }
  }
  v23 = v31;
  std::basic_stringstream<char,std::char_traits<char>,std::allocator<char>>::str(&encodedResult, v31);
  v32 = 1;
  LOBYTE(v36) = 5;
  std::basic_stringstream<char,std::char_traits<char>,std::allocator<char>>::`vbase destructor'(&encodedResult);
  LOBYTE(v36) = 4;
  std::string::~string(&resulta);
  LOBYTE(v36) = 2;
  G3D::BinaryOutput::~BinaryOutput(&binaryOutput);
  LOBYTE(v36) = 0;
  std::string::~string(&fileType);
  return v23;
}
