/*********************************************************************
** Program name: Fantasy Combat Tournament
** Author: Andrew Swaim
** Date: March 4, 2018
** Description: Queue.hpp, specification file for the Queue class.
*********************************************************************/

#ifndef QUEUE_HPP
#define QUEUE_HPP

#include <iostream>
using std::cout;

class Character;
class Node;

class Queue {

private:
	Node* head;

public:
	Queue();
	~Queue();
	bool isEmpty();
	void addBack(Character*);
	Character* getFront();
	void removeFront();
	void moveToBack();
	void printQueue();
	void printReverse();
};

#endif // !QUEUE_HPP
