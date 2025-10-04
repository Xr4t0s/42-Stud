#include "Zombie.hpp"

int main() {
	Zombie *horde = zombieHorde(3, "Alicia");
	Zombie *horde2 = zombieHorde(5, "Pouilleux"); 

	for (int i = 0; i < 3; i++) horde[i].announce();
	for (int i = 0; i < 5; i++) horde2[i].announce();

	delete[] horde;
	delete[] horde2;
}