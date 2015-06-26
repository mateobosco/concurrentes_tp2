/*
 * Mensaje.h
 *
 *  Created on: 24/6/2015
 *      Author: mateobosco
 */

#ifndef SRC_MENSAJE_H_
#define SRC_MENSAJE_H_

class ConstantesMensaje{
public:
	static const int BODY_MENSAJE_SIZE = 50;
};

typedef struct mensaje{
	long to;
	long from;
	int op;
	char body[ConstantesMensaje::BODY_MENSAJE_SIZE];
}Mensaje;


#endif /* SRC_MENSAJE_H_ */
