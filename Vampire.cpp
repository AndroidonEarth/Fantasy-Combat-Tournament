/*********************************************************************
** Program name: Fantasy Combat Tournament
** Author: Andrew Swaim
** Date: March 4, 2018
** Description: Vampire.cpp, implementation file for the Vampire class.
*********************************************************************/

#include "Vampire.hpp"

/*
* Constructor for the Vampire class. This constructor must be used over the 
* default constructor. Takes a string as an argument to initialize the name data member
* variable, and also initializes all other starting member variables.
*/
Vampire::Vampire(string name) {

	this->name = name;
	type = "Vampire";
	atkDies = 1;
	atkSides = 12;
	defDies = 1;
	defSides = 6;
	armor = 1;
	strength = maxStr = 18;
}

/*
* attack function of the Vampire class. Rolls a number of dice based on the 
* number of attack dies and the number of sides of each dice. Returns the total
* of the rolls.
*/
int Vampire::attack() {

	int attackRoll = 0;

	/*cout << "\nAttacker's name: " << name << "\n"
		<< "\nAttacker's type: " << type << "\n";*/

	// Roll attack dies.
	for (int i = 0; i < atkDies; i++) {

		attackRoll += rand() % atkSides + 1;
	}

	/*cout << "Attacker's roll: " << attackRoll << "\n";*/

	return attackRoll;
}

/*
* defend function of the Vampire class. Takes an integer as an argument for the
* attack roll of the opponent, used for calculating damage taken. Rolls a number of
* dice based on the number of defense dies and the sides of each dice. Also flips a
* coin to determine if the vampire's Charm ability activates, which changes the 
* opponents attack roll to 0. Finally, calculates the total damage taken based on
* the attack roll and defense roll and armor of the vampire, and subtracts it from
* the vampire's strength.
*/
int Vampire::defend(int& attackRoll) {

	int dmgTaken = 0;
	int defenseRoll = 0;
	int specialRoll = -1;

	/*cout << "\nDefender's name: " << name << "\n"
		<< "\nDefender's type: " << type << " (armor: "
		<< this->armor << ", str: " << strength << ")\n";*/

	// Roll defense dies.
	for (int i = 0; i < defDies; i++) {

		defenseRoll += rand() % defSides + 1;
	}

	// Check for Vampire special ability.
	specialRoll = rand() % 2;
	if (specialRoll == 0) {

		/*cout << "\n***" << name << "'s special ability CHARM has activated:\n"
			<< "Opponent's attack has been neutralized!\n\n";*/
		attackRoll = 0;
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