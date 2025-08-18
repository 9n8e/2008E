LONG __cdecl RBX::ServiceProvider::newIndex()
{
  return InterlockedIncrement(&index);
}
