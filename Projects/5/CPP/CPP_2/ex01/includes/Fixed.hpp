#ifndef __FIXED_HPP__
#define __FIXED_HPP__
#include <iostream>
#include <cmath>

class Fixed {
	private:
		int					_raw;
		static const int 	_fBits = 8;

	public:
		Fixed() : _raw(0) {
			std::cout << "Default  constructor called" << std::endl;
		}
		Fixed(const int raw) : _raw(raw * 256) {
			std::cout << "Int constructor called" << std::endl;
		}
		Fixed(const float raw) : _raw(roundf(raw * 256)) {
			std::cout << "Float constructor called" << std::endl;
		}
		Fixed(const Fixed& other);
		Fixed& operator=(Fixed const& rhs);
		


		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
		float	toFloat( void ) const;
		int		toInt( void ) const;

		~Fixed() {
			std::cout << "Destructor called" << std::endl;
		}
};

std::ostream& operator<<(std::ostream& os, Fixed const& obj) {
	os << obj.toFloat();
	return os;
}

#endif