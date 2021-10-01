/*
 * Fleet.h
 *
 *  Created on: Sep 29, 2021
 *      Author: Dipen
 */

#ifndef FLEET_H_
#define FLEET_H_
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>

#include "Board.h"
class Fleet{
public:
	Fleet();
	virtual ~Fleet();
	void checkBoundsOfCardinal(Boolean cardinals[], int bound, int direction);

	Boolean checkSunkShip(short sunkShip[][NUM_OF_SHIPS], short player,
			char shipSymbol, FILE *stream);


	Boolean isWinner(Stats players[], int player);

	Coordinate getTarget(void);

	short checkShot(Cell gameBoard[][COLS], Coordinate target);

};

#endif /* FLEET_H_ */
