/*
 * Server.cpp
 *
 *  Created on: 24/6/2015
 *      Author: mateobosco
 */

#include "Server.h"

Server::Server() {
	this->cola = new Cola<Mensaje>("files/cola", 'C');
}

Server::~Server(){
	delete this->cola;
}

void Server::run(){

	while (true){
		std::cout<<"esperando para leer de la cola"<<std::endl;
		Mensaje msj = Mensaje();
		this->cola->leer(0,&msj);
		std::cout<<"ya lei"<<std::endl;
	}
}
