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
	bool ok5 = testGotBoard();
	//pedagogical bool ok5 = testRemoveFromList();
	bool ok6 = testPrintHistory();

	bool ok7= testMoveDiagonalLeft();
	bool ok8= testMoveDiagonalRight();
	bool ok9= testMoveBackDiagonalLeft();
	bool ok10= testMoveBackDiagonalRight();

	bool ok11=this->testGetPlayerMove();

	//answer = ok1 &&ok3 && ok4 && ok6 && ok7 && ok8 && ok10 && ok11;
	answer=ok11;
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
	std::cout << "Running Test Enqueue" << std::endl;

	LinkedList lList;
	LLNode* disListP = lList.makeEmptyLinkedList();
	CheckerLoc* moveP = (CheckerLoc*)malloc(sizeof(CheckerLoc));
	moveP->roomNumber=3;
	moveP->treasure=4;

	lList.savePayload(disListP, moveP);
	Payload* dis =lList.dequeueLIFO(disListP);
	if(((dis->roomNumber)!=3)&&((dis->treasure)!=4))
	{
		ok=false;
	}

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

bool Tests::testGotBoard()
{
	bool ans = true;

	std::cout << "Running testGotBoard" << std::endl;

	Board* theBoard=new Board();
	theBoard->setEdgesP((char*) malloc(8 * 8 *sizeof(char)));
	theBoard->init();
	for(int i=0;i<8;i++){
		for(int j=0;j<8;j++){
			if(theBoard->getEdge(i, j)!='-'){
				ans=false;
			}
		}
	}
	if(ans){
		puts("testGotBoard passes");fflush(stdout);
	}
	else{
		puts("testGotBoard fails");fflush(stdout);
	}
	free(theBoard);

	return ans;
}

bool Tests::testMakeLList()
{
	bool ok = true;
	LinkedList llList;
	std::cout << "Running testMakeLList" << std::endl;
	LLNode* theListP = llList.makeEmptyLinkedList();
	bool rightAnswer = true;
	bool answer = llList.isEmpty(theListP);
	if(answer!=rightAnswer)
	{
		ok = false;
	}
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

bool Tests::testGetPlayerMove(){
	printf("In testGetPlayerMove");fflush(stdout);
	Production* prod=new Production();
	Checker** red=new Checker*[12];
	for(int i=0;i<12;i++){
		red[i]=new Checker();
		red[i]->setRow(i*10);
		red[i]->setColumn(i*10);
		red[i]->setPlayerColor('r');
	}
	Checker** black=new Checker*[12];
	for(int i=0;i<12;i++){
		black[i]=new Checker();
		black[i]->setRow(i);
		black[i]->setColumn(i);
		black[i]->setPlayerColor('b');
	}
	printf("Created checkers\n");fflush(stdout);
	pieceMove move=prod->getPlayerMove(red,black);
	printf("%d\n",move.row);
	printf("%d\n",move.col);
	printf("%c\n",move.move);
	if(prod->getYesNo("Were these the values you entered?")){
		printf("getPlayerMove passes\n");fflush(stdout);
		return true;
	}
	else{
		printf("getPlayerMove fails\n");fflush(stdout);
		return false;
	}
}
