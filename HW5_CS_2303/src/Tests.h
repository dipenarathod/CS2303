/*
 * Tests.h
 *
 *  Created on: Feb 1, 2020
 *      Author: Therese
 */

#ifndef TESTS_H_
#define TESTS_H_
#include "Production.h"
#include <stdio.h>
#include "Checker.h"
#include <iostream>
#include "Board.h"


class Tests {
public:
	Tests();
	virtual ~Tests();
	bool tests();
	bool testReadFile();
	bool testEnqueue();
	bool testGotBoard();
	bool testMakeLList();
	//pedagogical bool testRemoveFromList();
	bool testPrintHistory();
	bool testFileOutput();

	//Test cases for methods in Board
	bool testMoveDiagonalLeft();
	bool testMoveDiagonalRight();
	bool testMoveBackDiagonalLeft();
	bool testMoveBackDiagonalRight();
	bool testIsWin();
	//Test cases for methods in Production
	bool testGetPlayerMove();


};

#endif /* TESTS_H_ */
