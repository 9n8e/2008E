char __cdecl RBX::Http::isRobloxSite(const char *url)
{
  int v1; // eax
  ATL::CStringT<char,ATL::StrTraitATL<char,ATL::ChTraitsCRT<char> > > *v3; // eax
  bool v4; // bl
  char *v5; // eax
  char *v6; // eax
  int v7; // esi
  ATL::CStringT<char,ATL::StrTraitATL<char,ATL::ChTraitsCRT<char> > > v8; // [esp+4h] [ebp-1258h] BYREF
  ATL::CStringT<char,ATL::StrTraitATL<char,ATL::ChTraitsCRT<char> > > v9; // [esp+8h] [ebp-1254h] BYREF
  ATL::CUrl v10; // [esp+Ch] [ebp-1250h] BYREF
  int v11; // [esp+1258h] [ebp-4h]

  ATL::CUrl::InitFields(&v10);
  v10.m_nScheme = ATL_URL_SCHEME_HTTP;
  v10.m_dwSchemeNameLength = 4;
  v10.m_nPortNumber = 80;
  v1 = __mbsnbcpy_s((unsigned __int8 *)&v10, 0x21u, "http", 4u);
  ATL::AtlCrtErrorCheck(v1);
  ATL::CUrl::CrackUrl(&v10, url, 0);
  if ( v10.m_nScheme && (v10.m_nScheme <= ATL_URL_SCHEME_GOPHER || v10.m_nScheme > ATL_URL_SCHEME_HTTPS) )
    return 0;
  ATL::CStringT<char,ATL::StrTraitATL<char,ATL::ChTraitsCRT<char>>>::CStringT<char,ATL::StrTraitATL<char,ATL::ChTraitsCRT<char>>>(
    &v8,
    v10.m_szHostName);
  v11 = 0;
  ATL::CStringT<char,ATL::StrTraitATL<char,ATL::ChTraitsCRT<char>>>::MakeLower(&v8);
  v3 = ATL::CStringT<char,ATL::StrTraitATL<char,ATL::ChTraitsCRT<char>>>::Right(&v8, &v9, 10);
  v4 = __mbscmp((const unsigned __int8 *)v3->m_pszData, "roblox.com") == 0;
  v5 = v9.m_pszData - 16;
  if ( _InterlockedDecrement((volatile signed __int32 *)v9.m_pszData - 1) <= 0 )
    (*(void (__stdcall **)(char *))(**(_DWORD **)v5 + 4))(v5);
  v6 = v8.m_pszData - 16;
  v11 = -1;
  v7 = _InterlockedDecrement((volatile signed __int32 *)v8.m_pszData - 1);
  if ( v4 )
  {
    if ( v7 <= 0 )
      (*(void (__stdcall **)(char *))(**(_DWORD **)v6 + 4))(v6);
    return 1;
  }
  else
  {
    if ( v7 <= 0 )
      (*(void (__stdcall **)(char *))(**(_DWORD **)v6 + 4))(v6);
    return 0;
  }
}
