#include "../include/functions.h"

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <limits>

#include "../include/tree_exception.h"

void ClearScreen() {
#ifdef _WIN32
  system("cls");
#else
  system("clear");
#endif
}

void Pause() {
  std::cout << "\nPulsa ENTER para continuar...";
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  std::cin.get();
}

void InitManual(AB<nif>* arbol) {
  std::cout << "Arbol vacio\n";
  std::cout << *arbol << std::endl;
}

void InitRandom(AB<nif>* arbol, int size) {
  if (size <= 0) {
    throw TreeException("El numero de elementos debe ser mayor que 0.");
  }

  for (int i = 0; i < size; ++i) {
    long value = 10000000 + rand() % 90000000;
    arbol->insertar(nif(value));
  }

  std::cout << *arbol << std::endl;
}

void InitFile(AB<nif>* arbol, int size, const std::string& filename) {
  if (size <= 0) {
    throw TreeException("El numero de elementos debe ser mayor que 0.");
  }

  std::ifstream file(filename);
  if (!file) {
    throw TreeException("No se pudo abrir el fichero de entrada.");
  }

  nif clave;
  int count = 0;

  while (file >> clave && count < size) {
    arbol->insertar(clave);
    ++count;
  }

  std::cout << *arbol << std::endl;
}

void SaveTreeToFile(AB<nif>* arbol) {
  std::string filename;

  std::cout << "Nombre del fichero: ";
  std::cin >> filename;

  std::string path = "../docs/" + filename;
  std::ofstream file(path);

  if (!file) {
    throw TreeException("No se pudo crear el fichero en ../docs/.");
  }

  file << *arbol << std::endl;

  std::cout << "Arbol guardado correctamente en " << path << "\n";
}

void InsertNNodes(AB<nif>* arbol) {
  int n;

  std::cout << "Cuantos nodos quieres insertar?: ";
  std::cin >> n;

  if (n <= 0) {
    throw TreeException("El numero de nodos debe ser mayor que 0.");
  }

  for (int i = 0; i < n; ++i) {
    nif clave;

    std::cout << "Clave " << i + 1 << ": ";
    std::cin >> clave;

    if (arbol->insertar(clave)) {
      std::cout << "Clave insertada correctamente.\n";
    } else {
      std::cout << "Advertencia: la clave ya existe y no se inserto.\n";
    }
  }
}

void SearchThreeNodes(AB<nif>* arbol) {
  for (int i = 0; i < 3; ++i) {
    nif clave;
    int comparaciones = 0;

    std::cout << "Introduce la clave " << i + 1 << " a buscar: ";
    std::cin >> clave;

    bool found = arbol->buscarConComparaciones(clave, comparaciones);

    if (found) {
      std::cout << "Clave encontrada. Comparaciones: " << comparaciones << "\n";
    } else {
      std::cout << "Clave no encontrada. Comparaciones: " << comparaciones << "\n";
    }
  }
}

void Menu(AB<nif>* arbol, const std::string& tree_type,
          const std::string& init_mode) {
  int option = -1;

  while (option != 0) {
    try {
      ClearScreen();

      std::cout << "====================================\n";
      std::cout << " Practica 6 - TDA Arbol\n";
      std::cout << " Tipo de arbol: " << tree_type << "\n";
      std::cout << " Inicializacion: " << init_mode << "\n";
      std::cout << "====================================\n\n";

      std::cout << "Estado actual del arbol:\n";
      std::cout << *arbol << "\n\n";

      std::cout << "[0] Salir\n";
      std::cout << "[1] Insertar clave\n";
      std::cout << "[2] Buscar clave\n";
      std::cout << "[3] Mostrar arbol inorden\n";
      std::cout << "[4] Guardar estado actual\n";
      std::cout << "[5] Insertar N nodos\n";
      //std::cout << "[6] Buscar 3 nodos con comparaciones\n";
      std::cout << "Opcion: ";
      std::cin >> option;

      if (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        throw TreeException("Entrada no valida.");
      }

      ClearScreen();

      switch (option) {
        case 0:
          std::cout << "Saliendo...\n";
          break;

        case 1: {
          nif clave;

          std::cout << "Introduce la clave: ";
          std::cin >> clave;

          if (arbol->insertar(clave)) {
            std::cout << "Clave insertada correctamente.\n";
          } else {
            std::cout << "Advertencia: la clave ya existe.\n";
          }

          std::cout << "\nArbol resultante:\n";
          std::cout << *arbol << "\n";

          Pause();
          break;
        }

        case 2: {
          nif clave;

          std::cout << "Introduce la clave: ";
          std::cin >> clave;

          if (arbol->buscar(clave)) {
            std::cout << "La clave se encuentra en el arbol.\n";
          } else {
            std::cout << "Advertencia: la clave no se encuentra en el arbol.\n";
          }

          Pause();
          break;
        }

        case 3:
          std::cout << "Recorrido inorden:\n";
          arbol->inorden();
          Pause();
          break;

        case 4:
          SaveTreeToFile(arbol);
          Pause();
          break;

        case 5:
          InsertNNodes(arbol);
          std::cout << "\nArbol resultante:\n";
          std::cout << *arbol << "\n";
          Pause();
          break;

        //case 6:
        //  SearchThreeNodes(arbol);
        //  Pause();
        //  break;

        default:
          std::cout << "Advertencia: opcion no valida.\n";
          Pause();
          break;
      }

    } catch (const TreeException& error) {
      std::cout << "Advertencia: " << error.what() << "\n";
      Pause();
    }
  }
}