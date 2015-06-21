/*
 * Database_Test.cpp
 *
 *  Created on: 20/6/2015
 *      Author: mateo
 */

#include <gtest/gtest.h>
#include <iostream>

#include "../Database.h"

TEST(DatabaseTest, TestPut1Persona){
	Database db = Database();
	Persona p = Persona("Pepe","Santa Fe 1234 4to B", "4444-4444");
	ASSERT_TRUE(db.append(p));
	vector<Persona> personas = db.getVector();
	ASSERT_EQ(1, personas.size());
	ASSERT_EQ(p.serialize(), personas[0].serialize());
}


