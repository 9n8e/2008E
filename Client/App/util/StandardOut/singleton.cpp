boost::shared_ptr<RBX::StandardOut> *__cdecl RBX::StandardOut::singleton(boost::shared_ptr<RBX::StandardOut> *result)
{
  RBX::StandardOut *v1; // eax
  RBX::StandardOut *v2; // eax
  boost::shared_ptr<RBX::StandardOut> *v3; // eax

  if ( (_S1 & 1) == 0 )
  {
    _S1 |= 1u;
    v1 = (RBX::StandardOut *)operator new(0x28u);
    if ( v1 )
      RBX::StandardOut::StandardOut(v1);
    else
      v2 = 0;
    boost::shared_ptr<RBX::StandardOut>::shared_ptr<RBX::StandardOut>(&standardOut, v2);
    atexit(RBX::StandardOut::singleton_::_2_::_dynamic_atexit_destructor_for__standardOut__);
  }
  v3 = result;
  *result = standardOut;
  if ( standardOut.pn.pi_ )
    _InterlockedExchangeAdd(&standardOut.pn.pi_->use_count_, 1u);
  return v3;
}
