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
#include "Database.h"

class Server {
public:
	Server();
	virtual ~Server();

	void run();

	static int id;
private:
	void procesar(Mensaje m);

	Database* db;
	Cola<Mensaje>* cola;
};

#endif /* SRC_SERVER_H_ */
