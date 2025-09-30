#ifndef HUMANB_HPP
#define HUMANB_HPP
#include "Weapon.hpp"

class HumanB {
	private:
		std::string	_name;
		Weapon*		_weapon;

	public:
		HumanB( std::string name ) : _name( name ), _weapon( nullptr ) {}
		
		void	attack( void ) {
			if ( _weapon )
				std::cout << _name << " attacks with their " << _weapon->getType() << std::endl;
			else
				std::cout << _name << " has no weapons! " << std::endl;
		}

		void	setWeapon( Weapon& weapon ) {
			_weapon = &weapon;
		}

		~HumanB() {}
};

void	humanB();

#endif