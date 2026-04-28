#include <iostream>

#include "../include/abb.h"
#include "../include/nif.h"

void TestUnitario() {
  ABB<nif> arbol;

  arbol.insertar(nif(2));   // primo
  arbol.insertar(nif(3));   // primo
  arbol.insertar(nif(4));   // no primo
  arbol.insertar(nif(5));   // primo
  arbol.insertar(nif(6));   // no primo
  arbol.insertar(nif(7));   // primo
  arbol.insertar(nif(11));  // primo

  const int resultado = arbol.ContarPrimos();

  std::cout << "Numero de primos esperado: 5\n";
  std::cout << "Numero de primos obtenido: " << resultado << "\n";

  if (resultado == 5) { //Assert
    std::cout << "OK\n";
  } else {
    std::cout << "KO\n";
  }
}

int main() {
  TestUnitario();
  return 0;
}