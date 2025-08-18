const RBX::ServiceProvider *__cdecl RBX::ServiceProvider::findServiceProvider(const RBX::Instance *context)
{
  const RBX::Instance *v1; // esi
  const RBX::ServiceProvider *result; // eax

  v1 = context;
  if ( !context )
    return 0;
  while ( 1 )
  {
    result = (const RBX::ServiceProvider *)__RTDynamicCast(
                                             v1,
                                             0,
                                             &RBX::Instance `RTTI Type Descriptor',
                                             &RBX::ServiceProvider `RTTI Type Descriptor',
                                             0);
    if ( result )
      break;
    v1 = v1->parent;
    if ( !v1 )
      return 0;
  }
  return result;
}
