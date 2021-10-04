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
	bool ok8=testCheckBoundsOfCardinal();
	bool ok9=testCheckSunkShip();
	bool ok10=testCheckShot();
	bool ok11=testGetTarget();
	bool ok12=testIsWinner();

	return ok1&&ok2&&ok3&&ok4&&ok5&&ok6&&ok7&&ok8&&ok9&&ok10&&ok11&&ok12;
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

bool Tests::testCheckBoundsOfCardinal(){
	Fleet* ships=new Fleet();
	Boolean cardinals[4]   = {TRUE, TRUE, TRUE, TRUE};
	bool ok1=false;
	bool ok2=false;
	bool ok3=false;
	bool ok4=false;
	ships->checkBoundsOfCardinal(cardinals, -1, NORTH);
	if(!cardinals[0])
		ok1=true;
	ships->checkBoundsOfCardinal(cardinals, 10, SOUTH);
	if(!cardinals[1])
		ok2=true;
	ships->checkBoundsOfCardinal(cardinals, -1,WEST);
	if(!cardinals[2])
		ok3=true;
	ships->checkBoundsOfCardinal(cardinals, 10,EAST);
	if(!cardinals[3])
		ok4=true;
	if(ok1&&ok2&&ok3&&ok4){
		printf("testCheckBoundsOfCardinal passes\n");fflush(stdout);
		return true;
	}
	else{
		printf("testCheckBoundsOfCardinal fails\n");fflush(stdout);
		return false;
	}
}

bool Tests::testCheckSunkShip(){
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
	Fleet* ships=new Fleet();
	short sunkShip[2][NUM_OF_SHIPS] = {{1, 1, 1, 1, 1},
			{1, 1, 1, 1, 1}};
	Coordinate target=ships->getTarget();
	char  shipSymbol = gameBoard[target.row][target.column].symbol;
	std::cout<<shipSymbol<<std::endl;
	FILE *outStream = NULL;
	outStream = fopen (LOG_FILE_NAME, "w");
	bool ok=ships->checkSunkShip(sunkShip,0, shipSymbol, outStream);
	fclose(outStream);
	if(ok){
		printf("testCheckSunkShip passes\n");fflush(stdout);
		return true;
	}
	else{
		printf("testCheckSunkShip fails\n");fflush(stdout);
		return false;
	}
}

bool Tests::testIsWinner(){
	Stats players1[2] = {{17, 0, 0, 0.0}, {16, 0, 0, 0.0}};
	bool ok1=false;
	Stats players2[2] = {{16, 0, 0, 0.0}, {17, 0, 0, 0.0}};
	bool ok2=false;
	Stats players3[2] = {{17, 0, 0, 0.0}, {18, 0, 0, 0.0}};
	bool ok3=false;
	Stats players4[2] = {{16, 0, 0, 0.0}, {16, 0, 0, 0.0}};
	bool ok4=false;
	Fleet* ship=new Fleet();
	if(ship->isWinner(players1, 0) && !(ship->isWinner(players1,1)))
		ok1=true;\
	else if(!(ship->isWinner(players2,0)) && ship->isWinner(players2, 1))
		ok2=true;
	else if(ship->isWinner(players3,0) && ship->isWinner(players3, 1))
		ok3=true;
	else if(!(ship->isWinner(players4,0)) && !(ship->isWinner(players4, 1)))
		ok4=true;
	std::cout<<ok1<<std::endl;
	std::cout<<ok2<<std::endl;
	std::cout<<ok3<<std::endl;
	std::cout<<ok4<<std::endl;
	if(ok1&&ok2&&ok3&&ok4){
		printf("testIsWinner Passed\n");fflush(stdout);
		return true;
	}
	else{
		printf("testIsWinner Failed\n");fflush(stdout);
		return false;
	}
}

bool Tests::testGetTarget(){
	Fleet* ship=new Fleet();
	Coordinate target=ship->getTarget();
	printf("row=%d & column=%d\n",target.row,target.column);fflush(stdout);
	Production* prod=new Production();
	if(prod->getYesNo("Were these the numbers you entered?")){
		printf("testgetTarget passes\n");fflush(stdout);
		return true;
	}
	else{
		printf("testgetTarget fails\n");fflush(stdout);
		return false;
	}
}

bool Tests::testCheckShot(){
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
	Fleet* ships=new Fleet();
	Coordinate target=ships->getTarget();
	short status=ships->checkShot(gameBoard, target);
	if(status==1||status==-1||status==0){
		printf("testCheckShot passes\n");fflush(stdout);
		return true;
	}
	else{
		printf("testCheckShot fails\n");fflush(stdout);
		return false;
	}
}
