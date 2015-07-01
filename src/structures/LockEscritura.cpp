#include "LockEscritura.h"

LockEscritura :: LockEscritura ( const std::string nombre ) {

	this->nombre = nombre;
	this->fl.l_type = F_WRLCK;
	this->fl.l_whence = SEEK_SET;
	this->fl.l_start = 0;
	this->fl.l_len = 0;
	this->fd = open ( this->nombre.c_str(),O_CREAT|O_WRONLY,0777 );
	if (this->fd == -1) perror("Error al crear el lock de escritura");
}

int LockEscritura :: tomarLock () {
	this->fl.l_type = F_WRLCK;
	int res = fcntl ( this->fd,F_SETLKW,&(this->fl) );
	if (res == -1){
		perror("Error al tomar lock de escritura");
	}
	return res;
}

int LockEscritura :: liberarLock () {
	this->fl.l_type = F_UNLCK;
	int res = fcntl ( this->fd,F_SETLK,&(this->fl) );
	if (res == -1){
		perror("Error al liberar lock de escritura");
	}
	return res;
}

ssize_t LockEscritura :: escribir ( const void* buffer,const ssize_t buffsize ) const {
	lseek ( this->fd,0,SEEK_END );
	ssize_t escritos = write ( this->fd,buffer,buffsize );
	if (escritos < buffsize){
		perror("Error al escribir en el lock de escritura");
	}
	return escritos;
}

LockEscritura :: ~LockEscritura () {
	int res = close ( this->fd );
	if (res == -1 ) perror("Error al cerrar el lock de escritura");
}
