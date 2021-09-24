/*
 * Checker.h
 *
 *  Created on: Sep 23, 2021
 *      Author: Dipen
 */

#ifndef CHECKER_H_
#define CHECKER_H_

class Checker {
public:
	Checker();
	virtual ~Checker();
	void moveDiagonalRight();
	void moveDiagonalLeft();
	void moveBackDiagonalRight();
	void moveBackDiagonalLeft();
	void setRow(int);
	void setColumn(int);
	void setPlayerColor(char);
	int getRow();
	int getCol();
	char getPlayerColor();
	bool isKing;
private:
	int row;
	int col;
	char playerColor;

};
class King:public Checker{
public:
	King();
	~King();
};

#endif /* CHECKER_H_ */
