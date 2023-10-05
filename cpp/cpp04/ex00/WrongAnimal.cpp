#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void) : _type("default")
{
	std::cout << "WrongAnimal VOID constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(std::string type) : _type(type)
{
    if (type.empty())
	{
        this->_type = "default";
	}
	std::cout << "WrongAnimal " << this->_type << " TYPE constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal const &copy) : _type(copy._type)
{
	std::cout << "WrongAnimal " << this->_type << " COPY constructor called" << std::endl;
	*this = copy;
}

WrongAnimal::~WrongAnimal(void)
{
	std::cout << "WrongAnimal " << this->_type << " DESTRUCTOR called" << std::endl;
}

WrongAnimal   &WrongAnimal::operator=(WrongAnimal const &rhs)
{
	if (this != &rhs)
	{
		this->_type = rhs._type;
	}
	std::cout << "WrongAnimal " << this->_type << " COPY '=' assignement '=' called" << std::endl;
	return (*this);
}

void	WrongAnimal::makeSound(void) const
{
	std::cout << "Random sound of WRONGAnimal?!" << std::endl;
}

std::string	WrongAnimal::getType(void) const
{
	return (this->_type);
}

std::ostream	&operator<<(std::ostream &out, const WrongAnimal &i)
{
	out << "WrongAnimal of type " << i.getType() << " making this noise :" << std::endl;
	i.makeSound();
	return (out);
}