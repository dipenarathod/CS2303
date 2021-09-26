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
	printf("  0 1 2 3 4 5 6 7 \n");
	for(int i = 0; i<8; i++)
		{
			printf("%d", i);
			for(int j = 0; j<8; j++)
			{
				printf(" %c",(*this).getEdge(i, j));

			}
			printf("\n");
		}
}
void Board::printToFile(char* filename)
{
    //TODO
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


