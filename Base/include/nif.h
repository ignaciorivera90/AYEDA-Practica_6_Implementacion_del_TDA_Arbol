#ifndef NIF_H
#define NIF_H

#include <iostream>
#include <cstdlib>

class nif {
 public:
  nif(long value = 0);
  nif(const nif& other);

  nif& operator=(const nif& other);

  bool operator==(const nif& other) const;
  bool operator!=(const nif& other) const;
  bool operator<(const nif& other) const;
  bool operator>(const nif& other) const;
  bool operator<=(const nif& other) const;
  bool operator>=(const nif& other) const;

  friend std::ostream& operator<<(std::ostream& os, const nif& value);
  friend std::istream& operator>>(std::istream& is, nif& value);

 private:
  long value_;
};

#endif