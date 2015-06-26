//============================================================================
// Name        : concurrentes_tp2.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <gtest/gtest.h>

#include "Server.h"
#include "Cliente.h"

using namespace std;

int main(int argc, char **argv) {
//	testing::InitGoogleTest(&argc, argv);
//	return RUN_ALL_TESTS();

	if (argc > 1){
		Cliente c = Cliente();
		c.run();
	}
	else{
		Server s = Server();
		s.run();
	}

	return 0;
}
