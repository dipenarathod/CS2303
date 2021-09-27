/*
 * Production.h
 *
 *  Created on: Feb 1, 2020
 *      Author: Therese
 */

#ifndef PRODUCTION_H_
#define PRODUCTION_H_
#include <stdio.h>
#include <stdbool.h>
#include <string.h>//strncpy
#include <stdlib.h>//strtol
#include "Board.h"
#include "LinkedList.h"
#include "Checker.h"


#define FILENAMELENGTHALLOWANCE 50
class Production {
public:
	Production();
	virtual ~Production();
	bool prod(int argc, char* argv[]);
	bool readFile(char*, Board*,Checker**,Checker**);
	bool getYesNo(char* query);
	bool getTurn();
	void switchTurn();
	void setTurn(bool turn);
	pieceMove getPlayerMove(Checker**,Checker**);

private:
	bool turn;
	bool amGoingFirst;
};
#endif /* PRODUCTION_H_ */
