const RBX::Name *__cdecl RBX::Guid::getLocalScope()
{
  boost::call_once(initLocalScope, &flag);
  return localScope;
}
