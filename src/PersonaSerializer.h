/*
 * PersonaSerializer.h
 *
 *  Created on: 25/6/2015
 *      Author: mateo
 */

#ifndef PERSONASERIALIZER_H_
#define PERSONASERIALIZER_H_

#include <iostream>
#include <vector>

#include "Persona.h"

using namespace std;

class PersonaSerializer {
public:

	static string serialize(Persona p);
	static Persona deserialize(string str);
	static string serializeVector(vector<Persona> vector);
	static vector<Persona> deserializeVector(string str);

	static string personaDelimiterString;
	static char personaDelimiterChar;
	static string delimiterString;
	static char delimiterChar;

};

#endif /* PERSONASERIALIZER_H_ */
