int __cdecl RBX::Guid::compare(const RBX::Guid *a, const RBX::Guid *b)
{
  const RBX::Name *scope; // ecx
  const RBX::Name *v3; // eax
  int v4; // eax
  int index; // ecx
  int v7; // eax

  if ( a )
    scope = a->data.scope;
  else
    scope = 0;
  if ( b )
    v3 = b->data.scope;
  else
    v3 = 0;
  v4 = RBX::Name::compare(scope, v3);
  if ( v4 == -1 )
    return -1;
  if ( v4 )
    return v4 == 1;
  if ( a )
    index = a->data.index;
  else
    index = 0;
  if ( b )
    v7 = b->data.index;
  else
    v7 = 0;
  if ( index <= v7 )
    return (index >= v7) - 1;
  else
    return 1;
}
