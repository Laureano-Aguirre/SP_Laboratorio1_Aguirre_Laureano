#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Controller.h"


int controller_loadFromText(char* path , LinkedList* pArrayListLibro){

	int retorno=0;
	FILE *auxP;

	auxP=fopen(path ,"r");
	perror(path);
	if(auxP!=NULL)
	{
		if(parser_LibroFromText(auxP, pArrayListLibro)==1)
		{
			retorno=1;
			puts("\nDatos cargados correctamente.");
		}
	}
	else
	{
		puts("\nError, no se puede leer el archivo.");
	}
	fclose(auxP);
    return retorno;
}

int controller_loadFromTextMap(char* path, LinkedList* pArrayListLibroMap)
{
	int retorno=0;
	FILE *auxP;

	auxP=fopen(path, "w");
	perror(path);
	if(auxP!=NULL)
	{
		if(parser_LibroFromTextMap(auxP, pArrayListLibroMap)==1)
		{
			retorno=1;
			puts("\nDatos cargados correctamente.");
		}
	}
	else
	{
		puts("\nError, no se puede leer el archivo.");
	}
	fclose(auxP);
	return retorno;
}
int controller_ListLibro(LinkedList* pArrayListLibro)
{
	int i;
	int retorno=-1;

	if(pArrayListLibro!=NULL)
	{
		if(ll_len(pArrayListLibro)>0)
		{
			printf("\nID            TITULO                                               AUTOR                            PRECIO                  EDITORIAL");
			for(i=0;i<ll_len(pArrayListLibro);i++)
			{
				mostrarLibro(pArrayListLibro, i);
				retorno=1;
			}
		}
		else
		{
			puts("\nNo hay libros disponibles para listar.");
		}

	}
    return retorno;
}

int controller_sortLibro(LinkedList* pArrayListLibro)
{
	int retorno=-1;
	int opcion;

	if(pArrayListLibro!=NULL)
	{
		if(ll_len(pArrayListLibro)>0)
		{
			getInt("\nIngrese que desea ordenar (1.autor): ", &opcion);
			while(opcion!=1)
			{
				getInt("\nError, ingrese que desea ordenar (1.autor): ", &opcion);
			}
			if(opcion==1)
			{
				if(ll_sort(pArrayListLibro, OrdenamientoPorAutor, 1)==0)	//le paso a la funcion sort, encargada de hacer el swapeo, la lista, la funcion retornando
				{
					retorno=1;
				}
			}
		}
		else
		{
			puts("\nNo hay libros disponibles para ordenar.");
		}
	}
	else
	{
		puts("\nError, no hay nada cargado en la lista.");
	}
	return retorno;
}

void mostrarLibro(LinkedList* pArrayListLibro, int index)
{
	eLibro* libro;
	int id;
	int precio;
	char editorialId[50];
	char autor[50];
	char titulo[50];

	libro=(eLibro*)ll_get(pArrayListLibro, index);
	libro_getId(libro, &id);
	libro_getPrecio(libro, &precio);
	libro_getAutor(libro, autor);
	libro_getTitulo(libro, titulo);
	libro_getEditorialId(libro, editorialId);

	printf("\n%-10d    %-50s   %-30s   %-20d    %-30s", id, titulo, autor, precio, editorialId);

}

int OrdenamientoPorAutor(void* libroA, void* libroB)
{
	int retorno=0;

	retorno=strcmp(((eLibro*)libroA)->autor, ((eLibro*)libroB)->autor);		//declaro y casteo las variables de tipo libro, luego las comparo

	return retorno;
}

int libro_IncrementarPrecio(void* pElement)
{
	int retorno=-1;
	char editorial [50];
	int precio;
	//eLibro* libro;

	if(pElement!=NULL)
	{
		libro_getPrecio((eLibro*)pElement, &precio);
		libro_getEditorialId((eLibro*)pElement, editorial);
		if(strcmp(editorial,"Planeta")==0)
		{
			if(precio>=300)
			{
				precio=precio-((20*precio)/100);
				libro_setPrecio(pElement, precio);
				retorno=1;
			}
		}
		else if(strcmp(editorial,"SIGLO XXI EDITORES")==0)
		{
			if(precio<=200)
			{
				precio=precio-((10*precio)/100);
				libro_setPrecio(pElement, precio);
				retorno=1;
			}
		}
	}
	return retorno;
}

