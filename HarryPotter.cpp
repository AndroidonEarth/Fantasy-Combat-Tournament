/*********************************************************************
** Program name: Fantasy Combat Tournament
** Author: Andrew Swaim
** Date: March 4, 2018
** Description: HarryPotter.cpp, implementation file for the HarryPotter class.
*********************************************************************/

#include "HarryPotter.hpp"

/*
* Constructor for the HarryPotter class. This constructor must be used over the
* default constructor. Takes a string as an argument to initialize the name data member
* variable, and also initializes all other starting member variables.
*/
HarryPotter::HarryPotter(string name) {

	this->name = name;
	type = "Harry Potter";
	atkDies = 2;
	atkSides = 6;
	defDies = 2;
	defSides = 6;
	armor = 0;
	strength = maxStr = 10;
	hasDied = false;
}

/*
* attack function of the HarryPotter class. Rolls a number of dice based on the
* number of attack dies and the number of sides of each dice. Returns the total
* of the rolls.
*/
int HarryPotter::attack() {

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
* defend function of the HarryPotter class. Takes an integer as an argument for the
* attack roll of the opponent, used for calculating damage taken. Rolls a number of
* dice based on the number of defense dies and the sides of each dice. Then,
* calculates the total damage taken based on the attack roll and defense roll and
* armor of the bluemen, and subtracts it from the bluemen's strength. Finally, checks
* if the Harry Potter's health is at 0 and if it has not died previously, which 
* activates it's special ability Hogwarts. If the conditions are met then resets
* Harry Potter's strength to 20 and indicate that it has died once already.
*/
int HarryPotter::defend(int& attackRoll) {

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

		// Check for Harry Potter special ability.
		if (strength == 0 && hasDied == false) {

			strength = maxStr = 20;
			hasDied = true;

			/*cout << "\n***" << name << "'s special ability HOGWARTS has activated:\n"
				<< name << " has revived with 20 strength points!\n\n";*/
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