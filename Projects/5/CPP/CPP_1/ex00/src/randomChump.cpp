#include "Zombie.hpp"

void randomChump( std::string name ) {
	Zombie created = Zombie(name);
	created.announce();
}