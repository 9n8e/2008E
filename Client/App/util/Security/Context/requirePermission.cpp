void __thiscall RBX::Security::Context::requirePermission(
        RBX::Security::Context *this,
        RBX::Security::Permissions permission,
        const char *operation)
{
  const std::string *v3; // eax
  const std::string *v4; // eax
  std::runtime_error v5; // [esp+0h] [ebp-94h] BYREF
  std::runtime_error pExceptionObject; // [esp+28h] [ebp-6Ch] BYREF
  std::string v7; // [esp+50h] [ebp-44h] BYREF
  std::string result; // [esp+6Ch] [ebp-28h] BYREF
  int v9; // [esp+90h] [ebp-4h]

  if ( !RBX::Security::Context::isInRole(this->identity, permission) )
  {
    if ( operation )
    {
      v3 = G3D::format(&result, "The current security context cannot %s", operation);
      v9 = 0;
      std::runtime_error::runtime_error(&pExceptionObject, v3);
      _CxxThrowException(&pExceptionObject, (_ThrowInfo *)&_TI2_AVruntime_error_std__);
    }
    v4 = G3D::format(&v7, "The current security context cannot perform the requested operation");
    v9 = 1;
    std::runtime_error::runtime_error(&v5, v4);
    _CxxThrowException(&v5, (_ThrowInfo *)&_TI2_AVruntime_error_std__);
  }
}
