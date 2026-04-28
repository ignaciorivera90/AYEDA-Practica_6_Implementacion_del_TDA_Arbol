// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Algoritmos y Estructuras de Datos Avanzadas
// Curso: 2º
// Práctica 6: Implementación del TDA Árbol
// Autor: Ignacio Andres Rivera Barrientos
// Correo: alu0101675053@ull.edu.es
// Fecha: 27/04/2026
// Archivo: functions.h
// Descripción: Declaracion de funciones auxiliares para la gestión del árbol
// y del menú interactivo.

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

void Menu(AB<nif>* arbol, const std::string& tree_type, const std::string& init_mode);

void SaveTreeToFile(AB<nif>* arbol);
void InsertNNodes(AB<nif>* arbol);
void SearchThreeNodes(AB<nif>* arbol);

#endif