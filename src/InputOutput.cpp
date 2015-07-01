/*
 * InputOutput.cpp
 *
 *  Created on: 26/6/2015
 *      Author: mateobosco
 */

#include "InputOutput.h"

InputOutput::InputOutput() {
}

InputOutput::~InputOutput() {
}

Mensaje InputOutput::getMensaje(long from){
	Mensaje m = Mensaje();
	m.to = Server::id;
	int op = 0;
	while (op < Operaciones::GET_ALL || op > Operaciones::EXIT){
		std::cout<<"1 - "<< Operaciones::GET_ALL_STRING <<std::endl;
		std::cout<<"2 - "<< Operaciones::SEARCH_STRING <<std::endl;
		std::cout<<"3 - "<< Operaciones::ADD_STRING <<std::endl;
		std::cout<<"4 - "<< Operaciones::EXIT_STRING <<std::endl;
		std::cout<<"Ingrese el numero de opearacion que desea realizar: ";
		std::cin >> op;
		if (op == Operaciones::SEARCH || op == Operaciones::ADD){
			Persona p = InputOutput::getPersona();
			strcpy(m.body,PersonaSerializer::serialize(p).c_str());
		}
	}
	m.op = op;
	m.from = from;
	return m;
}

Persona InputOutput::getPersona(){
	std::string nombre;
	std::cout<<"Ingrese el nombre: ";
	std::getline(std::cin, nombre);
	std::getline(std::cin, nombre);
	std::string direccion;
	std::cout<<"Ingrese la direccion: ";
	std::getline(std::cin, direccion);
	std::string telefono;
	std::cout<<"Ingrese el telefono: ";
	std::getline(std::cin, telefono);

	return Persona(nombre,direccion,telefono);
}

void InputOutput::showRespuesta(Respuesta rta){
	if (rta.op == Operaciones::GET_ALL || rta.op == Operaciones::SEARCH){
		vector<Persona> personas = PersonaSerializer::deserializeVector(rta.body);
		std::cout<< "------------------------------------" << std::endl;
		InputOutput::showPersonaTitle();
		for (size_t i = 0 ; i < personas.size() ; i ++){
			InputOutput::showPersona(personas[i]);
		}
		std::cout<< "------------------------------------" << std::endl;
	}
	if (rta.op == Operaciones::ADD){

	}

	std::cout<< "=======================================" << std::endl;
}

void InputOutput::showPersonaTitle(){
	std::cout<< "Nombre \t Direccion \t Telefono \t" <<std::endl;
}

void InputOutput::showPersona(Persona p){
	std::cout<< p.getNombre() << '\t' << p.getDireccion() << '\t' << p.getTelefono() <<std::endl;
}
