#include "Zombie.hpp"

Zombie* newZombie(std::string name) {
	Zombie* created = new Zombie(name);
	return created;
}