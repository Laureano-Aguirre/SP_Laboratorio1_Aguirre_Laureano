/*
 ============================================================================
 Name        : SP_Labo1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Aguirre.h"
#include "LinkedList.h"
#include "Controller.h"
#include "Libros.h"

int main(void)
{
	setbuf(stdout, NULL);
	int option = 0;
	int resp;
	int retornoCargaTexto=-1;

	//eLibro* libro;
	LinkedList* listaLibros = ll_newLinkedList();
	LinkedList* listaMap;

	do{

		getInt(" \n  Menu de opciones: "
				"\n 1. Cargar los datos de los libros desde el archivo data.csv (modo texto)."
				"\n 2. Ordenar libros."
				"\n 3. Listar libros."
				"\n 4. ll_map."
				"\n 5. Cargar los datos de los libros modificados desde el archivo data.csv (modo texto)."
				"\n 6. Salir."
				"\n Ingresar la operacion que desea ejecutar: ", &option);

		switch(option)
		{
			case 1:
				puts("\nUsted ha elegido la opcion cargar los datos de los libros desde el archivo data.csv (en modo texto).");
				if(retornoCargaTexto==-1)
				{
					controller_loadFromText("Datos.csv",listaLibros);
					retornoCargaTexto=1;
					/*empleado=(Employee*)ll_get(listaEmpleados,ll_len(listaLibros)-1 );
					employee_getId(empleado, &idEmp);*/
				}
				else if(retornoCargaTexto==1)
				{
					getInt("\nYa hay una lista cargada, desea sobreescribirla? 1.si 2.no: ", &resp);
					while(resp!=1 && resp!=2)
					{
						getInt("\nError, ya hay una lista cargada, desea sobreescribirla? 1.si 2.no: ", &resp);
					}
					if(resp==1)
					{
						ll_clear(listaLibros);
						controller_loadFromText("Datos.csv",listaLibros);
						retornoCargaTexto=1;
						/*empleado=(Employee*)ll_get(listaEmpleados,ll_len(listaEmpleados)-1 );
						employee_getId(empleado, &idEmp);*/
					}
					else
					{
						puts("\nOperacion cancelada.");
					}
				}
				break;
			case 2:
				puts("\nUsted ha seleccionado la opcion ordenar libros.");
				controller_sortLibro(listaLibros);
				break;
			case 3:
				puts("\nUsted ha seleccionado la opcion listar libros.");
				controller_ListLibro(listaLibros);
				break;
			case 4:
				listaMap=ll_map(listaLibros, libro_IncrementarPrecio);
				break;
			case 5:
				controller_loadFromTextMap("mapeado.csv", listaMap);
				break;
			case 6:
				puts("\nSaliendo del programa...");
				break;
		}
		if(option<1 || option>6)
		{
			puts("\nOpcion incorrecta, por favor, intente nuevamente.");
		}
		fflush(stdin);
		getchar();
	}while(option!=6);
	return EXIT_SUCCESS;
}
