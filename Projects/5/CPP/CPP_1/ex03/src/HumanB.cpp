#include "HumanB.hpp"

HumanB::HumanB( std::string name ) : _name(name), _weapon(NULL) {}

void	HumanB::attack( void ) {
	if ( _weapon )
		std::cout << _name << " attacks with their " << _weapon->getType() << std::endl;
	else
		std::cout << _name << " has no weapons! " << std::endl;
}

void	HumanB::setWeapon( Weapon& weapon ) {
	_weapon = &weapon;
}

HumanB::~HumanB() {}