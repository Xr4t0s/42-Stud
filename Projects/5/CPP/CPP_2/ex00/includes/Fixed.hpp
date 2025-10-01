#include <iostream>

class Fixed {
	private:
		int					_raw;
		static const int 	_fBits = 8;

	public:
		Fixed() : _raw(0) {
			std::cout << "Default  constructor called" << std::endl;
		}
		Fixed(const Fixed& other);
		Fixed& operator=(Fixed const& rhs);
		
		int		getRawBits( void ) const;
		void	setRawBits( int const raw );

		~Fixed() {
			std::cout << "Destructor called" << std::endl;
		}
};