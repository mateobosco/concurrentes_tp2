#ifndef LOCKESCRITURA_H_
#define LOCKESCRITURA_H_

#include <unistd.h>
#include <fcntl.h>
#include <string>

class LockEscritura {

private:
	struct flock fl;
	int fd;
	std::string nombre;

public:
	LockEscritura ( const std::string nombre );
	~LockEscritura();

	int tomarLock ();
	int liberarLock ();
	ssize_t escribir ( const void* buffer,const ssize_t buffsize ) const;
};

#endif /* LOCKESCRITURA_H_ */
