// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Algoritmos y Estructuras de Datos Avanzadas
// Curso: 2º
// Práctica 6: Implementación del TDA Árbol
// Autor: Ignacio Andres Rivera Barrientos
// Correo: alu0101675053@ull.edu.es
// Fecha: 27/04/2026
// Archivo: nif.cc
// Descripción: Implementación de la clase nif y de sus operadores
// de comparación, entrada y salida.

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