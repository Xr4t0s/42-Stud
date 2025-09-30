#ifndef __HARL_H__
#define __HARL_H__
#include <iostream>

class Harl {
	private:
		void	_debug( void );
		void	_info( void );
		void	_warning( void );
		void	_error( void );
	
	public:
		Harl() {};
		void	complain( std::string level );
		~Harl() {};
};

#endif