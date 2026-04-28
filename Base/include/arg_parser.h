// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Algoritmos y Estructuras de Datos Avanzadas
// Curso: 2º
// Práctica 6: Implementación del TDA Árbol
// Autor: Ignacio Andres Rivera Barrientos
// Correo: alu0101675053@ull.edu.es
// Fecha: 27/04/2026
// Archivo: arg_parser.h
// Descripción: Clase encargada de procesar los argumentos de entrada del programa.

#ifndef ARG_PARSER_H
#define ARG_PARSER_H

#include <string>
#include "tree_exception.h"

enum TreeType {
  kABE,
  kABB
};

enum InitMode {
  kManual,
  kRandom,
  kFile
};

/**
 * @brief Parses command-line arguments
 */
class ArgParser {
 public:
  ArgParser(int argc, char* argv[]) {
    if (argc < 5) {
      throw TreeException("Numero de argumentos insuficiente.");
    }

    if (std::string(argv[1]) != "-ab") {
      throw TreeException("Falta el parametro -ab <abe|abb>.");
    }

    if (std::string(argv[3]) != "-init") {
      throw TreeException("Falta el parametro -init <manual|random|file>.");
    }

    std::string tree_type = argv[2];
    std::string init_mode = argv[4];

    if (tree_type == "abe") {
      tree_type_ = kABE;
    } else if (tree_type == "abb") {
      tree_type_ = kABB;
    } else {
      throw TreeException("Tipo de arbol no valido. Usa abe o abb.");
    }

    if (init_mode == "manual") {
      init_mode_ = kManual;
      size_ = 0;
    } else if (init_mode == "random") {
      if (argc < 6) {
        throw TreeException("Falta el numero de elementos para random.");
      }
      init_mode_ = kRandom;
      size_ = std::stoi(argv[5]);
    } else if (init_mode == "file") {
      if (argc < 7) {
        throw TreeException("Falta el numero de elementos o el fichero para file.");
      }
      init_mode_ = kFile;
      size_ = std::stoi(argv[5]);
      filename_ = argv[6];
    } else {
      throw TreeException("Modo de inicializacion no valido.");
    }
  }

  TreeType GetTreeType() const { return tree_type_; }
  InitMode GetInitMode() const { return init_mode_; }
  int GetSize() const { return size_; }
  std::string GetFilename() const { return filename_; }

  std::string GetTreeTypeName() const {
    return tree_type_ == kABE ? "ABE" : "ABB";
  }

  std::string GetInitModeName() const {
    if (init_mode_ == kManual) return "manual";
    if (init_mode_ == kRandom) return "random";
    return "file";
  }

 private:
  TreeType tree_type_;
  InitMode init_mode_;
  int size_;
  std::string filename_;
};

#endif