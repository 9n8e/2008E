std::string *__thiscall ThumbnailGenerator::clickTexture(
        ThumbnailGenerator *this,
        std::string *result,
        std::string textureId,
        std::string fileType,
        int cx,
        int cy)
{
  boost::shared_ptr<RBX::StandardOut> *v6; // eax
  std::string::_Bxty *Ptr; // edx
  std::string::_Bxty *p_Bx; // ecx
  int v9; // ebx
  int v10; // edi
  volatile signed __int32 *v11; // esi
  RBX::Instance *v12; // esi
  RBX::ContentProvider *v13; // eax
  int v14; // ecx
  void (__thiscall *v15)(_BYTE *); // eax
  const G3D::Matrix4 *v16; // eax
  bool v17; // bl
  size_t v18; // esi
  std::string::_Bxty *v19; // eax
  unsigned int v20; // ebx
  int v21; // esi
  _DWORD *v22; // eax
  char *v23; // edx
  base64<char,std::char_traits<char> > *v24; // ecx
  boost::shared_ptr<RBX::StandardOut> *v25; // eax
  volatile signed __int32 *Myptr; // esi
  std::string *v27; // esi
  OSContext *v28; // ecx
  RBX::ContentId v30; // [esp-4h] [ebp-168h] BYREF
  int v31; // [esp+1Ch] [ebp-148h] BYREF
  std::basic_stringstream<char,std::char_traits<char>,std::allocator<char> > encodedResult; // [esp+2Ch] [ebp-138h] BYREF
  OSContext context; // [esp+B4h] [ebp-B0h] BYREF
  RBX::AdornG3D a; // [esp+E8h] [ebp-7Ch] BYREF
  RBX::TextureId v35; // [esp+10Ch] [ebp-58h] BYREF
  std::string *v36; // [esp+12Ch] [ebp-38h]
  int v37; // [esp+130h] [ebp-34h]
  char v38[4]; // [esp+134h] [ebp-30h] BYREF
  RBX::Instance *top; // [esp+138h] [ebp-2Ch]
  char v40[4]; // [esp+13Ch] [ebp-28h] BYREF
  std::auto_ptr<std::istream > right; // [esp+140h] [ebp-24h] BYREF
  boost::detail::thread::scoped_lock<boost::mutex> lock; // [esp+144h] [ebp-20h] BYREF
  std::_String_iterator<char,std::char_traits<char>,std::allocator<char> > v43; // [esp+14Ch] [ebp-18h] BYREF
  int *v44; // [esp+154h] [ebp-10h]
  int v45; // [esp+160h] [ebp-4h]
  G3D::RenderDevice renderDevice; // [esp+164h] [ebp+0h] BYREF
  G3D::Matrix4 v47; // [esp+A14h] [ebp+8B0h] BYREF
  G3D::BinaryOutput binaryOutput; // [esp+A54h] [ebp+8F0h] BYREF
  std::string resulta; // [esp+A9Ch] [ebp+938h] BYREF

  v44 = &v31;
  top = this;
  v36 = result;
  v37 = 0;
  v45 = 3;
  v6 = RBX::StandardOut::singleton((boost::shared_ptr<RBX::StandardOut> *)&lock);
  LOBYTE(v45) = 4;
  Ptr = (std::string::_Bxty *)fileType._Bx._Ptr;
  if ( fileType._Myres < 0x10 )
    Ptr = &fileType._Bx;
  p_Bx = (std::string::_Bxty *)textureId._Bx._Ptr;
  if ( textureId._Myres < 0x10 )
    p_Bx = &textureId._Bx;
  v9 = cy;
  v10 = cx;
  RBX::StandardOut::print(
    v6->px,
    MESSAGE_INFO,
    "ThumbnailGenerator::clickTexture(%s, %s, %d, %d)",
    p_Bx->_Buf,
    Ptr->_Buf,
    cx,
    cy);
  LOBYTE(v45) = 3;
  v11 = *(volatile signed __int32 **)&lock.m_locked;
  if ( *(_DWORD *)&lock.m_locked )
  {
    if ( !_InterlockedExchangeAdd((volatile signed __int32 *)(*(_DWORD *)&lock.m_locked + 4), 0xFFFFFFFF) )
    {
      (*(void (__thiscall **)(volatile signed __int32 *))(*v11 + 4))(v11);
      if ( !_InterlockedExchangeAdd(v11 + 2, 0xFFFFFFFF) )
        (*(void (__thiscall **)(volatile signed __int32 *))(*v11 + 8))(v11);
    }
  }
  v43._Myptr = (const char *)&v30;
  RBX::ContentId::ContentId(&v30, &textureId);
  LOBYTE(v45) = 5;
  v12 = top;
  v13 = RBX::ServiceProvider::create<RBX::ContentProvider>(top);
  LOBYTE(v45) = 3;
  RBX::ContentProvider::getContent(v13, &right, v30);
  if ( *(float *)&right._Myptr != 0.0 )
  {
    v14 = *(_DWORD *)(*(_DWORD *)right._Myptr->gap0 + 4);
    v15 = **(void (__thiscall ***)(_BYTE *))&right._Myptr->gap0[v14];
    v30.mimeTypePtr = (const RBX::Name *)1;
    v15(&right._Myptr->gap0[v14]);
  }
  G3D::BinaryOutput::BinaryOutput(&binaryOutput);
  LOBYTE(v45) = 6;
  G3D::BinaryOutput::setEndian(&binaryOutput, G3D_LITTLE_ENDIAN);
  v43._Myptr = (const char *)G3D::GImage::stringToFormat(&fileType);
  OSContext::OSContext(&context, v10, v9, 1);
  LOBYTE(v45) = 7;
  boost::call_once(StaticMutex<OSContext>::init, &StaticMutex<OSContext>::initFlag);
  lock.m_mutex = StaticMutex<OSContext>::m;
  lock.m_locked = 0;
  boost::mutex::do_lock(StaticMutex<OSContext>::m);
  lock.m_locked = 1;
  LOBYTE(v45) = 8;
  if ( G3D::GWindow::m_current != &context )
  {
    context.reallyMakeCurrent(&context);
    G3D::GWindow::m_current = &context;
  }
  RBX::Render::Mesh::makeVAR();
  RBX::Render::Mesh::varDirty = 1;
  RBX::Adorn::contentProvider = RBX::ServiceProvider::create<RBX::ContentProvider>(v12);
  G3D::RenderDevice::RenderDevice(&renderDevice);
  LOBYTE(v45) = 9;
  G3D::RenderDevice::init(&renderDevice, &context, 0);
  G3D::RenderDevice::pushState(&renderDevice);
  G3D::RenderDevice::push2D(&renderDevice);
  *(float *)&top = (float)cy;
  *(float *)&right._Myptr = (float)cx;
  v16 = G3D::Matrix4::orthogonalProjection(&v47, 0.0, *(float *)&right._Myptr, 0.0, *(float *)&top, -1.0, 1.0);
  G3D::RenderDevice::setProjectionMatrix(&renderDevice, v16);
  a.renderDevice = &renderDevice;
  a.__vftable = (RBX::AdornG3D_vtbl *)&RBX::AdornG3D::`vftable';
  G3D::TextureManager::TextureManager(&a.textureManager, 0xA00000u);
  LOBYTE(v45) = 10;
  RBX::GuiDrawImage::GuiDrawImage((RBX::GuiDrawImage *)&v47.elt[0][2]);
  LOBYTE(v45) = 11;
  std::string::string(&textureId);
  LOBYTE(v45) = 12;
  v35.mimeTypePtr = RBX::Name::declare<0>();
  LOBYTE(v45) = 13;
  v17 = RBX::GuiDrawImage::setImage((RBX::GuiDrawImage *)&v47.elt[0][2], &a, &v35);
  LOBYTE(v45) = 11;
  std::string::~string(&v35);
  if ( v17 )
  {
    *((float *)&v35.id._Bx._Ptr + 3) = 0.0;
    *(float *)&v35.id._Mysize = 0.0;
    v35.id._Myres = (unsigned int)right._Myptr;
    v35.mimeTypePtr = (const RBX::Name *)top;
    RBX::GuiDrawImage::render2d(
      (RBX::GuiDrawImage *)&v47.elt[0][2],
      &a,
      1,
      (RBX::Rect *)(&v35.id._Bx._Ptr + 3),
      NOTHING);
  }
  LOBYTE(v45) = 10;
  RBX::GuiDrawImage::~GuiDrawImage((RBX::GuiDrawImage *)&v47.elt[0][2]);
  LOBYTE(v45) = 9;
  a.textureManager.cache.__vftable = (G3D::Table<G3D::TextureManager::TextureArgs,G3D::ReferenceCountedPointer<G3D::Texture> >_vtbl *)&G3D::Table<G3D::TextureManager::TextureArgs,G3D::ReferenceCountedPointer<G3D::Texture>>::`vftable';
  G3D::Table<G3D::TextureManager::TextureArgs,G3D::ReferenceCountedPointer<G3D::Texture>>::freeMemory(&a.textureManager.cache);
  G3D::GImage::encode(&context.image, (G3D::GImage::Format)v43._Myptr, &binaryOutput);
  G3D::RenderDevice::pop2D(&renderDevice);
  G3D::RenderDevice::popState(&renderDevice);
  G3D::RenderDevice::cleanup(&renderDevice);
  RBX::Adorn::contentProvider = 0;
  LOBYTE(v45) = 8;
  G3D::RenderDevice::~RenderDevice(&renderDevice);
  v18 = binaryOutput.bufferLen + binaryOutput.alreadyWritten;
  std::string::string(&resulta);
  LOBYTE(v45) = 14;
  std::string::resize(&resulta, v18);
  v19 = (std::string::_Bxty *)resulta._Bx._Ptr;
  if ( resulta._Myres < 0x10 )
    v19 = &resulta._Bx;
  memcpy(v19, binaryOutput.buffer, v18);
  std::basic_stringstream<char,std::char_traits<char>,std::allocator<char>>::basic_stringstream<char,std::char_traits<char>,std::allocator<char>>(
    &encodedResult,
    3,
    1);
  LOBYTE(v45) = 15;
  v20 = *(_DWORD *)&encodedResult.gap8[*(_DWORD *)(*(_DWORD *)encodedResult.gap8 + 4) + 40];
  LOBYTE(v35.id._Myres) = 0;
  LOBYTE(v43._Myptr) = 0;
  v21 = std::string::end(&resulta, v38);
  v22 = (_DWORD *)std::string::begin(&resulta, v40);
  v30.id._Myres = (unsigned int)v43._Myptr;
  *((_DWORD *)&v30.id._Bx._Ptr + 3) = v35.id._Myres;
  v23 = *(char **)v21;
  v30.id._Mysize = v20;
  *(_QWORD *)(&v30.id._Bx._Ptr + 1) = *(unsigned int *)(v21 + 4);
  v24 = (base64<char,std::char_traits<char> > *)v22[1];
  v30.id._Bx._Ptr = v23;
  base64<char,std::char_traits<char>>::put<std::_String_iterator<char,std::char_traits<char>,std::allocator<char>>,std::ostreambuf_iterator<char>,int,base64<char,std::char_traits<char>>::noline>(
    v24,
    &v43,
    (std::_String_iterator<char,std::char_traits<char>,std::allocator<char> >)__PAIR64__((unsigned int)v24, *v22),
    *(std::_String_iterator<char,std::char_traits<char>,std::allocator<char> > *)v30.id._Bx._Buf,
    *(std::ostreambuf_iterator<char> *)(&v30.id._Bx._Ptr + 2),
    (int *)v43._Myptr,
    (base64<char,std::char_traits<char> >::noline)v30.mimeTypePtr);
  v25 = RBX::StandardOut::singleton((boost::shared_ptr<RBX::StandardOut> *)&v43);
  LOBYTE(v45) = 16;
  RBX::StandardOut::print(v25->px, MESSAGE_INFO, "ThumbnailGenerator::click() success");
  LOBYTE(v45) = 15;
  Myptr = (volatile signed __int32 *)v43._Myptr;
  if ( v43._Myptr )
  {
    if ( !_InterlockedExchangeAdd((volatile signed __int32 *)v43._Myptr + 1, 0xFFFFFFFF) )
    {
      (*(void (__thiscall **)(volatile signed __int32 *))(*Myptr + 4))(Myptr);
      if ( !_InterlockedExchangeAdd(Myptr + 2, 0xFFFFFFFF) )
        (*(void (__thiscall **)(volatile signed __int32 *))(*Myptr + 8))(Myptr);
    }
  }
  v27 = v36;
  std::basic_stringstream<char,std::char_traits<char>,std::allocator<char>>::str(&encodedResult, v36);
  v37 = 1;
  LOBYTE(v45) = 14;
  std::basic_stringstream<char,std::char_traits<char>,std::allocator<char>>::`vbase destructor'(&encodedResult);
  LOBYTE(v45) = 8;
  std::string::~string(&resulta);
  LOBYTE(v45) = 7;
  boost::mutex::do_unlock(lock.m_mutex);
  v30.id._Myres = (unsigned int)&context;
  LOBYTE(v45) = 6;
  OSContext::~OSContext(v28);
  LOBYTE(v45) = 3;
  G3D::BinaryOutput::~BinaryOutput(&binaryOutput);
  LOBYTE(v45) = 1;
  std::string::~string(&textureId);
  LOBYTE(v45) = 0;
  std::string::~string(&fileType);
  return v27;
}
