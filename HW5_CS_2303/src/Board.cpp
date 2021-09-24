/*
 * Board.cpp
 *
 *  Created on: Aug 2, 2021
 *      Author: theresesmith
 */

#include "Board.h"

Board::Board() {
	// TODO Auto-generated constructor stub

}

Board::~Board() {
	// TODO Auto-generated destructor stub
}

void Board::displayBoard()
{
	//TODO
	for(int i = 0; i<8; i++)
		{
			for(int j = 0; j<8; j++)
			{
				printf("%c",(*this).getEdge(i, j));

			}
			printf("\n");
		}
}
void Board::printToFile(char* filename)
{
    //TODO
	ofstream fp;
	fp.open(filename);
	int ncols=n;
	for(int row = 0; row<ncols; row++)
		{
			for(int col = 0; col<ncols; col++)
			{
				fp<<*((edgesP)+(row*ncols)+col)<<" ";
			}
			fp<<"\n";
		}
	fp.close();
}
void Board::init()
{
	int ncols = n;
	printf("In init with ncols = %d\n", ncols);
	//TODO need to malloc for the edges
	for(int row = 0; row<ncols; row++)
	{
		for(int col = 0; col<ncols; col++)
		{
			*((edgesP)+(row*ncols)+col)= '-';
		}
	}
}

void Board::setEdge(int row, int col,char player)
{

	int ncols = n;
	char* arrayBeginning = edgesP;
	*(arrayBeginning + (ncols*row) +col) = player;
}

char Board::getEdge(int row, int col)
{
	//TODO
	int ncols=n;
	char* arrayBeginning =edgesP;
	return *(arrayBeginning + (ncols*row) +col) ;
}

void Board::setEdgesP(char* set)
{
	edgesP = set;
}

char* Board::getEdgesP(){
	return (*this).edgesP;
}

bool Board::getTurn(){
	return this->turn;
}

void Board::switchTurn(){
	this->turn=!this->turn;
}

void Board::setTurn(bool turn){
	this->turn=turn;
}
