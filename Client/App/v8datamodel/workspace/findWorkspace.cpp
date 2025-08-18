// attributes: thunk
RBX::Workspace *__cdecl RBX::Workspace::findWorkspace(const RBX::Instance *context)
{
  return RBX::ServiceProvider::find<RBX::Workspace>(context);
}
