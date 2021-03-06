/*
 * Libros.h
 *
 *  Created on: 20 nov. 2021
 *      Author: Lau
 */

#ifndef LIBROS_H_
#define LIBROS_H_
typedef struct{
	int id;
	char titulo [50];
	char autor [50];
	int precio;
	char editorialId[50];

}eLibro;


eLibro* libro_new(); //ok
eLibro* libro_newParametrosString(char* idStr,char* autorStr,char* tituloStr,char* editorialIDStr, char* precioStr); //ok
//eLibro* libro_newParametros(int idStr,char* autorStr,char* editorial, int precioStr, char* editorialIDStr);


int libro_setId(eLibro* this, int id);
int libro_setAutor(eLibro* this, char* autor);
int libro_setTitulo(eLibro* this, char* titulo);
int libro_setPrecio(eLibro* this, int precio);
int libro_setEditorialId(eLibro* this, char* editorialId);

int libro_getId(eLibro* this, int* id);
int libro_getAutor(eLibro* this, char* autor);
int libro_getTitulo(eLibro* this, char* titulo);
int libro_getPrecio(eLibro* this, int* precio);
int libro_getEditorialId(eLibro* this, char* editorialId);

#endif /* LIBROS_H_ */
