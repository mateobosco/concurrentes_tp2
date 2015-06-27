/*
 * Respuesta.cpp
 *
 *  Created on: 26/6/2015
 *      Author: mateo
 */

#include "Respuesta.h"

Respuesta::Respuesta(long to, long from, int op, string body) {
	this->to = to;
	this->from = from;
	this->op = op;
	this->body = body;
}

Respuesta::Respuesta(vector<Mensaje> mensajes){
	Mensaje primerMensaje = mensajes[0];
	this->to = primerMensaje.to;
	this->from = primerMensaje.from;
	this->op = primerMensaje.op;
	stringstream ss;
	for (size_t i = 0 ; i < mensajes.size(); i++){
		ss << mensajes[i].body;
	}
	this->body = ss.str();
}

Respuesta::~Respuesta() {
}

vector<Mensaje> Respuesta::getMensajes(){
	vector<Mensaje> mensajes = vector<Mensaje>();

	size_t sizeString = this->body.size();
	size_t cant = sizeString / ConstantesMensaje::BODY_MENSAJE_SIZE;

	for (size_t i = 0 ; i <= cant ; i ++){
		size_t inicio = i * ConstantesMensaje::BODY_MENSAJE_SIZE;
		string body = this->body.substr(inicio, ConstantesMensaje::BODY_MENSAJE_SIZE);
		Mensaje m = Mensaje();
		m.to = this->to;
		m.from = this->from;
		m.op = this->op;
		m.cont = (i != cant);
		strcpy(m.body , body.c_str());
		mensajes.push_back(m);
	}

	return mensajes;
}
