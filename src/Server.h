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
#include "Respuesta.h"
#include "Database.h"
#include "Operaciones.h"

using namespace std;

class Server {
public:
	Server();
	virtual ~Server();

	void run();
	void enviar(Respuesta rta);

	static int id;
private:
	Respuesta procesar(Mensaje m);

	Database* db;
	Cola<Mensaje>* cola;
};

#endif /* SRC_SERVER_H_ */
