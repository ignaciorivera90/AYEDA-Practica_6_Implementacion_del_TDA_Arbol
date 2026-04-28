// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Algoritmos y Estructuras de Datos Avanzadas
// Curso: 2º
// Práctica 6: Implementación del TDA Árbol
// Autor: Ignacio Andres Rivera Barrientos
// Correo: alu0101675053@ull.edu.es
// Fecha: 27/04/2026
// Archivo: tree_exception.h
// Descripción: Definición de la clase de excepciones personalizada para el programa.

#ifndef TREE_EXCEPTION_H
#define TREE_EXCEPTION_H

#include <exception>
#include <string>

/**
 * @brief Custom exception class for tree errors
 */
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