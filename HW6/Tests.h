/*
 * Tests.h
 *
 *  Created on: Oct 1, 2021
 *      Author: Dipen
 */

#ifndef TESTS_H_
#define TESTS_H_

#include "Production.h"
#include "Board.h"
#include <iostream>
class Tests {
public:
	Tests();
	virtual ~Tests();
	bool tests();
	//Production functions
	bool testWelcomeScreen();
	bool testSystemMessage();

	//Board Functions
	bool testInitializeGameBoard();
	bool testPrintGameBoard();
	bool testManuallyPlaceShipsOnGameBoard();
	bool testRandomlyPlaceShipsOnGameBoard();
	bool testUpdateGameBoard();

	//Fleet Functions
	bool testCheckBoundsOfCardinal();
	bool testCheckSunkShip();
	bool testIsWinner();
	bool testGetTarget();
	bool testCheckShot();
};

#endif /* TESTS_H_ */
