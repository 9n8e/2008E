// pasted directly from IDA Pro with some comment additions
char __cdecl RBX::Http::trustCheck(unsigned __int8 *url)
{
  const unsigned __int8 **v2; // eax
  bool v3; // bl
  int v4; // eax
  unsigned __int8 *v5; // eax
  unsigned __int8 **p_Str; // ecx
  int v7; // eax
  char v8; // bl
  int v9; // [esp+4h] [ebp-125Ch] BYREF
  unsigned __int8 *Str; // [esp+8h] [ebp-1258h] BYREF
  int v11; // [esp+Ch] [ebp-1254h] BYREF
  char Dst[33]; // [esp+10h] [ebp-1250h] BYREF
  char Source[4615]; // [esp+31h] [ebp-122Fh] BYREF
  int v14; // [esp+1238h] [ebp-28h]
  int v15; // [esp+125Ch] [ebp-4h]

  sub_5689F0((void (*)(void))sub_576DB0, &dword_9519A4);
  if ( kSkipTrustCheck ) // byte_000000, must be registry key
    return 1;
  v2 = (const unsigned __int8 **)sub_56F9E0(&v9, (unsigned int)"about:blank"); // temporary variable for std::string("about:blank");
  if ( !url )
    sub_401000(-2147467259);
  v3 = mbscmp(*v2, url) == 0; // temporary variable for comparing about:blank to url
  v4 = v9 - 16;
  if ( _InterlockedDecrement((volatile signed __int32 *)(v9 - 16 + 12)) <= 0 )
    (*(void (__stdcall **)(int))(**(_DWORD **)v4 + 4))(v4);
  if ( v3 || RBX::Http::isRobloxSite((int)url) || (unsigned __int8)RBX::Http::isScript(url) ) // thank 2016 source for making me being able to recognize this
    return 1;
  // have not done ANYTHING past here yet
  sub_4081C0((unsigned __int8 *)Dst);
  sub_409A10(url, 0);
  if ( v14 && (v14 <= 1 || v14 > 3) )
  {
    sub_56F9E0(&Str, (unsigned int)url);
    if ( *((int *)Str - 3) >= 0 )
    {
      v5 = mbsstr(Str, "res:");
      if ( v5 )
      {
        if ( v5 == Str )
        {
          p_Str = &Str;
LABEL_17:
          sub_407C40(p_Str);
          return 1;
        }
      }
    }
    p_Str = &Str;
  }
  else
  {
    sub_56F9E0(&v9, (unsigned int)Source);
    v15 = 0;
    sub_578670(&v9);
    v7 = sub_5778B0((int)&v11, 0x15u);
    v8 = sub_576FD0(v7, "googlesyndication.com");
    sub_407C40(&v11);
    p_Str = (unsigned __int8 **)&v9;
    if ( v8 )
      goto LABEL_17;
  }
  sub_407C40(p_Str);
  return 0;
}
