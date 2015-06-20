/*
 * Persona.cpp
 *
 *  Created on: 20/6/2015
 *      Author: mateo
 */

#include "Persona.h"

Persona::Persona(string nombre, string direccion, string telefono) {
	strcpy(this->nombre , nombre.c_str());
	strcpy(this->direccion , direccion.c_str());
	strcpy(this->telefono , telefono.c_str());
}

Persona::Persona(){
}

Persona::~Persona() {
}

string Persona::getNombre(){
	return string(this->nombre);
}

void Persona::setNombre(string nombre){
	strcpy(this->nombre , nombre.c_str());
}

string Persona::getDireccion(){
	return string(this->direccion);
}

void Persona::setDireccion(string direccion){
	strcpy(this->direccion , direccion.c_str());
}

string Persona::getTelefono(){
	return string(this->telefono);
}

void Persona::setTelefono(string telefono){
	strcpy(this->telefono , telefono.c_str());
}

string Persona::serialize(){
	return this->getNombre() + "|" + this->getDireccion() + "|" + this->getTelefono();
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

Persona Persona::deserialize(string str){
	vector<string> att = split(str,'|');

	if (att.size() != 3){
//		throw ERRRRRRRRRRRRRRRROR
	}

	Persona p = Persona();

	p.setNombre(att[0]);
	p.setDireccion(att[1]);
	p.setTelefono(att[2]);
	return p;
}
