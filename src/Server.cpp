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
	this->cola->destruir();
	delete this->cola;
}

void Server::run(){

	while (true){
		std::cout<<"SERVER: esperando para leer de la cola"<<std::endl;
		Mensaje msj = Mensaje();
		this->cola->leer(1,&msj);
		std::cout<<"SERVER: Un cliente "<< msj.from<<" pidio op"<< msj.op <<std::endl;
	}
}
