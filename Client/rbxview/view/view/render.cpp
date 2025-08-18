void __thiscall RBX::View::View::render(RBX::View::View *this, G3D::RenderDevice *rd)
{
  RBX::Workspace *px; // eax
  RBX::Render::RenderScene *Myptr; // esi
  const G3D::GCamera *v5; // eax

  this->updateLighting(this);
  ((void (__thiscall *)(const RBX::Render::SceneManager *, _DWORD, _DWORD))this->sceneManager._Myptr->prerender)(
    this->sceneManager._Myptr,
    COERCE_UNSIGNED_INT64(0.1000000014901161),
    HIDWORD(COERCE_UNSIGNED_INT64(0.1000000014901161)));
  px = this->dataModel.px->workspace.px;
  Myptr = (RBX::Render::RenderScene *)this->renderLibScene._Myptr;
  v5 = (const G3D::GCamera *)(*(int (__thiscall **)(_BYTE *))(*(_DWORD *)px->gap238 + 8))(px->gap238);
  RBX::Render::RenderScene::render(Myptr, rd, v5);
}
