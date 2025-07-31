// constructor
void __thiscall RBX::Guid::Guid(RBX::Guid *this)
{
  boost::call_once(initLocalScope, &flag);
  this->data.scope = localScope;
  this->data.index = InterlockedIncrement(&nextIndex);
}
