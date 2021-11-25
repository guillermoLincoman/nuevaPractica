/*
 * controller.c
 *
 *  Created on: 22 nov. 2021
 *      Author: Compumar
 */

#include "controller.h"

/** \brief Busca el ultimo Id cargado en la lista libros
 *
 * \param LinkedList* pArrayListLibros = lista para analizar
 *
 * \return int ultimoId = Retorna el ultimo id de la lista +1, en caso de error retorna -1
 * 						  en caso de que la lista no tenga ningun libro la funcion devuelve 1 como el primer id
 *
 */
int controller_ultimoIdLibros(LinkedList* pArrayListLibros)
{
	int ultimoId;
	int len;
	eLibros* libro;
	ultimoId = -2;//en caso de error retorna -1 ->retorno ultimoId +1

	if(pArrayListLibros != NULL)
	{

		//1. obtengo el tamaño de la lista
		len = ll_len(pArrayListLibros);
		if(len > 0)
		{
			//2. Obtengo el empleado que tiene el ultimo id
			libro = ll_get(pArrayListLibros, len-1);
			if(libro != NULL)
			{

				libros_getIdLibro(libro, &ultimoId);
			}
		}else{
			ultimoId = 0;
		}
	}
	//3. Retorno el id del ultimo empleado +1
	return ultimoId+1;
}

/** \brief Busca el ultimo Id cargado en la lista editoriales
 *
 * \param LinkedList* pArrayListEditoriales = lista para analizar
 *
 * \return int ultimoId = Retorna el ultimo id de la lista +1, en caso de error retorna -1
 * 						  en caso de que la lista no tenga ningun editorial la funcion devuelve 1 como el primer id
 *
 */
int controller_ultimoIdEditoriales(LinkedList* pArrayListEditoriales)
{
	int ultimoId;
	int len;
	eEditorial* editorial;
	ultimoId = -2;//en caso de error retorna -1 ->retorno ultimoId +1

	if(pArrayListEditoriales != NULL)
	{

		//1. obtengo el tamaño de la lista
		len = ll_len(pArrayListEditoriales);
		if(len > 0)
		{
			//2. Obtengo el empleado que tiene el ultimo id
			editorial = ll_get(pArrayListEditoriales, len-1);
			if(editorial != NULL)
			{

				editorial_getIdEditorial(editorial, &ultimoId);
			}
		}else{
			ultimoId = 0;
		}
	}
	//3. Retorno el id del ultimo empleado +1
	return ultimoId+1;
}

/** \brief Busca la posicion de un empleado segun el id
 *
 * \param pArrayListEmployee LinkedList* = lista para analizar
 * \param int id = id a buscar en la lista de empleados
 *
 * \return int ultimoId = Retorna el la posicion del empleado que coincide con el id,
 * 						  en caso de error retorna -1
 *
 */
int controller_buscarIdLibros(LinkedList* pArrayListLibros, int id)
{
	int posError;
	int i;
	int len;
	eLibros* libroId;
	posError = -1;
	if(pArrayListLibros != NULL && id >= 0)
	{
		//1.Obtengo el tamaño de la lista
		len = ll_len(pArrayListLibros);
		//2.Recorro la lista
		for (i = 0; i < len; ++i) {
			//3.Analizo empleado por empleado hasta encontrar el buscado
			libroId = ll_get(pArrayListLibros, i);
			if(libroId != NULL)
			{
				//4 Obtengo el id del empleado
				libros_getIdLibro(libroId, &posError);
				//5.Valido si es el id que busco
				if(id==posError)
				{
					//6. Cargo el index del empleado buscado, libero memoria y rompo la condicion
					posError = i;
					break;
				}
			}
		}
	}

	return posError;
}

/** \brief Busca la posicion de un empleado segun el id
 *
 * \param pArrayListEmployee LinkedList* = lista para analizar
 * \param int id = id a buscar en la lista de empleados
 *
 * \return int ultimoId = Retorna el la posicion del empleado que coincide con el id,
 * 						  en caso de error retorna -1
 *
 */
int controller_buscarIdEditorial(LinkedList* pArrayListEditoriales, int id)
{
	int posError;
	int i;
	int len;
	eEditorial* editorialId;
	posError = -1;
	if(pArrayListEditoriales != NULL && id >= 0)
	{
		//1.Obtengo el tamaño de la lista
		len = ll_len(pArrayListEditoriales);
		//2.Recorro la lista
		for (i = 0; i < len; ++i) {
			//3.Analizo empleado por empleado hasta encontrar el buscado
			editorialId = ll_get(pArrayListEditoriales, i);
			if(editorialId != NULL)
			{
				//4 Obtengo el id del empleado
				editorial_getIdEditorial(editorialId, &posError);
				//5.Valido si es el id que busco
				if(id==posError)
				{
					//6. Cargo el index del empleado buscado, libero memoria y rompo la condicion
					posError = i;
					break;
				}
			}
		}
	}

	return posError;
}


/** \brief Carga los datos de los libros desde el archivo libros.csv (modo texto).
 *
 * \param LinkedList* pArrayListLibros = Lista donde se cargan los datos
 *
 * \return int error = Si los datos se cargan correctamente retorna 0, en caso de error retorna 1
 *
 */
int controller_loadFromTextLibros(LinkedList* pArrayListLibros)
{
	int error;
	char path[128];
	FILE* pArchivo;
	error = 1;
	ingresarPath(path, menuLibros, "libros.csv", "../libros.csv");
	if(path != NULL && pArrayListLibros != NULL)
	{
		//1. Abro el archivo en modo escritura

		pArchivo = fopen(path, "r");
		if(pArchivo != NULL)
		{
			//2. Si hay un error devuelve 1, si funciona retorna 0
			error = parser_LibrosFromText(pArchivo, pArrayListLibros);
		}
		//3. Cierro el archivo
		fclose(pArchivo);
	}

    return error;
}

/** \brief Carga los datos de las Editoriales desde el archivo libros.csv (modo texto).
 *
 * \param LinkedList* pArrayListEditoriales = Lista donde se cargan los datos
 *
 * \return int error = Si los datos se cargan correctamente retorna 0, en caso de error retorna 1
 *
 */
int controller_loadFromTextEditoriales(LinkedList* pArrayListEditoriales)
{
	int error;
	char path[128];
	FILE* pArchivo;
	error = 1;

	if(path != NULL && pArrayListEditoriales != NULL)
	{
		//1. Abro el archivo en modo escritura
		ingresarPath(path, menuEditoriales, "editoriales.csv", "../editoriales.csv");
		pArchivo = fopen(path, "r");
		if(pArchivo != NULL)
		{
			//2. Si hay un error devuelve 1, si funciona retorna 0
			error = parser_EditorialFromText(pArchivo, pArrayListEditoriales);
		}
		//3. Cierro el archivo
		fclose(pArchivo);
	}

    return error;
}

/** \brief Listar Libros
 *
 * \param LinkedList* pArrayListLibros = lista de libros para mostrar
 * \param LinkedList* pArrayListEditoriales = lista con las descripciones de editoriales
 *
 * \return int error = En caso de error retorna 1, si puede listar a los empleados retorna 0
 *
 */
int controller_ListLibros(LinkedList* pArrayListLibros, LinkedList* pArrayListEditoriales)
{
	int error;
	int i;
	int j;
	int len;
	int lenAutores;
	eLibros* newLibros;
	newLibros = libros_new();
	eEditorial* newEditorial;
	newEditorial = editorial_new();
	int idEditorial;
	int auxIdEditorial;
	error = 1;
	if(newLibros != NULL && pArrayListLibros != NULL && newEditorial != NULL && pArrayListEditoriales != NULL)
	{
		len = ll_len(pArrayListLibros);
		lenAutores = ll_len(pArrayListEditoriales);
		if(len > 1)
		{
			error = 0;
			printf("\n\n____________________________________________________________________________________________________________\n");
			printf("||========================================================================================================||\n");
			printf("||==============================================LIBROS UTN================================================||\n");
			printf("||________________________________________________________________________________________________________||\n");
			printf("|| ID LIBRO |             TITULO               |          AUTOR          |  PRECIO  |      EDITORIAL      ||\n");
			printf("||__________|__________________________________|_________________________|__________|_____________________||\n");

			for (i = 0; i < len; ++i) {
				newLibros = ll_get(pArrayListLibros, i);
				libros_getIdEditorial(newLibros, &idEditorial);
				for (j = 0; j < lenAutores; ++j) {
					newEditorial = ll_get(pArrayListEditoriales, j);
					editorial_getIdEditorial(newEditorial, &auxIdEditorial);
					if(idEditorial == auxIdEditorial){
						break;
					}
				}
				printf("||----------|----------------------------------|-------------------------|----------|---------------------||\n");


				libros_printLibros(newLibros, newEditorial);
				if(len-1 == i){
					printf("||__________|__________________________________|_________________________|__________|_____________________||\n");
				}
			}

		}
	}

    return error;
}

/** \brief Listar Libros
 *
 * \param LinkedList* pArrayListLibros = lista de libros para mostrar
 * \param LinkedList* pArrayListEditoriales = lista con las descripciones de editoriales
 *
 * \return int error = En caso de error retorna 1, si puede listar a los empleados retorna 0
 *
 */
int controller_ListEditorial(LinkedList* pArrayListEditoriales)
{
	int error;
	int i;
	int len;
	eEditorial* newEditorial;
	newEditorial = editorial_new();
	error = 1;
	if(pArrayListEditoriales != NULL)
	{
		len = ll_len(pArrayListEditoriales);
		if(len > 1)
		{
			error = 0;
			printf("\n\n________________________________________\n");
			printf("||====================================||\n");
			printf("||=========== EDITORIALES ============||\n");
			printf("||____________________________________||\n");
			printf("|| ID EDITORIAL |      EDITORIAL      ||\n");
			printf("||______________|_____________________||\n");

			for (i = 0; i < len; ++i) {
				newEditorial = ll_get(pArrayListEditoriales, i);

				printf("||--------------|---------------------||\n");
				editorial_printEditorial(newEditorial);
				if(len-1 == i){
					printf("||______________|_____________________||\n");
				}
			}
		}
	}
    return error;
}

/** \brief Ordenar Libros según el criterio de ordenamiento “Autor” de manera ascendente.
 *
 * \param LinkedList* pArrayListLibros = lista que se va a clonar para odenar y mostrar
 * \param LinkedList* pArrayListEditorial = lista utilizada para tomar la descripcion de las editoriales
 *
 * \return int error = Si la lista se puede ordenar retorna 0, en caso de error retorna 1
 *
 */
int controller_sortAutorAscendente(LinkedList* pArrayListLibros, LinkedList* pArrayListEditorial)
{
	int error;
	LinkedList* clone;
	error = 1;
	if(pArrayListLibros != NULL)
	{
		clone = ll_clone(pArrayListLibros);

		error = ll_sort(clone, libros_compareByAutor,0);
		controller_ListLibros(clone, pArrayListEditorial);
		ll_deleteLinkedList(clone);
	}
    return error;
}

/** \brief Lista los libros de la editorial MINOTAURO
 *
 * \param LinkedList* pArrayListLibros = lista que se va a filtrar para odenar y mostrar
 * \param LinkedList* pArrayListEditorial = lista utilizada para tomar la descripcion de las editoriales
 *
 * \return int error = Si la lista se puede filtrar retorna 0, en caso de error retorna 1
 *
 */
int controller_filtrarMinotauro(LinkedList* pArrayListLibros, LinkedList* pArrayListEditoriales)
{
	int error;
	LinkedList* listaMinotauro = NULL;
	error = 1;
	if(pArrayListLibros != NULL)
	{
		listaMinotauro = ll_filter(pArrayListLibros, libros_filtrarEditorialMinotauro);

		if(listaMinotauro != NULL)
		{
			error = 0;
			controller_ListLibros(listaMinotauro, pArrayListEditoriales);
		}
	}
	return error;
}

int controller_saveAsText(char* path, LinkedList* pArrayListLibros)
{
	int id;
	char titulo[128];
	char autor[128];
	int precio;
	int idEditorial;
	int len;
	int i;
	int error;
	eLibros* newLibros;
	FILE* pArchivo;
	error = 1;

	if(pArrayListLibros != NULL)
	{
		//1. Abro el archivo en modo escritura
		pArchivo = fopen(path, "w");

		//2. Asigno espacio en memoria para el puntero a empleado
		newLibros = libros_new();

		//3. Obtengo el tamaño de la lista
		len = ll_len(pArrayListLibros);

		//4. Coloco la cabecera
		fprintf(pArchivo, "id,titulo,autor,precio,idEditorial\n");
		for(i=0; i<len;i++)
		{
			//5. obtengo el empleado con sus datos
			newLibros = ll_get(pArrayListLibros, i);
			if(newLibros != NULL)
			{
				//6. le paso los datos el empleado a las variables
				libros_getAutor(newLibros, autor);
				libros_getIdEditorial(newLibros, &idEditorial);
				libros_getIdLibro(newLibros, &id);
				libros_getPrecio(newLibros, &precio);
				libros_getTitulo(newLibros, titulo);
				//7. Escribo los datos del empleado en el archivo
				fprintf(pArchivo, "%d,%s,%s,%d,%d\n", id,titulo,autor,precio,idEditorial);
				error = 0;
			}else{
				error = 1;
				break;
			}
		}
		fclose(pArchivo);
	}

    return error;
}

int controller_librosSinEditPlaneta(LinkedList* pArrayListLibros, LinkedList* pArrayListEditoriales)
{
	int error;
	LinkedList* librosSinPlaneta = NULL;
	error = 1;
	if(pArrayListLibros != NULL && pArrayListEditoriales != NULL)
	{
		librosSinPlaneta = ll_newLinkedList();
		if(librosSinPlaneta != NULL)
		{
			printf("*-------------------------------------*\n");
			printf("| GUARDAR LISTA SIN EDITORIAL PLANETA |\n");
			printf("*-------------------------------------*");
			librosSinPlaneta = ll_filter(pArrayListLibros, libros_filtrarEditorialSinPlaneta);
			error = controller_saveAsText("../guardarLista.csv",librosSinPlaneta);
			if(error == 0){
				printf("\nEl archivo con libros sin edicion planeta fue creado con exito...\n");
				controller_ListLibros(librosSinPlaneta, pArrayListEditoriales);
			}
		}
	}
	return error;
}

void controller_cantLibrosMayorAMil(LinkedList* pArrayListLibros)
{
	int cant;
	if(pArrayListLibros != NULL)
	{
			cant = ll_count(pArrayListLibros, libros_librosPrecioMayorAMil);
			printf("\nLa cantidad de libros que el precio es menor a $1000 es: %d\n", cant);
	}
}

/** \brief Alta de Libro
 *
 * \param LinkedList* pArrayListLibros = lista donde se carga los libros
 *
 * \return int error = Si carga al libro retorna 0, en caso de error retorna 1
 *
 */
int controller_addLibro(LinkedList* pArrayListLibros, LinkedList* pArrayListEditoriales)
{
	eLibros* newLibro;
	int error;
	int ultimoId;
	char autor[128];
	char titulo[128];
	int precio;
	int editorial;
	int aux;
	int len;
	int confirmar;
	error = 1;

	if(pArrayListLibros != NULL && pArrayListEditoriales != NULL)
	{
		newLibro = libros_new();

		if(newLibro != NULL)
		{
			printf("+====================+\n");
			printf("| CARGAR NUEVO LIBRO |\n");
			printf("+====================+\n\n");
			ultimoId = controller_ultimoIdLibros(pArrayListLibros);

			libros_setIdLibro(newLibro, ultimoId);

			getString(titulo, "Ingresar titulo: ", "Error, ingrese un titulo valido: ", 1, 125, 4);
			libros_setTitulo(newLibro, titulo);

			getUsuario(autor, "Ingresar el nombre del autor: ", "Error, ingrese un nombre valido: ", 1, 128, 4);
			libros_setAutor(newLibro, autor);

			precio = cargarUnEntero("Ingrese el precio: $", "Error, ingrese un precio valido (entre 100 y 10000): $", 100, 10000, 4);
			libros_setPrecio(newLibro, precio);

			controller_ListEditorial(pArrayListEditoriales);
			len = ll_len(pArrayListEditoriales);
			editorial = cargarUnEntero("Seleccione una editorial: ", "Error, seleccione una editorial valida: ", 1, len, 4);
			libros_setIdEditorial(newLibro, editorial);


			limpiar();
			libros_printLibrosCabecera(newLibro, pArrayListEditoriales);
			confirmar = cargarUnEntero("\nDesea cargar el nuevo libro?(1.Si || 2.No):", "\nError,ingrese un numero valido?(1.Si || 2.No):", 1, 2, 4);
			if(confirmar == 1)
			{
				aux = ll_add(pArrayListLibros, newLibro);
				if(aux == 0)
				{
					printf("\nLibro cargado con exito....\n");
					error = 0;
				}else{
					printf("\nError al cargar Libro....\n");
					libros_delete(newLibro);
				}
			}else{
				printf("\nEl Libro no fue cargado....\n");
			}
		}
	}

    return error;
}


/** \brief Alta de Editorial
 *
 * \param LinkedList* pArrayListLibros = lista donde se carga los libros
 * \param LinkedList* pArrayListEditoriales = lista donde se carga las editoriales
 *
 * \return int error = Si carga al libro retorna 0, en caso de error retorna 1
 *
 */
int controller_addEditorial(LinkedList* pArrayListEditoriales)
{
	eEditorial* newEditorial;
	int error;
	int ultimoId;
	char nombre[128];
	int aux;
	int confirmar;
	error = 1;

	if(pArrayListEditoriales != NULL)
	{
		newEditorial = editorial_new();

		if(newEditorial != NULL)
		{
			printf("+====================+\n");
			printf("| CARGAR NUEVO LIBRO |\n");
			printf("+====================+\n\n");
			ultimoId = controller_ultimoIdEditoriales(pArrayListEditoriales);

			editorial_setIdEditorial(newEditorial, ultimoId);

			getUsuario(nombre, "Ingresar el nombre de la editorial: ", "Error, ingrese una nombre valido: ", 1, 128, 4);
			editorial_setNombre(newEditorial, nombre);


			limpiar();
			editorial_printEditorialCabecera(newEditorial);
			confirmar = cargarUnEntero("\nDesea cargar el nuevo libro?(1.Si || 2.No):", "\nError,ingrese un numero valido?(1.Si || 2.No):", 1, 2, 4);
			if(confirmar == 1)
			{
				aux = ll_add(pArrayListEditoriales, newEditorial);
				if(aux == 0)
				{
					printf("\nEditorial cargada con exito....\n");
					error = 0;
				}else{
					printf("\nError al cargar Editorial....\n");
					editorial_delete(newEditorial);
				}
			}else{
				printf("\nLa Editorial no fue cargado....\n");
			}
		}
	}

    return error;
}

int controller_editLibro(LinkedList* pArrayListLibros, LinkedList* pArrayListEditoriales)
{
	{
		char newAutor[128];
		char newTitulo[128];
		char nombreEditorial[128];
		int newPrecio;
		int newEditorial;
		int idMod;
		int ultimoId;
		int pos;
		int j;
		int error;
		int len;
		int auxIdEditorial;
		int opcion;
		int confirmar;
		eLibros* libroMod;
		eEditorial* auxEdit;
		error = 1;

		if(pArrayListLibros != NULL)
		{
			printf("*--------------------*\n");
			printf("| MODIFICAR LIBRO    |\n");
			printf("*--------------------*\n\n");
				//2. Muestro la lista de empleados
				controller_ListLibros(pArrayListLibros, pArrayListEditoriales);
				puts("\n\n");

				//3.Obtengo el ultimo id para validar
				ultimoId = controller_ultimoIdLibros(pArrayListLibros);

				//4.Obtengo el id del empleado a modificar
				idMod = cargarUnEntero("\n Ingrese el ID del Libro a modificar: ", "Error, ingrese un ID valido: ", 1, ultimoId-1, 4);

				//5. busco la posicion del empleado con el id ingresado por el usuario
				pos = controller_buscarIdLibros(pArrayListLibros, idMod);

				//6. Apunto el puntero al empleado en la posicion encontrada
				libroMod =ll_get(pArrayListLibros, pos);

				limpiar();

				if(libroMod != NULL)
				{
					error = 0;
					do{
						libros_printLibrosCabecera(libroMod, pArrayListEditoriales);
						menuModificarLibro();
						opcion = cargarUnEntero("Ingrese una opcion: ", "Error, ingrese una opcion", 0, 4, 4);
						switch(opcion)
						{
							case 1:
								getUsuario(newTitulo, "\nIngrese el nuevo titulo: ", "\nError, ingrese un titulo valido: ", 1, 128, 4);
								printf("\nEl nuevo titulo es %s\n", newTitulo);
								confirmar = cargarUnEntero("\nDesea cargar el nuevo titulo?(1.Si || 2.No):", "\nError,ingrese un numero valido?(1.Si || 2.No):", 1, 2, 4);
								if(confirmar == 1)
								{
									libros_setTitulo(libroMod, newTitulo);
									printf("\nEl titulo fue moficado con exito...\n");
								}else{
									printf("\nEl titulo no fue moficado...\n");
								}
								break;
							case 2:
								getUsuario(newAutor, "\nIngrese el nuevo Autor: ", "\nError, ingrese un Autor valido: ", 1, 128, 4);
								printf("\nEl nuevo titulo es %s\n", newAutor);
								confirmar = cargarUnEntero("\nDesea cargar el Autor titulo?(1.Si || 2.No):", "\nError,ingrese un numero valido?(1.Si || 2.No):", 1, 2, 4);
								if(confirmar == 1)
								{
									libros_setAutor(libroMod, newAutor);
									printf("\nEl Autor fue moficado con exito...\n");
								}else{
									printf("\nEl Autor no fue moficado...\n");
								}
								break;
							case 3:
								newPrecio = cargarUnEntero("\nIngrese el nuevo Precio:$", "\nError, ingrese un Precio valido(entre 100 y 10000):$ ", 100, 10000, 4);
								printf("\nEl nuevo sueldo es $%d\n", newPrecio);
								confirmar = cargarUnEntero("\nDesea cargar el nuevo Precio?(1.Si || 2.No):", "\nError,ingrese un numero valido?(1.Si || 2.No):", 1, 2, 4);
								if(confirmar == 1)
								{
									libros_setPrecio(libroMod, newPrecio);
									printf("\nEl Precio fue moficado con exito...\n");
								}else{
									printf("\nEl Precio no fue moficado...\n");
								}
								break;
							case 4:
								controller_ListEditorial(pArrayListEditoriales);
								len = ll_len(pArrayListEditoriales);
								newEditorial = cargarUnEntero("Seleccione una editorial: ", "Error, seleccione una editorial valida: ", 1, len, 4);


								for (j = 0; j < len; ++j) {
									auxEdit = ll_get(pArrayListEditoriales, j);
									editorial_getIdEditorial(auxEdit, &auxIdEditorial);
									if(newEditorial == auxIdEditorial){
										break;
									}
								}
								editorial_getNombre(auxEdit, nombreEditorial);


								printf("\nLa nuevo editorial es %s\n", nombreEditorial);
								confirmar = cargarUnEntero("\nDesea cargar la nueva editoria?(1.Si || 2.No):", "\nError,ingrese un numero valido?(1.Si || 2.No):", 1, 2, 4);
								if(confirmar == 1)
								{
									libros_setIdEditorial(libroMod, newEditorial);
									printf("\nLa editorial fue moficado con exito...\n");
								}else{
									printf("\nLa editorial no fue moficado...\n");
								}
								break;
						}
					}while(opcion != 0);
				}
		}
	    return error;
	}
}

int controller_editEditoriales(LinkedList* pArrayListEditoriales)
{
	{
		char newEditorial[128];
		int idMod;
		int ultimoId;
		int pos;
		int error;
		int opcion;
		int confirmar;
		eEditorial* modEdit;
		error = 1;

		if(pArrayListEditoriales != NULL)
		{
			printf("*---------------------*\n");
			printf("| MODIFICAR EDITORIAL |\n");
			printf("*---------------------*\n\n");
				//2. Muestro la lista de empleados
				controller_ListEditorial(pArrayListEditoriales);
				puts("\n\n");

				//3.Obtengo el ultimo id para validar
				ultimoId = controller_ultimoIdEditoriales(pArrayListEditoriales);

				//4.Obtengo el id del empleado a modificar
				idMod = cargarUnEntero("\n Ingrese el ID del Libro a modificar: ", "Error, ingrese un ID valido: ", 1, ultimoId-1, 4);

				//5. busco la posicion del empleado con el id ingresado por el usuario
				pos = controller_buscarIdEditorial(pArrayListEditoriales, idMod);

				//6. Apunto el puntero al empleado en la posicion encontrada
				modEdit =ll_get(pArrayListEditoriales, pos);

				limpiar();

				if(modEdit != NULL)
				{
					error = 0;
					do{
						editorial_printEditorialCabecera(modEdit);
						menuModificarEditorial();
						opcion = cargarUnEntero("Ingrese una opcion: ", "Error, ingrese una opcion", 0, 1, 4);
						switch(opcion)
						{
							case 1:
								getUsuario(newEditorial, "\nIngrese una nueva Editorial: ", "\nError, ingrese un nombre valido: ", 1, 128, 4);
								printf("\nEl nuevo titulo es %s\n", newEditorial);
								confirmar = cargarUnEntero("\nDesea cargar el nuevo titulo?(1.Si || 2.No):", "\nError,ingrese un numero valido?(1.Si || 2.No):", 1, 2, 4);
								if(confirmar == 1)
								{
									editorial_setNombre(modEdit, newEditorial);
									printf("\nLa editorial fue moficado con exito...\n");
								}else{
									printf("\nLa editorial no fue moficado...\n");
								}
								break;
						}
					}while(opcion != 0);
				}
		}
	    return error;
	}
}


int controller_removeLibro(LinkedList* pArrayListLibros, LinkedList* pArrayListEditoriales)
{
	{


		int idMod;
		int ultimoId;
		int pos;
		int error;
		int confirmar;
		eLibros* libroMod;
		error = 1;

		if(pArrayListLibros != NULL)
		{
			printf("*--------------------*\n");
			printf("| MODIFICAR LIBRO    |\n");
			printf("*--------------------*\n\n");
				//2. Muestro la lista de empleados
				controller_ListLibros(pArrayListLibros, pArrayListEditoriales);
				puts("\n\n");

				//3.Obtengo el ultimo id para validar
				ultimoId = controller_ultimoIdLibros(pArrayListLibros);

				//4.Obtengo el id del empleado a modificar
				idMod = cargarUnEntero("\n Ingrese el ID del Libro a Borrar: ", "Error, ingrese un ID valido: ", 1, ultimoId-1, 4);

				//5. busco la posicion del empleado con el id ingresado por el usuario
				pos = controller_buscarIdLibros(pArrayListLibros, idMod);

				//6. Apunto el puntero al empleado en la posicion encontrada
				libroMod =ll_get(pArrayListLibros, pos);

				limpiar();

				if(libroMod != NULL)
				{
					libros_printLibrosCabecera(libroMod, pArrayListEditoriales);
					confirmar = cargarUnEntero("\nDesea borrar el libro?(1.Si || 2.No):", "\nError,ingrese un numero valido?(1.Si || 2.No):", 1, 2, 4);
					if(confirmar == 1){
						ll_remove(pArrayListLibros, pos);
						libros_delete(libroMod);
						printf("\nEL Libro fue borrado con exito....\n");
						error = 0;
					}else{
						printf("\nEL Libro no fue borrado....\n");
					}
				}
		}
	    return error;
	}
}


int controller_removEditorial(LinkedList* pArrayListLibros, LinkedList* pArrayListEditoriales)
{
	{
		int idMod;
		int ultimoId;
		int pos;
		int error;
		int i;
		int idEdit;
		int idEditLibro;
		int confirmar;
		int len;
		eEditorial* modEdit;
		eLibros* libros;
		error = 1;

		if(pArrayListEditoriales != NULL)
		{
			printf("*---------------------*\n");
			printf("| MODIFICAR EDITORIAL |\n");
			printf("*---------------------*\n\n");
				//2. Muestro la lista de empleados
				controller_ListEditorial(pArrayListEditoriales);
				puts("\n\n");

				//3.Obtengo el ultimo id para validar
				ultimoId = controller_ultimoIdEditoriales(pArrayListEditoriales);

				//4.Obtengo el id del empleado a modificar
				idMod = cargarUnEntero("\n Ingrese el ID del Libro a modificar: ", "Error, ingrese un ID valido: ", 1, ultimoId-1, 4);

				//5. busco la posicion del empleado con el id ingresado por el usuario
				pos = controller_buscarIdEditorial(pArrayListEditoriales, idMod);

				//6. Apunto el puntero al empleado en la posicion encontrada
				modEdit =ll_get(pArrayListEditoriales, pos);

				limpiar();

				if(modEdit != NULL)
				{

					editorial_printEditorialCabecera(modEdit);
					error = 0;
					confirmar = cargarUnEntero("\nDesea borrar el libro?(1.Si || 2.No):", "\nError,ingrese un numero valido?(1.Si || 2.No):", 1, 2, 4);
					if(confirmar == 1){
						ll_remove(pArrayListEditoriales, pos);
						printf("\nLa editorial fue borrado con exito....\n");
						len = ll_len(pArrayListLibros);
						editorial_getIdEditorial(modEdit, &idEdit);
						for (i = 0; i < len; ++i) {
							libros = ll_get(pArrayListLibros, i);
							libros_getIdEditorial(libros, &idEditLibro);
							if(idEditLibro == idEdit)
							{
								ll_remove(pArrayListLibros, i);
								libros_delete(libros);
							}
						}
						editorial_delete(modEdit);
						error = 0;
					}else{
						printf("\nLa editorial no fue borrado....\n");
					}

				}
		}
	    return error;
	}
}

































/*
int controller_editorialConMasLibros(LinkedList* pArrayListLibros, LinkedList* pArrayListEditoriales)
{
	int error;
	int len;
	int lenEditorial;
	int i;
	int j;
	int id;
	int numMax;
	eEditorial* pEdit;
	lenEditorial = ll_len(pArrayListEditoriales);
	eCantEditorial editorial[lenEditorial];
	//LinkedList* librosSinPlaneta = NULL;
	error = 1;

	if(pArrayListLibros != NULL)
	{
		len = ll_len(pArrayListLibros);
		error = 0;
		//1.Inicializo la estructura
		for (i = 0; i < lenEditorial; ++i) {
			pEdit = ll_get(pArrayListEditoriales, i);
			editorial_getIdEditorial(pEdit, &id);
			editorial[i].idEditorial = id;
			editorial[i].cantLibros = 0;
		}
		//2. Cargo la cantidad de libros que tiene cada editorial
		for (i = 0; i < lenEditorial; ++i) {
			for (j = 0; j < len; ++j) {
				pEdit = ll_get(pArrayListLibros, j);
				editorial_getIdEditorial(pEdit, &id);
				if(editorial[i].idEditorial == id)
				{
					editorial[i].cantLibros= editorial[i].cantLibros +1;;
				}
			}
		}
		//3. Obtengo el num max de libros
		for (i = 0; i < lenEditorial; ++i) {
			if(i == 0 || numMax<editorial[i].cantLibros)
			{
				numMax = editorial[i].cantLibros;
				id = editorial[i].idEditorial;
			}
		}
		printf("\nLa editorial con mas libros tiene: %d is es el id %d\n\n", numMax, id);



	}
	return error;
}
*/
