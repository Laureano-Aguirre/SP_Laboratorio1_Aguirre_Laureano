#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Libros.h"

/*void hardcodearEditorial(eEditorial editorial)
{
	eEditorial editorialLocal[6]={{1,"Planeta"}, {2,"Siglo XXI Editores"}, {3,"Pearson"}, {4,"Minotauro"}, {5,"Salamandra"}, {6,"Penguin Books"}};
}*/
eLibro* libro_new()
{
	eLibro* nuevoLibro;
	nuevoLibro=(eLibro*) malloc(sizeof(eLibro));

	if(nuevoLibro!=NULL)
	{
		libro_setId(nuevoLibro, 0);
		libro_setTitulo(nuevoLibro," ");
		libro_setAutor(nuevoLibro," ");
		libro_setPrecio(nuevoLibro,0);
		libro_setEditorialId(nuevoLibro," ");
	}

	return nuevoLibro;
}

eLibro* libro_newParametrosString(char* idStr,char* tituloStr,char* autorStr,char* precioStr, char* editorialIDStr)
{
	eLibro* nuevoLibro=libro_new();


	if(nuevoLibro!=NULL)
	{
		if(libro_setId(nuevoLibro, atoi(idStr))==-1 ||
		   libro_setTitulo(nuevoLibro, tituloStr)==-1||
		   libro_setAutor(nuevoLibro, autorStr)==-1||
		   libro_setPrecio(nuevoLibro, atoi(precioStr))==-1 ||
		   libro_setEditorialId(nuevoLibro, editorialIDStr)==-1)
		{
			free(nuevoLibro);
			nuevoLibro=NULL;
		}
	}
	return nuevoLibro;
}

/*eLibro* libro_newParametros(int idStr,char* autorStr,char* tituloStr, int precioStr, char* editorialIDStr)
{
	eLibro* nuevoLibro=NULL;
	nuevoLibro=(eLibro*)malloc(sizeof(eLibro));

	if(nuevoLibro!=NULL)
	{
		nuevoLibro->id=idStr;
		strcpy(nuevoLibro->autor, autorStr);
		strcpy(nuevoLibro->titulo, tituloStr);
		nuevoLibro->precio=precioStr;
		strcpy(nuevoLibro->editorialId, editorialIDStr);
	}

	return nuevoLibro;
}*/

int libro_setId(eLibro* this, int id)
{
	int retorno=-1;

	if(this!=NULL && id>0)
	{
		this->id=id;
		retorno=1;
	}
	return retorno;
}

int libro_setAutor(eLibro* this, char* autor)
{
	int retorno=-1;

	if(this!=NULL && autor!=NULL && strlen(autor)<100 && strlen(autor)>1)
	{
		strcpy(this->autor, autor);
		retorno=1;
	}
	return retorno;
}

int libro_setTitulo(eLibro* this, char* titulo)
{
	int retorno=-1;

		if(this!=NULL && titulo!=NULL && strlen(titulo)<100 && strlen(titulo)>1)
		{
			strcpy(this->titulo, titulo);
			retorno=1;
		}
		return retorno;
}

int libro_setPrecio(eLibro* this, int precio)
{

	int retorno=-1;

	if(this!=NULL && precio>0)
	{
		this->precio=precio;
		retorno=1;
	}
	return retorno;
}

int libro_setEditorialId(eLibro* this, char* editorialId)
{
	int retorno=-1;

		if(this!=NULL && editorialId!=NULL && strlen(editorialId)>1 && strlen(editorialId)<50)
		{
			strcpy(this->editorialId, editorialId);
			retorno=1;
		}
		return retorno;
}

int libro_getId(eLibro* this, int* id)
{
	int retorno=-1;

	if(this!=NULL && id!=NULL)
	{
		*id=this->id;
		retorno=1;
	}
	return retorno;
}

int libro_getAutor(eLibro* this, char* autor)
{
	int retorno=-1;

	if(this!=NULL && autor!=NULL)
	{
		strcpy(autor, this->autor);
		retorno=1;
	}
	return retorno;
}

int libro_getTitulo(eLibro* this, char* titulo)
{
	int retorno=-1;

	if(this!=NULL && titulo!=NULL)
	{
		strcpy(titulo, this->titulo);
		retorno=1;
	}
	return retorno;
}

int libro_getPrecio(eLibro* this, int* precio)
{
	int retorno=-1;

	if(this!=NULL && precio>0)
	{
		*precio=this->precio;
		retorno=1;
	}
	return retorno;
}

int libro_getEditorialId(eLibro* this, char* editorialId)
{
	int retorno=-1;

	if(this!=NULL && editorialId!=NULL)
	{
		strcpy(editorialId, this->editorialId);
		retorno=1;
	}
	return retorno;
}
