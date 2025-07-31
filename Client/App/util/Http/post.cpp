void __thiscall RBX::Http::post(RBX::Http *this, std::istream *input, bool compress, std::string *response)
{
  std::string::_Bxty *p_Bx; // eax

  if ( this->additionalHeaders._Mysize )
  {
    if ( this->additionalHeaders._Myres < 0x10 )
      p_Bx = &this->additionalHeaders._Bx;
    else
      p_Bx = (std::string::_Bxty *)this->additionalHeaders._Bx._Ptr;
    RBX::httpGetPost(1, &this->url, input, compress, p_Bx->_Buf, response);
  }
  else
  {
    RBX::httpGetPost(1, &this->url, input, compress, 0, response);
  }
}
