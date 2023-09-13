#include "Fixed.hpp"

Fixed::Fixed(void)
{
	std::cout << "Default constructor called" << std::endl;
	this->_number = 0;
}

Fixed::Fixed(Fixed &copy)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = copy;
}

Fixed::Fixed(float const value)
{
	std::cout << "Float constructor called" << std::endl;
	this->_number = roundf(value * (1 << this->_fractional));
	std::cout << "float number = " << this->_number << std::endl;
}

Fixed::Fixed(int const value)
{
	this->_number = value << this->_fractional;
	std::cout << "Int constructor called" << std::endl;
}

Fixed   &Fixed::operator=(Fixed const &rhs)
{
	std::cout << "Copy assignement operator = called" << std::endl;
	this->_number = rhs.getRawBits();
	return (*this);
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor is called" << std::endl;
}

int Fixed::getRawBits(void) const
{
	std::cout << "getrawbits member function called" << std::endl;
	return (this->_number);
}

void    Fixed::setRawBits(int const raw)
{
	std::cout << "setrawbits member function called" << std::endl;
	this->_number = raw;
}

float Fixed::toFloat(void) const
{
	float	test;

	test = this->_number / (float)(1 << this->_fractional);
	return (test);
}

int Fixed::toInt(void) const
{
	int	nbr;

	nbr = _number >> _fractional;
	return (nbr);
}

std::ostream    &operator<<(std::ostream &out, Fixed const &i)
{
	out << i.toFloat();
	return out;
}
