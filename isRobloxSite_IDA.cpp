char __cdecl RBX::Http::isRobloxSite(int url)
{
  errno_t v1; // eax
  const unsigned __int8 **v3; // eax
  bool v4; // bl
  int v5; // eax
  int v6; // eax
  int v7; // esi
  int v8; // [esp+4h] [ebp-1258h] BYREF
  int v9; // [esp+8h] [ebp-1254h] BYREF
  unsigned __int8 Dst[33]; // [esp+Ch] [ebp-1250h] BYREF
  char Source[4613]; // [esp+2Dh] [ebp-122Fh] BYREF
  __int16 v12; // [esp+1232h] [ebp-2Ah]
  int v13; // [esp+1234h] [ebp-28h]
  int v14; // [esp+1238h] [ebp-24h]
  int v15; // [esp+1258h] [ebp-4h]

  sub_407450(Dst);
  v13 = 2;
  v14 = 4;
  v12 = 80;
  v1 = mbsnbcpy_s(Dst, 0x21u, "http", 4u);      // proves isValidScheme did not exist
  sub_56D440(v1);
  sub_409A10(url, 0);
  if ( v13 && (v13 <= 1 || v13 > 3) )
    return 0;
  sub_56F9E0(&v8, (unsigned int)Source);
  v15 = 0;
  sub_578670(&v8);
  v3 = (const unsigned __int8 **)sub_5778B0((int)&v9, 0xAu);
  v4 = mbscmp(*v3, "roblox.com") == 0;          // direct comparison
  v5 = v9 - 16;
  if ( _InterlockedDecrement((volatile signed __int32 *)(v9 - 16 + 12)) <= 0 )
    (*(void (__stdcall **)(int))(**(_DWORD **)v5 + 4))(v5);
  v6 = v8 - 16;
  v15 = -1;
  v7 = _InterlockedDecrement((volatile signed __int32 *)(v8 - 16 + 12));
  if ( v4 )                                     // if (mbscmp(*v3, "roblox.com") == 0) 
  {
    if ( v7 <= 0 )
      (*(void (__stdcall **)(int))(**(_DWORD **)v6 + 4))(v6);
    return 1;                          
  }
  else
  {
    if ( v7 <= 0 )
      (*(void (__stdcall **)(int))(**(_DWORD **)v6 + 4))(v6);
    return 0;                               
  }
}
