/*
 * Listener.h
 *
 *  Created on: 1/7/2015
 *      Author: mateo
 */

#ifndef LISTENER_H_
#define LISTENER_H_

#include <vector>
#include <iostream>

#include "structures/Semaforo.h"
#include "Server.h"

class Listener: public Proceso{
public:
	Listener();
	virtual ~Listener();

	void run();

private:
	Cola<Mensaje>* cola;
	Database* db;

	Semaforo* semaforoListener;
	std::vector<int> servers;

	int pid;
};

#endif /* LISTENER_H_ */
