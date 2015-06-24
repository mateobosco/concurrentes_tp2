/*
 * Cliente.h
 *
 *  Created on: 24/6/2015
 *      Author: mateobosco
 */

#ifndef SRC_CLIENTE_H_
#define SRC_CLIENTE_H_

#include <sys/types.h>
#include <unistd.h>
#include <iostream>

#include "structures/Cola.h"
#include "Mensaje.h"

class Cliente {
public:
	Cliente();
	virtual ~Cliente();

	void run();
	Mensaje getFromInput();

private:
	Cola<Mensaje>* cola;
	int id;
};

#endif /* SRC_CLIENTE_H_ */