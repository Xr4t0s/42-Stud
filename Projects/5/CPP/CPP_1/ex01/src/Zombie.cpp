#include "Zombie.hpp"

Zombie::Zombie() {}

void	Zombie::set_name( std::string name ) {
	_name = name;
}

void	Zombie::announce( void ) {
	std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::~Zombie() {
	std::cout << _name << " just died." << std::endl;
}