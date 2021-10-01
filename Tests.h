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
class Tests {
public:
	Tests();
	virtual ~Tests();
	bool tests();
	bool testWelcomeScreen();
	bool testSystemMessage();
	bool testInitializeGameBoard();
	bool testPrintGameBoard();
	bool testPutShipOnGameBoard();
	bool testManuallyPlaceShipsOnGameBoard();
	bool testRandomlyPlaceShipsOnGameBoard();
	bool testUpdateGameBoard();
};

#endif /* TESTS_H_ */
