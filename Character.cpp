/*********************************************************************
** Program name: Fantasy Combat Tournament
** Author: Andrew Swaim
** Date: March 4, 2018
** Description: Character.cpp, implementation file for the Character class.
*********************************************************************/

#include "Character.hpp"

/*
* 
*/
void Character::recover(int dmgTaken) {

	cout << "\nThe winner recovers some of the damage taken...";

	// Check if full strength, regardless of damage taken.
	if (strength == maxStr) {

		cout << "\nBut " << name << " is already at full strength!\n";
	}
	// Check if character did not take any damage.
	else if (dmgTaken == 0) {

		cout << "\nBut " << name << " did not take any damage!\n";
	}
	// Otherwise, if the character took damage and is not at full strength.
	else if (dmgTaken >= 1) {

		// Get a recovery amount equal to half the damage taken 
		// during the round (rounded down).
		int recoveryAmt = dmgTaken * 0.5;

		// Make sure they recover at least 1 point of strength.
		if (recoveryAmt == 0) {

			recoveryAmt = 1;
		}

		// Make sure the recovery amount wouldn't put them over their max strength.
		int missingStr = maxStr - strength;
		if (recoveryAmt > missingStr) {

			recoveryAmt = missingStr;
		}

		cout << "\nDamage taken: " << dmgTaken
			<< "\nEnding strength: " << strength << "\n";

		// Add the recovery amount to the character's strength.
		this->strength += recoveryAmt;

		cout << "\n" << name << " has recovered for "
			<< recoveryAmt << " strength points!\n"
			<< "New strength: " << strength << "\n";
	}
}

// Getters for the Character class.
string Character::getName() { return this->name; }
string Character::getType() { return this->type; }
int Character::getArmor() { return this->armor; }
int Character::getStr() { return this->strength; }