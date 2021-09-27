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
using namespace std;

class Board {
public:
	Board();
	virtual ~Board();
	void displayBoard();
	void printToFile(char* filename);
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
	void moveb();
	void mover();
	bool isValid(int,int);
private:
	char* edgesP;
	bool turn;
};

#endif /* BOARD_H_ */
