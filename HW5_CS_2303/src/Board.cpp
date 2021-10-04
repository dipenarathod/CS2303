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
	boards << "  0 1 2 3 4 5 6 7 \n";
	for (int i = 0; i < 8; i++)
	{
		printf("%d", i);
		boards << i;
		for (int j = 0; j < 8; j++)
		{
			printf(" %c", (*this).getEdge(i, j));
			boards << " " << (*this).getEdge(i, j);
			//gameState<<(*this).getEdge(i,j);
		}
		printf("\n");
		boards << "\n";
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
	for (int row = 0; row < ncols; row++)
	{
		for (int col = 0; col < ncols; col++)
		{
			*((edgesP)+(row * ncols) + col) = '-';
		}
	}
	for (int i = 0; i < 12; i++) {
		if (red[i]->getCol() >= 0 && red[i]->getRow() >= 0) {
			this->setEdge(red[i]->getRow(), red[i]->getCol(), red[i]->getPlayerColor());
		}
		if (black[i]->getCol() >= 0 && black[i]->getRow() >= 0) {
			this->setEdge(black[i]->getRow(), black[i]->getCol(), black[i]->getPlayerColor());
		}
	}
	for (int row = 0; row < ncols; row++)
	{
		for (int col = 0; col < ncols; col++)
		{
			fp << *((edgesP)+(row * ncols) + col) << " ";
		}
		fp << "\n";
	}
	fp.close();
}

void Board::init()
{
	int ncols = n;
	printf("In init with ncols = %d\n", ncols);
	//TODO need to malloc for the edges
	for (int row = 0; row < ncols; row++)
	{
		for (int col = 0; col < ncols; col++)
		{
			*((edgesP)+(row * ncols) + col) = '-';
		}
	}
}

void Board::setEdge(int row, int col, char player)
{

	int ncols = n;
	char* arrayBeginning = edgesP;
	*(arrayBeginning + (ncols * row) + col) = player;
}

char Board::getEdge(int row, int col)
{
	//TODO
	int ncols = n;
	char* arrayBeginning = edgesP;
	return *(arrayBeginning + (ncols * row) + col);
}

void Board::setEdgesP(char* set)
{
	edgesP = set;
}

char* Board::getEdgesP() {
	return (*this).edgesP;
}

bool Board::canJump(pieceMove inPiece) {
	int row = 0, col = 0;
	bool ok = false;

	if (inPiece.piece->getPlayerColor() == 'b' || inPiece.piece->getPlayerColor() == 'B') {
		if (inPiece.move == 'i') {
			if (this->getEdge((inPiece.row - 1), (inPiece.col - 1)) == 'r' || this->getEdge((inPiece.row - 1), (inPiece.col - 1)) == 'R') {
				row = inPiece.row - 2;
				col = inPiece.col - 2;
				if ((row >= 0 && row <= 7) && (col >= 0 && col <= 7) && (this->getEdge(row, col) == '-') && (this->findChecker(row,col) == NULL)) {
					ok = true;
					Checker* deadPiece = this->findChecker((inPiece.row - 1), (inPiece.col - 1));
					deadPiece->setColumn(-1);
					deadPiece->setRow(-1);
					inPiece.piece->moveDiagonalLeft();
					inPiece.piece->moveDiagonalLeft();

				}
			}
		}
		if (inPiece.move == 'o') {
			if (this->getEdge((inPiece.row - 1), (inPiece.col + 1)) == 'r' || this->getEdge((inPiece.row - 1), (inPiece.col + 1)) == 'R') {
				row = inPiece.row - 2;
				col = inPiece.col + 2;
				if ((row >= 0 && row <= 7) && (col >= 0 && col <= 7) && (this->getEdge(row, col) == '-') && (this->findChecker(row,col) == NULL)) {
					ok = true;
					Checker* deadPiece = this->findChecker((inPiece.row - 1), (inPiece.col + 1));
					deadPiece->setColumn(-1);
					deadPiece->setRow(-1);
					inPiece.piece->moveDiagonalRight();
					inPiece.piece->moveDiagonalRight();

				}
			}
		}
		if (inPiece.move == 'j') {
			if (this->getEdge((inPiece.row + 1), (inPiece.col + 1)) == 'r' || this->getEdge((inPiece.row + 1), (inPiece.col + 1)) == 'R') {
				row = inPiece.row + 2;
				col = inPiece.col + 2;
				if ((row >= 0 && row <= 7) && (col >= 0 && col <= 7) && (this->getEdge(row, col) == '-') && (this->findChecker(row,col) == NULL)) {
					ok = true;
					Checker* deadPiece = this->findChecker((inPiece.row + 1), (inPiece.col + 1));
					deadPiece->setColumn(-1);
					deadPiece->setRow(-1);
				}
			}
		}
		if (inPiece.move == 'k') {
			if (this->getEdge((inPiece.row + 1), (inPiece.col - 1)) == 'r' || this->getEdge((inPiece.row + 1), (inPiece.col - 1)) == 'R') {
				row = inPiece.row + 2;
				col = inPiece.col - 2;
				if ((row >= 0 && row <= 7) && (col >= 0 && col <= 7) && (this->getEdge(row, col) == '-') && (this->findChecker(row,col) == NULL)) {
					ok = true;
					Checker* deadPiece = this->findChecker((inPiece.row + 1), (inPiece.col - 1));
					deadPiece->setColumn(-1);
					deadPiece->setRow(-1);
				}
			}
		}
	}
	if (inPiece.piece->getPlayerColor() == 'r' || inPiece.piece->getPlayerColor() == 'R') {
		if (inPiece.move == 'i') {
			if (this->getEdge((inPiece.row + 1), (inPiece.col + 1)) == 'b' || this->getEdge((inPiece.row + 1), (inPiece.col + 1)) == 'B') {
				row = inPiece.row + 2;
				col = inPiece.col + 2;
				if ((row >= 0 && row <= 7) && (col >= 0 && col <= 7) && (this->getEdge(row, col) == '-') && (this->findChecker(row,col) == NULL)) {
					Checker* jumpPiece = this->findChecker((inPiece.row + 1), (inPiece.col + 1));
					jumpPiece->setColumn(-1);
					jumpPiece->setRow(-1);
					//free(jumpPiece);
					inPiece.piece->moveDiagonalLeft();
					inPiece.piece->moveDiagonalLeft();
					ok = true;
				}
			}

		}
		if (inPiece.move == 'o') {
			if (this->getEdge((inPiece.row + 1), (inPiece.col - 1)) == 'b' || this->getEdge((inPiece.row + 1), (inPiece.col - 1)) == 'B') {
				row = inPiece.row + 2;
				col = inPiece.col - 2;
				if ((row >= 0 && row <= 7) && (col >= 0 && col <= 7) && (this->getEdge(row, col) == '-') && (this->findChecker(row,col) == NULL)) {
					ok = true;
					Checker* jumpPiece = this->findChecker((inPiece.row + 1), (inPiece.col - 1));
					jumpPiece ->setColumn(-1);
					jumpPiece->setRow(-1);
					//free(jumpPiece);

					inPiece.piece->moveDiagonalRight();
					inPiece.piece->moveDiagonalRight();
				}
			}
		}
		if (inPiece.move == 'j') {
			if (this->getEdge((inPiece.row - 1), (inPiece.col + 1)) == 'b' || this->getEdge((inPiece.row - 1), (inPiece.col + 1)) == 'B') {
				row = inPiece.row - 2;
				col = inPiece.col + 2;
				if ((row >= 0 && row <= 7) && (col >= 0 && col <= 7) && (this->getEdge(row, col) == '-') && (this->findChecker(row,col) == NULL)) {
					Checker* jumpPiece = this->findChecker((inPiece.row - 1), (inPiece.col + 1));
					jumpPiece->setColumn(-1);
					jumpPiece->setRow(-1);
					inPiece.piece->moveBackDiagonalLeft();
					inPiece.piece->moveBackDiagonalLeft();
					ok = true;
				}
			}
		}
		if (inPiece.move == 'k') {
			if (this->getEdge((inPiece.row + 1), (inPiece.col - 1)) == 'b' || this->getEdge((inPiece.row + 1), (inPiece.col - 1)) == 'B') {
				row = inPiece.row + 2;
				col = inPiece.col - 2;
				if ((row >= 0 && row <= 7) && (col >= 0 && col <= 7) && (this->getEdge(row, col) == '-') && (this->findChecker(row,col) == NULL)) {
					Checker* jumpPiece = this->findChecker((inPiece.row + 1), (inPiece.col - 1));
					jumpPiece->setColumn(-1);
					jumpPiece->setRow(-1);
					inPiece.piece->moveBackDiagonalRight();
					inPiece.piece->moveBackDiagonalRight();
					ok = true;

				}
			}
		}

	}

	return ok;
}

bool Board::isWin() {
	int redPieces = 0;
	int blackPieces = 0;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if ('r' == (*this).getEdge(i, j) || 'R' == (*this).getEdge(i, j)) {
				redPieces++;
			}
			else if ('b' == (*this).getEdge(i, j) || 'B' == (*this).getEdge(i, j)) {
				blackPieces++;
			}
		}
	}
	if (redPieces == 0) {
		printf("Black won\n");
		return true;
	}
	else if (blackPieces == 0) {
		printf("Red won\n");
		return true;
	}
	else {
		return false;
	}
}

bool Board::isValid(pieceMove move) {
	bool ok = false;
	int row = 0, col = 0;
	if ((move.piece)->getPlayerColor() == 'b' || move.piece->getPlayerColor() == 'B') {
		if (move.move == 'i') {
			row = move.row - 1;
			col = move.col - 1;
			if ((row >= 0 && row <= 8) && (col >= 0 && col <= 8))
				if (this->getEdge(row, col) == '-' && (this->findChecker(row,col) == NULL))
					ok = true;
		}
		if (move.move == 'o') {
			row = move.row - 1;
			col = move.col + 1;
			if ((row >= 0 && row <= 8) && (col >= 0 && col <= 8))
				if (this->getEdge(row, col) == '-' && (this->findChecker(row,col) == NULL))
					ok = true;
		}
		if (move.move == 'j') {
			row = move.row + 1;
			col = move.col - 1;
			if ((row >= 0 && row <= 8) && (col >= 0 && col <= 8))
				if (this->getEdge(row, col) == '-' && (this->findChecker(row,col) == NULL))
					ok = true;
		}
		if (move.move == 'k') {
			row = move.row + 1;
			col = move.col + 1;
			if ((row >= 0 && row <= 8) && (col >= 0 && col <= 8))
				if (this->getEdge(row, col) == '-' && (this->findChecker(row,col) == NULL))
					ok = true;
		}
	}
	else {
		if (move.move == 'i') {
			row = move.row + 1;
			col = move.col - 1;
			if ((row >= 0 && row <= 7) && (col >= 0 && col <= 7))
				if (this->getEdge(row, col) == '-'&& (this->findChecker(row,col) == NULL))
					ok = true;
		}
		if (move.move == 'o') {
			row = move.row + 1;
			col = move.col + 1;
			if ((row >= 0 && row <= 7) && (col >= 0 && col <= 7))
				if (this->getEdge(row, col) == '-'&& (this->findChecker(row,col) == NULL))
					ok = true;
		}
		if (move.move == 'j') {
			row = move.row - 1;
			col = move.col - 1;
			if ((row >= 0 && row <= 7) && (col >= 0 && col <= 7))
				if (this->getEdge(row, col) == '-'&& (this->findChecker(row,col) == NULL))
					ok = true;
		}
		if (move.move == 'k') {
			row = move.row - 1;
			col = move.col + 1;
			if ((row >= 0 && row <= 7) && (col >= 0 && col <= 7))
				if (this->getEdge(row, col) == '-'&& (this->findChecker(row,col) == NULL))
					ok = true;
		}
	}


	return ok;

}


bool Board::mustJump() {
	bool ok = false;
	int row = 0, col = 0;
	for (int i = 0; i < 7; i++) {
		for (int j = 0; j < 7; j++) {
			if (this->getEdge(i, j) == 'r') {
				row = i + 1;
				col = j + 1;
				if((row >= 0 && row <= 7) && (col >= 0 && row <= 7)){
					if (this->getEdge(row, col) == 'b') {
						row += 1;
						col += 1;
						if (this->getEdge(row, col) == '-') { ok = true; }
					}
				}
				col = j - 1;
				if((col >= 0 && col <= 7))
				{
					if (this->getEdge(row, col) == 'b') {
						row += 1;
						col -= 1;
						if (this->getEdge(row, col) == '-') { ok = true; }
					}
				}
			}
		}

	}
	return ok;
}

bool Board::canMove(int row, int col)
{
	bool moving = true;

	if ((0 <= row && row <= 8) && (0 <= col && col <= 8))
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

		if (!(isValid(i) || isValid(o) || isValid(k) || isValid(j)))
		{
			moving = false;
		}
	}

	return moving;
}

Checker* Board::findChecker(int row, int col) {
	for (int i = 0; i < 12; i++) {

		if (row == black[i]->getRow() && col == black[i]->getCol()) {
			return black[i];
		}
		if (row == red[i]->getRow() && col == red[i]->getCol()) {
			return red[i];
		}
	}
	return NULL;
}
int Board::computer(Checker** red)
{
	bool mustJump = this->mustJump();

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
				std::cout << "The Computer Jumped a piece\n";
				return 0;
			}
			if (this->canJump(oMove))
			{
				std::cout << "The Computer Jumped a piece\n";
				return 0;
			}
			if (this->canJump(kMove))
			{
				std::cout << "The Computer Jumped a piece\n";
				return 0;
			}
			if (this->canJump(jMove))
			{
				std::cout << "The Computer Jumped a piece\n";
				return 0;
			}
			if (this->isValid(iMove) && mustJump == false)
			{
				std::cout << "The computer moved the piece (" << red[i]->getRow() << ", " << red[i]->getCol() << ") to ";
				red[i]->moveDiagonalLeft();
				std::cout << "(" << red[i]->getRow() << ", " << red[i]->getCol()<< ")" << std::endl;
				return 0;
			}
			if (this->isValid(oMove) && mustJump == false)
			{
				std::cout << "The computer moved the piece (" << red[i]->getRow() << ", " << red[i]->getCol() << ") to ";
				red[i]->moveDiagonalRight();
				std::cout << "(" << red[i]->getRow() << ", " << red[i]->getCol()<< ")" << std::endl;
				return 0;
			}
			if (this->isValid(kMove) && mustJump == false)
			{
				std::cout << "The computer moved the piece (" << red[i]->getRow() << ", " << red[i]->getCol() << ") to ";
				red[i]->moveBackDiagonalRight();
				std::cout << "(" << red[i]->getRow() << ", " << red[i]->getCol()<< ")" << std::endl;
				return 0;
			}
			if (this->isValid(jMove) && mustJump == false)
			{
				std::cout << "The computer moved the piece (" << red[i]->getRow() << ", " << red[i]->getCol() << ") to ";
				red[i]->moveBackDiagonalLeft();
				std::cout << "(" << red[i]->getRow() << ", " << red[i]->getCol()<< ")" << std::endl;
				return 0;
			}
		}
		else
		{
			if (this->canJump(iMove))
			{
				std::cout << "The Computer Jumped a piece\n";
				return 0;
			}
			if (this->canJump(oMove))
			{
				std::cout << "The Computer Jumped a piece\n";
				return 0;
			}
			if (this->isValid(iMove) && (mustJump == false))
			{
				std::cout << "The computer moved the piece (" << red[i]->getRow() << ", " << red[i]->getCol() << ") to ";
				red[i]->moveDiagonalRight();
				std::cout << "(" << red[i]->getRow() << ", " << red[i]->getCol() << ")" << std::endl;
				return i;
			}
			if (this->isValid(oMove) && (mustJump == false))
			{
				std::cout << "The computer moved the piece (" << red[i]->getRow() << ", " << red[i]->getCol() << ") to ";
				red[i]->moveDiagonalLeft();
				std::cout << "(" << red[i]->getRow() << ", " << red[i]->getCol()<< ")" << std::endl;
				return i;
			}
		}
	}
	return 0;
}
