boost::thread_specific_ptr<RBX::Security::Context> *__cdecl RBX::Security::Context::ptr()
{
  if ( (`RBX::Security::Context::ptr'::`2'::`local static guard' & 1) == 0 )
  {
    `RBX::Security::Context::ptr'::`2'::`local static guard' |= 1u;
    boost::thread_specific_ptr<RBX::Security::Context>::thread_specific_ptr<RBX::Security::Context>(&`RBX::Security::Context::ptr'::`2'::value);
    atexit(`RBX::Security::Context::ptr'::`2'::`dynamic atexit destructor for 'value'');
  }
  return &`RBX::Security::Context::ptr'::`2'::value;
}
