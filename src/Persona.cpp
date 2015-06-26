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

bool Persona::similar(Persona p){
	return (this->getNombre() == p.getNombre() ||
		this->getTelefono() == p.getTelefono() ||
		this->getDireccion() == p.getDireccion());
}
