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
#include <fstream>

#include "structures/LockEscritura.h"
#include "structures/LockLectura.h"
#include "PersonaSerializer.h"

using namespace std;

class Database {
public:
	Database();
	virtual ~Database();

	bool append(Persona p);
	vector<Persona> search(Persona query);
	vector<Persona> getPersonas();

private:
	void createFile(std::string file);

	LockEscritura* lockEscritura;
	LockLectura* lockLectura;

	FILE* dbFileAppend;
	FILE* dbFileRead;

	static string dbFilePath;
	static string lockFilePath;
};

#endif /* DATABASE_H_ */
