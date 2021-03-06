/*
 * InputOutput.h
 *
 *  Created on: 26/6/2015
 *      Author: mateobosco
 */

#ifndef SRC_INPUTOUTPUT_H_
#define SRC_INPUTOUTPUT_H_

#include <iostream>

#include "Respuesta.h"
#include "Server.h"
#include "Operaciones.h"

class InputOutput {
public:
	InputOutput();
	virtual ~InputOutput();

	static Mensaje getMensaje(long from);
	static Persona getPersona();

	static void showRespuesta(Respuesta rta);
	static void showPersona(Persona p);
	static void showPersonaTitle();
};

#endif /* SRC_INPUTOUTPUT_H_ */
