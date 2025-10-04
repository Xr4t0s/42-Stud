#include "Fixed.hpp"


Fixed::Fixed() : _raw(0) {
	std::cout << "Default  constructor called" << std::endl;
}

Fixed::Fixed(const int raw) : _raw(raw * 256) {
	std::cout << "Int constructor called" << std::endl;
} 

Fixed::Fixed(const float raw) : _raw(roundf(raw * 256)) {
	std::cout << "Float constructor called" << std::endl;
}


Fixed::Fixed(const Fixed& other) {
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
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

std::ostream& operator<<(std::ostream& os, Fixed const& obj) {
	os << obj.toFloat();
	return os;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}
