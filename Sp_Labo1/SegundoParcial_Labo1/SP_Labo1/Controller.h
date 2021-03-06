#include "Aguirre.h"
#include "parser.h"
#include "Libros.h"
#include "LinkedList.h"

int controller_loadFromText(char* path , LinkedList* pArrayListLibro);
int controller_loadFromTextMap(char* path, LinkedList* pArrayListLibroMap);
int controller_ListLibro(LinkedList* pArrayListLibro);
int controller_sortLibro(LinkedList* pArrayListLibro);
void mostrarLibro(LinkedList* pArrayListLibro, int index);
int OrdenamientoPorAutor(void* libroA, void* libroB);
int libro_IncrementarPrecio(void* pElement);
