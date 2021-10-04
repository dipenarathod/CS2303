/*
 * battleship.cpp
 *
 *  Created on: Sep 29, 2021
 *      Author: Dipen
 */

#include "Fleet.h"

Fleet::Fleet() {
	// TODO Auto-generated constructor stub

}

Fleet::~Fleet() {
	// TODO Auto-generated destructor stub
}





/**
 * Function name : checkBoundsOfCardinal ()
 * Date Created  : 17 October 2012
 * Usage         : checkBoundsOfCardinal (Boolean [], int, int);
 * Definition    : This function checks if the specified direction is
 *                 not over the bounds and sets the cardinals with TRUE
 *                 if its within bounds, otherwise FALSE
 * Pre-condition : n/a
 * Post-condition: Updates the cardinals array
 */
void Fleet::checkBoundsOfCardinal (Boolean cardinals[], int bound, int direction) {
	switch (direction) {
		case NORTH:
			if (bound < 0)
				cardinals[0] = FALSE;
			else
				cardinals[0] = TRUE;
			break;

		case SOUTH:
			if (bound > 9)
				cardinals[1] = FALSE;
			else
				cardinals[1] = TRUE;
			break;

		case WEST:
			if (bound < 0)
				cardinals[2] = FALSE;
			else
				cardinals[2] = TRUE;
			break;

		case EAST:
			if (bound > 9)
				cardinals[3] = FALSE;
			else
				cardinals[3] = TRUE;
			break;
		default:
			printf("Default case");fflush(stdout);
			break;
	}
}



/**
 * Function name : checkSunkShip ()
 * Date Created  : 17 October 2012
 * Usage         : checkSunkShip (shor [][], short, char, FILE *);
 * Definition    : This function check if a ship has sunk based on the
 *                 how of the length of ship is left. If a ship was sunk
 *                 it is logged on an output file
 * Pre-condition : stream to output file was created
 * Post-condition: n/a
 */
Boolean Fleet::checkSunkShip (short sunkShip[][NUM_OF_SHIPS], short player, char shipSymbol, FILE *stream) {
	Boolean sunked = FALSE;

	switch (shipSymbol) {
		case CARRIER:
			if (--sunkShip[player][0] == 0) {
				printf ("> Player %d's Carrier sunked!\n", player + 1);fflush(stdout);

				/* Write to battleship.log */
				fprintf (stream, "Player %d's Carrier sunked!\n", player + 1);

				sunked = TRUE;
			}
			break;

		case BATTLESHIP:
			if (--sunkShip[player][1] == 0) {
				printf ("> Player %d's Battleship sunked!\n", player + 1);fflush(stdout);

				/* Write to battleship.log */
				fprintf (stream, "Player %d's Battleship sunked!\n", player + 1);

				sunked = TRUE;
			}
			break;

		case CRUISER:
			if (--sunkShip[player][2] == 0) {
				printf ("> Player %d's Cruiser sunked!\n", player + 1);fflush(stdout);

				/* Write to battleship.log */
				fprintf (stream, "Player %d's Cruiser sunked!\n", player + 1);

				sunked = TRUE;
			}
			break;

		case SUBMARINE:
			if (--sunkShip[player][3] == 0) {
				printf ("> Player %d's Submarine sunked!\n", player + 1);fflush(stdout);

				/* Write to battleship.log */
				fprintf (stream, "Player %d's Submarine sunked!\n", player + 1);

				sunked = TRUE;
			}
			break;

		case DESTROYER:
			if (--sunkShip[player][4] == 0) {
				printf ("> Player %d's Destroyer sunked!\n", player + 1);fflush(stdout);

				/* Write to battleship.log */
				fprintf (stream, "Player %d's Destroyer sunked!\n", player + 1);

				sunked = TRUE;
			}
			break;
		default:
			printf("Default case");fflush(stdout);
			break;
	}

	return sunked;
}






/**
 * Function name : isWinner ()
 * Date Created  : 17 October 2012
 * Usage         : isWinner (Stats [], int);
 * Definition    : This function determines if there is a winner based
 *                 on the 17 total pegs for each player
 * Pre-condition : n/a
 * Post-condition: n/a
 */
Boolean Fleet::isWinner (Stats players[], int player) {
	Boolean isWin = FALSE;

	if (players[player].numHits >= 17)
		isWin = TRUE;

	return isWin;
}



/**
 * Function name : getTarget ()
 * Date Created  : 17 October 2012
 * Usage         : getTarget ();
 * Definition    : This function reads a row and column values from
 *                 the user
 * Pre-condition : n/a
 * Post-condition: n/a
 */
Coordinate Fleet::getTarget (void) {
	Coordinate target;

	fflush (stdin);

	printf ("> Enter Target (ex. > 3 4):\n");fflush(stdout);
	printf ("> ");
	scanf ("%d %d", &target.row, &target.column);fflush(stdout);

	return target;
}

/**
 * Function name : checkShot ()
 * Date Created  : 17 October 2012
 * Usage         : checkShot (Cell [][], Coordinate);
 * Definition    : This function checks if the coordinates on the
 *                 game board is a miss, hit, water or water craft
 * Pre-condition : n/a
 * Post-condition: n/a
 */
short Fleet::checkShot (Cell gameBoard[][COLS], Coordinate target) {
	int hit = -2;

	switch (gameBoard[target.row][target.column].symbol) {
		/* miss */
		case WATER:
			hit = 0;
			break;

		/* hit */
		case CARRIER:
		case BATTLESHIP:
		case CRUISER:
		case SUBMARINE:
		case DESTROYER:
			hit = 1;
			break;

		case HIT:
		case MISS:
		default:
			hit = -1;
			break;
	}

	return hit;
}


