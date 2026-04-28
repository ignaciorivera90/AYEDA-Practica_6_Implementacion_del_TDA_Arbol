#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <string>

#include "ab.h"
#include "abe.h"
#include "abb.h"
#include "nif.h"

void ClearScreen();
void Pause();

void InitManual(AB<nif>* arbol);
void InitRandom(AB<nif>* arbol, int size);
void InitFile(AB<nif>* arbol, int size, const std::string& filename);

void Menu(AB<nif>* arbol, const std::string& tree_type,
          const std::string& init_mode);

void SaveTreeToFile(AB<nif>* arbol);
void InsertNNodes(AB<nif>* arbol);
void SearchThreeNodes(AB<nif>* arbol);

#endif