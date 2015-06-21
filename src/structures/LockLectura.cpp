#include "LockLectura.h"

LockLectura :: LockLectura ( const std::string nombre ) {

	this->nombre = nombre;
	this->fl.l_type = F_RDLCK;
	this->fl.l_whence = SEEK_SET;
	this->fl.l_start = 0;
	this->fl.l_len = 0;
	this->fd = open ( this->nombre.c_str(),O_CREAT|O_RDONLY,0777 );
}

int LockLectura :: tomarLock () {
	this->fl.l_type = F_RDLCK;
	return fcntl ( this->fd,F_SETLKW,&(this->fl) );
}

int LockLectura :: liberarLock () {
	this->fl.l_type = F_UNLCK;
	return fcntl ( this->fd,F_SETLK,&(this->fl) );
}

int LockLectura :: leer ( void* buffer, const int count ) const {
	lseek ( this->fd,0,SEEK_END );
	return read ( this->fd,buffer,count );
}

LockLectura :: ~LockLectura () {
	close ( this->fd );
}
