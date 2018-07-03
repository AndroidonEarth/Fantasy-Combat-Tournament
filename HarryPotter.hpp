/*********************************************************************
** Program name: Fantasy Combat Tournament
** Author: Andrew Swaim
** Date: March 4, 2018
** Description: HarryPotter.hpp, specification file for the HarryPotter
		class.
*********************************************************************/

#ifndef HARRY_POTTER_HPP
#define HARRY_POTTER_HPP

#include "Character.hpp"

class HarryPotter : public Character {

private:
	bool hasDied;

public:
	HarryPotter(string);
	int attack();
	int defend(int&);
};

#endif // !HARRY_POTTER_HPP
