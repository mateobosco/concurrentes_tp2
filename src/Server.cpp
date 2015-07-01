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
	this->changeName("Database-Server");
}

Server::~Server(){
	this->cola->destruir();
	delete this->cola;

	delete this->db;
}

void Server::run(){
	while (sigint_handler.getGracefulQuit() == 0){
		cout<<"SERVER: esperando para leer de la cola"<<endl;
		Mensaje msj = Mensaje();
		this->cola->leer(1,&msj);

		cout<<"SERVER: Un cliente "<< msj.from<<" pidio op "<< msj.op <<endl;
		Respuesta rta = this->procesar(msj);

		this->enviar(rta);
	}
}

Respuesta Server::procesar(Mensaje m){
	string body;
	if (m.op == Operaciones::GET_ALL){ //LEER DE LA BASE DE DATOS
		string personas = PersonaSerializer::serializeVector(this->db->getPersonas());
		body = string (personas.c_str());
	}
	else if ( m.op == Operaciones::SEARCH){ //BUSCAR
		Persona pQuery = PersonaSerializer::deserialize(string(m.body));
		string personas = PersonaSerializer::serializeVector(this->db->search(pQuery));
		body = string(personas.c_str());
	}
	else if (m.op == Operaciones::ADD){ //AGREGAR A LA BASE DE DATOS
		string personaString = string(m.body);
		Persona p = PersonaSerializer::deserialize(personaString);
		bool res = this->db->append(p);
		if (res) body =  "OK";
		else body = "ERROR";
	}
	else{
		body = "ERROR";
	}
	return Respuesta(m.from, m.to, m.op, body);
}

void Server::enviar(Respuesta rta){
	vector<Mensaje> mensajes = rta.getMensajes();
	for (size_t i = 0; i < mensajes.size(); i++){
		Mensaje mensaje = mensajes[i];
		if (sigint_handler.getGracefulQuit() == 0) this->cola->escribir(mensaje);
	}
}
