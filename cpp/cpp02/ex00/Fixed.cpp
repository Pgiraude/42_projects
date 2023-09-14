#include "Fixed.hpp"

Fixed::Fixed(void)
{
    std::cout << "Default constructor is called" << std::endl;
    this->_rawNumber = 0;
}

Fixed::Fixed(Fixed &copy)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = copy;
}

Fixed   &Fixed::operator=(Fixed const &rhs)
{
    std::cout << "Copy assignement operator = called" << std::endl;
    this->_rawNumber = rhs.getRawBits();
    return (*this);
}

Fixed::~Fixed(void)
{
    std::cout << "Destructor is called" << std::endl;
}

int Fixed::getRawBits(void) const
{
    std::cout << "getrawbits member function called" << std::endl;
    return (this->_rawNumber);
}

void    Fixed::setRawBits(int const raw)
{
    std::cout << "setrawbits member function called" << std::endl;
    this->_rawNumber = raw;
}