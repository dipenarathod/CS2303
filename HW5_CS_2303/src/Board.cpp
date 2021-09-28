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
void Board::moveb()
{
	int right = 0, left = 0, up = 0;
	//check if can jump
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++) {
			if (this->getEdge(i,j) == 'b') {
				up = i - 1; right = j + 1; left = j - 1;
				if (up >= 0)
				{
					if (right >= 1 && right <= 8) {
						if (this->getEdge(up,right)== 'r')
						{
							up -= 1;
							right += 1;
							if (up >= 0 && right >= 1 && right <= 8)
							{
								if(this->getEdge(up,right)=='-')
								{
									this->setEdge(up, right, 'b');
									this->setEdge((up+1), (right-1), '-');
									this->setEdge(i,j,'-');
								}
							}
						}
					} // End if right
					if (left >= 0 && left <= 7)
					{
						if (this->getEdge(up,left) == 'r')
						{
							up -= 1;
							left -= 1;
							if (up >= 0 && left >= 0 && left <= 7)
							{
								puts("Can jump on left");
								if(this->getEdge(up,left)=='-'){
									this->setEdge(up, left, 'b');
									this->setEdge((up+1),(left+1),'-');
									this->setEdge(i,j,'-');
								}
							}
						}
					} // End if left
				}// End if up
			} // End if b
		} // End for col
	} // End for row
}
void Board::mover()
{
	int right = 0, left = 0, up = 0;
	//check if can jump
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++) {
			if (this->getEdge(i,j) == 'r') {
				up = i + 1; right = j + 1; left = j - 1;
				if (up <= 8)
				{
					if (right >= 1 && right <= 8) {
						if (this->getEdge(up,right)== 'r')
						{
							up += 1;
							right += 1;
							if (up <= 0 && right >= 1 && right <= 8)
							{
								if(this->getEdge(up,right)=='-')
								{
									this->setEdge(up, right, 'r');
									this->setEdge((up-1), (right-1), '-');
									this->setEdge(i,j,'-');
								}
							}
						}
					} // End if right
					if (left >= 0 && left <= 7)
					{
						if (this->getEdge(up,left) == 'b')
						{
							up += 1;
							left -= 1;
							if (up <= 0 && left >= 0 && left <= 7)
							{
								puts("Can jump on left");
								if(this->getEdge(up,left)=='-'){
									this->setEdge(up, left, 'r');
									this->setEdge((up-1),(left+1),'-');
									this->setEdge(i,j,'-');
								}
							}
						}
					} // End if left
				}// End if up
			} // End if r
		} // End for col
	} // End for row
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

bool Board::isValid(int rowIn, int colIn,char move){
	bool ok = false;
	int row = 0, col = 0;
	if(this->getEdge(rowIn, colIn) == 'b'){
		if(move == 'i'){
				row = rowIn -1;
				col = colIn - 1;
				if((row >= 0 && row <= 8) && (col >= 0 && col <= 8))
					if(this->getEdge(row, col) == '-')
						ok = true;
			}
			if(move == 'o'){
				row =rowIn - 1;
				col = colIn + 1;
				if((row >= 0 && row <= 8) && (col >= 0 && col <=8))
					if(this->getEdge(row, col) == '-')
						ok = true;
			}
			if(move == 'k'){
				row = rowIn + 1;
				col = colIn -1;
				if((row >= 0 && row <= 8) && (col >= 0 && col <= 8))
					if(this->getEdge(row, col) == '-')
						ok = true;
			}
			if(move == 'k'){
				row = rowIn + 1;
				col = colIn + 1;
				if((row >= 0 && row <= 8) && (col >= 0 && col <= 8))
					if(this->getEdge(row, col) == '-')
						ok = true;
			}
	}
	else{
		if(move == 'i'){
				row = rowIn + 1;
				col = colIn - 1;
				if((row >= 0 && row <= 8) && (col >= 0 && col <= 8))
					if(this->getEdge(row, col) == '-')
						ok = true;
			}
			if(move == 'o'){
				row =rowIn + 1;
				col = colIn + 1;
				if((row >= 0 && row <= 8) && (col >= 0 && col <=8))
					if(this->getEdge(row, col) == '-')
						ok = true;
			}
			if(move == 'k'){
				row = rowIn - 1;
				col = colIn -1;
				if((row >= 0 && row <= 8) && (col >= 0 && col <= 8))
					if(this->getEdge(row, col) == '-')
						ok = true;
			}
			if(move == 'k'){
				row = rowIn - 1;
				col = colIn + 1;
				if((row >= 0 && row <= 8) && (col >= 0 && col <= 8))
					if(this->getEdge(row, col) == '-')
						ok = true;
			}
	}


	return ok;

}

bool Board::canMove(int row, int col)
{
	bool moving = true;

	if((0 <= row && row <= 8) && (0 <= col && col <= 8))
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
		
		if(!(isValid(i.row,i.col,i.move) || isValid(o.row,o.col,o.move) || isValid(k.row,k.col,k.move) || isValid(j.row,j.col,j.move)))
		{
			moving = false;
		}
	}

	return moving;
}
