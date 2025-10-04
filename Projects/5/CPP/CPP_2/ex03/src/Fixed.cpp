#include "Fixed.hpp"
#include <cmath>

//////////////////////////////////////////////////////////////////////////////////////////

/* CONSTRUCTEUR */

	// Constructeur par défaut
	Fixed::Fixed() : _raw(0) {
		// std::cout << "Default  constructor called" << std::endl;
	}
	// Constructeur depuis un int
	Fixed::Fixed(const int raw) : _raw(raw * 256) {
		// std::cout << "Int constructor called" << std::endl;
	}
	// Constructeur depuis un float
	Fixed::Fixed(const float raw) : _raw(roundf(raw * 256)) {
		// std::cout << "Float constructor called" << std::endl;
	}
	// Constructeur depuis une classe Fixed
	Fixed::Fixed(const Fixed& other) {
		// std::cout << "Copy constructor called" << std::endl;
		*this = other;
	}

/* FIN DES CONSTRUCTEURS */

//////////////////////////////////////////////////////////////////////////////////////////

/* SURCHARGES MEMBRES DE FIXED */

	// Surcharge de l'opérateur = pour l'assignation de copie
	Fixed&	Fixed::operator=(Fixed const& rhs) {
		// std::cout << "Copy assignment operator called" << std::endl;
		if (this != &rhs)
			this->_raw = rhs._raw;
		return *this;
	}
	
	/* Surcharges des opérateurs arithmétiques */
		// Surcharge de l'opérateur +
		Fixed Fixed::operator+(const Fixed& rhs) const {
			Fixed	ret;

			ret.setRawBits(this->_raw + rhs._raw);
			return ret;
		}
		// Surcharge de l'opérateur -
		Fixed Fixed::operator-(const Fixed& rhs) const {
			Fixed	ret;

			ret.setRawBits(this->_raw - rhs._raw);
			return ret;
		}
		// Surcharge de l'opérateur *
		Fixed Fixed::operator*(const Fixed& rhs) const {
			Fixed	ret;

			ret.setRawBits((this->_raw * rhs._raw) >> _fBits);
			return ret;
		}
		// Surcharge de l'opérateur /
		Fixed Fixed::operator/(const Fixed& rhs) const {
			Fixed	ret;
			if (rhs._raw != 0)
				ret.setRawBits((this->_raw  << _fBits) / rhs._raw);
			else
				ret.setRawBits(1 << _fBits);
			return ret;
		}
		// Surcharge de l'opérateur ()++
		Fixed& Fixed::operator++() {
			this->_raw += 1;
			return *this;
		}
		// Surcharge de l'opérateur ()--
		Fixed& Fixed::operator--() {
			this->_raw -= 1;
			return *this;
		}
		// Surcharge de l'opérateur ++()
		Fixed Fixed::operator++(int) {
			Fixed ret(*this);
			this->_raw += 1;
			return ret;
		}
		// Surcharge de l'opérateur --()
		Fixed Fixed::operator--(int) {
			Fixed ret(*this);
			this->_raw -= 1;
			return ret;
		}
	/* Fin de surcharges des opérateurs arithmétiques */

	/* Surcharges des opérateurs de comparaisons */
		// Surcharge de l'opérateur <
		bool	Fixed::operator<(const Fixed& rhs) const {
			return this->_raw < rhs._raw;
		}
		// Surcharge de l'opérateur >
		bool	Fixed::operator>(const Fixed& rhs) const {
			return this->_raw > rhs._raw;
		}
		// Surcharge de l'opérateur <=
		bool	Fixed::operator<=(const Fixed& rhs) const {
			return this->_raw <= rhs._raw;
		}
		// Surcharge de l'opérateur >=
		bool	Fixed::operator>=(const Fixed& rhs) const {
			return this->_raw >= rhs._raw;
		}
		// Surcharge de l'opérateur ==
		bool	Fixed::operator==(const Fixed& rhs) const {
			return this->_raw == rhs._raw;
		}
		// Surcharge de l'opérateur !=
		bool	Fixed::operator!=(const Fixed& rhs) const {
			return this->_raw != rhs._raw;
		}
	/* Fin des surcharges des opérateurs de comparaisons */

/* FIN DES SURCHARGES MEMBRES DE FIXED */

//////////////////////////////////////////////////////////////////////////////////////////

/* FONCTION UTILITAIRES */

	/* Fonctions publiques min/max */
		// Fonction min avec une classe non constante
		Fixed&	Fixed::min(Fixed& a, Fixed& b) {
			return (a < b) ? a : b;
		}
		// Fonction min avec une classe constante
		const Fixed&	Fixed::min(const Fixed& a, const Fixed& b) {
			return (a < b) ? a : b;
		}
		// Fonction max avec une classe non constante
		Fixed&	Fixed::max(Fixed& a, Fixed& b) {
			return (a > b) ? a : b;
		}
		// Fonction max avec une classe constante
		const Fixed&	Fixed::max(const Fixed& a, const Fixed& b) {
			return (a > b) ? a : b;
		}
	/* Fin des fonctions publiques min/max */

	// Renvoie _raw en bits
	int		Fixed::getRawBits( void ) const {
		// std::cout << "getRawBits member function called" << std::endl;
		return this->_raw;
	}
	// Assigne une valeur en bits à _raw
	void	Fixed::setRawBits( int const raw ) {
		this->_raw = raw;
	}
	// Renvoie _raw en flottant
	float	Fixed::toFloat( void ) const {
		return _raw / 256.f;
	}
	// Renvoie _raw en entier
	int		Fixed::toInt( void ) const {
		return _raw >> _fBits;
	}

/* FIN DES FONCTION UTILITAIRES */

//////////////////////////////////////////////////////////////////////////////////////////

/* DESTRUCTEURS */

	// Destructeur par défaut
	Fixed::~Fixed() {
		// std::cout << "Destructor called" << std::endl;
	}

/* FIN DES DESTRUCTEURS */

//////////////////////////////////////////////////////////////////////////////////////////

/* SURCHARGES PUBLIQUES */

	// Surcharge de l'opérateur << pour afficher correctement la sortie lors de ...<< a <<...
	std::ostream& operator<<(std::ostream& os, Fixed const& obj) {
		os << obj.toFloat();
		return os;
	}

/* FIN DES SURCHARGES PUBLIQUES */