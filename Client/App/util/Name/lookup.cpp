const RBX::Name *__cdecl RBX::Name::lookup(const char *sName)
{
  const std::string *v2; // eax
  const RBX::Name *v3; // esi
  char v4[28]; // [esp+0h] [ebp-28h] BYREF
  int v5; // [esp+24h] [ebp-4h]

  if ( sName )
  {
    v2 = (const std::string *)std::string::string(v4, sName);
    v5 = 0;
    v3 = RBX::Name::lookup(v2);
    v5 = -1;
    std::string::~string(v4);
    return v3;
  }
  else
  {
    boost::call_once(declareNullName, &flag_1);
    return nullName;
  }
}
