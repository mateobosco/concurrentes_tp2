#include "LockLectura.h"

LockLectura :: LockLectura ( const std::string nombre ) {

	this->nombre = nombre;
	this->fl.l_type = F_RDLCK;
	this->fl.l_whence = SEEK_SET;
	this->fl.l_start = 0;
	this->fl.l_len = 0;
	this->fd = open ( this->nombre.c_str(),O_CREAT|O_RDONLY,0777 );
	if (this->fd == -1) perror("Error al crear el lock de lectura");
}

int LockLectura :: tomarLock () {
	this->fl.l_type = F_RDLCK;
	int res = fcntl ( this->fd,F_SETLKW,&(this->fl) );
	if (res == -1){
		perror("Error al tomar lock de lectura");
	}
	return res;
}

int LockLectura :: liberarLock () {
	this->fl.l_type = F_UNLCK;
	int res = fcntl ( this->fd,F_SETLK,&(this->fl) );
	if (res == -1){
		perror("Error al liberar lock de lectura");
	}
	return res;
}

int LockLectura :: leer ( void* buffer, const int count ) const {
	lseek ( this->fd,0,SEEK_END );
	int leidos = read ( this->fd,buffer,count );
	if ( leidos < count) perror("Erro al leer del lock de lectura");
	return leidos;
}

LockLectura :: ~LockLectura () {
	int res = close ( this->fd );
	if (res == -1 ) perror("Error al cerrar el lock de lectura");
}
