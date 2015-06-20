/*
 * Persona_Test.cpp
 *
 *  Created on: 20/6/2015
 *      Author: mateo
 */

#include <gtest/gtest.h>
#include <iostream>

#include "../Persona.h"

TEST(PersonaTests,TestPersonaSerialize){
	Persona p = Persona("Pepe","Santa Fe 1234 4to B", "4444-4444");
	string serialized = "Pepe|Santa Fe 1234 4to B|4444-4444";
	ASSERT_EQ(serialized , p.serialize());
}



