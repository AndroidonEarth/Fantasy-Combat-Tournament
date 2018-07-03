/*********************************************************************
** Program name: Fantasy Combat Tournament
** Author: Andrew Swaim
** Date: March 4, 2018
** Description: Node.cpp, implementation file for the Node class.
*********************************************************************/

#include "Node.hpp"
#include "Character.hpp"

/*
*
*/
Node::Node(Character* fighter) {

	this->fighter = fighter;
}

/*
*
*/
void Node::deleteFighter() {

	delete this->fighter;
}