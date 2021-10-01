/*
 * Tests.cpp
 *
 *  Created on: Oct 1, 2021
 *      Author: Dipen
 */

#include "Tests.h"

Tests::Tests() {
	// TODO Auto-generated constructor stub

}

Tests::~Tests() {
	// TODO Auto-generated destructor stub
}

bool Tests::testWelcomeScreen(){
	Production* prod=new Production();
	prod->welcomeScreen();
	if(prod->getYesNo("Correct welcome screen?")){
		return true;
	}
	else{
		return false;
	}
}

bool Tests::testSystemMessage(){
	Production* prod=new Production();
	prod->systemMessage("Hello, press enter to move on");
	if(prod->getYesNo("Did pressing enter work?")){
		return true;
	}
	else{
		return false;
	}
}

bool Tests::testInitializeGameBoard(){
	Cell gameBoard[ROWS][COLS];
	Board* board=new Board();
	board->initializeGameBoard(gameBoard);
	if(gameBoard[0][0].symbol==WATER)
		return true;
	else
		return false;
}

bool Tests::testPrintGameBoard(){
	Cell gameBoard[ROWS][COLS];
	Board* board=new Board();
	board->initializeGameBoard(gameBoard);
	//board->printGameBoard(gameBoard);

}

