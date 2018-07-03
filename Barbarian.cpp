/*********************************************************************
** Program name: Fantasy Combat Tournament
** Author: Andrew Swaim
** Date: March 4, 2018
** Description: Barbarian.cpp, implementation file for the Barbarian class.
*********************************************************************/

#include "Barbarian.hpp"

/*
* Constructor for the Barbarian class. This constructor must be used over the
* default constructor. Takes a string as an argument to initialize the name data member
* variable, and also initializes all other starting member variables.
*/
Barbarian::Barbarian(string name) {

	this->name = name;
	type = "Barbarian";
	atkDies = 2;
	atkSides = 6;
	defDies = 2;
	defSides = 6;
	armor = 0;
	strength = maxStr = 12;
}

/*
* attack function of the Barbarian class. Rolls a number of dice based on the
* number of attack dies and the number of sides of each dice. Returns the total
* of the rolls.
*/
int Barbarian::attack() {

	int attackRoll = 0;

	/*cout << "\nAttacker's type: " << type << "\n";*/

	// Roll attack dies.
	for (int i = 0; i < atkDies; i++) {

		attackRoll += rand() % atkSides + 1;
	}

	/*cout << "Attacker's roll: " << attackRoll << "\n";*/

	return attackRoll;
}

/*
* defend function of the Barbarian class. Takes an integer as an argument for the
* attack roll of the opponent, used for calculating damage taken. Rolls a number of
* dice based on the number of defense dies and the sides of each dice. Then, 
* calculates the total damage taken based on the attack roll and defense roll and 
* armor of the barbarian, and subtracts it from the barbarian's strength.
*/
int Barbarian::defend(int& attackRoll) {

	int dmgTaken = 0;
	int defenseRoll = 0;

	/*cout << "\nDefender's type: " << type << " (armor: "
		<< this->armor << ", str: " << strength << ")\n";*/

	// Roll defense dies.
	for (int i = 0; i < defDies; i++) {

		defenseRoll += rand() % defSides + 1;
	}
	
	// Calc damage taken.
	dmgTaken = attackRoll - defenseRoll - armor;

	// Evaluate damage taken.
	if (dmgTaken > 0) {			// Attack roll higher - takes damage.

		// If damage taken is greater than remaining strength.
		if (dmgTaken > strength) {
			dmgTaken = strength;
			strength = 0;
		}
		// Otherwise simply subtract damage taken.
		else {
			strength -= dmgTaken;
		}
	}
	else if (dmgTaken < 0) {	// Defense and armor were greater - no damage.
		dmgTaken = 0;
	}

	/*cout << "Defenders roll: " << defenseRoll << "\n";
	cout << "Total inflicted damage: " << dmgTaken << "\n";
	cout << "Defenders updated strength: " << strength << "\n";*/

	return dmgTaken;
}