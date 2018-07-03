/*********************************************************************
** Program name: Fantasy Combat Tournament
** Author: Andrew Swaim
** Date: March 4, 2018
** Description: Game.hpp, specification file for the Game class.
*********************************************************************/

#ifndef GAME_HPP
#define GAME_HPP

#include "Barbarian.hpp"
#include "BlueMen.hpp"
#include "HarryPotter.hpp"
#include "Medusa.hpp"
#include "Vampire.hpp"
#include "Queue.hpp"

enum Type { VAMPIRE, BARBARIAN, BLUEMEN, MEDUSA, HARRYPOTTER };

struct Team {

	Queue* lineup;
	int points;

	Team(Queue* lineup) {

		this->lineup = lineup;
		points = 0;
	}
	~Team() {

		delete this->lineup;
	}
};

class Game {

private:
	Team* teamA;
	Team* teamB;
	Queue* losers;
	int round;
	bool gameOver;
	bool roundOver;

	Game();
	void printResults();
	Character* combat(Character*& attacker, Character*& defender, int& defenderDmg);

public:
	Game(Queue*, Queue*);
	~Game();
	void update();
	bool isGameOver();
	void printLosers();
	static Character* createCharacter(char selection, string name);
};

#endif // !GAME_HPP
