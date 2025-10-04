#include "Zombie.hpp"

Zombie::Zombie(std::string name) : _name(name) {}

void	Zombie::announce( void ) {
	std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::~Zombie() {
	std::cout << _name << " just died." << std::endl;
}

void	run( void ) {
	Zombie* heap = newZombie("heap");
	
	heap->announce();

	randomChump("stack");

	delete heap;
}
