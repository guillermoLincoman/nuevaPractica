/*
 * vuelos.c
 *
 *  Created on: 18 nov. 2021
 *      Author: Compumar
 */
#include "libros.h"

/** \brief Inicializa un nuevo libro
 *
 *
 * \return Retorna un libro con sus campos inicializados
  */
eLibros* libros_new()
{
	eLibros* newLibro = (eLibros*)malloc(sizeof(eLibros));
	//inicializo las variables
	if(newLibro != NULL)
	{
		libros_setIdLibro(newLibro, 0);
		libros_setTitulo(newLibro, " ");
		libros_setAutor(newLibro, " ");
		libros_setPrecio(newLibro, 0);
		libros_setIdEditorial(newLibro, 0);

	}

	return newLibro;
}

/** \brief Carga un libro con parametros recibidos
 *
 * \param char* id = id a cargar en la estructura.
 * \param char* titulo = titulo a cargar en la estructura.
 * \param char* autor = autor trabajadas a cargar en la estructura.
 * \param char* precio = precio a cargar en la estructura.
 * \param char* idEditorial = idEditorial a cargar en la estructura.
 *
 * \return un libro con sus parametros cargados
 */
eLibros* libros_newParametros(char* id,char* titulo,char* autor, char* precio, char* idEditorial)
{
	eLibros* libro = libros_new();
	if(id != NULL && titulo != NULL && autor != NULL && precio != NULL && idEditorial != NULL)
	{
		libros_setIdLibro(libro, atoi(id));
		libros_setTitulo(libro, titulo);
		libros_setAutor(libro, autor);
		libros_setPrecio(libro, atoi(precio));
		libros_setIdEditorial(libro, atoi(idEditorial));
	}

	return libro;
}

/** \brief Borra un libro de la estructura
 *
 * \param eVuelos* this = puntero a estructura de libro
 *
 */
void libros_delete(eLibros* this)
{
	if(this != NULL)
	{
		free(this);
	}
}



/** \brief Carga un id en el campo de la estructura libro
 *
 * \param eLibros* this = puntero a estructura de libro
 * \param int idLibro = id a cargar en la estructura.
 *
 * \return Devuelve 1 si hay un error y 0 si se cargo correctamente
 */
int libros_setIdLibro(eLibros* this,int idLibro)
{
	int error;
	error = 1;
	if(this != NULL && idLibro>= 0)
	{
		this->id = idLibro;
		error = 0;
	}
	return error;
}

/** \brief Obtiene un id del campo de una estructura libro
 *
 * \param eLibros* this = puntero a estructura de libro
 * \param int* idLibro = idLibro obtenido de la estructura.
 *
 * \return Devuelve 1 si hay un error y 0 si se cargo correctamente
 */
int libros_getIdLibro(eLibros* this,int* idLibro)
{
	int error;
	error = 1;
	if(this != NULL && idLibro != NULL)
	{
		*idLibro = this->id;
		error = 0;
	}
	return error;
}

/** \brief Carga un titulo en el campo de la estructura eVuelos
 *
 * \param eLibros* this = puntero a estructura de libro
 * \param char* titulo = titulo a cargar en la estructura.
 *
 * \return Devuelve 1 si hay un error y 0 si se obtuvo el id correctamente
 */
int libros_setTitulo(eLibros* this,char* titulo)
{
	int error;
	error=1;
	if(this != NULL && titulo != NULL)
	{
		strncpy(this->titulo, titulo, 128);
		error = 0;
	}
	return error;
}

/** \brief Obtiene un titulo del campo de una estructura eVuelos
 *
 * \param eLibros* this = puntero a estructura de libro
 * \param char* titulo = titulo obtenido de la estructura.
 *
 * \return Devuelve 1 si hay un error y 0 si se obtuvo el nombre correctamente
 */
int libros_getTitulo(eLibros* this,char* titulo)
{
	int error;
	error=1;
	if(this != NULL && titulo != NULL)
	{
		strncpy(titulo, this->titulo,128);
		error = 0;
	}
	return error;
}

/** \brief Carga un autor en el campo de la estructura eVuelos
 *
 * \param eLibros* this = puntero a estructura de libro
 * \param char* autor = autor a cargar en la estructura.
 *
 * \return Devuelve 1 si hay un error y 0 si se obtuvo el id correctamente
 */
int libros_setAutor(eLibros* this,char* autor)
{
	int error;
	error=1;
	if(this != NULL && autor != NULL)
	{
		strncpy(this->autor, autor, 128);
		error = 0;
	}
	return error;
}

/** \brief Obtiene un autor del campo de una estructura eVuelos
 *
 * \param eLibros* this = puntero a estructura de libro
 * \param char* autor = autor obtenido de la estructura.
 *
 * \return Devuelve 1 si hay un error y 0 si se obtuvo el nombre correctamente
 */
int libros_getAutor(eLibros* this,char* autor)
{
	int error;
	error=1;
	if(this != NULL && autor != NULL)
	{
		strncpy(autor, this->autor,128);
		error = 0;
	}
	return error;
}


/** \brief Carga una precio en el campo de la estructura eVuelos
 *
 * \param eLibros* this = puntero a estructura de libro
 * \param int precio = precio a cargar en la estructura.
 *
 * \return Devuelve 1 si hay un error y 0 si se obtuvo el id correctamente
 */
int libros_setPrecio(eLibros* this,int precio)
{
	int error;
	error = 1;
	if(this != NULL && precio >= 0)
	{
		this->precio = precio;
		error = 0;
	}
	return error;
}

/** \brief Obtiene una precio del campo de una estructura eVuelos
 *
 * \param eLibros* this = puntero a estructura de libro
 * \param int* precio = precio obtenido de la estructura.
 *
 * \return Devuelve 1 si hay un error y 0 si se obtuvo el nombre correctamente
 */
int libros_getPrecio(eLibros* this,int* precio)
{
	int error;
	error = 1;
	if(this != NULL && precio != NULL)
	{
		*precio = this->precio;
		error = 0;
	}
	return error;
}

/** \brief Carga una idEditorial en el campo de la estructura eVuelos
 *
 * \param eLibros* this = puntero a estructura de libro
 * \param int idEditorial = idEditorial a cargar en la estructura.
 *
 * \return Devuelve 1 si hay un error y 0 si se obtuvo el id correctamente
 */
int libros_setIdEditorial(eLibros* this,int idEditorial)
{
	int error;
	error = 1;
	if(this != NULL && idEditorial >= 0)
	{
		this->idEditorial = idEditorial;
		error = 0;
	}
	return error;
}

/** \brief Obtiene una idEditorial del campo de una estructura eVuelos
 *
 * \param eLibros* this = puntero a estructura de libro
 * \param int* idEditorial = idEditorial obtenido de la estructura.
 *
 * \return Devuelve 1 si hay un error y 0 si se obtuvo el nombre correctamente
 */
int libros_getIdEditorial(eLibros* this,int* idEditorial)
{
	int error;
	error = 1;
	if(this != NULL && idEditorial != NULL)
	{
		*idEditorial = this->idEditorial;
		error = 0;
	}
	return error;
}

/** \brief Imprime un libro sin cabecera, Complementaria de funcion controller_ListLibros
 *
 * \param Employee* this = puntero a libro que se va a mostrar
 *
 */

void libros_printLibrosCabecera(eLibros* this, LinkedList* pArrayListEditoriales)
{

	int idLibro;
	char aNombreAutor[128];
	char titulo[128];
	int precio;
	char editorial[128];
	int auxIdEditorial;
	int idEditorial;
	int lenAutores;
	int j;
	eEditorial* newEditorial;
	newEditorial = editorial_new();
	if(this != NULL )
	{
		libros_getIdLibro(this, &idLibro);
		libros_getTitulo(this, titulo);
		libros_getAutor(this, aNombreAutor);
		libros_getPrecio(this, &precio);
		libros_getIdEditorial(this, &idEditorial);
		lenAutores = ll_len(pArrayListEditoriales);

		for (j = 0; j < lenAutores; ++j) {
			newEditorial = ll_get(pArrayListEditoriales, j);
			editorial_getIdEditorial(newEditorial, &auxIdEditorial);
			if(idEditorial == auxIdEditorial){
				break;
			}
		}
		editorial_getNombre(newEditorial, editorial);

		printf("\n\n____________________________________________________________________________________________________________\n");
		printf("||________________________________________________________________________________________________________||\n");
		printf("|| ID LIBRO |             TITULO               |          AUTOR          |  PRECIO  |      EDITORIAL      ||\n");
		printf("||__________|__________________________________|_________________________|__________|_____________________||\n");
		printf("||  %4d    | %32s | %23s |  $ %4d  | %19s ||\n", idLibro, titulo, aNombreAutor, precio, editorial);
	}
}

/** \brief Imprime un libro sin cabecera, Complementaria de funcion controller_ListLibros
 *
 * \param Employee* this = puntero a libro que se va a mostrar
 *
 */

void libros_printLibros(eLibros* this, eEditorial* thisEditorial)
{

	int idLibro;
	char aNombreAutor[128];
	char titulo[128];
	int precio;
	char editorial[128];

	if(this != NULL )
	{
		libros_getIdLibro(this, &idLibro);
		libros_getTitulo(this, titulo);
		libros_getAutor(this, aNombreAutor);
		libros_getPrecio(this, &precio);
		editorial_getNombre(thisEditorial, editorial);

		printf("||  %4d    | %32s | %23s |  $ %4d  | %19s ||\n", idLibro, titulo, aNombreAutor, precio, editorial);
	}
}

/** \brief Compara empleados segun el nombre
 *
 * \param void* emp1 = puntero a nombre Uno
 * \param void* emp2 = puntero a nombre Dos
 *
 * \return Retorna 1 si compara de mayor a menor
 * 		   Retorna -1 si compara de menor a mayor
 */
int libros_compareByAutor(void* emp1, void* emp2)
{
	int retorno = -1;
	char autorUno[128];
	char autorDos[128];
	eLibros* unLibro;
	eLibros* otroLibro;

	unLibro = (eLibros*) emp1;
	otroLibro = (eLibros*) emp2;

	if(unLibro != NULL && otroLibro != NULL)
	{
		libros_getAutor(unLibro, autorUno);
		libros_getAutor(otroLibro, autorDos);
		if(strcmp(autorUno, autorDos)<0)
		{
			retorno = 0;
		}else{
			if(strcmp(autorUno, autorDos)>0)
			{
				retorno = 1;
			}
		}
	}
	return retorno;
}
/** \brief Verifica que el libro sea de la editorial MINOTAURO
 *
 * \param void* pElement = puntero a idEditorial
 *
 * \return Retorna 1 si el libro pertenece a la editorial minotauro
 * 		   Retorna 0 si no pertenece a la editorial
 */
int libros_filtrarEditorialMinotauro(void* pElement)
{
	int rtn;
	int idEditorial;
	rtn = 0;
	eLibros* pAuxElement;
	if(pElement != NULL)
	{
		pAuxElement = (eLibros*) pElement;
		libros_getIdEditorial(pAuxElement, &idEditorial);
		if(idEditorial == 4)
		{
			rtn = 1;
		}
	}
	return rtn;
}

int libros_filtrarEditorialSinPlaneta(void* pElement)
{
	int rtn;
	int idEditorial;
	rtn = 0;
	eLibros* pAuxElement;
	if(pElement != NULL)
	{
		pAuxElement = (eLibros*) pElement;
		libros_getIdEditorial(pAuxElement, &idEditorial);
		if(idEditorial != 1)
		{
			rtn = 1;
		}
	}
	return rtn;
}


int libros_librosPrecioMayorAMil(void* pElement)
{
	int rtn;
	int precio;
	rtn = 0;
	eLibros* pAuxElement;
	if(pElement != NULL)
	{
		pAuxElement = (eLibros*) pElement;
		libros_getPrecio(pAuxElement, &precio);
		if(precio < 1000)
		{
			rtn = 1;
		}
	}

	return rtn;
}

