//============================================================================
// Name        : Battleship_cpp.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>

#include "Fleet.h"
#include "Production.h"
#include "Tests.h"
using namespace std;

int main() {
	Tests* test=new Tests();
	Production* prod=new Production();
	if(test->tests()){
		prod->production();
		return 0;
	}
	else{
		printf("Not all tests passed\n");fflush(stdout);
		return 0;
	}
}
