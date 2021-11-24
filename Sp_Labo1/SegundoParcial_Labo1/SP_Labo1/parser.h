/*
 * parser.h
 *
 *  Created on: 20 nov. 2021
 *      Author: Lau
 */

#ifndef PARSER_H_
#define PARSER_H_
#include "LinkedList.h"

int parser_LibroFromText(FILE* pFile , LinkedList* pArrayListEmployee);
int parser_LibroFromTextMap(FILE* pFile, LinkedList* pArrayListLibroMap);

#endif /* PARSER_H_ */
