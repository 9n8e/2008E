void __cdecl RBX::Guid::generateGUID(std::string *result)
{
  _GUID guid; // [esp+0h] [ebp-D4h] BYREF
  char ansiClsid[64]; // [esp+10h] [ebp-C4h] BYREF
  wchar_t wszGUID_4[64]; // [esp+54h] [ebp-80h] OVERLAPPED BYREF

  std::string::operator=(result, "RBX");
  CoCreateGuid((GUID *)&guid.Data2);
  memset(wszGUID_4, 0, sizeof(wszGUID_4));
  StringFromGUID2((const GUID *const)&guid.Data2, wszGUID_4, 64);
  WideCharToMultiByte(0, 0, wszGUID_4, 64, &ansiClsid[4], 64, 0, 0);
  std::string::operator+=(result, &ansiClsid[4]);
  std::string::erase(result, 40, 1);
  std::string::erase(result, 27, 1);
  std::string::erase(result, 22, 1);
  std::string::erase(result, 17, 1);
  std::string::erase(result, 12, 1);
  std::string::erase(result, 3, 1);
}
