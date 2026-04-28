// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Algoritmos y Estructuras de Datos Avanzadas
// Curso: 2º
// Práctica 6: Implementación del TDA Árbol
// Autor: Ignacio Andres Rivera Barrientos
// Correo: alu0101675053@ull.edu.es
// Fecha: 27/04/2026
// Archivo: abb.h
// Descripción: Implementación del árbol binario de búsqueda (ABB).

#ifndef ABB_H
#define ABB_H

#include "ab.h"

/**
 * @brief Binary search tree implementation
 * @tparam Key Type of the elements
 */
template <class Key>
class ABB : public AB<Key> {
 public:
  ABB() : AB<Key>() {}

  /**
    * @brief Inserts a key following BST rules
    */
  bool insertar(const Key& k) override {
    return InsertarRama(this->raiz_, k);
  }

  /**
    * @brief Searches a key in the tree
    */
  bool buscar(const Key& k) const override {
    return BuscarRama(this->raiz_, k);
  }

  /**
    * @brief Searches a key and counts comparisons
    */
  bool buscarConComparaciones(const Key& k, int& comparaciones) const override {
    comparaciones = 0;
    return BuscarRamaComparaciones(this->raiz_, k, comparaciones);
  }

 private:
  /**
    * @brief Recursive search helper
    */
  bool BuscarRama(NodoB<Key>* nodo, const Key& k) const {
    if (nodo == nullptr) return false;
    if (k == nodo->dato_) return true;
    if (k < nodo->dato_) return BuscarRama(nodo->izdo_, k);
    return BuscarRama(nodo->dcho_, k);
  }

  /**
    * @brief Recursive insertion helper
    */
  bool InsertarRama(NodoB<Key>*& nodo, const Key& k) {
    if (nodo == nullptr) {
      nodo = new NodoB<Key>(k);
      return true;
    }

    if (k == nodo->dato_) return false;
    if (k < nodo->dato_) return InsertarRama(nodo->izdo_, k);
    return InsertarRama(nodo->dcho_, k);
  }

  /**
    * @brief Searches a key and counts comparisons
    */
  bool BuscarRamaComparaciones(NodoB<Key>* nodo, const Key& k, int& comparaciones) const {
    if (nodo == nullptr) return false;

    ++comparaciones;

    if (k == nodo->dato_) return true;
    if (k < nodo->dato_) return BuscarRamaComparaciones(nodo->izdo_, k, comparaciones);
    return BuscarRamaComparaciones(nodo->dcho_, k, comparaciones);
  }
};

#endif