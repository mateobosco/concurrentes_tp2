/*
 * Server.h
 *
 *  Created on: 24/6/2015
 *      Author: mateobosco
 */

#ifndef SRC_SERVER_H_
#define SRC_SERVER_H_

#include <iostream>

#include "structures/Cola.h"
#include "Mensaje.h"

class Server {
public:
	Server();
	virtual ~Server();

	void run();

private:
	Cola<Mensaje>* cola;
};

#endif /* SRC_SERVER_H_ */
