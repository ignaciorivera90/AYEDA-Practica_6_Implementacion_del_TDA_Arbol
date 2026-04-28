#include <ctime>
#include <cstdlib>
#include <iostream>

#include "../include/ab.h"
#include "../include/abe.h"
#include "../include/abb.h"
#include "../include/arg_parser.h"
#include "../include/functions.h"
#include "../include/nif.h"
#include "../include/tree_exception.h"

int main(int argc, char* argv[]) {
  srand(time(nullptr));

  try {
    ArgParser args(argc, argv);

    AB<nif>* arbol = nullptr;

    if (args.GetTreeType() == kABE) {
      arbol = new ABE<nif>();
    } else {
      arbol = new ABB<nif>();
    }

    switch (args.GetInitMode()) {
      case kManual:
        InitManual(arbol);
        break;

      case kRandom:
        InitRandom(arbol, args.GetSize());
        break;

      case kFile:
        InitFile(arbol, args.GetSize(), args.GetFilename());
        break;
    }

    Menu(arbol, args.GetTreeTypeName(), args.GetInitModeName());

    delete arbol;

  } catch (const TreeException& error) {
    std::cerr << "Error: " << error.what() << "\n";
    std::cerr << "Uso: ./p06_arboles -ab <abe|abb> -init <manual|random|file> [s] [f]\n";
    return 1;
  }

  return 0;
}