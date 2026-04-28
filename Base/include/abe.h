#ifndef ABE_H
#define ABE_H

#include "ab.h"

template <class Key>
class ABE : public AB<Key> {
 public:
  ABE() : AB<Key>() {}

  bool insertar(const Key& k) override {
    if (buscar(k)) return false;
    InsertarEquilibrado(this->raiz_, k);
    return true;
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
    if (nodo->dato_ == k) return true;
    return BuscarRama(nodo->izdo_, k) || BuscarRama(nodo->dcho_, k);
  }

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

  bool BuscarRamaComparaciones(NodoB<Key>* nodo, const Key& k, int& comparaciones) const {
    if (nodo == nullptr) return false;

    ++comparaciones;

    if (nodo->dato_ == k) return true;

    return BuscarRamaComparaciones(nodo->izdo_, k, comparaciones) || BuscarRamaComparaciones(nodo->dcho_, k, comparaciones);
  }
};

#endif