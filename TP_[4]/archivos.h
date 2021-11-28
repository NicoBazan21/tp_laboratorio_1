#ifndef ARCHIVOS_H_INCLUDED
#define ARCHIVOS_H_INCLUDED
#include "linkedList.h"



#endif // ARCHIVOS_H_INCLUDED

int arch_loadFromText(char* path , LinkedList* pArrayListaPersonas);
int arch_parsearPersonaPorTexto(FILE* pFile , LinkedList* pArrayListaPersonas);

int arch_ListarPersonas(LinkedList* pArrayListaPersonas);
int arch_findPersonaById(LinkedList* pArrayListaPersonas);

int arch_addEmployee(LinkedList* pArrayListaPersonas);
int arch_editarPersonas(LinkedList* pArrayListaPersonas);
int arch_bajaPersona(LinkedList* pArrayListaPersonas);
int arch_sortPersonas(LinkedList* pArrayListaPersonas);
