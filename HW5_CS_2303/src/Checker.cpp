/*
 * Checker.cpp
 *
 *  Created on: Sep 23, 2021
 *      Author: Dipen
 */

#include "Checker.h"

Checker::Checker() {
	// TODO Auto-generated constructor stub

}

Checker::~Checker() {
	// TODO Auto-generated destructor stub
}

void Checker::moveDiagonalLeft(){
	if(this->getPlayerColor()=='b' || this->getPlayerColor()=='B'){
		this->row-=1;
		this->col-=1;
		this->checkIfKing();
	}
	else if(this->getPlayerColor()=='r' || this->getPlayerColor()=='R'){
		this->row+=1;
		this->col+=1;
		this->checkIfKing();
	}
}

void Checker::moveDiagonalRight(){
	if(this->getPlayerColor()=='b' || this->getPlayerColor()=='B'){
		this->row-=1;
		this->col+=1;
		this->checkIfKing();
	}
	if(this->getPlayerColor()=='r' || this->getPlayerColor()=='R'){
		this->row+=1;
		this->col-=1;
		this->checkIfKing();
	}
}

void Checker::checkIfKing(){
	if(this->getPlayerColor() == 'b'){
		if(this->row == 0){
			this->makeKing();
		}
	}
	if(this->getPlayerColor() == 'r'){
		if(this->row == 7){
			this->makeKing();
		}
	}
}

void Checker::moveBackDiagonalLeft(){
	if(this->getPlayerColor()=='B'){
		this->row+=1;
		this->col-=1;
	}
	else if(this->getPlayerColor()=='R'){
		this->row-=1;
		this->col+=1;
	}
}

void Checker::moveBackDiagonalRight(){

	if(this->getPlayerColor()=='B'){
		this->row+=1;
		this->col+=1;
	}
	else if(this->getPlayerColor()=='R'){
		this->row-=1;
		this->col-=1;
	}
}

void Checker::setRow(int row){
	this->row=row;
}

void Checker::setColumn(int col){
	this->col=col;
}

void Checker::setPlayerColor(char color){
	this->playerColor=color;
}

int Checker::getRow(){
	return this->row;
}

int Checker::getCol(){
	return this->col;
}

char Checker::getPlayerColor(){
	return this->playerColor;
}


void Checker::makeKing(){
	if(((this->row)==7)&&((this->playerColor)=='r')){
		setPlayerColor('R');
		isKing=true;
	}
	if(((this->row)==0)&&((this->playerColor)=='b')){
		setPlayerColor('B');
		isKing=true;
	}
}

