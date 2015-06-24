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
}

Cliente::~Cliente() {
	delete this->cola;
}

void Cliente::run(){

	while(true){
		Mensaje m = getFromInput();
		if (m.op == 3) break;
		int resEscribir = this->cola->escribir(m);
		std::cout<<"CLIENTE: escribi en la cola con res" << resEscribir <<std::endl;
		Mensaje respuesta = Mensaje();
		std::cout<<"CLIENTE: voy a leer"<<std::endl;
		this->cola->leer(this->id,&respuesta);
	}
}

Mensaje Cliente::getFromInput(){
	Mensaje m = Mensaje();
	m.to = 1;
	int op = 0;
	while (op < 1 || op > 3){
		std::cout<<"Ingrese el numero de opearacion que desea realizar"<<std::endl;
		std::cout<<"1 - Leer base de datos"<<std::endl;
		std::cout<<"2 - Agregar a la base de datos"<<std::endl;
		std::cout<<"3 - Salir"<<std::endl;
		std::cin >> op;
		std::cout<<"Elegiste " << op <<std::endl;
	}
	m.op = op;
	m.from = this->id;
	return m;
}
