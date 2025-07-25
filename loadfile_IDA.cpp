int __stdcall RBX::ContentProvider::loadfile(
        int a1,
        char a2,
        char ArgList,
        int a4,
        int a5,
        int a6,
        int a7,
        unsigned int a8,
        int a9)
{
  int v9; // eax
  int v10; // esi
  char *p_ArgList; // eax
  int v13; // eax
  char v14; // [esp-24h] [ebp-84h] BYREF
  int v15; // [esp-20h] [ebp-80h]
  int v16; // [esp-1Ch] [ebp-7Ch]
  int v17; // [esp-18h] [ebp-78h]
  int v18; // [esp-14h] [ebp-74h]
  int v19; // [esp-10h] [ebp-70h]
  int v20; // [esp-Ch] [ebp-6Ch]
  int v21; // [esp-4h] [ebp-64h]
  int v22; // [esp+8h] [ebp-58h]
  char *v23; // [esp+Ch] [ebp-54h]
  int v24[7]; // [esp+10h] [ebp-50h] BYREF
  char pExceptionObject[40]; // [esp+2Ch] [ebp-34h] BYREF
  int v26; // [esp+5Ch] [ebp-4h]

  v22 = 0;
  v21 = 2;
  v23 = &v14;
  v26 = 1;
  std::string::string(&v14, &a2);
  v9 = sub_571450(v14, v15, v16, v17, v18, v19, v20, a9, (void *)v21);
  v10 = v9;
  if ( !v9 || !(unsigned __int8)sub_5709B0(v9) )
  {
    LOBYTE(p_ArgList) = ArgList;
    if ( a8 < 0x10 )
      p_ArgList = &ArgList;
    v13 = RBX::runtime_error((int)v24, "Unable to load %s", (char)p_ArgList);
    LOBYTE(v26) = 2;
    sub_40A700((std::exception *)pExceptionObject, v13);
    CxxThrowException(pExceptionObject, (_ThrowInfo *)&_TI2_AVruntime_error_std__);
  }
  std::string::string(a1, *(_DWORD *)(v10 + 8));
  v22 = 1;
  LOBYTE(v26) = 0;
  std::string::~string(&a2);
  return a1;
}
