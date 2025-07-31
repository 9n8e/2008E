char __cdecl RBX::Http::trustCheck(const char *url)
{
  const unsigned __int8 **v2; // eax
  bool v3; // bl
  char *v4; // eax
  unsigned __int8 *v5; // eax
  ATL::CPathT<ATL::CStringT<char,ATL::StrTraitATL<char,ATL::ChTraitsCRT<char> > > > *v6; // ecx
  const ATL::CStringT<char,ATL::StrTraitATL<char,ATL::ChTraitsCRT<char> > > *v7; // eax
  bool v8; // bl
  ATL::CStringT<char,ATL::StrTraitATL<char,ATL::ChTraitsCRT<char> > > v9; // [esp+4h] [ebp-125Ch] BYREF
  ATL::CStringT<char,ATL::StrTraitATL<char,ATL::ChTraitsCRT<char> > > v10; // [esp+8h] [ebp-1258h] BYREF
  ATL::CStringT<char,ATL::StrTraitATL<char,ATL::ChTraitsCRT<char> > > v11; // [esp+Ch] [ebp-1254h] BYREF
  ATL::CUrl v12; // [esp+10h] [ebp-1250h] BYREF
  int v13; // [esp+125Ch] [ebp-4h]

  boost::call_once((void (__cdecl *)())RBX::initTrustCheck, &flagTrustCheck);
  if ( skipTrustCheck )
    return 1;
  ATL::CStringT<char,ATL::StrTraitATL<char,ATL::ChTraitsCRT<char>>>::CStringT<char,ATL::StrTraitATL<char,ATL::ChTraitsCRT<char>>>(
    &v9,
    "about:blank");
  if ( !url )
    ATL::AtlThrowImpl(-2147467259);
  v3 = __mbscmp(*v2, (const unsigned __int8 *)url) == 0;
  v4 = v9.m_pszData - 16;
  if ( _InterlockedDecrement((volatile signed __int32 *)v9.m_pszData - 1) <= 0 )
    (*(void (__stdcall **)(char *))(**(_DWORD **)v4 + 4))(v4);
  if ( v3 || RBX::Http::isRobloxSite(url) || RBX::Http::isScript(url) )
    return 1;
  ATL::CUrl::CUrl(&v12);
  ATL::CUrl::CrackUrl(&v12, url, 0);
  if ( v12.m_nScheme && (v12.m_nScheme <= ATL_URL_SCHEME_GOPHER || v12.m_nScheme > ATL_URL_SCHEME_HTTPS) )
  {
    ATL::CStringT<char,ATL::StrTraitATL<char,ATL::ChTraitsCRT<char>>>::CStringT<char,ATL::StrTraitATL<char,ATL::ChTraitsCRT<char>>>(
      &v10,
      url);
    if ( *((int *)v10.m_pszData - 3) >= 0 )
    {
      v5 = __mbsstr((const unsigned __int8 *)v10.m_pszData, "res:");
      if ( v5 )
      {
        if ( v5 == (unsigned __int8 *)v10.m_pszData )
        {
          v6 = (ATL::CPathT<ATL::CStringT<char,ATL::StrTraitATL<char,ATL::ChTraitsCRT<char> > > > *)&v10;
LABEL_17:
          ATL::CPathT<ATL::CStringT<char,ATL::StrTraitATL<char,ATL::ChTraitsCRT<char>>>>::~CPathT<ATL::CStringT<char,ATL::StrTraitATL<char,ATL::ChTraitsCRT<char>>>>(v6);
          return 1;
        }
      }
    }
    v6 = (ATL::CPathT<ATL::CStringT<char,ATL::StrTraitATL<char,ATL::ChTraitsCRT<char> > > > *)&v10;
  }
  else
  {
    ATL::CStringT<char,ATL::StrTraitATL<char,ATL::ChTraitsCRT<char>>>::CStringT<char,ATL::StrTraitATL<char,ATL::ChTraitsCRT<char>>>(
      &v9,
      v12.m_szHostName);
    v13 = 0;
    ATL::CStringT<char,ATL::StrTraitATL<char,ATL::ChTraitsCRT<char>>>::MakeLower(&v9);
    v7 = ATL::CStringT<char,ATL::StrTraitATL<char,ATL::ChTraitsCRT<char>>>::Right(&v9, &v11, 21);
    v8 = ATL::operator==(v7, "googlesyndication.com");
    ATL::CPathT<ATL::CStringT<char,ATL::StrTraitATL<char,ATL::ChTraitsCRT<char>>>>::~CPathT<ATL::CStringT<char,ATL::StrTraitATL<char,ATL::ChTraitsCRT<char>>>>((ATL::CPathT<ATL::CStringT<char,ATL::StrTraitATL<char,ATL::ChTraitsCRT<char> > > > *)&v11);
    v6 = (ATL::CPathT<ATL::CStringT<char,ATL::StrTraitATL<char,ATL::ChTraitsCRT<char> > > > *)&v9;
    if ( v8 )
      goto LABEL_17;
  }
  ATL::CPathT<ATL::CStringT<char,ATL::StrTraitATL<char,ATL::ChTraitsCRT<char>>>>::~CPathT<ATL::CStringT<char,ATL::StrTraitATL<char,ATL::ChTraitsCRT<char>>>>(v6);
  return 0;
}
