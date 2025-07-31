char __cdecl RBX::Http::isScript(char *url)
{
  int v1; // eax
  char *m_pszData; // ecx
  unsigned __int8 *v3; // eax
  char *v4; // eax
  unsigned __int8 *v6; // eax
  ATL::CStringT<char,ATL::StrTraitATL<char,ATL::ChTraitsCRT<char> > > v7; // [esp+4h] [ebp-124Ch] BYREF
  ATL::CUrl v8; // [esp+Ch] [ebp-1244h] BYREF

  ATL::CUrl::InitFields(&v8);
  v8.m_nScheme = ATL_URL_SCHEME_HTTP;
  v8.m_dwSchemeNameLength = 4;
  v8.m_nPortNumber = 80;
  v1 = __mbsnbcpy_s((unsigned __int8 *)&v8, 0x21u, "http", 4u);
  ATL::AtlCrtErrorCheck(v1);
  ATL::CUrl::CrackUrl(&v8, url, 0);
  if ( v8.m_nScheme == ATL_URL_SCHEME_FTP
    || v8.m_nScheme > ATL_URL_SCHEME_GOPHER && v8.m_nScheme <= ATL_URL_SCHEME_HTTPS )
  {
    return 0;
  }
  ATL::CStringT<char,ATL::StrTraitATL<char,ATL::ChTraitsCRT<char>>>::CStringT<char,ATL::StrTraitATL<char,ATL::ChTraitsCRT<char>>>(
    &v7,
    url);
  m_pszData = v7.m_pszData;
  if ( *((int *)v7.m_pszData - 3) < 0
    || ((v3 = __mbsstr((const unsigned __int8 *)v7.m_pszData, "javascript:"), m_pszData = v7.m_pszData, !v3)
     || v3 != (unsigned __int8 *)v7.m_pszData)
    && (*((int *)v7.m_pszData - 3) < 0
     || (v6 = __mbsstr((const unsigned __int8 *)v7.m_pszData, "jscript:"), m_pszData = v7.m_pszData, !v6)
     || v6 != (unsigned __int8 *)v7.m_pszData) )
  {
    if ( _InterlockedDecrement((volatile signed __int32 *)m_pszData - 1) <= 0 )
      (*(void (__stdcall **)(char *))(**((_DWORD **)m_pszData - 4) + 4))(m_pszData - 16);
    return 0;
  }
  v4 = v7.m_pszData - 16;
  if ( _InterlockedDecrement((volatile signed __int32 *)v7.m_pszData - 1) <= 0 )
    (*(void (__stdcall **)(char *))(**(_DWORD **)v4 + 4))(v4);
  return 1;
}
