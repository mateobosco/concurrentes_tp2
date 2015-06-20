/*
 * Persona.h
 *
 *  Created on: 20/6/2015
 *      Author: mateo
 */

#ifndef PERSONA_H_
#define PERSONA_H_

#include <iostream>
#include <string.h>

using namespace std;

class Persona {
public:
	Persona(string nombre, string direccion, string telefono);
	virtual ~Persona();

	string getNombre();
	void setNombre(string nombre);
	string getDireccion();
	void setDireccion(string direccion);
	string getTelefono();
	void setTelefono(string telefono);

	string serialize();

private:
	char nombre[61];
	char direccion[120];
	char telefono[13];
};

#endif /* PERSONA_H_ */
