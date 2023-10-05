#include "Animal.hpp"

Animal::Animal(void) : _type("default")
{
	std::cout << "Animal VOID constructor called" << std::endl;
}

Animal::Animal(std::string type) : _type(type)
{
    if (type.empty())
	{
        this->_type = "default";
	}
	std::cout << "Animal of type " << this->_type << " TYPE constructor called" << std::endl;
}


Animal::Animal(Animal const &copy) : _type(copy._type)
{
	std::cout << "Animal of type " << this->_type << " COPY constructor called" << std::endl;
}

Animal::~Animal(void)
{
	std::cout << "Animal of type " << this->_type << " DESTRUCTOR called" << std::endl;
}

Animal   &Animal::operator=(Animal const &rhs)
{
	if (this != &rhs)
	{
		this->_type = rhs._type;
	}
	std::cout << "Animal of type " << this->_type << " COPY '=' assignement '=' called" << std::endl;
	return (*this);
}

std::string	Animal::getType(void) const
{
	return (this->_type);
}

void	Animal::makeSound(void) const
{
	std::cout << "Random sound of animal?!" << std::endl;
}

std::ostream	&operator<<(std::ostream &out, const Animal &i)
{
	out << "Animal of type " << i.getType() << " making this noise :" << std::endl;
	i.makeSound();
	return (out);
}