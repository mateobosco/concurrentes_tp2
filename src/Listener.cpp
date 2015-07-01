/*
 * Listener.cpp
 *
 *  Created on: 1/7/2015
 *      Author: mateo
 */

#include "Listener.h"

Listener::Listener() {
	this->semaforoListener = new Semaforo("files/semaforoListener", 0);
	this->db = new Database();
	this->cola = new Cola<Mensaje>("files/cola", 'C');

	this->changeName("TP2 - Listener");
	this->pid = getpid();
}

Listener::~Listener() {
	if (this->pid == getpid()){
		this->semaforoListener->eliminar();
		delete this->semaforoListener;

		this->cola->destruir();
		delete this->cola;
		delete this->db;
		}
	else{
		delete this->semaforoListener;
		delete this->cola;
		delete this->db;
	}
	}

void Listener::run(){
	while (sigint_handler.getGracefulQuit() == 0){
		std::cout<< "Quiero crear un server"<< std::endl;
		int res = this->semaforoListener->p();
		if (res == -1) break;
		std::cout<< "Creo un server"<< std::endl;
		int pid = fork();
		if (pid == 0){
			Server s = Server(this->db, this->cola);
			s.run();
			std::cout<< "soy un server y me quiero ir: "<<getpid()<< std::endl;
			return;
		}else{
			this->servers.push_back(pid);
		}
	}

	for (size_t i = 0; i < this->servers.size() ; i++){
		int p = this->servers[i];
		kill(p,SIGINT);
	}
}

