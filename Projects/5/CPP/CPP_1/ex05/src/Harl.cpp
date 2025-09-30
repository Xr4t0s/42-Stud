#include "Harl.hpp"

void	Harl::complain( std::string level ) {
	std::string levels[] = { "DEBUG", "INFO", "WARNING", "ERROR" };
	
	void (Harl::*functions[4])(void) = {
		&Harl::_debug,
		&Harl::_info,
		&Harl::_warning,
		&Harl::_error
	};

	for (int i = 0; i < 4; i++) {
		if (level == levels[i]) {
			return (this->*functions[i])();
		}
	}
}

void	Harl::_debug( void ) {
	std::cout << "Hi i'm debugging" << std::endl;
}
void	Harl::_info( void ) {
	std::cout << "Hi i'm giving intels" << std::endl;
}
void	Harl::_warning( void ) {
	std::cout << "Hi i'm warning you" << std::endl;
}
void	Harl::_error( void ) {
	std::cout << "Hi i'm tellings your errors" << std::endl;
}