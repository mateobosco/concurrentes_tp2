/*
 * Persona_Test.cpp
 *
 *  Created on: 20/6/2015
 *      Author: mateo
 */

#include <gtest/gtest.h>
#include <iostream>

#include "../PersonaSerializer.h"

TEST(PersonaSerializerTest, TestPersonaSerialize){
	Persona p = Persona("Pepe","Santa Fe 1234 4to B", "4444-4444");
	string serialized = "Pepe|Santa Fe 1234 4to B|4444-4444";
	ASSERT_EQ(serialized , PersonaSerializer::serialize(p));
}

TEST(PersonaSerializerTest, TestPersonaDeserialize){
	Persona p = Persona("Pepe","Santa Fe 1234 4to B", "4444-4444");
	string serialized = "Pepe|Santa Fe 1234 4to B|4444-4444";
	Persona deserialized = PersonaSerializer::deserialize(serialized);
	ASSERT_EQ(p.getNombre(), deserialized.getNombre());
	ASSERT_EQ(p.getDireccion(), deserialized.getDireccion());
	ASSERT_EQ(p.getTelefono(), deserialized.getTelefono());
}

TEST(PersonaSerializerTest, TestPersonaDeserializeSerialize){
	string serialized = "Pepe|Santa Fe 1234 4to B|4444-4444";
	Persona deserialized = PersonaSerializer::deserialize(serialized);
	ASSERT_EQ(serialized, PersonaSerializer::serialize(deserialized));
}


TEST(PersonaSerializerTest, TestSerializeVectorOfTwoPersonas){
	Persona p1 = Persona("Pepe","Santa Fe 1234 4to B", "4444-4444");
	Persona p2 = Persona("Jose","Corrientes 124 3to A", "5555-5555");
	vector<Persona> personas = vector<Persona>();
	personas.push_back(p1);
	personas.push_back(p2);
	string serialized = "Pepe|Santa Fe 1234 4to B|4444-4444\nJose|Corrientes 124 3to A|5555-5555";
	ASSERT_EQ(serialized, PersonaSerializer::serializeVector(personas));
}

TEST(PersonaSerializerTest, TestDeserializeAndSerializeVectorOfTwoPersonas){
	string serialized = "Pepe|Santa Fe 1234 4to B|4444-4444\nJose|Corrientes 124 3to A|5555-5555";
	ASSERT_EQ(serialized, PersonaSerializer::serialize(PersonaSerializer::deserialize(serialized)));
}

