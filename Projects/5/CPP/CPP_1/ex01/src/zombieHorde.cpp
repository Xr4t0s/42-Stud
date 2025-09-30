#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name ) {
	Zombie* horde = new Zombie[N];
	for (int i = 0; i < N - 1; i++) {
		horde[i].set_name(name);
	}
	horde[N - 1].set_name("Spécial");
	return horde;
}