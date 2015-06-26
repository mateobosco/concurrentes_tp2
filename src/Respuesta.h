/*
 * Respuesta.h
 *
 *  Created on: 26/6/2015
 *      Author: mateo
 */

#ifndef RESPUESTA_H_
#define RESPUESTA_H_

#include <iostream>
#include <vector>
#include <sstream>
#include <string.h>

#include "Mensaje.h"

using namespace std;

class Respuesta {
public:
	Respuesta(long to, long from, int op, string body);
	Respuesta(vector<Mensaje>);
	virtual ~Respuesta();

	vector<Mensaje> getMensajes();

	long to;
	long from;
	int op;
	string body;
};

#endif /* RESPUESTA_H_ */
