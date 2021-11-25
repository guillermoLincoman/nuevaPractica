/*
 * controller.h
 *
 *  Created on: 22 nov. 2021
 *      Author: Compumar
 */
#include "libros.h"
#include "editorial.h"
#include "LinkedList.h"
#include "parser.h"
#include "menu.h"
#ifndef CONTROLLER_H_
#define CONTROLLER_H_

int controller_ultimoIdLibros(LinkedList* pArrayListLibros);
int controller_ultimoIdEditoriales(LinkedList* pArrayListEditoriales);
int controller_buscarIdLibros(LinkedList* pArrayListLibros, int id);
int controller_buscarIdEditorial(LinkedList* pArrayListEditoriales, int id);
int controller_loadFromTextLibros(LinkedList* pArrayListLibros);
int controller_loadFromTextEditoriales(LinkedList* pArrayListEditoriales);
int controller_sortAutorAscendente(LinkedList* pArrayListLibros, LinkedList* pArrayListEditorial);
int controller_ListLibros(LinkedList* pArrayListLibros, LinkedList* pArrayListEditoriales);
int controller_ListEditorial(LinkedList* pArrayListEditoriales);
int controller_filtrarMinotauro(LinkedList* pArrayListLibros, LinkedList* pArrayListEditoriales);
int controller_saveAsText(char* path, LinkedList* pArrayListLibros);
int controller_librosSinEditPlaneta(LinkedList* pArrayListLibros, LinkedList* pArrayListEditoriales);
void controller_cantLibrosMayorAMil(LinkedList* pArrayListLibros);
//int controller_editorialConMasLibros(LinkedList* pArrayListLibros, LinkedList* pArrayListEditoriales);
int controller_addLibro(LinkedList* pArrayListLibros, LinkedList* pArrayListEditoriales);
int controller_addEditorial(LinkedList* pArrayListEditoriales);
int controller_editLibro(LinkedList* pArrayListLibros, LinkedList* pArrayListEditoriales);
int controller_editEditoriales(LinkedList* pArrayListEditoriales);
int controller_removeLibro(LinkedList* pArrayListLibros, LinkedList* pArrayListEditoriales);
int controller_removEditorial(LinkedList* pArrayListLibros, LinkedList* pArrayListEditoriales);
#endif /* CONTROLLER_H_ */
