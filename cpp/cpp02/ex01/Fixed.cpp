#include "Fixed.hpp"

Fixed::Fixed(void)
{
	std::cout << "Default constructor called" << std::endl;
	this->_rawNumber = 0;
}

Fixed::Fixed(Fixed const &copy)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = copy;
}

Fixed::Fixed(float const value)
{
	std::cout << "Float constructor called" << std::endl;
	this->_rawNumber = roundf(value * (1 << this->_fractional));
}

Fixed::Fixed(int const value)
{
	this->_rawNumber = value << this->_fractional;
	std::cout << "Int constructor called" << std::endl;
}

Fixed   &Fixed::operator=(Fixed const &rhs)
{
	std::cout << "Copy assignement operator '=' called" << std::endl;
	this->_rawNumber = rhs.getRawBits();
	return (*this);
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor is called" << std::endl;
}

int Fixed::getRawBits(void) const
{
	// std::cout << "getrawbits member function called" << std::endl;
	return (this->_rawNumber);
}

void    Fixed::setRawBits(int const raw)
{
	std::cout << "setrawbits member function called" << std::endl;
	this->_rawNumber = raw;
}

float Fixed::toFloat(void) const
{
	float	value;

	value = this->_rawNumber / (float)(1 << this->_fractional);
	return (value);
}

int Fixed::toInt(void) const
{
	int	nbr;

	nbr = _rawNumber >> _fractional;
	return (nbr);
}

std::ostream    &operator<<(std::ostream &out, Fixed const &i)
{
	out << i.toFloat();
	return out;
}
