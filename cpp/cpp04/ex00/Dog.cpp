#include "Dog.hpp"

Dog::Dog(void) : Animal("Dog")
{
	std::cout << "Dog VOID constructor called" << std::endl;
}


Dog::Dog(Dog const &copy) : Animal(copy)
{
	std::cout << "Dog of type " << this->_type << " COPY constructor called" << std::endl;
}

Dog::~Dog(void)
{
	std::cout << "Dog of type " << this->_type << " DESTRUCTOR called" << std::endl;
}

Dog   &Dog::operator=(Dog const &rhs)
{
	if (this != &rhs)
	{
		this->_type = rhs._type;
	}
	std::cout << "Dog of type " << this->_type << " COPY '=' assignement '=' called" << std::endl;
	return (*this);
}

void	Dog::makeSound(void) const
{
	std::cout << this->_type << " WOUF!!" << std::endl;
}

std::ostream	&operator<<(std::ostream &out, const Dog &i)
{
	out << "Dog of type " << i.getType() << " making this noise :" << std::endl;
	i.makeSound();
	return (out);
}