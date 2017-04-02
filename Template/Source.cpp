/*
Chgitem xi erb grumem

#include"QueueArray.h"
#include"QueueList.h"

Linking errora talis
*/

#include <iostream>
#include "QueueArray.cpp"
#include "QueueList.cpp"
using namespace std;



int main() {
	Stack<char> * stack;
	char _input;
	cout << "input A if you want QueueArray\nanather will run with QueueList\ninput :: ";
	cin >> _input;
	
	/*
		chgites xi 
		stack = (_input=='A') ? new QueueArray<char,12> : new QueueList<char>;
		compile errora talis
	*/

	if (_input == 'A') stack = new QueueArray<char, 12>;
	else
	stack =  new QueueList<char>();

	char c = 'a';
	for (int i = 0; i < 15;i++)//READ ME 15>12
	{
		stack->push(c); c++;
	}
	
	stack->pop();
	stack->pop();
	cout << "stack->empty() :: " << stack->empty() << endl;
	cout << "stack->front() :: " << stack->front() << endl;
	
	for (int i = 0; i < 15; i++)//READ ME 15>10
		stack->pop();
	cout << "stack->empty() :: " << stack->empty() << endl;



	return 0;
}
