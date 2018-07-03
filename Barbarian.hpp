/*********************************************************************
** Program name: Fantasy Combat Tournament
** Author: Andrew Swaim
** Date: March 4, 2018
** Description: Barbarian.hpp, specification file for the Barbarian class.
*********************************************************************/

#ifndef BARBARIAN_HPP
#define BARBARIAN_HPP

#include "Character.hpp"

class Barbarian : public Character {

public:
	Barbarian(string);
	int attack();
	int defend(int&);
};

#endif // !BARBARIAN_HPP
