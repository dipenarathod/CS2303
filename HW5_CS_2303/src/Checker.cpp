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
	}
	else if(this->getPlayerColor()=='r' || this->getPlayerColor()=='R'){
		this->row+=1;
		this->col+=1;
	}
}

void Checker::moveDiagonalRight(){
	if(this->getPlayerColor()=='b' || this->getPlayerColor()=='B'){
		this->row-=1;
		this->col+=1;
	}
	if(this->getPlayerColor()=='r' || this->getPlayerColor()=='R'){
		this->row+=1;
		this->col-=1;
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
	if(((this->row)==8)&&((this->playerColor)=='r')){
		setPlayerColor('R');
		isKing=true;
	}
	if(((this->row)==1)&&((this->playerColor)=='b')){
		setPlayerColor('B');
		isKing=true;
	}
}
bool Checker::checkVaild(char holder){
	bool vaild=true;
	if((((this->row)+1)>8)||(((this->col)+1)>8)||(((this->row)-1)<0)||(((this->col)-1)<0)){
		vaild=false;
		cout<<"off the board make a different move"<<endl;
	}
	if((holder=='r')&&(this->playerColor!='r'))
	{
		vaild=false;
		cout<<"opposition piece is here check if you can jump"<<endl;
		
	}
	if((holder=='r')&&(this->playerColor=='r')){
		cout<<"cannot move to where one of your piece already is"<<endl;
	}
	
	return vaild;
}

