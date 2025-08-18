void __cdecl RBX::httpGetPost(
        bool isPost,
        int url,
        std::istream *data,
        bool compressData,
        const char *additionalHeaders,
        std::string *response)
{
  void *v6; // esp
  const std::string *v7; // ebx
  unsigned int v8; // eax
  std::string::_Bxty *v9; // edi
  std::string::_Bxty *Ptr; // eax
  const std::string *v11; // eax
  const char *Buf; // eax
  const std::string *v13; // eax
  const char *v14; // eax
  HINTERNET v15; // esi
  const std::string *v16; // eax
  BOOL (__stdcall *v17)(HINTERNET, LPCSTR, DWORD, DWORD); // ebx
  std::string::_Bxty *p_Bx; // eax
  const boost::iostreams::basic_gzip_compressor<std::allocator<char> > *v19; // eax
  unsigned int Mysize; // edi
  std::string::_Bxty *v21; // eax
  std::string::_Bxty *v22; // eax
  int *os; // eax
  std::string::_Bxty *v24; // eax
  std::string::_Bxty *v25; // eax
  RBX::MD5Hasher *v26; // edi
  void (__thiscall *addData)(RBX::MD5Hasher *, const std::string *); // edx
  const char *v28; // eax
  std::string::_Bxty *v29; // eax
  std::string::_Bxty *v30; // eax
  int v31; // eax
  char v32; // bl
  const boost::iostreams::basic_gzip_decompressor<std::allocator<char> > *v33; // eax
  const std::string *v34; // eax
  std::string v35; // [esp-4Ch] [ebp-1798h] BYREF
  std::string v36; // [esp-30h] [ebp-177Ch] BYREF
  __int64 v37; // [esp-14h] [ebp-1760h]
  int v38; // [esp-Ch] [ebp-1758h] BYREF
  ATL::CUrl v39; // [esp+0h] [ebp-174Ch] BYREF
  char v40[256]; // [esp+1244h] [ebp-508h] BYREF
  char Buffer[256]; // [esp+1344h] [ebp-408h] BYREF
  boost::iostreams::gzip_params p; // [esp+1444h] [ebp-308h] BYREF
  std::runtime_error v43; // [esp+149Ch] [ebp-2B0h] BYREF
  std::runtime_error v44; // [esp+14C4h] [ebp-288h] BYREF
  std::runtime_error v45; // [esp+14ECh] [ebp-260h] BYREF
  std::runtime_error pExceptionObject; // [esp+1514h] [ebp-238h] BYREF
  std::runtime_error v47; // [esp+153Ch] [ebp-210h] BYREF
  std::runtime_error v48; // [esp+158Ch] [ebp-1C0h] BYREF
  std::runtime_error v49; // [esp+15DCh] [ebp-170h] BYREF
  std::runtime_error v50; // [esp+162Ch] [ebp-120h] BYREF
  boost::iostreams::filtering_stream<boost::iostreams::input,char,std::char_traits<char>,std::allocator<char>,boost::iostreams::public_> v51; // [esp+1654h] [ebp-F8h] BYREF
  std::string result; // [esp+16A0h] [ebp-ACh] BYREF
  boost::iostreams::basic_gzip_decompressor<std::allocator<char> > v53; // [esp+16C8h] [ebp-84h] BYREF
  std::string v54; // [esp+1720h] [ebp-2Ch] BYREF
  int *v55; // [esp+173Ch] [ebp-10h]
  int v56; // [esp+1748h] [ebp-4h]
  CHINTERNET request; // [esp+174Ch] [ebp+0h]
  CHINTERNET session; // [esp+1750h] [ebp+4h]
  std::string uploadData; // [esp+1754h] [ebp+8h] BYREF
  boost::scoped_ptr<RBX::MD5Hasher> hasher; // [esp+1770h] [ebp+24h]
  unsigned int statusCode; // [esp+1774h] [ebp+28h] BYREF
  CHINTERNET connection; // [esp+1778h] [ebp+2Ch]
  std::string contentSizeHeader; // [esp+177Ch] [ebp+30h] BYREF
  ATL::CStringT<char,ATL::StrTraitATL<char,ATL::ChTraitsCRT<char> > > s; // [esp+1798h] [ebp+4Ch] BYREF
  unsigned int length; // [esp+179Ch] [ebp+50h] BYREF

  v6 = alloca(5948);
  v7 = (const std::string *)url;
  v8 = *(_DWORD *)(url + 20);
  v55 = &v38;
  if ( !v8 )
  {
    std::string::string(&contentSizeHeader, "empty url");
    v56 = 0;
    std::runtime_error::runtime_error(&pExceptionObject, &contentSizeHeader);
    _CxxThrowException(&pExceptionObject, (_ThrowInfo *)&_TI2_AVruntime_error_std__);
  }
  v9 = (std::string::_Bxty *)(url + 4);
  if ( *(_DWORD *)(url + 24) < 0x10u )
    Ptr = (std::string::_Bxty *)(url + 4);
  else
    Ptr = (std::string::_Bxty *)v9->_Ptr;
  if ( !RBX::Http::trustCheck(Ptr->_Buf) )
  {
    if ( v7->_Myres >= 0x10 )
      v9 = (std::string::_Bxty *)v9->_Ptr;
    v11 = G3D::format(&contentSizeHeader, "trust check failed for %s", v9->_Buf);
    v56 = 1;
    std::runtime_error::runtime_error(&v50, v11);
    _CxxThrowException(&v50, (_ThrowInfo *)&_TI2_AVruntime_error_std__);
  }
  ATL::CUrl::CUrl(&v39);
  if ( v7->_Myres < 0x10 )
    Buf = v7->_Bx._Buf;
  else
    Buf = v9->_Ptr;
  ATL::CUrl::CrackUrl(&v39, Buf, 0);
  if ( !v39.m_dwHostNameLength )
  {
    if ( v7->_Myres >= 0x10 )
      v9 = (std::string::_Bxty *)v9->_Ptr;
    v13 = G3D::format(&contentSizeHeader, "'%s' is missing a hostName", v9->_Buf);
    v56 = 2;
    std::runtime_error::runtime_error(&v49, v13);
    _CxxThrowException(&v49, (_ThrowInfo *)&_TI2_AVruntime_error_std__);
  }
  session.handle = InternetOpenA("Roblox", 0, 0, 0, 0);
  v56 = 3;
  connection.handle = InternetConnectA(
                        session.handle,
                        v39.m_szHostName,
                        v39.m_nPortNumber,
                        v39.m_szUserName,
                        v39.m_szPassword,
                        3u,
                        0,
                        1u);
  LOBYTE(v56) = 4;
  ATL::CStringT<char,ATL::StrTraitATL<char,ATL::ChTraitsCRT<char>>>::CStringT<char,ATL::StrTraitATL<char,ATL::ChTraitsCRT<char>>>(
    &s,
    v39.m_szUrlPath);
  LOBYTE(v56) = 5;
  ATL::CStringT<char,ATL::StrTraitATL<char,ATL::ChTraitsCRT<char>>>::operator+=(&s, v39.m_szExtraInfo);
  v14 = "POST";
  if ( !isPost )
    v14 = "GET";
  v15 = HttpOpenRequestA(connection.handle, v14, s.m_pszData, 0, 0, 0, 0x20400010u, 1u);
  request.handle = v15;
  LOBYTE(v56) = 6;
  if ( !v15 )
  {
    if ( v7->_Myres >= 0x10 )
      v9 = (std::string::_Bxty *)v9->_Ptr;
    v16 = G3D::format(&contentSizeHeader, "HttpOpenRequest failed for %s", v9->_Buf);
    LOBYTE(v56) = 7;
    std::runtime_error::runtime_error(&v45, v16);
    _CxxThrowException(&v45, (_ThrowInfo *)&_TI2_AVruntime_error_std__);
  }
  if ( additionalHeaders )
  {
    v17 = HttpAddRequestHeadersA;
    if ( !HttpAddRequestHeadersA(v15, additionalHeaders, strlen(additionalHeaders), 0x20000000u) )
      RBX::ThrowIfFailure(0, "HttpAddRequestHeaders failed");
  }
  else
  {
    v17 = HttpAddRequestHeadersA;
  }
  if ( !v17(v15, "Accept-Encoding: gzip\r\n", strlen("Accept-Encoding: gzip\r\n"), 0x20000000u) )
    RBX::ThrowIfFailure(0, "HttpAddRequestHeaders failed");
  v37 = 0i64;
  length = (unsigned int)&v36;
  std::string::string(&v36, hostAddress);
  hasher.ptr = (RBX::MD5Hasher *)&v35;
  LOBYTE(v56) = 8;
  std::string::string(&v35, hostAddress);
  LOBYTE(v56) = 6;
  boost::iostreams::gzip_params::gzip_params(
    &p,
    boost::iostreams::zlib::default_compression,
    boost::iostreams::zlib::deflated,
    15,
    8,
    boost::iostreams::zlib::default_strategy,
    v35,
    v36,
    v37);
  LOBYTE(v56) = 9;
  if ( isPost )
  {
    std::string::string(&uploadData);
    HIDWORD(v37) = 1;
    LOBYTE(v56) = 11;
    boost::iostreams::filtering_stream<boost::iostreams::output,char,std::char_traits<char>,std::allocator<char>,boost::iostreams::public_>::filtering_stream<boost::iostreams::output,char,std::char_traits<char>,std::allocator<char>,boost::iostreams::public_>((boost::iostreams::filtering_stream<boost::iostreams::output,char,std::char_traits<char>,std::allocator<char>,boost::iostreams::public_> *)(&v53.file_name_._Bx._Ptr + 1));
    LOBYTE(v56) = 12;
    if ( compressData )
    {
      std::string::string(&v54, "Content-Encoding: gzip\r\n");
      p_Bx = (std::string::_Bxty *)v54._Bx._Ptr;
      LOBYTE(v56) = 13;
      if ( v54._Myres < 0x10 )
        p_Bx = &v54._Bx;
      if ( !v17(v15, p_Bx->_Buf, v54._Mysize, 0x20000000u) )
        RBX::ThrowIfFailure(0, "HttpAddRequestHeaders failed");
      boost::iostreams::basic_gzip_compressor<std::allocator<char>>::basic_gzip_compressor<std::allocator<char>>(
        (boost::iostreams::basic_gzip_compressor<std::allocator<char> > *)&v51.chain_,
        &p,
        4096);
      LOBYTE(v56) = 14;
      boost::iostreams::detail::chain_base<boost::iostreams::chain<boost::iostreams::output,char,std::char_traits<char>,std::allocator<char>>,char,std::char_traits<char>,std::allocator<char>,boost::iostreams::output>::push_impl<boost::iostreams::basic_gzip_compressor<std::allocator<char>>>(
        *((boost::iostreams::detail::chain_base<boost::iostreams::chain<boost::iostreams::output,char,std::char_traits<char>,std::allocator<char> >,char,std::char_traits<char>,std::allocator<char>,boost::iostreams::output> **)&v53.file_name_._Bx._Ptr
        + 2),
        v19,
        -1,
        -1);
      LOBYTE(v56) = 13;
      boost::iostreams::basic_gzip_compressor<std::allocator<char>>::~basic_gzip_compressor<std::allocator<char>>((boost::iostreams::basic_gzip_decompressor<std::allocator<char> > *)&v51.chain_);
      LOBYTE(v56) = 12;
      std::string::~string(&v54);
    }
    length = (unsigned int)&uploadData;
    boost::iostreams::detail::chain_base<boost::iostreams::chain<boost::iostreams::output,char,std::char_traits<char>,std::allocator<char>>,char,std::char_traits<char>,std::allocator<char>,boost::iostreams::output>::push_impl<String_sink>(
      *((boost::iostreams::detail::chain_base<boost::iostreams::chain<boost::iostreams::output,char,std::char_traits<char>,std::allocator<char> >,char,std::char_traits<char>,std::allocator<char>,boost::iostreams::output> **)&v53.file_name_._Bx._Ptr
      + 2),
      (const String_sink *)&length,
      -1,
      -1);
    boost::iostreams::detail::copy_impl<boost::reference_wrapper<std::istream>,boost::reference_wrapper<boost::iostreams::filtering_stream<boost::iostreams::output,char,std::char_traits<char>,std::allocator<char>,boost::iostreams::public_>>>(
      (boost::reference_wrapper<std::istream >)data,
      (boost::reference_wrapper<boost::iostreams::filtering_stream<boost::iostreams::output,char,std::char_traits<char>,std::allocator<char>,boost::iostreams::public_> >)(&v53.file_name_._Bx._Ptr + 1),
      4096);
    LOBYTE(v56) = 11;
    boost::iostreams::filtering_stream<boost::iostreams::output,char,std::char_traits<char>,std::allocator<char>,boost::iostreams::public_>::`vbase destructor'((boost::iostreams::filtering_stream<boost::iostreams::output,char,std::char_traits<char>,std::allocator<char>,boost::iostreams::public_> *)(&v53.file_name_._Bx._Ptr + 1));
    Mysize = uploadData._Mysize;
    v56 = 10;
    length = uploadData._Mysize;
    if ( uploadData._Mysize > 0x2710 )
    {
      G3D::format(&contentSizeHeader, "Roblox-Content-Size: %d\r\n", uploadData._Mysize);
      v21 = (std::string::_Bxty *)contentSizeHeader._Bx._Ptr;
      LOBYTE(v56) = 17;
      if ( contentSizeHeader._Myres < 0x10 )
        v21 = &contentSizeHeader._Bx;
      if ( !v17(v15, v21->_Buf, contentSizeHeader._Mysize, 0x20000000u) )
        RBX::ThrowIfFailure(0, "HttpAddRequestHeaders failed");
      v22 = (std::string::_Bxty *)uploadData._Bx._Ptr;
      if ( uploadData._Myres < 0x10 )
        v22 = &uploadData._Bx;
      G3D::format((std::string *)&v53.comment_._Myres, "Roblox-Content-First: %d\r\n", v22->_Buf[0]);
      os = (int *)v53.os_;
      LOBYTE(v56) = 18;
      if ( *(&v53.flags_ + 1) < 0x10u )
        os = &v53.os_;
      if ( !v17(v15, (LPCSTR)os, v53.flags_, 0x20000000u) )
        RBX::ThrowIfFailure(0, "HttpAddRequestHeaders failed");
      v24 = (std::string::_Bxty *)uploadData._Bx._Ptr;
      if ( uploadData._Myres < 0x10 )
        v24 = &uploadData._Bx;
      G3D::format(&result, "Roblox-Content-Last: %d\r\n", v24->_Buf[Mysize - 1]);
      v25 = (std::string::_Bxty *)result._Bx._Ptr;
      LOBYTE(v56) = 19;
      if ( result._Myres < 0x10 )
        v25 = &result._Bx;
      if ( !v17(v15, v25->_Buf, result._Mysize, 0x20000000u) )
        RBX::ThrowIfFailure(0, "HttpAddRequestHeaders failed");
      v26 = RBX::MD5Hasher::create();
      hasher.ptr = v26;
      addData = v26->addData;
      LOBYTE(v56) = 20;
      addData(v26, &uploadData);
      v28 = v26->c_str(v26);
      G3D::format(&v54, "Roblox-Content-Hash: %s\r\n", v28);
      v29 = (std::string::_Bxty *)v54._Bx._Ptr;
      LOBYTE(v56) = 21;
      if ( v54._Myres < 0x10 )
        v29 = &v54._Bx;
      if ( !v17(v15, v29->_Buf, v54._Mysize, 0x20000000u) )
        RBX::ThrowIfFailure(0, "HttpAddRequestHeaders failed");
      LOBYTE(v56) = 20;
      std::string::~string(&v54);
      operator delete(v26);
      LOBYTE(v56) = 18;
      std::string::~string(&result);
      LOBYTE(v56) = 17;
      std::string::~string(&v53.comment_._Myres);
      LOBYTE(v56) = 10;
      std::string::~string(&contentSizeHeader);
      Mysize = length;
    }
    memset(&v53.comment_._Mysize, 0, 20);
    v53.flags_ = 0;
    *(&v53.flags_ + 1) = 0;
    *((_QWORD *)&v53.comment_._Bx._Ptr + 1) = 40i64;
    HIDWORD(v53.mtime_) = Mysize;
    if ( !HttpSendRequestExA(v15, (LPINTERNET_BUFFERSA)(&v53.comment_._Bx._Ptr + 2), 0, 0, 0) )
    {
      std::string::string(&contentSizeHeader, "HttpSendRequestEx failed");
      LOBYTE(v56) = 22;
      std::runtime_error::runtime_error(&v48, &contentSizeHeader);
      _CxxThrowException(&v48, (_ThrowInfo *)&_TI2_AVruntime_error_std__);
    }
    v30 = (std::string::_Bxty *)uploadData._Bx._Ptr;
    LOBYTE(v56) = 23;
    if ( uploadData._Myres < 0x10 )
      v30 = &uploadData._Bx;
    if ( !InternetWriteFile(v15, v30, Mysize, &length) )
      RBX::ThrowIfFailure(0, "InternetWriteFile failed");
    if ( length != Mysize )
    {
      std::string::string(&contentSizeHeader, "Failed to upload content");
      LOBYTE(v56) = 24;
      std::runtime_error::runtime_error(&v43, &contentSizeHeader);
      _CxxThrowException(&v43, (_ThrowInfo *)&_TI2_AVruntime_error_std__);
    }
    v56 = 10;
    if ( !HttpEndRequestA(v15, 0, 0, 0) )
      RBX::ThrowIfFailure(0, "HttpEndRequest failed");
    LOBYTE(v56) = 9;
    std::string::~string(&uploadData);
  }
  else if ( !HttpSendRequestA(v15, 0, 0, 0, 0) )
  {
    RBX::ThrowIfFailure(0, "HttpSendRequest failed");
  }
  length = 4;
  if ( !HttpQueryInfoA(v15, 0x20000013u, &statusCode, &length, 0) )
    RBX::ThrowIfFailure(0, "HttpQueryInfo failed");
  HIDWORD(v37) = 1;
  LOBYTE(v56) = 26;
  boost::iostreams::filtering_stream<boost::iostreams::input,char,std::char_traits<char>,std::allocator<char>,boost::iostreams::public_>::filtering_stream<boost::iostreams::input,char,std::char_traits<char>,std::allocator<char>,boost::iostreams::public_>(&v51);
  LOBYTE(v56) = 27;
  length = 256;
  if ( HttpQueryInfoA(v15, 0x1Du, Buffer, &length, 0) )
  {
    v31 = std::string::string(&contentSizeHeader, Buffer);
    LOBYTE(v56) = 28;
    v32 = std::operator==<char>(v31, "gzip");
    LOBYTE(v56) = 27;
    std::string::~string(&contentSizeHeader);
    if ( v32 )
    {
      boost::iostreams::basic_gzip_decompressor<std::allocator<char>>::basic_gzip_decompressor<std::allocator<char>>(
        &v53,
        15,
        4096);
      LOBYTE(v56) = 29;
      boost::iostreams::detail::chain_base<boost::iostreams::chain<boost::iostreams::input,char,std::char_traits<char>,std::allocator<char>>,char,std::char_traits<char>,std::allocator<char>,boost::iostreams::input>::push_impl<boost::iostreams::basic_gzip_decompressor<std::allocator<char>>>(
        v51.chain_,
        v33,
        -1,
        -1);
      LOBYTE(v56) = 27;
      boost::iostreams::basic_gzip_compressor<std::allocator<char>>::~basic_gzip_compressor<std::allocator<char>>(&v53);
    }
  }
  length = (unsigned int)v15;
  boost::iostreams::detail::chain_base<boost::iostreams::chain<boost::iostreams::input,char,std::char_traits<char>,std::allocator<char>>,char,std::char_traits<char>,std::allocator<char>,boost::iostreams::input>::push_impl<HttpRequest_source>(
    v51.chain_,
    (const HttpRequest_source *)&length,
    -1,
    -1);
  boost::iostreams::detail::copy_impl<boost::reference_wrapper<boost::iostreams::filtering_stream<boost::iostreams::input,char,std::char_traits<char>,std::allocator<char>,boost::iostreams::public_>>,String_sink>(
    (boost::reference_wrapper<boost::iostreams::filtering_stream<boost::iostreams::input,char,std::char_traits<char>,std::allocator<char>,boost::iostreams::public_> >)&v51,
    (String_sink)response,
    4096);
  LOBYTE(v56) = 26;
  boost::iostreams::filtering_stream<boost::iostreams::input,char,std::char_traits<char>,std::allocator<char>,boost::iostreams::public_>::`vbase destructor'(&v51);
  v56 = 9;
  if ( statusCode != 200 )
  {
    url = 512;
    if ( HttpQueryInfoA(v15, 0x14u, v40, (LPDWORD)&url, 0) )
    {
      std::string::string(&contentSizeHeader, v40);
      LOBYTE(v56) = 33;
      std::runtime_error::runtime_error(&v47, &contentSizeHeader);
      _CxxThrowException(&v47, (_ThrowInfo *)&_TI2_AVruntime_error_std__);
    }
    v34 = G3D::format((std::string *)&v53.comment_._Myres, "statusCode = %d", statusCode);
    LOBYTE(v56) = 34;
    std::runtime_error::runtime_error(&v44, v34);
    _CxxThrowException(&v44, (_ThrowInfo *)&_TI2_AVruntime_error_std__);
  }
  LOBYTE(v56) = 6;
  boost::iostreams::gzip_params::~gzip_params(&p);
  InternetCloseHandle(v15);
  ATL::CPathT<ATL::CStringT<char,ATL::StrTraitATL<char,ATL::ChTraitsCRT<char>>>>::~CPathT<ATL::CStringT<char,ATL::StrTraitATL<char,ATL::ChTraitsCRT<char>>>>((ATL::CPathT<ATL::CStringT<char,ATL::StrTraitATL<char,ATL::ChTraitsCRT<char> > > > *)&s);
  InternetCloseHandle(connection.handle);
  InternetCloseHandle(session.handle);
}
