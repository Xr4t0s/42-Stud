#include <iostream>

class Zombie
{
	private:
		std::string _name;
	public:
		Zombie(std::string name) : _name(name) {}

		void	announce( void ) {
			std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
		}

		~Zombie() {
			std::cout << _name << " just died." << std::endl;
		}
};

Zombie*	newZombie(std::string name);
void	randomChump( std::string name );
void	run( void );