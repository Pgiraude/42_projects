#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
	public:
		Fixed(void);
		Fixed(Fixed &copy);
		~Fixed(void);

		int getRawBits(void) const;
		void setRawBits(int const raw);

		Fixed	&operator=(Fixed const &rhs);

	private:
		int                 _number;
		const static int	_fractional = 8;
};

#endif