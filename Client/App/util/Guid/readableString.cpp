std::string *__thiscall RBX::Guid::readableString(RBX::Guid *this, std::string *result, int scopeLength)
{
  RBX::Guid::Data::readableString(&this->data, result, 4);
  return result;
}
