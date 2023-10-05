#include "WrongCat.hpp"

WrongCat::WrongCat(void) : WrongAnimal("WrongCat")
{
	std::cout << "WrongCat VOID constructor called" << std::endl;
}


WrongCat::WrongCat(WrongCat const &copy) : WrongAnimal(copy)
{
	std::cout << "WrongCat of type " << this->_type << " COPY constructor called" << std::endl;
	*this = copy;
}

WrongCat::~WrongCat(void)
{
	std::cout << "WrongCat of type " << this->_type << " DESTRUCTOR called" << std::endl;
}

WrongCat   &WrongCat::operator=(WrongCat const &rhs)
{
	if (this != &rhs)
	{
		this->_type = rhs._type;
	}
	std::cout << "WrongCat of type " << this->_type << " COPY assignement '=' called" << std::endl;
	return (*this);
}

void	WrongCat::makeSound(void) const
{
	std::cout << this->_type << " MEOW!!" << std::endl;
}

std::ostream	&operator<<(std::ostream &out, const WrongCat &i)
{
	out << "WrongCat of type " << i.getType() << " making this noise :" << std::endl;
	i.makeSound();
	return (out);
}