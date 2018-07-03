/*********************************************************************
** Program name: Fantasy Combat Tournament
** Author: Andrew Swaim
** Date: March 4, 2018
** Description: menu.cpp, implementation file the menu helper functions.
*********************************************************************/

#include "menu.hpp"
#include <iostream>
using std::cout;

/**
* Display the intro to the program. This is used when the program first
* starts to give an introduction and description of the program. 
*/
void displayIntro() {

	cout << "\n\nWELCOME!\n\n"
		<< "To Fantasy Combat Game!\n";
}


/**
* Display the first menu prompt. This is used at the start of the program
* after the introduction in order to prompt the user for their first selection.
*/
char mainMenu() {

	cout << "\n\nMAIN MENU\n\n"
		<< "1) Play game\n"
		<< "2) Quit\n\n";

	return '2';
}

/**
* Display the character select menu prompt.
*/
char charSelectMenu() {

	cout << "\n1) Vampire\n"
		<< "2) Barbarian\n"
		<< "3) Blue Men\n"
		<< "4) Medusa\n"
		<< "5) Harry Potter\n\n";

	return '5';
}

/**
* Display the play again menu prompt.
*/
char playAgainMenu() {

	cout << "\n\nMAIN MENU\n\n"
		<< "1) Play again?\n"
		<< "2) Quit\n\n";

	return '2';
}

/**
* Display the outro to the program. This is used when the program is about to end
* to indicate so to the user.
*/
void displayOutro() {

	cout << "\nGame is exiting."
		<< "\n\nTHANK YOU FOR PLAYING!\n\n";
}