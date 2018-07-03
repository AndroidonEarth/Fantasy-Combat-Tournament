/*********************************************************************
** Program name: Fantasy Combat Tournament
** Author: Andrew Swaim
** Date: March 4, 2018
** Description: BlueMen.cpp, implementation file for the BlueMen class.
*********************************************************************/

#include "BlueMen.hpp"

/*
* Constructor for the BlueMen class. This constructor must be used over the
* default constructor. Takes a string as an argument to initialize the name data member
* variable, and also initializes all other starting member variables.
*/
BlueMen::BlueMen(string name) {

	this->name = name;
	type = "Blue Men";
	atkDies = 2;
	atkSides = 10;
	defDies = 3;
	defSides = 6;
	armor = 3;
	strength = maxStr = 12;
}

/*
* attack function of the BlueMen class. Rolls a number of dice based on the
* number of attack dies and the number of sides of each dice. Returns the total
* of the rolls.
*/
int BlueMen::attack() {

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
* defend function of the BlueMen class. Takes an integer as an argument for the
* attack roll of the opponent, used for calculating damage taken. Rolls a number of
* dice based on the number of defense dies and the sides of each dice. Then,
* calculates the total damage taken based on the attack roll and defense roll and 
* armor of the bluemen, and subtracts it from the bluemen's strength. Finally, checks
* if the bluemen has taken enough damage to activate it's special ability Mob, and if
* so subtracts 1 from the bluemen's number of defense dies.
*/
int BlueMen::defend(int& attackRoll) {

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
		// Otherwise simply subtract damage taken and record it in the damage counter.
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

	// Check for Blue Men's special ability.
	if (strength > 0) {

		if (strength <= 8 && defDies > 2) {

			defDies--;

			/*cout << "\n***" << name << "'s special ability MOB activated:\n"
				<< name << " loses 1 defense die! (" << defDies << ")\n\n";*/
		}

		if (strength <= 4 && defDies > 1) {

			defDies--;

			/*cout << "\n***" << name << "'s special ability MOB activated:\n"
				<< name << " loses 1 defense die! (" << defDies << ")\n\n";*/
		}
	}

	return dmgTaken;
}

/*
* Overridden recover function, same as the other characters but checks if 
* Blue Men's special ability activates to add defense dies back.
*/
void BlueMen::recover(int dmgTaken) {

	cout << "The winner recovers some of the damage taken...";

	// Check if full strength, regardless of damage taken.
	if (strength == maxStr) {

		cout << "\nBut " << name << " is already at full strength!\n";
	}
	// Check if Blue Men did not take any damage.
	else if (dmgTaken == 0) {

		cout << "\nBut " << name << " did not take any damage!\n";
	}
	// Otherwise, if the Blue Men took damage and is not at full strength
	else if (dmgTaken >= 1) {

		// Get a recovery amount equal to half the damage taken 
		// during the round (rounded down).
		int recoveryAmt = dmgTaken * 0.5;

		// Make sure they recover at least 1 point of strength.
		if (recoveryAmt == 0) {

			recoveryAmt = 1;
		}

		cout << "\nDamage taken: " << dmgTaken
			<< "\nEnding strength: " << strength << "\n";

		// Add the recovery amount to the character's strength.
		this->strength += recoveryAmt;

		cout << "\n" << name << " has recovered for "
			<< recoveryAmt << " strength points!\n"
			<< "New strength: " << strength << "\n";
	}

	// Check for Blue Men's special ability.
	if (strength > 4 && defDies <= 1) {

		defDies++;

		/*cout << "\n***" << name << "'s special ability MOB activated:\n"
			<< name << " gains 1 defense die! (" << defDies << ")\n\n";*/
	}

	if (strength > 8 && defDies <= 2) {

		defDies++;

		/*cout << "\n***" << name << "'s special ability MOB activated:\n"
			<< name << " gains 1 defense die! (" << defDies << ")\n\n";*/
	}
}