/*
 * Board.h
 *
 *  Created on: Aug 2, 2021
 *      Author: theresesmith
 */

#ifndef BOARD_H_
#define BOARD_H_
#include <stdio.h>
#include <iostream>
#include<fstream>
#include "pieceMove.h"
#include  "Checker.h"

using namespace std;

class Board {
public:
	Board();
	virtual ~Board();
	void displayBoard();
	void printToFile(char* filename,Checker**,Checker**);
	void setEdge(int row, int col, char player);
	char getEdge(int row, int col); //Returns binary value on adjMatrix given a row and a col
	void init();
	//void setN(int set);
	void setEdgesP(char* set);
	char* getEdgesP();
	int n=8;
	bool getTurn();
	void switchTurn();
	void setTurn(bool);
	bool moveb();
	void mover();
	bool isWin();
	bool canJump(pieceMove);
	bool isValid(pieceMove);
	bool canMove(int, int);
	int computer(Checker**);
	bool mustJump();
	Checker* findChecker(int, int);
	Checker** red;
	Checker** black;

private:
	char* edgesP;
	bool turn;
};

#endif /* BOARD_H_ */
