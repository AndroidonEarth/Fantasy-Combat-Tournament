/*********************************************************************
** Program name: Fantasy Combat Tournament
** Author: Andrew Swaim
** Date: March 4, 2018
** Description: Node.hpp, specification file for the Node class.
*********************************************************************/

#ifndef NODE_HPP
#define NODE_HPP

class Character;

class Node {

private:
	Node *next, *prev;
	Character* fighter;

public:
	Node(Character* fighter);
	void deleteFighter();

	Node* getNext() { return this->next; }
	void setNext(Node* next) { this->next = next; }
	Node* getPrev() { return this->prev; }
	void setPrev(Node* prev) { this->prev = prev; }
	Character* getFighter() { return this->fighter; }
	void setFighter(Character* fighter) { this->fighter = fighter; }
};

#endif // !NODE_HPP

