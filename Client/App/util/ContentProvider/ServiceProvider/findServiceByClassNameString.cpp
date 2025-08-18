boost::shared_ptr<RBX::Instance> *__thiscall RBX::ServiceProvider::findServiceByClassNameString(
        RBX::ServiceProvider *this,
        boost::shared_ptr<RBX::Instance> *result,
        std::string sName)
{
  const RBX::Name *v4; // esi
  std::string::_Bxty *Ptr; // eax
  const std::string *v6; // eax
  RBX::ScriptContext *v7; // eax
  std::string v9; // [esp+Ch] [ebp-50h] BYREF
  std::runtime_error pExceptionObject; // [esp+28h] [ebp-34h] BYREF
  int v11; // [esp+58h] [ebp-4h]

  v11 = 1;
  v4 = RBX::Name::lookup(&sName);
  if ( RBX::Name::declare<0>() == v4 )
  {
    Ptr = (std::string::_Bxty *)sName._Bx._Ptr;
    if ( sName._Myres < 0x10 )
      Ptr = &sName._Bx;
    v6 = G3D::format(&v9, "'%s' is not a valid Service name", Ptr->_Buf);
    LOBYTE(v11) = 2;
    std::runtime_error::runtime_error(&pExceptionObject, v6);
    _CxxThrowException(&pExceptionObject, (_ThrowInfo *)&_TI2_AVruntime_error_std__);
  }
  v7 = (RBX::ScriptContext *)RBX::ServiceProvider::create(this, v4);
  RBX::shared_from<RBX::ModelInstance>((boost::shared_ptr<RBX::ScriptContext> *)result, v7);
  std::string::~string(&sName);
  return result;
}
