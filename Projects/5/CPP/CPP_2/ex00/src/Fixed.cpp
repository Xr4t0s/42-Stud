#include "Fixed.hpp"

Fixed::Fixed( void ) : _raw(0) {
	std::cout << "Default  constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other) {
	std::cout << "Copy constructor called" << std::endl;
	_raw = other._raw;
}

Fixed&	Fixed::operator=(Fixed const& rhs) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &rhs)
	    this->_raw = rhs._raw;
	return *this;
}

int		Fixed::getRawBits( void ) const {
	std::cout << "getRawBits member function called" << std::endl;
	return this->_raw;
}

void	Fixed::setRawBits( int const raw ) {
	this->_raw = raw;
}

Fixed::~Fixed() {
	std::cout << "Default  constructor called" << std::endl;
}
