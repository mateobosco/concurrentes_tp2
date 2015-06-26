/*
 * PersonaSerializer.cpp
 *
 *  Created on: 25/6/2015
 *      Author: mateo
 */

#include "PersonaSerializer.h"

string PersonaSerializer::delimiterString = "|";
char PersonaSerializer::delimiterChar = '|';
string PersonaSerializer::personaDelimiterOpenString = "[";
char PersonaSerializer::personaDelimiterOpenChar = '{';
string PersonaSerializer::personaDelimiterCloseString = "}";
char PersonaSerializer::personaDelimiterCloseChar = '{';

string PersonaSerializer::serialize(Persona p){
	return 	p.getNombre() +
			PersonaSerializer::delimiterString +
			p.getDireccion() +
			PersonaSerializer::delimiterString +
			p.getTelefono();
}

vector<string> split(const string &s, char delim) {
    stringstream ss(s);
    string item;
    vector<string> tokens;
    while (getline(ss, item, delim)) {
        tokens.push_back(item);
    }
    return tokens;
}

Persona PersonaSerializer::deserialize(string str){
	vector<string> att = split(str , PersonaSerializer::delimiterChar);
	if (att.size() != 3){
//		throw ERRRRRRRRRRRRRRRROR
	}

	Persona p = Persona(att[0], att[1], att[2]);
	return p;
}

string PersonaSerializer::serializeVector(vector<Persona> vector){
	size_t i;
	stringstream ss;
	for (i = 0 ; i < vector.size() ; i++){
		Persona p = vector[i];
		ss << PersonaSerializer::personaDelimiterOpenString << PersonaSerializer::serialize(p) << PersonaSerializer::personaDelimiterCloseString;
	}
	return ss.str();
}

vector<Persona> PersonaSerializer::deserializeVector(string str){
	vector<Persona> personas = vector<Persona>();

	//TODO Implementar

	return personas;
}
