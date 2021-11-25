/*
 * menu.c
 *
 *  Created on: 18 nov. 2021
 *      Author: Compumar
 */

#include "menu.h"

void menuPrincipal()
{
    printf("\n\n______________________________________________\n");
    printf("||==========================================||\n");
    printf("||================LIBROS  UTN===============||\n");
    printf("||==========================================||\n");
    printf("||==============MENU PRINCIPAL==============||\n");
    printf("||==========================================||\n");
	printf("||                                          ||\n");
    printf("|| 1. Cargar archivo de Libros              ||\n");
    printf("|| 2. Cargar archivo de Editoriales         ||\n");
    printf("|| 3. Ordenar lista por autor ascendente    ||\n");
    printf("|| 4. Listar libros                         ||\n");
    printf("|| 5. Listar libros editorial MINOTAURO     ||\n");
    printf("|| 6. Generar arch lib sin editorial PLANETA||\n");
    printf("|| 7. Cant de lib precio menor a 1000       ||\n");
    printf("|| 8. Alta libro                            ||\n");
    printf("|| 9. Alta Editorial                        ||\n");
    printf("|| 10. Modificar Libro                      ||\n");
    printf("|| 11. Modificar Editorial                  ||\n");
    printf("|| 12. Baja libro                           ||\n");
    printf("|| 13. Baja Editorial                       ||\n");
    printf("|| 14. Salir                                ||\n");
	printf("||__________________________________________||\n");
}

void menuModificarLibro()
{
    printf("\n\n________________________\n");
    printf("||=====================||\n");
    printf("||=====LIBROS  UTN=====||\n");
    printf("||=====================||\n");
    printf("||===MENU MODIFICAR====||\n");
    printf("||=====================||\n");
	printf("||                     ||\n");
    printf("|| 1. TITULO           ||\n");
    printf("|| 2. AUTOR            ||\n");
    printf("|| 3. PRECIO           ||\n");
    printf("|| 4. EDITORIAL        ||\n");
    printf("|| 0. SALIR            ||\n");
	printf("||_____________________||\n");
}


void menuModificarEditorial()
{
    printf("\n\n________________________\n");
    printf("||=====================||\n");
    printf("||===EDITORIALES  UTN==||\n");
    printf("||=====================||\n");
    printf("||===MENU MODIFICAR====||\n");
    printf("||=====================||\n");
	printf("||                     ||\n");
    printf("|| 1. NOMBRE           ||\n");
    printf("|| 0. SALIR            ||\n");
	printf("||_____________________||\n");
}
void menuLibros()
{
    printf("\n\n________________________________________________________\n");
    printf("||====================================================||\n");
    printf("||==========INGRESE LA DIRECCION DEL ARCHIVO==========||\n");
    printf("||======================LIBROS========================||\n");
    printf("||===================MENU ARCHIVO=====================||\n");
    printf("||====================================================||\n");
	printf("||                                                    ||\n");
    printf("|| 1. libros.csv (Recomendable en consola de eclipse) ||\n");
    printf("|| 2. ../libros.csv (Recomendable en archivo .exe)    ||\n");
    printf("|| 3. Ingresar manualmente                            ||\n");
    printf("|| 4. Salir                                           ||\n");
	printf("||____________________________________________________||\n");
}

void menuEditoriales()
{
    printf("\n\n_____________________________________________________________\n");
    printf("||=========================================================||\n");
    printf("||=============INGRESE LA DIRECCION DEL ARCHIVO============||\n");
    printf("||========================EDITORIALES======================||\n");
    printf("||=======================MENU ARCHIVO======================||\n");
    printf("||=========================================================||\n");
	printf("||                                                         ||\n");
    printf("|| 1. editoriales.csv (Recomendable en consola de eclipse) ||\n");
    printf("|| 2. ../editoriales.csv (Recomendable en archivo .exe)    ||\n");
    printf("|| 3. Ingresar manualmente                                 ||\n");
    printf("|| 4. Salir                                                ||\n");
	printf("||_________________________________________________________||\n");
}


