// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Algoritmos y Estructuras de Datos Avanzadas
// Curso: 2º
// Práctica 6: Implementación del TDA Árbol
// Autor: Ignacio Andres Rivera Barrientos
// Correo: alu0101675053@ull.edu.es
// Fecha: 27/04/2026
// Archivo: nodo_b.h
// Descripción: Definición de la clase NodoB que representa un nodo de un árbol binario.

#ifndef NODO_B_H
#define NODO_B_H

/**
 * @brief Class that represents a node of a binary tree
 * @tparam Key Type of the data stored in the node
 */
template <class Key>
class NodoB {
 public:
  NodoB(const Key& dato, NodoB<Key>* izdo = nullptr, NodoB<Key>* dcho = nullptr)
      : dato_(dato), izdo_(izdo), dcho_(dcho) {}

  Key dato_;
  NodoB<Key>* izdo_;
  NodoB<Key>* dcho_;
};

#endif