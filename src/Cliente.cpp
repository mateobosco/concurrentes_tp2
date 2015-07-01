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
	this->semaforoListener = new Semaforo("files/semaforoListener");
}

Cliente::~Cliente() {
	delete this->cola;
	delete this->semaforoListener;
}

void Cliente::run(){
	this->semaforoListener->v();
	std::cout<<"aumento el semaforo"<<std::endl;
	while(true){
		Mensaje m = InputOutput::getMensaje(this->id);

		this->cola->escribir(m);

		if (m.op == Operaciones::EXIT) break;

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
