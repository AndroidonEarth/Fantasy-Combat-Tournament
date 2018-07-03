/*********************************************************************
** Program name: Fantasy Combat Tournament
** Author: Andrew Swaim
** Date: March 4, 2018
** Description: Game.cpp, implementation file for the Game class.
*********************************************************************/

#include "Game.hpp"
using std::cin;

/*
* Constructor for the Game class, which must be used over the default constructor.
* Takes two pointers to lineup queues as arguments. Also initializes the round number 
* and the game over and round over flags in order to start the game.
*/
Game::Game(Queue* lineupA, Queue* lineupB) {

	teamA = new Team(lineupA);
	teamB = new Team(lineupB);
	losers = new Queue();
	round = 1;
	gameOver = roundOver = false;
}

/*
* Destructor for the Game class. Deallocates the memory for the Team objects and the
* loser queue object before the game object is destroyed.
*/
Game::~Game() {

	delete teamA;
	delete teamB;
	delete losers;
}

/*
* update function, the primary function of the Game class which simulates one
* round of the game. Initiates combat with one character as the attacker and the
* other as the defender. Then checks to see if the round is over, and if not
* initates combat again with the characters in opposite roles. Once the round has ended
* this function resolves the end of the round by incrementing team points, healing the
* winner, moves the winner to the back of the queue and moves to the loser to the loser
* queue. Ends by incrementing the round number to prepare for the next round.
*/
void Game::update() {

	// Check if either side is out of fighters, and if so display the results.
	if ((teamA->lineup->isEmpty()) || (teamB->lineup->isEmpty())) {

		gameOver = true;
		printResults();
	}
	// If both sides have at least 1 fighter, initiate a round of combat.
	else {

		Character* winner;		// To hold the winner of the round.

		// To hold the characters at the front of each team's lineup.
		Character* character1 = teamA->lineup->getFront();
		Character* character2 = teamB->lineup->getFront();

		// To record total damage taken for the winner to recover a percentage of.
		int character1Dmg = 0;
		int character2Dmg = 0;

		roundOver = false;		// To determine when one character dies.

		cout << "-----------------------------------------------\n";
		cout << "Round " << round << ":\n"
			<< "Team A, " << character1->getName() << " (" << character1->getType() << ")\n"
			<< "- VS. -\n"
			<< "Team B, " << character2->getName() << " (" << character2->getType() << ")\n";

		// Initiate combat until 1 combatant dies.
		do {

			// Have character 1 attack character 2.
			winner = combat(character1, character2, character2Dmg);

			// If the round did not end
			if (roundOver == false) {

				// Have character 2 attack character 1.
				winner = combat(character2, character1, character1Dmg);
			}
		} while (roundOver == false);

		// Once the round has ended, resolve the round.
		if (winner == character1) {

			// Print the winner
			cout << "\n" << character1->getName() 
				<< " (" << character1->getType() << ") Won!\n";

			// Character 1 / Team A wins
			character1->recover(character1Dmg);	// Recover the winner
			teamA->lineup->moveToBack();		// and move them to the back.
			teamA->points += 2;					// Increase winning team points.

			// Character 2 / Team B loses
			losers->addBack(character2);		// Add the loser to the loser queue.
			teamB->lineup->removeFront();		// Remove the loser from their team's queue.
			if (teamB->points >= 1) {
				teamB->points -= 1;				// Decrease losing team points if able.
			}

			cout << "\nTeam A +2 Points (" << teamA->points << ")\n";
			cout << "Team B -1 Points (" << teamB->points << ")\n";
		}
		else if (winner == character2) {

			cout << "\n" << character2->getName()
				<< " (" << character2->getType() << ") Won!\n";

			// Character 2 / Team B wins.
			character2->recover(character2Dmg);
			teamB->lineup->moveToBack();
			teamB->points += 2;

			// Character 1 / Team A loses.
			losers->addBack(character1);
			teamA->lineup->removeFront();
			if (teamA->points >= 1) {
				teamA->points -= 1;
			}

			cout << "\nTeam A -1 Points (" << teamA->points << ")\n";
			cout << "Team B +2 Points (" << teamB->points << ")\n";
		}

		// Increment round number.
		round++;
		cout << "\n-----------------------------------------------\n";
	}
}

/*
* combat function. Takes a character object for the attacker and defender as arguments and
* calls their attack and defend function respectively, keeping track of the damage
* taken by the defender. Afterwards, checks the remaining strength of the defender 
* to see if the character died and if so sets the round over flag to true to end the round.
*/
Character* Game::combat(Character*& attacker, Character*& defender, int& defenderDmg) {

	int attackRoll;
	
	attackRoll = attacker->attack();
	defenderDmg += defender->defend(attackRoll);

	if (defender->getStr() <= 0) {

		roundOver = true;
		return attacker;
	}
	else {
		return nullptr;
	}
}

/*
* isGameOver function, indicates whether the game has ended.
*/
bool Game::isGameOver() {

	return gameOver;
}

/*
* printResults function, to display the final scores of the game and determine
* which team has the most points (i.e. which team is the winner).
*/
void Game::printResults() {

	int teamAPoints = teamA->points;
	int teamBPoints = teamB->points;

	cout << "-----------------------------------------------\n";
	cout << "GAME FINISHED!\n"
		<< "\nTeam A Score: " << teamA->points << "\n"
		<< "Team B Score: " << teamB->points << "\n";

	if (teamAPoints > teamBPoints) {
		cout << "\nTEAM A WINS!";
	}
	else if (teamAPoints < teamBPoints) {
		cout << "\nTEAM B WINS!";
	}
	else if (teamAPoints == teamBPoints) {
		cout << "\nTIE GAME!";
	}
	cout << "\n-----------------------------------------------\n";
}

/*
* printLosers function, to print the losers queue in reverse so that the last defeated
* fighter is printed first, etc.
*/
void Game::printLosers() {

	losers->printReverse();
}

/*
* static createCharacter function, used in main before the game object has been created,
* so that character objects can be created and added to the lineup of each team, which are
* then passed to the constructor of the Game object to begin the game.
*/
Character* Game::createCharacter(char selection, string name) {

	Character* newCharacter = nullptr;

	switch (selection)
	{
	case '1':
		newCharacter = new Vampire(name);
		break;
	case '2':
		newCharacter = new Barbarian(name);
		break;
	case '3':
		newCharacter = new BlueMen(name);
		break;
	case '4':
		newCharacter = new Medusa(name);
		break;
	case '5':
		newCharacter = new HarryPotter(name);
		break;
	}

	return newCharacter;
}