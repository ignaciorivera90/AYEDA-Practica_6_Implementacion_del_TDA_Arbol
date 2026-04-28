#ifndef NODO_B_H
#define NODO_B_H

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