#include <iostream>

class Fixed {
	private:
		int					_raw;
		static const int	_fBits = 8;

	public:
		Fixed() {
			_raw = 0;
		}
		Fixed(Fixed& copy) {
			_raw = copy._raw;
		}
		
		
		~Fixed() {}
};