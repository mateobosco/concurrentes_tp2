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

		int resEscribir = this->cola->escribir(m);
		std::cout<<"CLIENTE: escribi en la cola con res" << resEscribir <<std::endl;

		Mensaje respuesta = Mensaje();
		std::cout<<"CLIENTE: voy a leer"<<std::endl;
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
