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
		Mensaje m = InputOutput::getMensaje(this->id);
		if (m.op == Operaciones::EXIT) break;

		this->cola->escribir(m);

		Mensaje respuesta = Mensaje();
		Respuesta rta = this->escuchar();

		InputOutput::showRespuesta(rta);
	}
}

Respuesta Cliente::escuchar(){
	vector<Mensaje> mensajes = vector<Mensaje>();
	Mensaje msj = Mensaje();
	do{
		this->cola->leer(this->id, &msj);
		mensajes.push_back(msj);
	}while(msj.cont);
	return Respuesta(mensajes);
}
