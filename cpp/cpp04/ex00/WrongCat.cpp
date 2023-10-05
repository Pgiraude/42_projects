#include "WrongCat.hpp"

WrongCat::WrongCat(void) : WrongAnimal("WrongCat")
{
	std::cout << "WrongCat void constructor called" << std::endl;
}


WrongCat::WrongCat(WrongCat const &copy) : WrongAnimal(copy)
{
	std::cout << "WrongCat " << this->_type << " copy constructor called" << std::endl;
	*this = copy;
}

WrongCat::~WrongCat(void)
{
	std::cout << "WrongCat " << this->_type << " destructor called" << std::endl;
}

WrongCat   &WrongCat::operator=(WrongCat const &rhs)
{
	this->_type = rhs._type;
	std::cout << "WrongCat " << this->_type << " copy assignement '=' called" << std::endl;
	return (*this);
}

void	WrongCat::makeSound(void)
{
	std::cout << this->_type << " MEOW!!" << std::endl;
}

std::ostream	&operator<<(std::ostream &out, const WrongCat &i)
{
	out << "WrongCat of type " << i.get_type() << " making this noise :" << std::endl;
	return (out);
}