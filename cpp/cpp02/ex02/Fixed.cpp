#include "Fixed.hpp"

Fixed::Fixed(void)
{
	std::cout << "Default constructor called" << std::endl;
	this->_number = 0;
}

Fixed::Fixed(Fixed const &copy)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = copy;
}

Fixed::Fixed(float const value)
{
	std::cout << "Float constructor called" << std::endl;
	this->_number = roundf(value * (1 << this->_fractional));
}

Fixed::Fixed(int const value)
{
	this->_number = value << this->_fractional;
	std::cout << "Int constructor called" << std::endl;
}

Fixed   &Fixed::operator=(Fixed const &rhs)
{
	std::cout << "Copy assignement operator '=' called" << std::endl;
	this->_number = rhs.getRawBits();
	return (*this);
}

Fixed   Fixed::operator+(Fixed const &rhs) const
{
	std::cout << "Addition assignement operator '+' called" << std::endl;
	return (Fixed(this->toFloat() + rhs.toFloat()));
}

void	Fixed::operator++(int)
{
	this->_number = this->_number + (1 << this->_fractional);
}

Fixed   Fixed::operator-(Fixed const &rhs) const
{
	std::cout << "Addition assignement operator '-' called" << std::endl;
	return (Fixed(this->toFloat() - rhs.toFloat()));
}

void	Fixed::operator--(int)
{
	this->_number = this->_number - (1 << this->_fractional);
}

Fixed   Fixed::operator*(Fixed const &rhs) const
{
	std::cout << "Addition assignement operator '*' called" << std::endl;
	return (Fixed(this->toFloat() * rhs.toFloat()));
}

Fixed   Fixed::operator/(Fixed const &rhs) const
{
	std::cout << "Addition assignement operator '/' called" << std::endl;
	return (Fixed(this->toFloat() / rhs.toFloat()));
}

bool	Fixed::operator==(Fixed const &rhs) const
{
	std::cout << "Addition assignement operator '==' called" << std::endl;
	return (this->_number == rhs._number);
}

bool	Fixed::operator<(Fixed const &rhs) const
{
	std::cout << "Addition assignement operator '<' called" << std::endl;
	return (this->_number < rhs._number);
}

bool	Fixed::operator>(Fixed const &rhs) const
{
	std::cout << "Addition assignement operator '>' called" << std::endl;
	return (this->_number > rhs._number);
}

bool	Fixed::operator<=(Fixed const &rhs) const
{
	std::cout << "Addition assignement operator '<=' called" << std::endl;
	return (this->_number <= rhs._number);
}

bool	Fixed::operator>=(Fixed const &rhs) const
{
	std::cout << "Addition assignement operator '>=' called" << std::endl;
	return (this->_number >= rhs._number);
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor is called" << std::endl;
}

int Fixed::getRawBits(void) const
{
	// std::cout << "getrawbits member function called" << std::endl;
	return (this->_number);
}

void    Fixed::setRawBits(int const raw)
{
	std::cout << "setrawbits member function called" << std::endl;
	this->_number = raw;
}

float Fixed::toFloat(void) const
{
	float	value;

	value = this->_number / (float)(1 << this->_fractional);
	return (value);
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
