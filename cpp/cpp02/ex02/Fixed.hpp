#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
	public:
		Fixed(void);
		Fixed(Fixed const &copy);
		~Fixed(void);
		Fixed(float const);
		Fixed(int const);

		int getRawBits(void) const;
		void setRawBits(int const raw);

		float	toFloat(void) const;
		int		toInt(void) const;

		Fixed	&operator=(Fixed const &rhs);
		Fixed	operator-(Fixed const &rhs) const;
		Fixed	operator+(Fixed const &rhs) const;
		Fixed	operator*(Fixed const &rhs) const;
		Fixed	operator/(Fixed const &rhs) const;

		Fixed	operator++(int);
		Fixed	operator++(void);
		Fixed	operator--(int);
		Fixed	operator--(void);

		bool	operator==(Fixed const &rhs) const;
		bool	operator!=(Fixed const &rhs) const;
		bool	operator<(Fixed const &rhs) const;
		bool	operator>(Fixed const &rhs) const;
		bool	operator<=(Fixed const &rhs) const;
		bool	operator>=(Fixed const &rhs) const;

		Fixed static		&min(Fixed&, Fixed&);
		Fixed static const	&min(Fixed const&, Fixed const&);
		Fixed static		&max(Fixed&, Fixed&);
		Fixed static const	&max(Fixed const&, Fixed const&);

	private:
		int					_rawNumber;
		const static int	_fractional = 8;
};

std::ostream	&operator<<(std::ostream &out, Fixed const &i);

#endif