/*
 * Database.cpp
 *
 *  Created on: 20/6/2015
 *      Author: mateo
 */

#include "Database.h"

string Database::dbFilePath = "files/database.dat";
string Database::lockFilePath = "files/lockFile";

Database::Database() {
	this->lockLectura = new LockLectura(Database::lockFilePath);
	this->lockEscritura = new  LockEscritura(Database::lockFilePath);

	this->dbFileAppend = fopen(Database::dbFilePath.c_str(),"a");
	this->dbFileRead = fopen(Database::dbFilePath.c_str(),"r");

	if (this->dbFileAppend == NULL || this->dbFileRead == NULL){
		//CAGASTE TODO
	}
}

Database::~Database() {
	fclose(this->dbFileAppend);
	fclose(this->dbFileRead);

	remove(Database::dbFilePath.c_str());
	delete this->lockLectura;
	delete this->lockEscritura;
}

bool Database::append(Persona p){
	int resLock = this->lockEscritura->tomarLock();
	if (resLock == -1){
		return false;
	}
	string personaSerialized = p.serialize() + "\n";

	int resWrite = fputs(personaSerialized.c_str(), this->dbFileAppend);
	fflush(this->dbFileAppend);

	resLock = this->lockEscritura->liberarLock();
	if (resLock == -1){
		return false;
	}
	if (resWrite == EOF){
		return false;
	}
	return true;
}

vector<Persona> Database::getVector(){
	int resLock = this->lockLectura->tomarLock();
	if (resLock == -1){
//		ver que carajo hacer TODO
	}
	vector<Persona> personas = vector<Persona>();
	char line[255];

	rewind(this->dbFileRead);
	while ((fscanf(this->dbFileRead, "%[^\n]", line)) != EOF){
		fgetc(this->dbFileRead);
		Persona p = Persona::deserialize(string(line));
		personas.push_back(p);
	}
	resLock = this->lockLectura->liberarLock();
	if (resLock == -1){
//		ver que carajo hacer TODO
	}

	return personas;
}
