/*
 * Production.h
 *
 *  Created on: Sep 29, 2021
 *      Author: Dipen
 */

#ifndef PRODUCTION_H_
#define PRODUCTION_H_
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>

#include "Board.h"
#include "Fleet.h"
class Production {
public:
	Production();
	virtual ~Production();
	void production();
	void welcomeScreen(void);
	void systemMessage(char *message);
	bool getYesNo(char*);
};

#endif /* PRODUCTION_H_ */
