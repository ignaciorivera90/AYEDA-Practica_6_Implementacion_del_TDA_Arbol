// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Algoritmos y Estructuras de Datos Avanzadas
// Curso: 2º
// Práctica 6: Implementación del TDA Árbol
// Autor: Ignacio Andres Rivera Barrientos
// Correo: alu0101675053@ull.edu.es
// Fecha: 27/04/2026
// Archivo: abe.h
// Descripción: Implementación del árbol binario equilibrado (ABE).

#ifndef ABE_H
#define ABE_H

#include "ab.h"

/**
 * @brief Balanced binary tree implementation
 * @tparam Key Type of the elements
 */
template <class Key>
class ABE : public AB<Key> {
 public:
  ABE() : AB<Key>() {}

  /**
    * @brief Inserts a key in a balanced way
    */
  bool insertar(const Key& k) override {
    if (buscar(k)) return false;
    InsertarEquilibrado(this->raiz_, k);
    return true;
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
    if (nodo->dato_ == k) return true;
    return BuscarRama(nodo->izdo_, k) || BuscarRama(nodo->dcho_, k);
  }

  /**
    * @brief Inserts a node keeping the tree balanced
    */
  void InsertarEquilibrado(NodoB<Key>*& nodo, const Key& k) {
    if (nodo == nullptr) {
      nodo = new NodoB<Key>(k);
      return;
    }

    if (this->TamRama(nodo->izdo_) <= this->TamRama(nodo->dcho_)) {
      InsertarEquilibrado(nodo->izdo_, k);
    } else {
      InsertarEquilibrado(nodo->dcho_, k);
    }
  }

  /**
    * @brief Searches a key and counts comparisons
    */
  bool BuscarRamaComparaciones(NodoB<Key>* nodo, const Key& k, int& comparaciones) const {
    if (nodo == nullptr) return false;

    ++comparaciones;

    if (nodo->dato_ == k) return true;

    return BuscarRamaComparaciones(nodo->izdo_, k, comparaciones) || BuscarRamaComparaciones(nodo->dcho_, k, comparaciones);
  }
};

#endif