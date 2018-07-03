/*********************************************************************
** Program name: Fantasy Combat Tournament
** Author: Andrew Swaim
** Date: March 4, 2018
** Description: Medusa.cpp, implementation file for the Medusa class.
*********************************************************************/

#include "Medusa.hpp"

/*
* Constructor for the Medusa class. This constructor must be used over the
* default constructor. Takes a string as an argument to initialize the name data member
* variable, and also initializes all other starting member variables.
*/
Medusa::Medusa(string name) {

	this->name = name;
	type = "Medusa";
	atkDies = 2;
	atkSides = 6;
	defDies = 1;
	defSides = 6;
	armor = 3;
	strength = maxStr = 8;
}

/*
* attack function of the Medusa class. Rolls a number of dice based on the
* number of attack dies and the number of sides of each dice. Then checks to see
* if the Medusa rolled a 12, and if so activates its special ability Glare, which
* changes it's attack roll to 1000 to instantly kill any opponent. Returns the total
* of the rolls (or 1000 if Glare activated).
*/
int Medusa::attack() {

	int attackRoll = 0;

	/*cout << "\nAttacker's type: " << type << "\n";*/

	// Roll attack dies.
	for (int i = 0; i < atkDies; i++) {

		attackRoll += rand() % atkSides + 1;
	}

	/*cout << "Attacker's roll: " << attackRoll << "\n";*/

	// Check for Medusa special ability.
	if (attackRoll == 12) {

		/*cout << "\n***" << name << "'s special ability GLARE has activated:\n"
			<< "Opponent is turned to stone!\n\n";*/
		attackRoll = 1000;
	}

	return attackRoll;
}

/*
* defend function of the Medusa class. Takes an integer as an argument for the
* attack roll of the opponent, used for calculating damage taken. Rolls a number of
* dice based on the number of defense dies and the sides of each dice. Then,
* calculates the total damage taken based on the attack roll and defense roll and
* armor of the Medusa, and subtracts it from the Medusa's strength.
*/
int Medusa::defend(int& attackRoll) {

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