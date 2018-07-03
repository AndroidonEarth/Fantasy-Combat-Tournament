/*********************************************************************
** Program name: Fantasy Combat Tournament
** Author: Andrew Swaim
** Date: March 4, 2018
** Description: Vampire.hpp, specification file for the Vampire class.
*********************************************************************/

#ifndef VAMPIRE_HPP
#define VAMPIRE_HPP

#include "Character.hpp"

class Vampire : public Character {

public:
	Vampire(string);
	int attack();
	int defend(int&);
};

#endif // !VAMPIRE_HPP
