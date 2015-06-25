/*
 * Cliente.cpp
 *
 *  Created on: 24/6/2015
 *      Author: mateobosco
 */

#include "Cliente.h"

Cliente::Cliente() {
	this->id = getpid();
	this->cola = new Cola<Mensaje>("files/cola",'C');
}

Cliente::~Cliente() {
	delete this->cola;
}

void Cliente::run(){

	while(true){
		Mensaje m = this->getMensajeFromInput();
		if (m.op == 4) break;
		int resEscribir = this->cola->escribir(m);
		std::cout<<"CLIENTE: escribi en la cola con res" << resEscribir <<std::endl;
		Mensaje respuesta = Mensaje();
		std::cout<<"CLIENTE: voy a leer"<<std::endl;
		this->cola->leer(this->id,&respuesta);
		std::cout<<"CLIENTE: lei este body" << string(respuesta.body) <<std::endl;
	}
}

Mensaje Cliente::getMensajeFromInput(){
	Mensaje m = Mensaje();
	m.to = Server::id;
	int op = 0;
	while (op < 1 || op > 4){
		std::cout<<"1 - Leer todos los registros de la base de datos"<<std::endl;
		std::cout<<"2 - Buscar una persona"<<std::endl;
		std::cout<<"3 - Agregar a la base de datos"<<std::endl;
		std::cout<<"4 - Salir"<<std::endl;
		std::cout<<"Ingrese el numero de opearacion que desea realizar: ";
		std::cin >> op;
		std::cout<<"Elegiste " << op <<std::endl;
		if (op == 2){
			Persona p = this->getPersonaFromInput();
			strcpy(m.body,p.serialize().c_str());
		}
	}
	m.op = op;
	m.from = this->id;
	return m;
}

Persona Cliente::getPersonaFromInput(){
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
