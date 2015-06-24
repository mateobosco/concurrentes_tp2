/*
 * Mensaje.h
 *
 *  Created on: 24/6/2015
 *      Author: mateobosco
 */

#ifndef SRC_MENSAJE_H_
#define SRC_MENSAJE_H_


typedef struct mensaje{
	long to;
	long from;
	int op;
	char body[16];
}Mensaje;


#endif /* SRC_MENSAJE_H_ */
