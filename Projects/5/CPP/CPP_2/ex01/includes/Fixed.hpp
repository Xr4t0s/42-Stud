#ifndef __FIXED_HPP__
#define __FIXED_HPP__
#include <iostream>
#include <cmath>


/// @brief Class Fixed
class Fixed {
	private:
		/// @brief Valeur de la sauvegarde en bits.
		int					_raw;
		/// @brief Facteur de division de bits pour calculer.
		static const int 	_fBits = 8;

	public:
		/// Constructeur par défault, initialise _raw à 0.
		Fixed();
		
		/// Constructeur par défaut d'un int.
		/// @param raw Valeur de l'int d'initialisation.
		Fixed(const int raw);
	
		/// Constructeur par défaut d'un float.
		///@param raw Valeur de le float d'initialisation .
		Fixed(const float raw);

		/// @brief Constructeur d'assignation de copie.
		/// @param other Classe à copier. 
		Fixed(const Fixed& other);

		/// @brief Surcharge de l'opérateur =.
		/// @param rhs Classe Fixed à assigner avec l'overload.
		/// @return Un référence à la classe appliquée.
		Fixed& operator=(Fixed const& rhs);

		/// @brief Renvoie la valeur de la variable _raw.
		/// @return _raw en bits.
		int		getRawBits( void ) const;

		/// @brief Affecte une valeur à la variable _raw.
		/// @param raw Le nouvel int à affecter.
		void	setRawBits( int const raw );

		/// @brief Conversion de _raw en float.
		/// @return Le résultat de la conversion.
		float	toFloat( void ) const;

		/// @brief Conversion de _raw en int.
		/// @return Le résultat de la conversion.
		int		toInt( void ) const;

		/// @brief Destructeur
		~Fixed();
};

std::ostream& operator<<(std::ostream& os, Fixed const& obj);

#endif