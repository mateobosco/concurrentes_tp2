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
	this->createFile(Database::lockFilePath.c_str());
	this->lockLectura = new LockLectura(Database::lockFilePath);
	this->lockEscritura = new  LockEscritura(Database::lockFilePath);

	this->dbFileAppend = fopen(Database::dbFilePath.c_str(),"a");
	this->dbFileRead = fopen(Database::dbFilePath.c_str(),"r");

	if (this->dbFileAppend == NULL || this->dbFileRead == NULL){
		perror("Error al abrir el archivo de la base de datos");
	}
}

Database::~Database() {
	fclose(this->dbFileAppend);
	fclose(this->dbFileRead);

//	remove(Database::dbFilePath.c_str());
	delete this->lockLectura;
	delete this->lockEscritura;
	remove(Database::lockFilePath.c_str());
}

bool Database::append(Persona p){
	int resLock = this->lockEscritura->tomarLock();
	if (resLock == -1){
		return false;
	}
	string personaSerialized = PersonaSerializer::serialize(p) + "\n";

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

vector<Persona> Database::getPersonas(){
	this->lockLectura->tomarLock();
	vector<Persona> personas = vector<Persona>();
	char line[255];

	rewind(this->dbFileRead);
	while ((fscanf(this->dbFileRead, "%[^\n]", line)) != EOF){
		fgetc(this->dbFileRead);
		Persona p = PersonaSerializer::deserialize(string(line));
		personas.push_back(p);
	}
	this->lockLectura->liberarLock();

	return personas;
}

vector<Persona> Database::search(Persona query){
	this->lockLectura->tomarLock();

	vector<Persona> personas = vector<Persona>();
	char line[255];

	rewind(this->dbFileRead);
	while ((fscanf(this->dbFileRead, "%[^\n]", line)) != EOF){
		fgetc(this->dbFileRead);
		Persona p = PersonaSerializer::deserialize(string(line));
		if (p.similar(query)){
			personas.push_back(p);
		}
	}
	this->lockLectura->liberarLock();

	return personas;
}

void Database::createFile(std::string file){
	std::ofstream outfile (file.c_str());
	outfile.close();
}
