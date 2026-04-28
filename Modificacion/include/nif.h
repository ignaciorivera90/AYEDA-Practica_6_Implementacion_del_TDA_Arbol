// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Algoritmos y Estructuras de Datos Avanzadas
// Curso: 2º
// Práctica 6: Implementación del TDA Árbol
// Autor: Ignacio Andres Rivera Barrientos
// Correo: alu0101675053@ull.edu.es
// Fecha: 27/04/2026
// Archivo: nif.h
// Descripción: Definición de la clase nif utilizada como tipo de clave
// para almacenar y comparar valores dentro del árbol.

#ifndef NIF_H
#define NIF_H

#include <iostream>
#include <cstdlib>

/**
 * @brief Class that represents a NIF key
 */
class nif {
 public:
  nif(long value = 0);
  nif(const nif& other);

  long GetValue() const;

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