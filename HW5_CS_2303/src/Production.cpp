/*
 * Production.cpp
 *
 *  Created on: Feb 1, 2020
 *      Author: Therese
 */

#include "Production.h"


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
	Board* theBoard = new Board();
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
		bool turn;
		for(int i = 1; i<argc; i++) //don't want to read argv[0]
		{//argv[i] is a string
			switch(i)
			{
			case 1:
				theBoard->setTurn(argv[i]);
				break;
			default:
				puts("Unexpected argument count."); fflush(stdout);
				answer = false;
				break;
			}//end of switch
		}//end of for loop on argument count
		puts("after reading arguments"); fflush(stdout);
		//we'll want to read the file
		puts("Before read file"); fflush(stdout);
		answer = readFile("originalBoard.txt", theBoard,redCheckers,blackCheckers); //read the file
		puts("Back from read file"); fflush(stdout);
		theBoard->displayBoard();

		printf("%d\n",redCheckers[0]->getRow());fflush(stdout);





	}
	return answer;
}

bool Production::readFile(char* filename, Board* theBoard,Checker** red,Checker** black)
{
	bool ok = true;
	char temp = '-';
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

