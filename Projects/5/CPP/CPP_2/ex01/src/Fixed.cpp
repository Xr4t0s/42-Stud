#include "Fixed.hpp"

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

float	Fixed::toFloat( void ) const {
	return _raw / 256.f;
}

int		Fixed::toInt( void ) const {
	return _raw >> 8;
}