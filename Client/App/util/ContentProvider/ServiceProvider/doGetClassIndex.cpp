// Players as an example
unsigned int __cdecl RBX::ServiceProvider::doGetClassIndex<RBX::Network::Players>()
{
  unsigned int result; // eax

  if ( (`RBX::ServiceProvider::doGetClassIndex<RBX::Network::Players>'::`2'::`local static guard' & 1) != 0 )
    return `RBX::ServiceProvider::doGetClassIndex<RBX::Network::Players>'::`2'::index;
  `RBX::ServiceProvider::doGetClassIndex<RBX::Network::Players>'::`2'::`local static guard' |= 1u;
  result = RBX::ServiceProvider::newIndex();
  `RBX::ServiceProvider::doGetClassIndex<RBX::Network::Players>'::`2'::index = result;
  return result;
}
