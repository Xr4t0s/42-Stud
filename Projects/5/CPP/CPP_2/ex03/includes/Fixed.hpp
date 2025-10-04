#ifndef __FIXED_HPP__
#define __FIXED_HPP__
#include <iostream>

class Fixed {
	private:
		int					_raw;
		static const int 	_fBits = 8;
	public:
		Fixed();
		Fixed(const int raw);
		Fixed(const float raw); 
		Fixed(const Fixed& other);

		Fixed&	operator=(Fixed const& rhs);		
		
		Fixed 	operator+(const Fixed& rhs) const;
		Fixed 	operator-(const Fixed& rhs) const;
		Fixed 	operator*(const Fixed& rhs) const;
		Fixed 	operator/(const Fixed& rhs) const;
		Fixed&	operator++();
		Fixed&	operator--();
		Fixed 	operator++(int);
		Fixed 	operator--(int);
		
		bool	operator<(const Fixed& rhs) const;
		bool	operator>(const Fixed& rhs) const;
		bool	operator<=(const Fixed& rhs) const;
		bool	operator>=(const Fixed& rhs) const;
		bool	operator==(const Fixed& rhs) const;
		bool	operator!=(const Fixed& rhs) const;

		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
		int		toInt( void ) const;
		float	toFloat( void ) const;

		static Fixed&	min(Fixed& a, Fixed& b);
		static Fixed&	max(Fixed& a, Fixed& b);
		static const	Fixed&	min(const Fixed& a, const Fixed& b);
		static const	Fixed&	max(const Fixed& a, const Fixed& b);

		~Fixed();
};

std::ostream& operator<<(std::ostream& os, Fixed const& obj);


#endif