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


class Tests {
public:
	Tests();
	virtual ~Tests();
	bool tests();

private:
	bool testReadFile();
	bool testEnqueue();
	bool testGotAdjacencyMatrix();
	bool testMakeLList();
	//pedagogical bool testRemoveFromList();
	bool testPrintHistory();
	bool testFileOutput();

	//My test cases
	bool testMoveDiagonalLeft();
	bool testMoveDiagonalRight();
	bool testMoveBackDiagonalLeft();
	bool testMoveBackDiagonalRight();
};

#endif /* TESTS_H_ */
