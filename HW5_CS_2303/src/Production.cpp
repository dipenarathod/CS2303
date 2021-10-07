/*
 * Production.cpp
 *
 *  Created on: Feb 1, 2020
 *      Author: Therese
 */

#include "Production.h"
#include <iostream>


Production::Production() {
	// TODO Auto-generated constructor stub

}

Production::~Production() {
	// TODO Auto-generated destructor stub
}

bool Production::prod(int argc, char* argv[])
{
	printf("Starting Production\n");
	bool answer;

	Checker** redCheckers=new Checker*[12];
	for(int i=0;i<12;i++){
		redCheckers[i]=(Checker*)0;
	}
	Checker** blackCheckers=new Checker*[12];
	for(int i=0;i<12;i++){
		blackCheckers[i]=(Checker*)0;
	}


	if(argc <=1) //no interesting information
	{
		puts("Didn't find any arguments.");
		fflush(stdout);
		answer = false;
	}
	else //there is interesting information
	{
		printf("Found %d interesting arguments.\n", argc-1);
		fflush(stdout);
		for(int i = 1; i<argc; i++) //don't want to read argv[0]
		{//argv[i] is a string
			switch(i)
			{
			case 1:
				this->setTurn(argv[i]);
				this->amGoingFirst=argv[i];
				break;
			default:
				puts("Unexpected argument count."); fflush(stdout);
				answer = false;
				break;
			}//end of switch
		}//end of for loop on argument count
		puts("after reading arguments"); fflush(stdout);
		//we'll want to read the file
		ofstream boards;
		boards.open("boards.txt");
		boards<<"Here goes nothing \n";
		boards.close();
		puts("Before read file"); fflush(stdout);
		Board* theBoard = new Board();
		answer = readFile("originalBoard.txt", theBoard,redCheckers,blackCheckers); //read the file
		puts("Back from read file"); fflush(stdout);

		theBoard->red = redCheckers;
		theBoard->black = blackCheckers;
		theBoard->redTest = this->amGoingFirst;

		if(this->amGoingFirst){

			while(!theBoard->isWin()){
				std::cout << "Player is going first\n";
				theBoard->displayBoard();
				//printf("%d\n",redCheckers[0]->getCol());fflush(stdout);
				pieceMove move=getPlayerMove(redCheckers,blackCheckers);

				bool valid = theBoard->isValid(move);
				std::cout << "Is valid: " << valid<< std::endl;

				if(valid){
					if(move.move == 'i'){
						move.piece->moveDiagonalLeft();
					}
					else if(move.move == 'o'){
						move.piece->moveDiagonalRight();
					}
					else if(move.move == 'j'){
						move.piece->moveBackDiagonalLeft();
					}
					else if(move.move == 'k'){
						move.piece->moveBackDiagonalRight();
					}
				}
				else if(theBoard->canJump(move)){if(theBoard->isWin()){break;}}
				theBoard->printToFile("gameState.txt", redCheckers, blackCheckers);
				theBoard->computer(redCheckers, blackCheckers);
				theBoard->printToFile("gameState.txt", redCheckers, blackCheckers);
			}
		}
		else if(this->amGoingFirst == false){

			while(!theBoard->isWin()){
				std::cout << "Comp is going first\n";
				theBoard->computer(redCheckers, blackCheckers);
				theBoard->printToFile("gameState.txt", redCheckers, blackCheckers);
				theBoard->displayBoard();


				printf("%d\n",redCheckers[0]->getCol());fflush(stdout);
				pieceMove move=getPlayerMove(redCheckers,blackCheckers);

				bool valid = theBoard->isValid(move);
				//std::cout << "Is valid: " << valid<< std::endl;

				if(valid){
					if(move.move == 'i'){
						move.piece->moveDiagonalLeft();
					}
					else if(move.move == 'o'){
						move.piece->moveDiagonalRight();
					}
					else if(move.move == 'j'){
						move.piece->moveBackDiagonalLeft();
					}
					else if(move.move == 'k'){
						move.piece->moveBackDiagonalRight();
					}
				}
				else if(theBoard->canJump(move)){if(theBoard->isWin()){break;}}
				theBoard->printToFile("gameState.txt", redCheckers, blackCheckers);
			}
		}

	}

	return answer;
}

bool Production::readFile(char* filename, Board* theBoard,Checker** red,Checker** black)
{
	bool ok = true;
	FILE* fp = fopen(filename, "r"); //read the file

	if (fp == NULL)
	{
		puts("Error! opening file");

	}
	else
	{
		int redIndex=0;
		int blackIndex=0;
		theBoard->setEdgesP((char*) malloc(8 * 8 *sizeof(char)));
		puts("Before init Board"); fflush(stdout);
		theBoard->init();
		puts("After init Board"); fflush(stdout);
		char temp ='-';
		for(int row = 0; row<9; row++)
		{
			printf("on row %d\n", row);fflush(stdout);
			for(int col = 0; col<9; col++)
			{
				fscanf(fp,"%c", &temp);
				printf("in column %d, read %c\n", col, temp);fflush(stdout);
				//now set the value in the adjacency matrix
				if(temp=='b' ||temp=='B'){
					theBoard->setEdge(row,col,temp);
					black[blackIndex]=new Checker();
					black[blackIndex]->setRow(row);
					black[blackIndex]->setColumn(col);
					black[blackIndex]->setPlayerColor(temp);
					if(temp=='B'){
						black[blackIndex]->isKing=true;
					}
					blackIndex++;
				}
				else if(temp=='r' ||temp=='R'){
					theBoard->setEdge(row,col,temp);
					red[redIndex]=new Checker();
					red[redIndex]->setRow(row);
					red[redIndex]->setColumn(col);
					red[redIndex]->setPlayerColor(temp);
					if(temp=='R'){
						red[redIndex]->isKing=true;
					}
					redIndex++;
				}
			}
		}
		//TODO read the board from the file,
		//discover checkers
		//make instances of class checker as needed
		//board needs to keep track of instances of checkers
		//checkers might also know where they are...
		//fscanf(fp,"%c", &temp); //red checker, black, none?
		//notice, this reads only one character, and <CR> is a character

	}
	fclose(fp);

	return ok;
}

bool Production::getYesNo(char* query)
{
	bool answer = true; //so far
	char said = 'x';
	do
	{
		printf("%s (y/n):",query);
		fflush(stdout);
		fflush(stdin);
		scanf("%c",&said);
	}while((said!= 'y')&&(said!='n'));
	if(said=='n')
	{
		answer=false;
	}


	return answer;
}

bool Production::getTurn(){
	return this->turn;
}

void Production::switchTurn(){
	this->turn=!this->turn;
}

void Production::setTurn(bool turn){
	this->turn=turn;
}

pieceMove Production::getPlayerMove(Checker** red,Checker** black){
	pieceMove move;
	bool foundPiece=false;
	bool correctMoveDirection=false;
	printf("Enter row of piece:\n");fflush(stdout);
	scanf("%d",&(move.row));fflush(stdin);
	printf("Enter column of piece:\n");fflush(stdout);
	scanf("%d",&(move.col));fflush(stdin);
	printf("Enter direction:\n");fflush(stdout);
	scanf("%c",&(move.move));fflush(stdin);
	if(move.move=='i' ||move.move=='o' || move.move=='j' || move.move=='k'){
		correctMoveDirection=true;
	}
	if(this->amGoingFirst){
		for(int i=0;i<12;i++){
			if(black[i]->getRow()==move.row && black[i]->getCol()==move.col){
				foundPiece=true;
				move.piece=black[i];
				if(move.move=='j' || move.move=='k'){
					if(!black[i]->isKing){
						correctMoveDirection=false;
					}
				}
				//printf("%d,%d,%c\n",move.row,move.col,move.move);
			}
		}
	}
	else{
		for(int i=0;i<12;i++){
			if(red[i]->getRow()==move.row && red[i]->getCol()==move.col){
				foundPiece=true;
				move.piece=red[i];
				if(move.move=='j' || move.move=='k'){
					if(!red[i]->isKing){
						correctMoveDirection=false;
					}
				}
			}
		}
	}
	if(!(foundPiece && correctMoveDirection)){
		printf("Invalid row, or column, or direction\n");
		return getPlayerMove(red,black);
	}
	return move;
}
