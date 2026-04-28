#ifndef AB_H
#define AB_H

#include <iostream>
#include <queue>
#include "nodo_b.h"

template <class Key>
class AB {
 public:
  AB() : raiz_(nullptr) {}
  virtual ~AB() { Podar(raiz_); }

  virtual bool insertar(const Key& k) = 0;
  virtual bool buscar(const Key& k) const = 0;
  virtual bool buscarConComparaciones(const Key& k, int& comparaciones) const = 0;

  void inorden() const {
    InordenRama(raiz_);
    std::cout << std::endl;
  }

  template <class K>
  friend std::ostream& operator<<(std::ostream& os, const AB<K>& arbol);

 protected:
  NodoB<Key>* raiz_;

  void Podar(NodoB<Key>*& nodo) {
    if (nodo == nullptr) return;
    Podar(nodo->izdo_);
    Podar(nodo->dcho_);
    delete nodo;
    nodo = nullptr;
  }

  void InordenRama(NodoB<Key>* nodo) const {
    if (nodo == nullptr) return;
    InordenRama(nodo->izdo_);
    std::cout << nodo->dato_ << " ";
    InordenRama(nodo->dcho_);
  }

  int TamRama(NodoB<Key>* nodo) const {
    if (nodo == nullptr) return 0;
    return 1 + TamRama(nodo->izdo_) + TamRama(nodo->dcho_);
  }
};

template <class Key>
std::ostream& operator<<(std::ostream& os, const AB<Key>& arbol) {
  if (arbol.raiz_ == nullptr) {
    os << "Nivel 0: [.]";
    return os;
  }

  std::queue<std::pair<NodoB<Key>*, int>> cola;
  cola.push({arbol.raiz_, 0});

  int nivel_actual = 0;
  os << "Nivel 0: ";

  while (!cola.empty()) {
    NodoB<Key>* nodo = cola.front().first;
    int nivel = cola.front().second;
    cola.pop();

    if (nivel != nivel_actual) {
      nivel_actual = nivel;
      os << "\nNivel " << nivel_actual << ": ";
    }

    if (nodo != nullptr) {
      os << "[" << nodo->dato_ << "] ";
      cola.push({nodo->izdo_, nivel + 1});
      cola.push({nodo->dcho_, nivel + 1});
    } else {
      os << "[.] ";
    }
  }

  return os;
}

#endif