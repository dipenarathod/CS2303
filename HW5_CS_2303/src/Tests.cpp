/*
 * Tests.cpp
 *
 *  Created on: Feb 1, 2020
 *      Author: Therese
 */

#include "Tests.h"
#include <stdbool.h>
#include <stdio.h>
#include "LinkedList.h"

Tests::Tests() {
	// TODO Auto-generated constructor stub

}

Tests::~Tests() {
	// TODO Auto-generated destructor stub
}

bool Tests::tests()
{
	bool answer = true;

	bool ok1 = testReadFile();
	bool ok2 = testFileOutput();
	bool ok3 = testMakeLList();
	bool ok4 = testEnqueue();
	//pedagogical bool ok5 = testRemoveFromList();
	bool ok6 = testPrintHistory();

	bool ok7= testMoveDiagonalLeft();
	bool ok8= testMoveDiagonalRight();
	bool ok9= testMoveBackDiagonalLeft();
	bool ok10= testMoveBackDiagonalRight();
	answer = ok1 && ok3 && ok4  && ok6 && ok7 && ok8 && ok10;
	return answer;
}

bool Tests::testReadFile()
{
	puts("starting testReadFile"); fflush(stdout);
	bool ok = true;
	//the file tells how many rooms there are
	int answer = -1;
	int rightAnswer = 8;


	Board* theBoard = new Board();


	Production* pP = new Production();

	Checker** red=new Checker*[12];
	Checker** black=new Checker*[12];
	ok = pP->readFile("gameState.txt", theBoard,red,black); //read the file

	theBoard->displayBoard();
	ok = pP->getYesNo("Does the board look right?");
	if(ok)
	{
		puts("testReadfile did pass");
	}
	else
	{
		puts("testReadfile did not pass.");
	}

	return ok;
}
bool Tests::testEnqueue()
{
	bool ok = true;
	if(ok)
	{
		puts("testEnqueue did pass");
	}
	else
	{
		puts("testEnqueue did not pass.");
	}
	return ok;
}
bool Tests::testGotAdjacencyMatrix()
{
	bool ok = true;
	if(ok)
	{
		puts("testGotAdjacencyMatrix did pass");
	}
	else
	{
		puts("testGotAdjacencyMatrix did not pass.");
	}
	return ok;
}

bool Tests::testMakeLList()
{
	bool ok = true;
	if(ok)
	{
		puts("testMakeLList did pass");
	}
	else
	{
		puts("testMakeLList did not pass.");
	}
	return ok;
}
bool Tests::testPrintHistory()
{
	bool ok = true;
	LinkedList lList;
	LLNode* case1 = lList.makeEmptyLinkedList();
	Payload* pay1 = (Payload*) malloc(sizeof(Payload));
	pay1->roomNumber =1;
	pay1->treasure = 1.1;
	lList.savePayload(case1, pay1);


	Payload* pay2 = (Payload*) malloc(sizeof(Payload));
	pay2->roomNumber = 2;
	pay2->treasure = 2.2;
	lList.savePayload(case1, pay2);
	if(case1->payP ==(Payload*)0)
	{
		puts("Empty List");
	}
	else
	{
		//traverse the list, printing as we go
		float treasureSubtotal = 0.0;
		int room = -1;
		LLNode* temp = case1;
		while(temp->next)
		{
			room =temp->payP->roomNumber;
			treasureSubtotal+= temp->payP->treasure;
			printf("The room was %d, and the treasure subtotal was %f.\n", room, treasureSubtotal);
			temp=(LLNode*)temp->next;

		}
		room =temp->payP->roomNumber;
		treasureSubtotal+= temp->payP->treasure;
		printf("The room was %d, and the treasure subtotal was %f.\n", room, treasureSubtotal);
	}


	if(ok)
	{
		puts("testPrintHistory did pass");
	}
	else
	{
		puts("testPrintHistory did not pass.");
	}
	return ok;
}
bool Tests::testFileOutput()
{
	bool ok = true;

	FILE* fd = fopen("boardPlay.txt", "w");
	fprintf(fd, "Here goes nothing\n"); fflush(fd);


	fclose(fd);
	if(ok)
	{
		puts("testFileOutput did pass");
	}
	else
	{
		puts("testFileOutput did not pass.");
	}
	return ok;
}

bool Tests::testMoveDiagonalLeft(){
	Checker* checker1=new Checker;
	bool answer1=false;
	checker1->setColumn(4);
	checker1->setRow(4);
	checker1->setPlayerColor('b');
	checker1->moveDiagonalLeft();
	if(checker1->getRow()==3 && checker1->getCol()==3){
		answer1=true;
	}

	Checker* checker2=new Checker;
	bool answer2=false;
	checker2->setColumn(4);
	checker2->setRow(4);
	checker2->setPlayerColor('r');
	checker2->moveDiagonalLeft();
	if(checker2->getRow()==5 && checker2->getCol()==5){
		answer2=true;
	}

	if(answer1&&answer2){
		printf("testMoveDiagonalLeft passed\n");
		fflush(stdout);
		return true;
	}
	else{
		printf("testMoveDiagonalLeft fails\n");
		fflush(stdout);
		return false;
	}
}

bool Tests::testMoveDiagonalRight(){
	Checker* checker1=new Checker;
	bool answer1=false;
	checker1->setColumn(4);
	checker1->setRow(4);
	checker1->setPlayerColor('b');
	checker1->moveDiagonalRight();
	if(checker1->getRow()==3 && checker1->getCol()==5){
		answer1=true;
	}

	Checker* checker2=new Checker;
	bool answer2=false;
	checker2->setColumn(4);
	checker2->setRow(4);
	checker2->setPlayerColor('r');
	checker2->moveDiagonalRight();
	if(checker2->getRow()==5 && checker2->getCol()==3){
		answer2=true;
	}

	if(answer1&&answer2){
		printf("testMoveDiagonalRight passed\n");
		fflush(stdout);
		return true;
	}
	else{
		printf("testMoveDiagonalRight fails\n");
		fflush(stdout);
		return false;
	}
}

bool Tests::testMoveBackDiagonalLeft(){
	Checker* checker1=new Checker;
	bool answer1=false;
	checker1->setColumn(4);
	checker1->setRow(4);
	checker1->setPlayerColor('B');
	checker1->moveBackDiagonalLeft();
	if(checker1->getRow()==5 && checker1->getCol()==3){
		answer1=true;
	}

	Checker* checker2=new Checker;
	bool answer2=false;
	checker2->setColumn(4);
	checker2->setRow(4);
	checker2->setPlayerColor('R');
	checker2->moveBackDiagonalLeft();
	if(checker2->getRow()==3 && checker2->getCol()==5){
		answer2=true;
	}

	if(answer1&&answer2){
		printf("testMoveBackDiagonalLeft passed\n");
		fflush(stdout);
		return true;
	}
	else{
		printf("testMoveBackDiagonalLeft fails\n");
		fflush(stdout);
		return false;
	}
}

bool Tests::testMoveBackDiagonalRight(){
	Checker* checker1=new Checker;
		bool answer1=false;
		checker1->setColumn(4);
		checker1->setRow(4);
		checker1->setPlayerColor('B');
		checker1->moveBackDiagonalRight();
		if(checker1->getRow()==5 && checker1->getCol()==5){
			answer1=true;
		}

		Checker* checker2=new Checker;
		bool answer2=false;
		checker2->setColumn(4);
		checker2->setRow(4);
		checker2->setPlayerColor('R');
		checker2->moveBackDiagonalRight();
		if(checker2->getRow()==3 && checker2->getCol()==3){
			answer2=true;
		}

		if(answer1&&answer2){
			printf("testMoveBackDiagonalRight passed\n");
			fflush(stdout);
			return true;
		}
		else{
			printf("testMoveBackDiagonalRight fails\n");
			fflush(stdout);
			return false;
		}
}
