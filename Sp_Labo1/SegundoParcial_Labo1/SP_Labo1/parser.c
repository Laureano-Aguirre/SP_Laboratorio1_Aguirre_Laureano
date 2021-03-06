#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Libros.h"
//#include "parser.h"


int parser_LibroFromText(FILE* pFile , LinkedList* pArrayListLibro)
{
	int retorno=0;
	int cantidad;
	char buffer1[1024];
	char buffer2[1024];
	char buffer3[1024];
	char buffer4[1024];
	char buffer5[1024];
	eLibro* nuevoLibro;

	if(pFile!=NULL && pArrayListLibro!=NULL)
	{
		fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^\n]\n", buffer1, buffer2, buffer3, buffer4, buffer5); //lectura fantasma
		//fprintf
		while(!feof(pFile))//hasta q no lea la ultima linea, no sale del while
		{//for
			//ll get en el indice
			//a nuevo libro
			//todos los get
			//fprintf de todas las variables
			cantidad= fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^\n]\n", buffer1, buffer2, buffer3, buffer4, buffer5);
			 if(cantidad<5)
			{
				break;
			}

			nuevoLibro=libro_newParametrosString(buffer1, buffer2, buffer3, buffer4, buffer5);
			if(nuevoLibro!=NULL)
			{
				ll_add(pArrayListLibro, nuevoLibro);
				retorno=1;
			}
		}
	}
	return retorno;
}

int parser_LibroFromTextMap(FILE* pFile, LinkedList* pArrayListLibroMap)
{
	int retorno=-1;
	int id;
	char titulo[50];
	char autor[50];
	int precio;
	char editorial[50];
	int i;

	eLibro* aux;

	if(pFile!=NULL && pArrayListLibroMap!=NULL)
	{
		fprintf(pFile, "id,titulo,autor,precio,editorial\n");
		for(i=0;i<ll_len(pArrayListLibroMap);i++)
		{
			aux=(eLibro*)ll_get(pArrayListLibroMap, i);
			libro_getId(aux, &id);
			libro_getAutor(aux, autor);
			libro_getTitulo(aux, titulo);
			libro_getPrecio(aux, &precio);
			//libro_getEditorialId(aux, editorial);
			fprintf(pFile,"%d,%s,%s,%d,%s\n", id, titulo, autor, precio, editorial);//escribimos el archivo y lo guardamos
			retorno=1;
		}
	}
	return retorno;
}
