#include "Fixed.hpp"

//-------- constructors and destructor ---------- 

Fixed::Fixed(void)
{
	// std::cout << "Default constructor called" << std::endl;
	this->_rawNumber = 0;
}

Fixed::Fixed(Fixed const &copy)
{
	// std::cout << "Copy constructor called" << std::endl;
	*this = copy;
}

Fixed::Fixed(float const value)
{
	// std::cout << "Float constructor called" << std::endl;
	this->_rawNumber = roundf(value * (1 << this->_fractional));
}

Fixed::Fixed(int const value)
{
	// std::cout << "Int constructor called" << std::endl;
	this->_rawNumber = value << this->_fractional;
}

Fixed::~Fixed(void)
{
	// std::cout << "Destructor is called" << std::endl;
}

//---- '=' '+' '-' '*' '/' ---------- 

Fixed   &Fixed::operator=(Fixed const &rhs)
{
	// std::cout << "Copy assignement operator '=' called" << std::endl;
	this->_rawNumber = rhs.getRawBits();
	return (*this);
}

Fixed   Fixed::operator+(Fixed const &rhs) const
{
	// std::cout << "Addition assignement operator '+' called" << std::endl;
	return (Fixed(this->toFloat() + rhs.toFloat()));
}

Fixed   Fixed::operator-(Fixed const &rhs) const
{
	// std::cout << "Substraction assignement operator '-' called" << std::endl;
	return (Fixed(this->toFloat() - rhs.toFloat()));
}

Fixed   Fixed::operator*(Fixed const &rhs) const
{
	// std::cout << "Multiplication assignement operator '*' called" << std::endl;
	return (Fixed(this->toFloat() * rhs.toFloat()));
}

Fixed   Fixed::operator/(Fixed const &rhs) const
{
	// std::cout << "Division assignement operator '/' called" << std::endl;
	return (Fixed(this->toFloat() / rhs.toFloat()));
}

//-------- operators '++' '--' ----------

Fixed	Fixed::operator++(int)
{
	Fixed	tmp(*this);

	// std::cout << "Foreword incrementation operator '++' called" << std::endl;
	this->_rawNumber += (1 << this->_fractional);
	return (tmp);
}

Fixed	Fixed::operator++()
{
	// std::cout << "Backward incrementation operator '++' called" << std::endl;
	this->_rawNumber += (1 << this->_fractional);
	return (*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed	tmp(*this);

	// std::cout << "Foreword decrementation operator '--' called" << std::endl;
	this->_rawNumber -= (1 << this->_fractional);
	return (tmp);
}

Fixed	Fixed::operator--()
{
	// std::cout << "Backward decrementation operator '--' called" << std::endl;
	this->_rawNumber -= (1 << this->_fractional);
	return (*this);
}

//-------- operators '==' '!=' '<=' '>=''<' '>' ---------- 

bool	Fixed::operator==(Fixed const &rhs) const
{
	// std::cout << "Operator equal to '==' called" << std::endl;
	return (this->_rawNumber == rhs._rawNumber);
}

bool	Fixed::operator!=(Fixed const &rhs) const
{
	// std::cout << "Operator not equal to '!=' called" << std::endl;
	return (this->_rawNumber != rhs._rawNumber);
}

bool	Fixed::operator<(Fixed const &rhs) const
{
	// std::cout << "Operator less than '<' called" << std::endl;
	return (this->_rawNumber < rhs._rawNumber);
}

bool	Fixed::operator>(Fixed const &rhs) const
{
	// std::cout << "Operator more than '>' called" << std::endl;
	return (this->_rawNumber > rhs._rawNumber);
}

bool	Fixed::operator<=(Fixed const &rhs) const
{
	// std::cout << "Operator less or equal than '<=' called" << std::endl;
	return (this->_rawNumber <= rhs._rawNumber);
}

bool	Fixed::operator>=(Fixed const &rhs) const
{
	// std::cout << "Operator more or equal than '>=' called" << std::endl;
	return (this->_rawNumber >= rhs._rawNumber);
}

//-------- max and min ---------- 

Fixed	&Fixed::min(Fixed &A, Fixed &B)
{
	if (A < B)
		return (A);
	else
		return (B);
}

Fixed const	&Fixed::min(Fixed const &A, Fixed const &B)
{
	if (A < B)
		return (A);
	else
		return (B);
}

Fixed	&Fixed::max(Fixed &A, Fixed &B)
{
	if (A > B)
		return (A);
	else
		return (B);
}

Fixed const	&Fixed::max(Fixed const &A, Fixed const &B)
{
	if (A > B)
		return (A);
	else
		return (B);
}

//-------- get and set rawbits ---------- 

int Fixed::getRawBits(void) const
{
	// std::cout << "getrawbits member function called" << std::endl;
	return (this->_rawNumber);
}

void    Fixed::setRawBits(int const raw)
{
	// std::cout << "setrawbits member function called" << std::endl;
	this->_rawNumber = raw;
}

//-------- convert number to float/to int ---------- 

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

//-------- print number to float ---------- 

std::ostream    &operator<<(std::ostream &out, Fixed const &i)
{
	out << i.toFloat();
	return out;
}
