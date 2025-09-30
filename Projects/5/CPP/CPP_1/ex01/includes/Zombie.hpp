#include <iostream>

class Zombie
{
	private:
		std::string _name;
	public:
		Zombie() {}

		void	set_name( std::string name ) {
			_name = name;
		}

		void	announce( void ) {
			std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
		}

		~Zombie() {
			std::cout << _name << " just died." << std::endl;
		}
};

Zombie*	zombieHorde( int N, std::string name );
void	run( void );