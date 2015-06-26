/*
 * Persona_Test.cpp
 *
 *  Created on: 20/6/2015
 *      Author: mateo
 */

#include <gtest/gtest.h>
#include <iostream>

#include "../PersonaSerializer.h"

TEST(PersonaTest, TestPersonaSerialize){
	Persona p = Persona("Pepe","Santa Fe 1234 4to B", "4444-4444");
	string serialized = "Pepe|Santa Fe 1234 4to B|4444-4444";
	ASSERT_EQ(serialized , PersonaSerializer::serialize(p));
}

TEST(PersonaTest, TestPersonaDeserialize){
	Persona p = Persona("Pepe","Santa Fe 1234 4to B", "4444-4444");
	string serialized = "Pepe|Santa Fe 1234 4to B|4444-4444";
	Persona deserialized = PersonaSerializer::deserialize(serialized);
	ASSERT_EQ(p.getNombre(), deserialized.getNombre());
	ASSERT_EQ(p.getDireccion(), deserialized.getDireccion());
	ASSERT_EQ(p.getTelefono(), deserialized.getTelefono());
}

TEST(PersonaTest, TestPersonaDeserializeSerialize){
	string serialized = "Pepe|Santa Fe 1234 4to B|4444-4444";
	Persona deserialized = PersonaSerializer::deserialize(serialized);
	ASSERT_EQ(serialized, PersonaSerializer::serialize(deserialized));
}


