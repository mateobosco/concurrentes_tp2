/*
 * Database_Test.cpp
 *
 *  Created on: 20/6/2015
 *      Author: mateo
 */

#include <gtest/gtest.h>
#include <iostream>

#include "../Database.h"
#include "../PersonaSerializer.h"

TEST(DatabaseTest, TestPut1Persona){
	Database db = Database();
	Persona p = Persona("Pepe","Santa Fe 1234 4to B", "4444-4444");
	ASSERT_TRUE(db.append(p));
	vector<Persona> personas = db.getPersonas();
	ASSERT_EQ(1, personas.size());
	ASSERT_EQ(PersonaSerializer::serialize(p), PersonaSerializer::serialize(personas[0]));
}

TEST(DatabaseTest, TestPutAndSearchPersonaByName){
	Database db = Database();
	Persona p1 = Persona("Pepe","Santa Fe 1234 4to B", "4444-4444");
	Persona p2 = Persona("Pepe1","Santa Fe 1234 4to B", "4444-4444");
	Persona p3 = Persona("Pepe","Santa Fe 1234 4to B", "4444-4444");
	Persona p4 = Persona("Pepe","Santa Fe 1234 4to B", "4444-4444");
	Persona p5 = Persona("Pepe4","Santa Fe 1234 4to B", "4444-4444");
	ASSERT_TRUE(db.append(p1));
	ASSERT_TRUE(db.append(p2));
	ASSERT_TRUE(db.append(p3));
	ASSERT_TRUE(db.append(p4));
	ASSERT_TRUE(db.append(p5));
	Persona query = Persona("Pepe","", "");
	vector<Persona> personas = db.search(query);
	ASSERT_EQ(3, personas.size());
}

TEST(DatabaseTest, TestPutAndSearchPersonaByAddress){
	Database db = Database();
	Persona p1 = Persona("Pepe","Santa Fe 1234 4to B", "4444-4444");
	Persona p2 = Persona("Pepe1","Santa Fe 1234 4to B", "4444-4444");
	Persona p3 = Persona("Pepe","Santa Fe 1234 4to B", "4444-4444");
	Persona p4 = Persona("Pepe","Santa Fe 1234 4to B", "4444-4444");
	Persona p5 = Persona("Pepe4","Santa Fe 1234 4to B", "4444-4444");
	ASSERT_TRUE(db.append(p1));
	ASSERT_TRUE(db.append(p2));
	ASSERT_TRUE(db.append(p3));
	ASSERT_TRUE(db.append(p4));
	ASSERT_TRUE(db.append(p5));
	Persona query = Persona("","Santa Fe 1234 4to B", "");
	vector<Persona> personas = db.search(query);
	ASSERT_EQ(5, personas.size());
}

TEST(DatabaseTest, TestPutAndSearchPersonaByTelephone){
	Database db = Database();
	Persona p1 = Persona("Pepe","Santa Fe 1234 4to B", "4444-4444");
	Persona p2 = Persona("Pepe1","Santa Fe 1234 4to B", "4444-4444");
	Persona p3 = Persona("Pepe","Santa Fe 1234 4to B", "4444-4444");
	Persona p4 = Persona("Pepe","Santa Fe 1234 4to B", "4444-4444");
	Persona p5 = Persona("Pepe4","Santa Fe 1234 4to B", "4444-4444");
	ASSERT_TRUE(db.append(p1));
	ASSERT_TRUE(db.append(p2));
	ASSERT_TRUE(db.append(p3));
	ASSERT_TRUE(db.append(p4));
	ASSERT_TRUE(db.append(p5));
	Persona query = Persona("","", "1234-1234");
	vector<Persona> personas = db.search(query);
	ASSERT_EQ(0, personas.size());
}

