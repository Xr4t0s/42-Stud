#include "Point.hpp"

//////////////////////////////////////////////////////////////////////////////////////////

/* CONSTRUCTEUR */

	// Constructeur par défaut
	Point::Point( void ) : _x(0), _y(0) {
		std::cout << "Default Point constructor called" << std::endl;
	}
	// Constructeur depuis 2 float
	Point::Point( const float x, const float y ) : _x(x), _y(y) {
		std::cout << "Default float Point constructor called" << std::endl;
	}
	// Constructeur de copy
	Point::Point( const Point& rhs ) : _x(rhs._x), _y(rhs._y) {}

/* FIN DES CONSTRUCTEURS */

//////////////////////////////////////////////////////////////////////////////////////////

/* SURCHARGES MEMBRES */

	// Surchage de l'opérateur = 
	Point& Point::operator=( const Point& rhs ) {
		(void)rhs;
		return *this;
	}
	// Surcharge de l'opérateur -
	Point	Point::operator-( Point const sub ) const {
		float	x = this->getFloatX() - sub.getFloatX();
		float	y = this->getFloatY() - sub.getFloatY();
		return Point(x, y);
	}

/* FIN DES SURCHARGES MEMBRES */

//////////////////////////////////////////////////////////////////////////////////////////

/* FONCTION UTILITAIRES */

	// Getter pour _x en flottant
	float	Point::getFloatX( void ) const {
		return this->_x.toFloat();
	}
	// Getter pour _y en flottant
	float	Point::getFloatY( void ) const {
		return this->_y.toFloat();
	}
	// Getter pour _x en entier
	int		Point::getIntX( void ) const {
		return this->_x.toInt();
	}
	// Getter pour _y en entier
	int		Point::getIntY( void ) const {
		return this->_y.toInt();
	}

/* FIN DES FONCTION UTILITAIRES */

//////////////////////////////////////////////////////////////////////////////////////////

/* DESTRUCTEURS */

	// Destructeur par défaut
	Point::~Point() {
			std::cout << "Point destructor called" << std::endl;
	}

/* FIN DES DESTRUCTEURS */

/* FONCTIONS PUBLIQUES */

	// Comparateur X pour le triangle
	bool	minX( Point const a, Point const b) {
		return a.getFloatX() <= b.getFloatX() ? true : false;
	}
	// Comparateur Y pour le triangle
	bool	minY( Point const a, Point const b) {
		return a.getFloatX() >= b.getFloatX() ? true : false;
	}
	// Produits en croix 
	float	cross(Point const& u, Point const& v) {
		return u.getFloatX() * v.getFloatY() - u.getFloatY() * v.getFloatX();
	}

/* FIN DES FONCTIONS PUBLIQUES */

/* SURCHARGES PUBLIQUES */
	// Surcharge de << pour l'affichage
	std::ostream& 	operator<<(std::ostream& os, Point const& obj) {
		return os << "X -> " << obj.getFloatX() << std::endl << "Y -> " << obj.getFloatY() << std::endl; 
	}
/* FIN DES SURCHARGES PUBLIQUES */