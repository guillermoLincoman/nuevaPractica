/*
 ============================================================================
 Name        : SPL_Lincoman.c
 Author      : Guillermo Lincoman
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include "controller.h"

int main(void) {
{
		setbuf(stdout, NULL);
		LinkedList* libros = ll_newLinkedList();
		LinkedList* editoriales = ll_newLinkedList();
		int flagLibro;
		int flagEditorial;
		int flagCargaLibro;
		int flagCargaEdit;
		int opcion;
		flagCargaEdit = 1;
		flagCargaLibro = 1;
		flagLibro = 1;
		flagEditorial= 1;
		do{
			menuPrincipal();
			opcion = cargarUnEntero("Ingrese una opcion: ", "Error, ingrese una opcion", 1, 14, 4);
			switch(opcion)
			{
				case 1:
					if(flagCargaLibro == 1)
					{
						limpiar();
						printf("+==========================+\n");
						printf("| CARGAR ARCHIVO DE LIBROS |\n");
						printf("+==========================+\n");
						flagEditorial= controller_loadFromTextLibros(libros);
						if(flagEditorial == 0){
							printf("\nEl archivo fue cargado con exito....\n");
							flagCargaLibro = 0;
						}else{
							printf("\nHubo un error al cargar el archivo....\n");
							flagEditorial= 1;
						}
					}else{
						printf("\nEl archivo ya fue cargado....\n");
					}
					limpiar();
					break;
				case 2:
					if(flagCargaEdit == 1)
					{
						if(flagEditorial == 0)
						{
							limpiar();
							printf("+===============================+\n");
							printf("| CARGAR ARCHIVO DE EDITORIALES |\n");
							printf("+===============================+");
							flagLibro= controller_loadFromTextEditoriales(editoriales);
							if(flagLibro == 0){
								printf("\nEl archivo fue cargado con exito....\n");
								controller_ListEditorial(editoriales);
								flagCargaEdit = 0;
							}else{
								printf("\nHubo un error al cargar el archivo....\n");
							}
						}else{
							printf("\nPara cargar el archivo editoriales debe cargar el archivo de libros....\n");
						}
					}else{
						printf("\nEl archivo ya fue cargado....\n");
					}
					limpiar();
					break;
				case 3:
					if(flagLibro == 0){
						controller_sortAutorAscendente(libros, editoriales);
					}else{
						printf("\nPara Ordenar Libros, cargue los archivos de libros y editoriales....\n");
					}
					limpiar();
					break;
				case 4:
					if(flagLibro == 0){
						controller_ListLibros(libros, editoriales);
					}else{
						printf("\nPara Listar Libros, cargue los archivos de libros y editoriales....\n");
					}
					limpiar();
					break;
				case 5:
					if(flagLibro == 0){
						controller_filtrarMinotauro(libros, editoriales);
					}else{
						printf("\nPara Filtrar una editorial, cargue los archivos de libros y editoriales....\n");
					}
					limpiar();
					break;
				case 6:
					if(flagLibro == 0){
						controller_librosSinEditPlaneta(libros, editoriales);
					}else{
						printf("\nPara Filtrar una editorial, cargue los archivos de libros y editoriales....\n");
					}
					limpiar();
					break;
				case 7:
					if(flagLibro == 0){
						controller_cantLibrosMayorAMil(libros);
					}else{
						printf("\nPara Calcular la Cantidad de Libros menor a 1000, cargue los archivos de libros y editoriales....\n");
					}
					limpiar();
					break;
				case 8:
					if(flagEditorial == 0){
						controller_addLibro(libros, editoriales);
					}else{
						printf("\nPara Cargar un libro, cargue el archivo de editoriales ....\n");
					}
					limpiar();
					break;
				case 9:
					if(flagEditorial == 0){
						controller_addEditorial(editoriales);
					}else{
						printf("\nPara Cargar una editorial primer,  cargue un archivo de editorial....\n");
					}
					limpiar();
					break;
				case 10:
					if(flagLibro == 0){
						controller_editLibro(libros, editoriales);
					}else{
						printf("\nPara Modificar un libro primero,  cargue un archivo de libros ....\n");
					}
					limpiar();
					break;
				case 11:
					if(flagLibro == 0){
						controller_editEditoriales(editoriales);
					}else{
						printf("\nPara Modificar una editorial primero,  cargue un archivo de editoriales ....\n");
					}

					limpiar();
					break;
				case 12:
					if(flagLibro == 0){
						controller_removeLibro(libros, editoriales);
					}else{
						printf("\nPara Borrar un libro primero,  cargue un archivo de libros ....\n");
					}

					limpiar();
					break;
				case 13:
					if(flagLibro == 0){
						controller_removEditorial(libros, editoriales);
					}else{
						printf("\nPara Borrar una editorial primero,  cargue un archivo de editoriales ....\n");
					}

					limpiar();
					break;
			}
		}while(opcion != 14);

	    return 0;
	}
}
