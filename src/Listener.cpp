/*
 * Listener.cpp
 *
 *  Created on: 1/7/2015
 *      Author: mateo
 */

#include "Listener.h"

string Listener::colaFilePath = "files/cola";
string Listener::semaforoFilePath = "files/semaforoListener";

Listener::Listener() {
	this->createFile(Listener::colaFilePath);
	this->createFile(Listener::semaforoFilePath);
	this->semaforoListener = new Semaforo(Listener::semaforoFilePath, 0);
	this->db = new Database();
	this->cola = new Cola<Mensaje>(Listener::colaFilePath, 'C');

	this->changeName("TP2 - Listener");
	this->pid = getpid();
}

Listener::~Listener() {
	if (this->pid == getpid()){
		this->semaforoListener->eliminar();
		delete this->semaforoListener;
		remove(Listener::semaforoFilePath.c_str());

		this->cola->destruir();
		delete this->cola;
		remove(Listener::colaFilePath.c_str());
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
		int res = this->semaforoListener->p();
		if (res == -1) break;
		std::cout<< "Creo un server"<< std::endl;
		int pid = fork();
		if (pid == 0){
			Server s = Server(this->db, this->cola);
			s.run();
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

void Listener::createFile(std::string file){
	std::ofstream outfile (file.c_str());
	outfile.close();
}

