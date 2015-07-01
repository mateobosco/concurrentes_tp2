/*
 * Server.cpp
 *
 *  Created on: 24/6/2015
 *      Author: mateobosco
 */

#include "Server.h"

int Server::id = 1;

Server::Server(Database* db, Cola<Mensaje>* cola) {
	this->db = db;
	this->cola = cola;
	this->changeName("TP2 - Server");
}

Server::~Server(){
}

void Server::run(){
	while (sigint_handler.getGracefulQuit() == 0){
		cout<<"SERVER: esperando para leer de la cola"<<endl;
		Mensaje msj = this->leerPedido();

		if (msj.op == Operaciones::EXIT) break;

		cout<<"SERVER: Un cliente "<< msj.from<<" pidio op "<< msj.op <<endl;
		Respuesta rta = this->procesar(msj);

		this->enviar(rta);
	}
}

Mensaje Server::leerPedido(){
	Mensaje msj = Mensaje();
	if (sigint_handler.getGracefulQuit() == 0) this->cola->leer(1,&msj);
	return msj;
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
