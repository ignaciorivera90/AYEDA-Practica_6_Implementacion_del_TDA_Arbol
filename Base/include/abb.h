#ifndef ABB_H
#define ABB_H

#include "ab.h"

template <class Key>
class ABB : public AB<Key> {
 public:
  ABB() : AB<Key>() {}

  bool insertar(const Key& k) override {
    return InsertarRama(this->raiz_, k);
  }

  bool buscar(const Key& k) const override {
    return BuscarRama(this->raiz_, k);
  }

  bool buscarConComparaciones(const Key& k, int& comparaciones) const override {
    comparaciones = 0;
    return BuscarRamaComparaciones(this->raiz_, k, comparaciones);
  }

 private:
  bool BuscarRama(NodoB<Key>* nodo, const Key& k) const {
    if (nodo == nullptr) return false;
    if (k == nodo->dato_) return true;
    if (k < nodo->dato_) return BuscarRama(nodo->izdo_, k);
    return BuscarRama(nodo->dcho_, k);
  }

  bool InsertarRama(NodoB<Key>*& nodo, const Key& k) {
    if (nodo == nullptr) {
      nodo = new NodoB<Key>(k);
      return true;
    }

    if (k == nodo->dato_) return false;
    if (k < nodo->dato_) return InsertarRama(nodo->izdo_, k);
    return InsertarRama(nodo->dcho_, k);
  }

  bool BuscarRamaComparaciones(NodoB<Key>* nodo, const Key& k, int& comparaciones) const {
    if (nodo == nullptr) return false;

    ++comparaciones;

    if (k == nodo->dato_) return true;
    if (k < nodo->dato_) return BuscarRamaComparaciones(nodo->izdo_, k, comparaciones);
    return BuscarRamaComparaciones(nodo->dcho_, k, comparaciones);
  }
};

#endif