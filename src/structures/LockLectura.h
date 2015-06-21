#ifndef LOCKLECTURA_H_
#define LOCKLECTURA_H_

#include <unistd.h>
#include <fcntl.h>
#include <string>

class LockLectura {

private:
	struct flock fl;
	int fd;
	std::string nombre;

public:
	LockLectura ( const std::string nombre );
	~LockLectura();

	int tomarLock ();
	int liberarLock ();
	int leer ( void* buffer,const int count ) const;
};

#endif /* LOCKLECTURA_H_ */
