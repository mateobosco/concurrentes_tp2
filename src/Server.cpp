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
		cout<<"SERVER: esperando para leer de la cola"<<endl;
		Mensaje msj = Mensaje();
		this->cola->leer(1,&msj);
		cout<<"SERVER: Un cliente "<< msj.from<<" pidio op"<< msj.op <<endl;
		Mensaje rta = this->procesar(msj);
		this->cola->escribir(rta);
		cout<<"SERVER: respondio"<<endl;
	}
}

Mensaje Server::procesar(Mensaje m){
	Mensaje rta = Mensaje();
	rta.to = m.from;
	rta.from = Server::id;
	if (m.op == 1){ //LEER DE LA BASE DE DATOS
		string personas = this->db->getString();
		strcpy(rta.body,personas.c_str());
	}
	else if (m.op == 2){ //AGREGAR A LA BASE DE DATOS
		string personaString = string(m.body);
		Persona p = Persona::deserialize(personaString);
		bool res = this->db->append(p);
		if (res) strcpy(rta.body, "OK");
		else strcpy(rta.body, "ERROR");
	}
	return rta;
}
