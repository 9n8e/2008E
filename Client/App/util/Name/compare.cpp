int __cdecl RBX::Name::compare(const RBX::Name *a, const RBX::Name *b)
{
  if ( a && a != RBX::Name::declare<0>() )
  {
    if ( b && b != RBX::Name::declare<0>() )
    {
      if ( a == b )
        return 0;
      else
        return std::string::compare(&a->name, &b->name);
    }
    else
    {
      return a != RBX::Name::declare<0>();
    }
  }
  else if ( !b || b == RBX::Name::declare<0>() )
  {
    return 0;
  }
  else
  {
    return -1;
  }
}
