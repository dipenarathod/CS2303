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

bool Tests::tests(){
	bool ok1=testWelcomeScreen();
	bool ok2=testSystemMessage();
	bool ok3=testInitializeGameBoard();
	bool ok4=testPrintGameBoard();
	bool ok5=testManuallyPlaceShipsOnGameBoard();
	bool ok6=testRandomlyPlaceShipsOnGameBoard();
	bool ok7=testUpdateGameBoard();

	return ok1&&ok2&&ok3&&ok4&&ok5&&ok6&&ok7;
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
	prod->systemMessage("Hello, press enter to move on");fflush(stdout);
	if(prod->getYesNo("Did pressing enter work?")){
		printf("system message works\n");fflush(stdout);
		return true;
	}
	else{
		printf("system message fails\n");fflush(stdout);
		return false;
	}
}

bool Tests::testInitializeGameBoard(){
	Cell gameBoard[ROWS][COLS];
	Board* board=new Board();
	board->initializeGameBoard(gameBoard);
	if(gameBoard[0][0].symbol==WATER){
		printf("Initializing game board worked\n");fflush(stdout);
		return true;
	}
	else{
		printf("Initializing game board failed\n");fflush(stdout);
		return false;
	}
}

bool Tests::testPrintGameBoard(){
	Cell gameBoard[ROWS][COLS];
	Board* board=new Board();
	board->initializeGameBoard(gameBoard);
	board->printGameBoard(gameBoard,TRUE);
	Production* prod=new Production();
	if(prod->getYesNo("Was a correct blank board displayed?")){
		printf("printGameBoard works\n");fflush(stdout);
		return true;
	}
	else{
		printf("printGameBoard fails\n");fflush(stdout);
		return false;
	}
}

bool Tests::testManuallyPlaceShipsOnGameBoard(){
	Cell gameBoard[ROWS][COLS];
	Board* board=new Board();
	board->initializeGameBoard(gameBoard);
	WaterCraft ship[NUM_OF_SHIPS] = {{'c', 5, "Carrier"},
			{'b', 4, "Battleship"},
			{'r', 3, "Cruiser"},
			{'s', 3, "Submarine"},
			{'d', 2, "Destroyer"}};
	board->manuallyPlaceShipsOnGameBoard (gameBoard, ship);
	board->printGameBoard(gameBoard, TRUE);
	Production* prod=new Production();
	if(prod->getYesNo("Were the ships placed correctly?")){
		printf("testManuallyPlaceShipsOnGameBoard passes\n");fflush(stdout);
		return true;
	}
	else{
		printf("testManuallyPlaceShipsOnGameBoard passes\n");fflush(stdout);
		return false;
	}
}

bool Tests::testRandomlyPlaceShipsOnGameBoard(){
	Cell gameBoard[ROWS][COLS];
	Board* board=new Board();
	board->initializeGameBoard(gameBoard);
	WaterCraft ship[NUM_OF_SHIPS] = {{'c', 5, "Carrier"},
			{'b', 4, "Battleship"},
			{'r', 3, "Cruiser"},
			{'s', 3, "Submarine"},
			{'d', 2, "Destroyer"}};
	board->randomlyPlaceShipsOnGameBoard (gameBoard, ship);
	board->printGameBoard(gameBoard, TRUE);
	Production* prod=new Production();
	if(prod->getYesNo("Were the ships placed randomly?")){
		printf("testRandomlyPlaceShipsOnGameBoard passes\n");fflush(stdout);
		return true;
	}
	else{
		printf("testRandomlyPlaceShipsOnGameBoard fails\n");fflush(stdout);
		return false;
	}
}

bool Tests::testUpdateGameBoard(){
	Cell gameBoard[ROWS][COLS];
	Board* board=new Board();
	board->initializeGameBoard(gameBoard);
	Fleet* ship1=new Fleet();
	Coordinate target=ship1->getTarget();
	WaterCraft ship[NUM_OF_SHIPS] = {{'c', 5, "Carrier"},
			{'b', 4, "Battleship"},
			{'r', 3, "Cruiser"},
			{'s', 3, "Submarine"},
			{'d', 2, "Destroyer"}};
	board->randomlyPlaceShipsOnGameBoard (gameBoard, ship);
	board->updateGameBoard(gameBoard, target);
	board->printGameBoard(gameBoard, TRUE);
	Production* prod=new Production();
	if(prod->getYesNo("Was the coordinate targeted?")){
		printf("testUpdateGameBoard passes\n");fflush(stdout);
		return true;
	}
	else{
		printf("testUpdateGameBoard fails\n");fflush(stdout);
		return false;
	}
}
