// local variable allocation has failed, the output may be wrong!
void __thiscall ThumbnailGenerator::doClick(
        ThumbnailGenerator *this,
        std::string fileType,
        int cx,
        int cy,
        int hideSky,
        G3D::BinaryOutput *binaryOutput,
        G3D::BinaryOutput *binaryOutputa)
{
  RBX::View::View *ptr; // ebp
  char v8; // bl
  G3D::GImage::Format v9; // esi
  RBX::Lighting *v10; // ecx
  RBX::Workspace *v11; // eax
  RBX::ContentProvider *v12; // edi
  RBX::View::View *v13; // esi
  float v14; // eax
  float v15; // edi
  int v16; // ecx
  int v17; // eax
  int v18; // esi
  int width; // ebp
  int j; // edi
  int k; // eax
  RBX::Workspace *v22; // eax
  OSContext *v23; // ecx
  G3D::Color4 v24[2]; // [esp+0h] [ebp-A58h] BYREF
  bool v25[4]; // [esp+24h] [ebp-A34h]
  float *i; // [esp+28h] [ebp-A30h]
  double i_4; // [esp+2Ch] [ebp-A2Ch] OVERLAPPED
  G3D::GImage::Format v28; // [esp+34h] [ebp-A24h]
  _BYTE s[12]; // [esp+38h] [ebp-A20h] OVERLAPPED BYREF
  G3D::GImage::Format v30; // [esp+44h] [ebp-A14h]
  float v31; // [esp+48h] [ebp-A10h]
  boost::scoped_ptr<RBX::View::View> rbxView; // [esp+4Ch] [ebp-A0Ch]
  float v33; // [esp+50h] [ebp-A08h]
  float v34; // [esp+54h] [ebp-A04h]
  OSContext context; // [esp+58h] [ebp-A00h] BYREF
  boost::detail::thread::scoped_lock<boost::mutex> lock; // [esp+8Ch] [ebp-9CCh]
  G3D::RenderDevice renderDevice; // [esp+94h] [ebp-9C4h] BYREF
  unsigned __int8 L[255]; // [esp+944h] [ebp-114h]
  int v39; // [esp+A54h] [ebp-4h]

  ptr = *(RBX::View::View **)&fileType._Alval.std::_Allocator_base<char>;
  rbxView.ptr = *(RBX::View::View **)&fileType._Alval.std::_Allocator_base<char>;
  context.__vftable = (OSContext_vtbl *)binaryOutputa;
  v39 = 0;
  v8 = 0;
  *(float *)&v9 = COERCE_FLOAT(G3D::GImage::stringToFormat((const std::string *)&fileType._Bx));
  v28 = v9;
  v25[0] = 0;
  if ( (_BYTE)binaryOutput )
  {
    v10 = RBX::ServiceProvider::create<RBX::Lighting>(*(const RBX::Instance **)&fileType._Alval.std::_Allocator_base<char>);
    v10->hasSky = 0;
    if ( v9 == PNG )
    {
      v24[0].r = 0.0;
      v8 = 1;
      v24[0].g = 0.0;
      v25[0] = 1;
      v24[0].b = 0.0;
      LODWORD(i_4) = v24;
      v24[0].a = 0.0;
    }
    else
    {
      v24[0].r = 1.0;
      v24[0].g = 1.0;
      v24[0].b = 1.0;
      v24[0].a = 1.0;
    }
    RBX::Lighting::setClearColor(v10, v24[0]);
    v11 = RBX::ServiceProvider::find<RBX::Workspace>(*(const RBX::Instance **)&fileType._Alval.std::_Allocator_base<char>);
    v33 = (float)cy;
    v34 = (float)hideSky;
    *(float *)&s[4] = 0.0;
    *(float *)&s[8] = 0.0;
    *(float *)&v30 = v33;
    v31 = v34;
    RBX::Workspace::setImageServerView(v11, (const G3D::Rect2D *)&s[4]);
  }
  OSContext::OSContext((OSContext *)&context.loopBodyStack, cy, hideSky, v25[0]);
  LOBYTE(v39) = 1;
  boost::call_once(StaticMutex<OSContext>::init, &StaticMutex<OSContext>::initFlag);
  *(_DWORD *)&lock.m_locked = StaticMutex<OSContext>::m;
  boost::mutex::do_lock(StaticMutex<OSContext>::m);
  LOBYTE(renderDevice._window) = 1;
  LOBYTE(v39) = 2;
  if ( G3D::GWindow::m_current != (const G3D::GWindow *)&context.loopBodyStack )
  {
    (*(void (__thiscall **)(G3D::Array<G3D::GWindow::LoopBody> *))&context.loopBodyStack.data[12].isGApplet)(&context.loopBodyStack);
    G3D::GWindow::m_current = (const G3D::GWindow *)&context.loopBodyStack;
  }
  RBX::Render::Mesh::makeVAR();
  RBX::Render::Mesh::varDirty = 1;
  G3D::RenderDevice::RenderDevice((G3D::RenderDevice *)&renderDevice.deleteWindow);
  LOBYTE(v39) = 3;
  G3D::RenderDevice::init((G3D::RenderDevice *)&renderDevice.deleteWindow, (G3D::GWindow *)&context.loopBodyStack, 0);
  v12 = *(RBX::ContentProvider **)(*(_DWORD *)&fileType._Alval.std::_Allocator_base<char> + 204);
  v13 = (RBX::View::View *)operator new(0x58u);
  LODWORD(i_4) = v13;
  LOBYTE(v39) = 4;
  if ( v13 )
  {
    i = &v24[0].b;
    RBX::shared_from<RBX::DataModel>((boost::shared_ptr<RBX::ContentProvider> *)&v24[0].b, v12);
    RBX::View::View::View(v13, *(boost::shared_ptr<RBX::DataModel> *)&v24[0].b);
    v15 = v14;
    *(float *)v25 = v14;
  }
  else
  {
    *(float *)v25 = 0.0;
    v15 = 0.0;
  }
  v33 = v15;
  LOBYTE(v39) = 5;
  (*(void (__thiscall **)(float, _DWORD, _DWORD, _DWORD, _DWORD))(*(_DWORD *)LODWORD(v15) + 16))(
    COERCE_FLOAT(LODWORD(v15)),
    100.0,
    100.0,
    0,
    10.0);
  glMatrixMode(0x1700u);
  (*(void (__thiscall **)(float, bool *))(*(_DWORD *)LODWORD(v15) + 4))(
    COERCE_FLOAT(LODWORD(v15)),
    &renderDevice.deleteWindow);
  glMatrixMode(0x1700u);
  if ( v8 )
    G3D::GImage::flipRGBAVertical(
      (const unsigned __int8 *)context.image.width,
      (unsigned __int8 *)context.image.width,
      context.image.height,
      context.image.channels);
  else
    G3D::GImage::flipRGBVertical(
      (const unsigned __int8 *)context.image.width,
      (unsigned __int8 *)context.image.width,
      context.image.height,
      context.image.channels);
  *(double *)&s[4] = *(double *)((char *)&renderDevice.lightSaturation + 4);
  if ( 1.0 != *(double *)((char *)&renderDevice.lightSaturation + 4) )
  {
    v16 = 255;
    LODWORD(i_4) = 255;
    do
    {
      i_4 = (double)SLODWORD(i_4) * *(double *)&s[4];
      i = (float *)(int)i_4;
      v17 = (int)i_4;
      if ( (int)i_4 > 255 )
        LOBYTE(v17) = -1;
      L[v16-- + 4] = v17;
      LODWORD(i_4) = v16;
    }
    while ( v16 >= 0 );
    v18 = context.image.channels * context.image.height * (int)lock.m_mutex;
    width = context.image.width;
    for ( j = 0; j < v18; j += (v8 != 0) + 3 )
    {
      for ( k = 0; k < 3; ++k )
        *(_BYTE *)(j + width + k) = L[*(unsigned __int8 *)(j + width + k) + 4];
    }
    v15 = *(float *)v25;
    ptr = rbxView.ptr;
  }
  if ( context.__vftable )
  {
    G3D::GImage::encode((G3D::GImage *)&context.image._byte, v28, (G3D::BinaryOutput *)context.__vftable);
  }
  else if ( (_BYTE)binaryOutput )
  {
    v22 = RBX::ServiceProvider::find<RBX::Workspace>((const RBX::Instance *)ptr);
    *(float *)&v28 = (float)cy;
    *(float *)s = (float)hideSky;
    *(float *)&s[4] = 0.0;
    *(float *)&s[8] = 0.0;
    v30 = v28;
    v31 = *(float *)s;
    RBX::Workspace::setImageServerView(v22, (const G3D::Rect2D *)&s[4]);
  }
  G3D::RenderDevice::cleanup((G3D::RenderDevice *)&renderDevice.deleteWindow);
  LOBYTE(v39) = 3;
  (**(void (__thiscall ***)(float, int))LODWORD(v15))(COERCE_FLOAT(LODWORD(v15)), 1);
  LOBYTE(v39) = 2;
  G3D::RenderDevice::~RenderDevice((G3D::RenderDevice *)&renderDevice.deleteWindow);
  LOBYTE(v39) = 1;
  boost::mutex::do_unlock(*(boost::mutex **)&lock.m_locked);
  LODWORD(v24[0].a) = &context.loopBodyStack;
  LOBYTE(v39) = 0;
  OSContext::~OSContext(v23);
  v39 = -1;
  std::string::~string(&fileType._Bx);
}
