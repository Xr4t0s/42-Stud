#include <iostream>
#ifndef WEAPON_HPP
#define WEAPON_HPP

class Weapon {
	private:
		std::string _type;
	
	public:
		Weapon( std::string type ) : _type(type) {}

		void	setType(std::string newType) {
			_type = newType;
		}

		const std::string&	getType( void ) const {
			return _type;
		}

		~Weapon() {}
};

#endif 