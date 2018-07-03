/*********************************************************************
** Program name: Fantasy Combat Tournament
** Author: Andrew Swaim
** Date: March 4, 2018
** Description: main.cpp, driver for the game.
*********************************************************************/

#include "Game.hpp"
#include "menu.hpp"
#include "inputValidation.hpp"

#include <ctime>
#include <climits>
using std::cin;
using std::getline;

int main() {

	Game* game;				// To hold the game object to start the game.
	Queue* lineupA;			// To hold the lineup for team A.
	Queue* lineupB;			// To hold the lineup for team B.
	string name;			// To hold a user input for a character's name.
	Character* character;	// To hold a character object to be added to a lineup.
	int numOfCharacters;	// To hold the number of characters to create for each team.

	char choice;	// To hold the user choice.

	// Setup seed and srand for use with rand().
	unsigned seed = time(0);
	srand(seed);

	// Display the intro to the program.
	displayIntro();

	// Prompt user to play or exit.
	choice = getMenuChoice(mainMenu());

	while (choice == '1') {

		// Initialize lineups.
		lineupA = new Queue();
		lineupB = new Queue();

		// Get number of characters.
		cout << "\nEnter the number for fighters for each team: ";
		numOfCharacters = getValidIntInRange(0, INT_MAX);

		// Setup the lineup for team A.
		for (int i = 1; i <= numOfCharacters; i++) {

			cout << "\nSelect a character type for Team A, character " << i << ":\n";
			choice = getMenuChoice(charSelectMenu());

			cout << "\nEnter a name for Team A, character " << i << ":\n\n";
			getline(cin, name);

			while (name.empty()) {

				cout << "\nAll fighters must have a name;\n"
					<< "Please enter a name for Team A, character " << i << ":\n\n";
				getline(cin, name);
			}

			character = game->createCharacter(choice, name);
			lineupA->addBack(character);
		}

		// Setup the lineup for team B.
		for (int i = 1; i <= numOfCharacters; i++) {

			cout << "\nSelect a character type for Team B, character " << i << ":\n";
			choice = getMenuChoice(charSelectMenu());

			cout << "\nEnter a name for Team B, character " << i << ":\n\n";
			getline(cin, name);

			while (name.empty()) {

				cout << "\nAll fighters must have a name;\n"
					<< "Please enter a name for Team A, character " << i << ":\n\n";
				getline(cin, name);
			}

			character = game->createCharacter(choice, name);
			lineupB->addBack(character);
		}

		// Start the game.
		game = new Game(lineupA, lineupB);

		// While the game has not ended
		do {

			// Execute one round of the game and then wait for user response.
			game->update();
			cout << "\nPress enter to continue...\n";
			cin.get();

		} while (!game->isGameOver());

		// Ask the user if they want to display the losers.
		cout << "Do you want to display the list of defeated fighters? (Y/N)\n\n";
		choice = getValidChar("yes", "no");

		if (choice == 'y') {

			cout << "\nList of defeated fighters from last defeated to first:\n";
			game->printLosers();
			cout << "\nPress enter to continue...\n";
			cin.get();
		}

		// If the game has ended, deallocate memory for the game object.
		delete game;

		// Prompt user to play again or quit.
		choice = getMenuChoice(playAgainMenu());
	}

	// If user decided to immediately exit or not play again, display the outro.
	displayOutro();
	getchar();
	return 0;
}