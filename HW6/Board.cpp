/*
 * Board.cpp
 *
 *  Created on: Sep 29, 2021
 *      Author: Dipen
 */

#include "Board.h"

Board::Board() {
	// TODO Auto-generated constructor stub

}

Board::~Board() {
	// TODO Auto-generated destructor stub
}

/**
 * Function name : initializeGameBoard ()
 * Date Created  : 17 October 2012
 * Usage         : initializeGameBoard ();
 * Definition    : This function displays initializes values of the multi-
 *                 dimensional array called gameBoard.
 * Pre-condition : ROWS & COLS are defined as constant macros
 * Post-condition: Array initialize to (~) tilde representing water
 */
void Board::initializeGameBoard (Cell gameBoard[][COLS]) {

	for (int i = 0; i < ROWS; i++)
		for (int j = 0; j < COLS; j++) {
			gameBoard[i][j].symbol          = WATER;
			gameBoard[i][j].position.row    = i;
			gameBoard[i][j].position.column = j;
		}
}

/**
 * Function name : printGameBoard ()
 * Date Created  : 17 October 2012
 * Usage         : printGameBoard (Cell [][], Boolean);
 * Definition    : This function prints the game board on the console
 *                 screen with an option of showing or not showing the pegs
 * Pre-condition : Game board is of Cell struct type and showPegs
                   if Boolean enum type
 * Post-condition: Game board printed on console screen
 */
void Board::printGameBoard (Cell gameBoard [][COLS], Boolean showPegs) {

	printf ("  0 1 2 3 4 5 6 7 8 9\n");

	for (int i = 0; i < ROWS; i++) {
		printf ("%d ", i);fflush(stdout);

		for (int j = 0; j < COLS; j++) {
			if (showPegs == TRUE) {
				printf ("%c ", gameBoard [i][j].symbol);fflush(stdout);
			}
			else {
				switch (gameBoard [i][j].symbol) {
					case HIT:   printf ("%c ", HIT);fflush(stdout);   break;
					case MISS:  printf ("%c ", MISS);fflush(stdout);  break;
					case WATER:
					default:    printf ("%c ", WATER);fflush(stdout); break;
				}
			}
		}

		putchar ('\n');
	}
}

/**
 * Function name : putShipOnGameBoard ()
 * Date Created  : 17 October 2012
 * Usage         : putShipOnGameBoard (Cell [][], WaterCraft, Coordinate, int)
 * Definition    : This function allows you to put the 5 types of ship in the
 *                 the game board specified in the formal argument
 * Pre-condition : n/a
 * Post-condition: Specific type of ship place on specificied target cell
 */
void Board::putShipOnGameBoard (Cell gameBoard[][COLS], WaterCraft ship,
	                     Coordinate position, int direction) {
	//int i = ship.length - 1;

	for (int i = 0; i < ship.length; i++) {
		if (direction == HORIZONTAL)
			gameBoard [position.row][position.column + i].symbol = ship.symbol;
		else /* VERTICAL */
			gameBoard [position.row + i][position.column].symbol = ship.symbol;
	}
}

/**
 * Function name : manuallyPlaceShipsOnGameBoard ()
 * Date Created  : 17 October 2012
 * Usage         : manuallyPlaceShipsOnGameBoard (Cell [][], WaterCraft []);
 * Definition    : This function allows user to manually place ship on the specified
 *                 gameboard with specific ship
 * Pre-condition : Assuming user inputs correct coordinates as it does not check
 *                 if input is correctly inputted
 * Post-condition: Ships placed on game board
 */
void Board::manuallyPlaceShipsOnGameBoard (Cell gameBoard[][COLS], WaterCraft ship[]) {
	char       stringPosition[11] = "";
	int  i = 0, j = 0;

	Coordinate position[5];
	Boolean isValid = FALSE;

	fflush (stdin);

	for (i = 0; i < NUM_OF_SHIPS; i++) {

		while (TRUE) {
			system ("cls");
			printGameBoard (gameBoard, TRUE);
			printf ("> Please enter the %d cells to place the %s across (no spaces):\n", ship[i].length, ship[i].name);fflush(stdout);
			printf ("> ");fflush(stdout);
			scanf ("%s", stringPosition);

			/* convertStringtoPosition returns false if unsuccessful */
			if (convertStringtoPosition (position, stringPosition, ship[i].length)) {

				isValid = TRUE;

				for (j = 0; j < ship[i].length; j++) {

					if (gameBoard[position[j].row][position[j].column].symbol == WATER) {
						gameBoard[position[j].row][position[j].column].symbol = ship[i].symbol;
					} else {
						isValid = FALSE;
						printf ("> Invalid input!\n");fflush(stdout);

						if (j != 0)
							while (j >= 0) {
								gameBoard[position[j].row][position[j].column].symbol = WATER;
								j--;
							}

						break;
					}
				}
			} else {
				isValid = FALSE;
				printf ("> Invalid input!\n");fflush(stdout);
			}

			if (isValid == TRUE) break;
		}

	}
}

/**
 * Function name : convertStringtoPosition ()
 * Date Created  : 17 October 2012
 * Usage         : convertStringtoPosition (Cell [], char *, int);
 * Definition    : This function converts string coordinates into individual
 *                 integer coordinates
 * Pre-condition : Assuming that user inputs correct coordinates since program
 *                 does not check for inccorrect coordinates
 * Post-condition: n/a
 */
Boolean Board::convertStringtoPosition (Coordinate position[], char *stringPosition, int length) {
	Boolean flag = TRUE;
	char temp = '\0';
	//int i = 0;

	/* checks if length of input is good */
	if (strlen (stringPosition)/2 == length) {
		int j = 0, k = 1;
		/* loops through the length of the ship */
		for (int i = 0; i < length && flag; i++) {
			/* checks if each cell is a digit */
			if (isdigit (stringPosition[j]) && isdigit (stringPosition[k])) {
				position[i].row    = stringPosition[j] - '0';
				position[i].column = stringPosition[k] - '0';

				j += 2;
				k += 2;
			} else {
				flag = FALSE;
			}
		}
	} else {
		flag = FALSE;
	}

	return flag;
}

/**
 * Function name : randomlyPlaceShipsOnGameBoard ()
 * Date Created  : 17 October 2012
 * Usage         : randomlyPlaceShipsOnGameBoard (Cell [][], WaterCraft []);
 * Definition    : This function lets the computer randomly place ship on the
 *                 game board
 * Pre-condition : n/a
 * Post-condition: Ships placed on game board
 */
void Board::randomlyPlaceShipsOnGameBoard (Cell gameBoard[][COLS], WaterCraft ship[]) {
	Coordinate position;
	int direction = -1;

	for (int i = 0; i < NUM_OF_SHIPS; i++) {
		while (TRUE) {
			direction = getRandomNumber (0, 1); /* 0 -> horizontal, 1 -> vertical */
			position = generatePosition (direction, ship[i].length);

			if (isValidLocation (gameBoard, position, direction, ship[i].length)) break;
		}

		putShipOnGameBoard (gameBoard, ship[i], position, direction);
	}
}

/**
 * Function name : isValidLocation ()
 * Date Created  : 17 October 2012
 * Usage         : isValidLocation (Cell [][], Coordinate, int, int);
 * Definition    : This function checks if specified position, direction and
 *                 length is valid on location specified on the game board
 * Pre-condition : n/a
 * Post-condition: n/a
 */
Boolean Board::isValidLocation (Cell gameBoard[][COLS], Coordinate position,
				         int direction, int length) {
	//int i = length - 1;
	Boolean isValid = TRUE;

	for (int i = 0; isValid && i < length; i++) {
		if (direction == HORIZONTAL) {
			if (gameBoard [position.row][position.column + i].symbol != WATER &&
				(position.column + i) < COLS)
				isValid = FALSE;
		} else { /* VERTICAL */
			if (gameBoard [position.row + i][position.column].symbol != WATER &&
				(position.row + i) < ROWS)
				isValid = FALSE;
		}
	}

	return isValid;
}

/**
 * Function name : generatePosition ()
 * Date Created  : 17 October 2012
 * Usage         : generatePosition (int, int);
 * Definition    : This function generates position based on the
 *                 direction and length specified and it can't be
 *                 more than the game board size
 * Pre-condition : n/a
 * Post-condition: n/a
 */
Coordinate Board::generatePosition (int direction, int length) {
	Coordinate position;

	if (direction == HORIZONTAL) {
		position.row    = getRandomNumber (0, ROWS);
		position.column = getRandomNumber (0, COLS - length);
	} else { /* VERTICAL */
		position.row    = getRandomNumber (0, ROWS - length);
		position.column = getRandomNumber (0, COLS);
	}

	return position;
}

/**
 * Function name : getRandomNumber ()
 * Date Created  : 17 October 2012
 * Usage         : getRandomNumber (int, int);
 * Definition    : This function returns a random number between and
 *                 including the lowest to the highest number
 * Pre-condition : n/a
 * Post-condition: n/a
 */
int Board::getRandomNumber (int lowest, int highest) {
	if (lowest == 0)
		return rand () % ++highest;

	if (lowest > 0)
		return rand () % ++highest + lowest;
}

/**
 * Function name : updateGameBoard ()
 * Date Created  : 17 October 2012
 * Usage         : updateGameBoard (Cell [][], Coordinate);
 * Definition    : This function updates the game board whether
 *                 its a hit or miss
 * Pre-condition : n/a
 * Post-condition: Game board updated with proper symbol
 */
void Board::updateGameBoard (Cell gameBoard[][COLS], Coordinate target) {
	switch (gameBoard[target.row][target.column].symbol) {
		/* miss */
		case WATER:
			gameBoard[target.row][target.column].symbol = MISS;
			break;

		/* hit */
		case CARRIER:
		case BATTLESHIP:
		case CRUISER:
		case SUBMARINE:
		case DESTROYER:
			gameBoard[target.row][target.column].symbol = HIT;
			break;

		case HIT:
		case MISS:
		default:
			break;
	}
}
