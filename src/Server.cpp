/*
 * Server.cpp
 *
 *  Created on: 24/6/2015
 *      Author: mateobosco
 */

#include "Server.h"

int Server::id = 1;

Server::Server() {
	this->db = new Database();
	this->cola = new Cola<Mensaje>("files/cola", 'C');
}

Server::~Server(){
	this->cola->destruir();
	delete this->cola;

	delete this->db;
}

void Server::run(){
	while (true){
		std::cout<<"SERVER: esperando para leer de la cola"<<std::endl;
		Mensaje msj = Mensaje();
		this->cola->leer(1,&msj);
		std::cout<<"SERVER: Un cliente "<< msj.from<<" pidio op"<< msj.op <<std::endl;
		this->procesar(msj);
	}
}

void Server::procesar(Mensaje m){
	if (m.op == 1){ //LEER DE LA BASE DE DATOS
	}
	else if (m.op == 2){ //AGREGAR A LA BASE DE DATOS
		std::string personaString = std::string(m.body);
		Persona p = Persona::deserialize(personaString);
		this->db->append(p);
	}
}
