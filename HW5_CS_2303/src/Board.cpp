/*
 * Board.cpp
 *
 *  Created on: Aug 2, 2021
 *      Author: theresesmith
 */

#include "Board.h"
#include <ostream>

Board::Board() {
	// TODO Auto-generated constructor stub

}

Board::~Board() {
	// TODO Auto-generated destructor stub
}

void Board::displayBoard()
{
	//TODO
	ofstream boards;
	boards.open("boards.txt", ios_base::app);

	//ofstream gameState;
	//gameState.open("gameState.txt");

	printf("  0 1 2 3 4 5 6 7 \n");
	boards<<"  0 1 2 3 4 5 6 7 \n";
	for(int i = 0; i<8; i++)
	{
		printf("%d", i);
		boards<<i;
		for(int j = 0; j<8; j++)
		{
			printf(" %c",(*this).getEdge(i, j));
			boards<<" "<<(*this).getEdge(i, j);
			//gameState<<(*this).getEdge(i,j);
		}
		printf("\n");
		boards<< "\n";
		//gameState<<"\n";
	}
	boards.close();
	//gameState.close();
}

void Board::printToFile(char* filename, Checker** red, Checker** black)
{
	//TODO
	ofstream fp;
	fp.open(filename);
	int ncols = n;
	for(int row = 0; row<ncols; row++)
	{
		for(int col = 0; col<ncols; col++)
		{
			*((edgesP)+(row*ncols)+col)= '-';
		}
	}
	for(int i=0;i<12;i++){
		if(red[i]->getCol()>=0 && red[i]->getRow()>=0){
			this->setEdge(red[i]->getRow(),red[i]->getCol(),red[i]->getPlayerColor());
		}
		if(black[i]->getCol()>=0 && black[i]->getRow()>=0){
			this->setEdge(black[i]->getRow(),black[i]->getCol(),black[i]->getPlayerColor());
		}
	}
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

bool Board::canJump(pieceMove inPiece){
	int row = 0, col = 0;
	bool ok = false;

	if(inPiece.move == 'i'){
		row = inPiece.row - 2;
		col = inPiece.col - 2;
		if((row >=0 && row <= 7) && (col >= 0 && col <= 7) && (this->getEdge(row, col) == '-')){
			ok = true;
			inPiece.piece->moveDiagonalLeft();
			inPiece.piece->moveDiagonalLeft();

		}
	}
	if(inPiece.move == 'o'){
		row = inPiece.row-2;
		col = inPiece.col +2;
		if((row >=0 && row <= 7) && (col >= 0 && col <= 7) && (this->getEdge(row, col) == '-')){
			ok = true;
			this->setEdge((inPiece.row-1), (inPiece.col+1), '-');
			inPiece.piece->moveDiagonalRight();
			inPiece.piece->moveDiagonalRight();

		}
	}
	if (inPiece.move=='j'){
		row= inPiece.row+2;
		col= inPiece.col+2;
		if((row >=0 && row <= 7) && (col >= 0 && col <= 7) && (this->getEdge(row, col) == '-')){
			ok = true;
		}
	}
	if (inPiece.move=='k'){
		row= inPiece.row+2;
		col= inPiece.col-2;
		if((row >=0 && row <= 7) && (col >= 0 && col <= 7) && (this->getEdge(row, col) == '-')){
			ok = true;
		}
	}
	return ok;
}

bool Board::isWin(){
	int redPieces=0;
	int blackPieces=0;
	for(int i = 0; i<8; i++)
	{
		for(int j = 0; j<8; j++)
		{
			if('r'==(*this).getEdge(i, j) || 'R'==(*this).getEdge(i, j)){
				redPieces++;
			}
			else if('b'==(*this).getEdge(i, j) || 'B'==(*this).getEdge(i, j)){
				blackPieces++;
			}
		}
	}
	if(redPieces==0){
		printf("Black won\n");
		return true;
	}
	else if(blackPieces==0){
		printf("Red won\n");
		return true;
	}
	else{
		return false;
	}
}

bool Board::isValid(pieceMove move) {
	bool ok = false;
	int row = 0, col = 0;
	if ((move.piece)->getPlayerColor() == 'b' || (move.piece)->getPlayerColor() == 'B' ) {
		if (move.move == 'i') {
			row = move.row - 1;
			col = move.col - 1;
			if ((row >= 0 && row <= 7) && (col >= 0 && col <=7))
				if (this->getEdge(row, col) == '-')
					ok = true;
		}
		if (move.move == 'o') {
			row = move.row - 1;
			col = move.col + 1;
			if ((row >= 0 && row <= 7) && (col >= 0 && col <= 7))
				if (this->getEdge(row, col) == '-')
					ok = true;
		}
		if (move.move == 'j') {
			row = move.row + 1;
			col = move.col - 1;
			if ((row >= 0 && row <= 7) && (col >= 0 && col <= 7))
				if (this->getEdge(row, col) == '-')
					ok = true;
		}
		if (move.move == 'k') {
			row = move.row + 1;
			col = move.col + 1;
			if ((row >= 0 && row <= 7) && (col >= 0 && col <= 7))
				if (this->getEdge(row, col) == '-')
					ok = true;
		}
	}
	else if((move.piece)->getPlayerColor() == 'r' || (move.piece)->getPlayerColor() == 'R' ) {
		if (move.move == 'i') {
			row = move.row + 1;
			col = move.col - 1;
			if ((row >= 0 && row <= 7) && (col >= 0 && col <= 7))
				if (this->getEdge(row, col) == '-')
					ok = true;
		}
		if (move.move == 'o') {
			row = move.row + 1;
			col = move.col + 1;
			if ((row >= 0 && row <= 7) && (col >= 0 && col <= 7))
				if (this->getEdge(row, col) == '-')
					ok = true;
		}
		if (move.move == 'j') {
			row = move.row - 1;
			col = move.col - 1;
			if ((row >= 0 && row <= 7) && (col >= 0 && col <= 7))
				if (this->getEdge(row, col) == '-')
					ok = true;
		}
		if (move.move == 'k') {
			row = move.row - 1;
			col = move.col + 1;
			if ((row >= 0 && row <= 7) && (col >= 0 && col <= 7))
				if (this->getEdge(row, col) == '-')
					ok = true;
		}
	}


	return ok;

}

bool Board::canMove(int row, int col)
{
	bool moving = true;

	if((0 <= row && row <= 7) && (0 <= col && col <= 7))
	{
		pieceMove i;
		i.row = row;
		i.col = col;
		i.move = 'i';

		pieceMove o;
		o.row = row;
		o.col = col;
		o.move = 'o';

		pieceMove k;
		k.row = row;
		k.col = col;
		k.move = 'k';

		pieceMove j;
		j.row = row;
		j.col = col;
		j.move = 'j';

		if(!(isValid(i) || isValid(o) || isValid(k) || isValid(j)))
		{
			moving = false;
		}
	}

	return moving;
}

Checker* Board::findChecker(int row,int col,Checker** red,Checker** black){
	for(int i=0;i<12;i++){
		if(row==red[i]->getRow() && col==red[i]->getCol()){
			return red[i];
		}
		if(row==black[i]->getRow() && col==black[i]->getCol()){
			return black[i];
		}
	}
	return NULL;
}

int Board::computer(Checker** red)
{

	for (int i = 0; i < 12; i++)
	{
		pieceMove iMove;
		iMove.row = red[i]->getRow();
		iMove.col = red[i]->getCol();
		iMove.piece = red[i];
		iMove.move = 'i';

		pieceMove oMove;
		oMove.row = red[i]->getRow();
		oMove.col = red[i]->getCol();
		oMove.piece = red[i];
		oMove.move = 'o';

		if (red[i]->isKing)
		{
			pieceMove kMove;
			kMove.row = red[i]->getRow();
			kMove.col = red[i]->getCol();
			kMove.piece = red[i];
			kMove.move = 'k';

			pieceMove jMove;
			jMove.row = red[i]->getRow();
			jMove.col = red[i]->getCol();
			jMove.piece = red[i];
			jMove.move = 'j';

			if (this->canJump(iMove))
			{
				return 0;
			}
			if (this->canJump(oMove))
			{
				return 0;
			}
			if (this->canJump(kMove))
			{
				return 0;
			}
			if (this->canJump(jMove))
			{
				return 0;
			}
			if (this->isValid(iMove))
			{
				std::cout << "The computer moved (" << red[i]->getRow() << ", " << red[i]->getCol() <<  ") to ";
				red[i]->moveDiagonalLeft();
				std::cout << "(" << red[i]->getRow() << ", " << red[i]->getCol() <<  ")\n";
				return 0;
			}
			if (this->isValid(oMove))
			{
				std::cout << "The computer moved (" << red[i]->getRow() << ", " << red[i]->getCol() <<  ") to ";
				red[i]->moveDiagonalRight();
				std::cout << "(" << red[i]->getRow() << ", " << red[i]->getCol() <<  ")\n";
				return 0;
			}
			if (this->isValid(kMove))
			{
				std::cout << "The computer moved (" << red[i]->getRow() << ", " << red[i]->getCol() <<  ") to ";
				red[i]->moveBackDiagonalRight();
				std::cout << "(" << red[i]->getRow() << ", " << red[i]->getCol() <<  ")\n";
				return 0;
			}
			if (this->isValid(jMove))
			{
				std::cout << "The computer moved (" << red[i]->getRow() << ", " << red[i]->getCol() <<  ") to ";
				red[i]->moveBackDiagonalLeft();
				std::cout << "(" << red[i]->getRow() << ", " << red[i]->getCol() <<  ")\n";
				return 0;
			}
		}
		else
		{
			if (this->canJump(iMove))
			{
				return 0;
			}
			if (this->canJump(oMove))
			{
				return 0;
			}
			if (this->isValid(iMove))
			{
				std::cout << "The computer moved (" << red[i]->getRow() << ", " << red[i]->getCol() <<  ") to ";
				red[i]->moveDiagonalRight();
				std::cout << "(" << red[i]->getRow() << ", " << red[i]->getCol() <<  ")\n";
				return i;
			}
			if (this->isValid(oMove))
			{
				std::cout << "The computer moved (" << red[i]->getRow() << ", " << red[i]->getCol() <<  ") to ";
				red[i]->moveDiagonalLeft();
				std::cout << "(" << red[i]->getRow() << ", " << red[i]->getCol() <<  ")\n";
				return i;
			}
		}
	}
	return 0;
}

