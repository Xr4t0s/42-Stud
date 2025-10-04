#include <iostream>

class Fixed {
	private:
		int					_raw;
		static const int 	_fBits = 8;

	public:
		Fixed( void );
		Fixed(const Fixed& other);
		Fixed& operator=(Fixed const& rhs);
		
		int		getRawBits( void ) const;
		void	setRawBits( int const raw );

		~Fixed();
};