/*
 * PersonaSerializer.cpp
 *
 *  Created on: 25/6/2015
 *      Author: mateo
 */

#include "PersonaSerializer.h"

string PersonaSerializer::delimiterString = "|";
char PersonaSerializer::delimiterChar = '|';
string PersonaSerializer::personaDelimiterString = "\n";
char PersonaSerializer::personaDelimiterChar = '\n';

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
	if (att.size() == 2){
		att.push_back("");
	}
	string nombre = att[0];
	string direccion = att[1];
	string telefono = att[2];
	Persona p = Persona(nombre, direccion, telefono);
	return p;
}

string PersonaSerializer::serializeVector(vector<Persona> vector){
	size_t i;
	stringstream ss;
	for (i = 0 ; i < vector.size() ; i++){
		Persona p = vector[i];
		ss << PersonaSerializer::serialize(p);
		if (i < vector.size()-1){
			ss << PersonaSerializer::personaDelimiterString;
		}
	}
	return ss.str();
}

vector<Persona> PersonaSerializer::deserializeVector(string str){
	vector<Persona> personas = vector<Persona>();
	vector<string> personasString = split(str , PersonaSerializer::personaDelimiterChar);
	size_t i;
	for (i = 0 ; i < personasString.size() ; i++){
		personas.push_back(PersonaSerializer::deserialize(personasString[i]));
	}
	return personas;
}
