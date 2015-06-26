/*
 * Respuesta_Tests.cpp
 *
 *  Created on: 26/6/2015
 *      Author: mateo
 */

#include <gtest/gtest.h>
#include <iostream>

#include "../Respuesta.h"

TEST(RespuestaTest, TestRespuestaToMensajeAndMensajeToRespuesta){
	std::string body = "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt "
			"ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris "
			"nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse "
			"cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa"
			" qui officia deserunt mollit anim id est laborum.";
	Respuesta rta = Respuesta(1,1,1,body);
	vector<Mensaje> mensajes = rta.getMensajes();
	ASSERT_TRUE(mensajes.size() > 0);
	ASSERT_EQ(body , Respuesta(mensajes).body);

}
