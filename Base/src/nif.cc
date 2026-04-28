#include "../include/nif.h"

nif::nif(long value) : value_(value) {}

nif::nif(const nif& other) : value_(other.value_) {}

nif& nif::operator=(const nif& other) {
  if (this != &other) {
    value_ = other.value_;
  }
  return *this;
}

bool nif::operator==(const nif& other) const { return value_ == other.value_; }
bool nif::operator!=(const nif& other) const { return value_ != other.value_; }
bool nif::operator<(const nif& other) const { return value_ < other.value_; }
bool nif::operator>(const nif& other) const { return value_ > other.value_; }
bool nif::operator<=(const nif& other) const { return value_ <= other.value_; }
bool nif::operator>=(const nif& other) const { return value_ >= other.value_; }

std::ostream& operator<<(std::ostream& os, const nif& value) {
  os << value.value_;
  return os;
}

std::istream& operator>>(std::istream& is, nif& value) {
  is >> value.value_;
  return is;
}