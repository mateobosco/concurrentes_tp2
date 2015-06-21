/*
 * Database.h
 *
 *  Created on: 20/6/2015
 *      Author: mateo
 */

#ifndef DATABASE_H_
#define DATABASE_H_

#include <iostream>
#include <stdio.h>


#include "structures/LockEscritura.h"
#include "structures/LockLectura.h"
#include "Persona.h"

using namespace std;

class Database {
public:
	Database();
	virtual ~Database();

	bool append(Persona p);
	vector<Persona> getVector();
	string getString();

private:
	LockEscritura* lockEscritura;
	LockLectura* lockLectura;

	FILE* dbFileAppend;
	FILE* dbFileRead;

	static string dbFilePath;
	static string lockFilePath;
};

#endif /* DATABASE_H_ */
