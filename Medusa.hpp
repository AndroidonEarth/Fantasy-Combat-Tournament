/*********************************************************************
** Program name: Fantasy Combat Tournament
** Author: Andrew Swaim
** Date: March 4, 2018
** Description: Medusa.hpp, specification file for the Medusa class.
*********************************************************************/

#ifndef MEDUSA_HPP
#define MEDUSA_HPP

#include "Character.hpp"

class Medusa : public Character {

public:
	Medusa(string);
	int attack();
	int defend(int&);
};

#endif // !MEDUSA_HPP