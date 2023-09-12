#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
	public:
		Fixed(void);
		Fixed(Fixed &copy);
		~Fixed(void);
		Fixed(float const &);
		Fixed(int const &);

		int getRawBits(void) const;
		void setRawBits(int const raw);

		Fixed	&operator=(Fixed const &rhs);

		float	toFloat(void) const;
		int		toInt(void) const;

	private:
		int _number;
		const static int	_fractional = 8;
};

std::ostream	&operator<<(std::ostream &out, Fixed const &i);

#endif