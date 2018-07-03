/*********************************************************************
** Program name: Fantasy Combat Tournament
** Author: Andrew Swaim
** Date: March 4, 2018
** Description: Character.hpp, specification file for the Character class.
*********************************************************************/

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <iostream>
#include <cstdlib>
#include <string>
using std::cout;
using std::string;

class Character {

protected:
	string type;
	string name;
	int atkDies;
	int atkSides;
	int defDies;
	int defSides;
	int armor;
	int strength;
	int maxStr;

public:
	virtual int attack() = 0;
	virtual int defend(int&) = 0;
	virtual void recover(int);

	string getName();
	string getType();
	int getArmor();
	int getStr();

};

#endif // !CHARACTER_HPP
