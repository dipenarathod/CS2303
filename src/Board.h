/*
 * Board.h
 *
 *  Created on: Sep 29, 2021
 *      Author: Dipen
 */

#ifndef BOARD_H_
#define BOARD_H_
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
/* CONSTANT MACROS */

#define ROWS 10
#define COLS 10

#define LOG_FILE_NAME "battleship.log"

#define NUM_OF_SHIPS  5

#define HORIZONTAL    0
#define VERTICAL      1

#define PLAYER_ONE    0
#define PLAYER_TWO    1

#define WATER         '~'
#define HIT           '*'
#define MISS          'm'

#define CARRIER       'c'
#define BATTLESHIP    'b'
#define CRUISER       'r'
#define SUBMARINE     's'
#define DESTROYER     'd'

#define NORTH 0
#define SOUTH 1
#define WEST  2
#define EAST  3

/* ENUMERATED TYPES */

typedef enum {
	FALSE, TRUE
} Boolean;

typedef enum {
	CARRIER_L = 5,
	BATTLESHIP_L = 4,
	CRUISER_L = 3,
	SUBMARINE_L = 3,
	DESTROYER_L = 2
} ShipType;

/* STRUCT TYPES */

typedef struct watercraft {
	char symbol;
	short length;
	char *name;
} WaterCraft;

typedef struct stats {
	int numHits;
	int numMisses;
	int totalShots;
	double hitMissRatio;
} Stats;

typedef struct coordinate {
	int row;
	int column;
} Coordinate;

typedef struct cell {
	char symbol;
	Coordinate position;
} Cell;
class Board {
public:
	Board();
	virtual ~Board();
	void initializeGameBoard(Cell gameBoard[][COLS]);
	void printGameBoard(Cell gameBoard[][COLS], Boolean showPegs);
	void putShipOnGameBoard(Cell gameBoard[][COLS], WaterCraft ship,
			Coordinate position, int direction);
	void manuallyPlaceShipsOnGameBoard(Cell gameBoard[][COLS], WaterCraft ship[]);
	void randomlyPlaceShipsOnGameBoard(Cell gameBoard[][COLS], WaterCraft ship[]);
	void updateGameBoard(Cell gameBoard[][COLS], Coordinate target);
	Coordinate generatePosition(int direction, int length);
	int getRandomNumber(int lowest, int highest);
	Boolean isValidLocation(Cell gameBoard[][COLS], Coordinate position,
			int direction, int length);
	Boolean convertStringtoPosition(Coordinate position[], char *stringPosition,
			int length);
};

#endif /* BOARD_H_ */
