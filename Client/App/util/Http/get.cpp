void __thiscall RBX::Http::get(RBX::Http *this, std::string *response)
{
  std::string::_Bxty *p_Bx; // edi
  bool v4; // zf
  int v5; // [esp+0h] [ebp-B0h] BYREF
  std::istringstream dummy; // [esp+Ch] [ebp-A4h] BYREF
  std::string *url; // [esp+98h] [ebp-18h]
  const char *h; // [esp+9Ch] [ebp-14h]
  int *v9; // [esp+A0h] [ebp-10h]
  int v10; // [esp+ACh] [ebp-4h]

  p_Bx = 0;
  v4 = this->additionalHeaders._Mysize == 0;
  v9 = &v5;
  url = (std::string *)&this->url;
  h = 0;
  if ( !v4 )
  {
    if ( this->additionalHeaders._Myres < 0x10 )
      p_Bx = &this->additionalHeaders._Bx;
    else
      p_Bx = (std::string::_Bxty *)this->additionalHeaders._Bx._Ptr;
    h = (const char *)p_Bx;
  }
  std::istringstream::istringstream(&dummy, 1, 1);
  v10 = 1;
  RBX::httpGetPost(0, &this->url, &dummy, 0, p_Bx->_Buf, response);
  v10 = -1;
  std::istringstream::`vbase destructor'(&dummy);
}
