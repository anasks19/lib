#include "HumanB.hpp"

HumanB::HumanB( const std::string n ) {
	name = n;
	weapon = NULL;
};

void	HumanB::attack( void ) {
	if (!weapon)
		return ;
	std::cout << name;
	std::cout << " attacks with their ";
	std::cout << weapon->getType() << std::endl;
};

void	HumanB::setWeapon( Weapon &w ) {
	weapon = &w;
}