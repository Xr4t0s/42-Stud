#include "Zombie.hpp"

void	run( void ) {
	Zombie* heap = newZombie("heap");
	
	heap->announce();

	randomChump("stack");

	delete heap;
}