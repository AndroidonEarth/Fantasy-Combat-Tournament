/*********************************************************************
** Program name: Fantasy Combat Tournament
** Author: Andrew Swaim
** Date: March 4, 2018
** Description: BlueMen.hpp, specification file for the BlueMen class.
*********************************************************************/

#ifndef BLUE_MEN_HPP
#define BLUE_MEN_HPP

#include "Character.hpp"

class BlueMen : public Character {

public:
	BlueMen(string);
	int attack();
	int defend(int&);
	void recover(int);
};

#endif // !BLUE_MEN_HPP
