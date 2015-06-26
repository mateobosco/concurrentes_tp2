/*
 * Operaciones.h
 *
 *  Created on: 26/6/2015
 *      Author: mateobosco
 */

#ifndef SRC_OPERACIONES_H_
#define SRC_OPERACIONES_H_

#include <iostream>

class Operaciones {
public:
	static const int GET_ALL = 1;
	static const int SEARCH = 2;
	static const int ADD = 3;
	static const int EXIT = 4;

	static constexpr const char* GET_ALL_STRING = "Obtener todas las personas";
	static constexpr const char* SEARCH_STRING = "Buscar personas";
	static constexpr const char* ADD_STRING = "Agregar una persona";
	static constexpr const char* EXIT_STRING = "Salir";

};


#endif /* SRC_OPERACIONES_H_ */
