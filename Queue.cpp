/*********************************************************************
** Program name: Fantasy Combat Tournament
** Author: Andrew Swaim
** Date: March 4, 2018
** Description: Queue.cpp, implementation file for the Queue class.
*********************************************************************/

#include "Queue.hpp"
#include "Node.hpp"
#include "Character.hpp"

/*
* Constructor for the Queue class, initializes the head pointer to null.
*/
Queue::Queue() { head = nullptr; }

/*
* Destructor for the Queue class, steps through the list deallocating
* the memory for each node.
*/
Queue::~Queue() {

	Node* nodePtr = head;
	Node* garbage = nodePtr;

	if (isEmpty()) {

		// Nothing to deallocate.
	}
	else {
		// Delete all but the last node.
		while (nodePtr->getNext() != head) {

			garbage = nodePtr;
			nodePtr = nodePtr->getNext();
			garbage->deleteFighter();
			delete garbage;
		}
		// Delete the last node.
		garbage = nodePtr;
		garbage->deleteFighter();
		delete garbage;
	}
}

/*
* isEmpty function, checks if the queue is empty. If so, 
* returns true; otherwise, return false.
*/
bool Queue::isEmpty() {

	if (head == nullptr) {
		return true;
	}
	else {
		return false;
	}
}

/*
* addLast function, takes a pointer to a fighter, creates a QueueNode 
* with the pointer, and appends it to the back of the list.
*/
void Queue::addBack(Character* fighter) {

	Node* newNode = new Node(fighter);

	// Check if empty.
	if (isEmpty()) {

		newNode->setNext(newNode);
		newNode->setPrev(newNode);
		head = newNode;
	}
	else {

		// The queue is not empty.
		Node* lastNode = head->getPrev();
		newNode->setNext(head);
		newNode->setPrev(lastNode);
		head->setPrev(newNode);
		lastNode->setNext(newNode);
	}
}

/*
* getFront function, returns a pointer to the fighter in the node at the front of the queue.
* If there are no fighters in the queue, then a nullptr is returned instead.
*/
Character* Queue::getFront() {

	// Check if empty.
	if (isEmpty()) {

		cout << "\nQueue is empty, nothing to display.\n";
		return nullptr;
	}
	else {

		return head->getFighter();
	}
}

/*
* removeFirst function, removes the front QueueNode of the queue and frees the memory.
*/
void Queue::removeFront() {

	// Check if empty.
	if (isEmpty()) {

		cout << "\nQueue is empty, nothing to remove.\n";
	}
	// Check if 1 node in the queue.
	else if (head->getNext() == head) {

		delete head;
		head = nullptr;
	}
	else {

		// The list has multiple nodes.
		Node* secondNode = head->getNext();
		Node* lastNode = head->getPrev();
		secondNode->setPrev(lastNode);
		lastNode->setNext(secondNode);
		delete head;
		head = secondNode;
	}
}

/*
*
*/
void Queue::moveToBack() {

	// Check if empty.
	if (isEmpty()) {

		cout << "\nQueue is empty, nothing to move.\n";
	}
	else {

		// Get the next node.
		head = head->getNext();
	}
}

/*
* display function. traverses through the queue from head using next 
* pointers, and prints the values of each QueueNode in the queue.
*/
void Queue::printQueue() {

	// Check if empty.
	if (isEmpty()) {

		cout << "\nQueue is empty, nothing to display.\n";
	}
	else {

		// The queue is not empty.
		Node* nodePtr = head;
		
		// Display all but the last node.
		while (nodePtr->getNext() != head) {

			cout << nodePtr->getFighter()->getName()
				<< " (" << nodePtr->getFighter()->getType() << ")\n";
			nodePtr = nodePtr->getNext();
		}
		// Display the last node.
		cout << nodePtr->getFighter()->getName()
			<< " (" << nodePtr->getFighter()->getType() << ")\n";
	}
}

/*
*
*/
void Queue::printReverse() {

	// Check if empty.
	if (isEmpty()) {

		cout << "\nQueue is empty, nothing to display.\n";
	}
	else {

		// The queue is not empty.
		Node* nodePtr = head->getPrev();

		// Display all but first node, stepping backwards from the last node.
		while (nodePtr->getPrev() != head->getPrev()) {

			cout << nodePtr->getFighter()->getName()
				<< " (" << nodePtr->getFighter()->getType() << ")\n";
			nodePtr = nodePtr->getPrev();
		}
		// Display the first node.
		cout << nodePtr->getFighter()->getName()
			<< " (" << nodePtr->getFighter()->getType() << ")\n";
	}
}