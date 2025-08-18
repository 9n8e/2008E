std::string *__thiscall RBX::Lighting::getTimeStr(RBX::Lighting *this, std::string *result)
{
  int value_high; // ecx
  boost::posix_time::time_duration v4; // [esp+0h] [ebp-10h] BYREF
  boost::posix_time::time_duration *v5; // [esp+Ch] [ebp-4h]

  LODWORD(v4.ticks_.value_) = this->timeOfDay.ticks_.value_;
  value_high = HIDWORD(this->timeOfDay.ticks_.value_);
  v5 = &v4;
  HIDWORD(v4.ticks_.value_) = value_high;
  boost::posix_time::to_simple_string(result, v4);
  return result;
}
