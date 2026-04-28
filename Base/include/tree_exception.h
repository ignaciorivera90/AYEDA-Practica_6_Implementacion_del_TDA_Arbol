#ifndef TREE_EXCEPTION_H
#define TREE_EXCEPTION_H

#include <exception>
#include <string>

class TreeException : public std::exception {
 public:
  explicit TreeException(const std::string& message) : message_(message) {}

  const char* what() const noexcept override {
    return message_.c_str();
  }

 private:
  std::string message_;
};

#endif