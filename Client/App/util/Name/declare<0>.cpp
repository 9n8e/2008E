const RBX::Name *__cdecl RBX::Name::declare<0>()
{
  boost::call_once(declareNullName, &flag_1);
  return nullName;
}
