int __cdecl RBX::ContentProvider::loadfile(int L)
{
  int v1; // eax
  int v2; // edi
  char *v3; // eax
  int v4; // esi
  char v6[8]; // [esp-20h] [ebp-74h] BYREF
  int v7; // [esp-18h] [ebp-6Ch]
  int v8; // [esp-14h] [ebp-68h]
  int v9; // [esp-10h] [ebp-64h]
  int v10; // [esp-Ch] [ebp-60h]
  unsigned int v11; // [esp-8h] [ebp-5Ch]
  int v12; // [esp-4h] [ebp-58h]
  char *v13; // [esp+8h] [ebp-4Ch]
  int v14; // [esp+Ch] [ebp-48h] BYREF
  char *FileName[6]; // [esp+10h] [ebp-44h] BYREF
  char v16[28]; // [esp+28h] [ebp-2Ch] BYREF
  int v17; // [esp+44h] [ebp-10h]
  int v18; // [esp+50h] [ebp-4h]

  RBX::Security::Context::current();
  RBX::Security::Context::requirePermission(1, (char)"loadfile");
  v1 = sub_618840(L, -1);
  std::string::string(v16, v1);
  v18 = 0;
  v17 = sub_560BF0();
  v13 = v6;
  v18 = 1;
  std::string::string(v6, v16);
  v12 = v17;
  LOBYTE(v18) = 2;
  sub_6101C0(L, 67);
  sub_610210(L, -10002);
  v2 = sub_60FED0(L, -1);
  sub_60F9D0(L, -2);
  sub_467500(v2);
  LOBYTE(v18) = 1;
  sub_571920((int)&v14, v6[0], v6[4], v7, v8, v9, v10, v11, v12);
  v3 = FileName[0];
  LOBYTE(v18) = 3;
  if ( FileName[5] < (char *)0x10 )
    v3 = (char *)FileName;
  if ( sub_60F040(L, v3) )
  {
    sub_60FF90(L);
    sub_60FA70(L, -2);
    v4 = 2;
  }
  else
  {
    v4 = 1;
  }
  LOBYTE(v18) = 1;
  std::string::~string(&v14);
  v18 = -1;
  std::string::~string(v16);
  return v4;
}
