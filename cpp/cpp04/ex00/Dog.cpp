#include "Dog.hpp"

Dog::Dog(void) : Animal("Dog")
{
	std::cout << "Dog void constructor called" << std::endl;
}


Dog::Dog(Dog const &copy) : Animal(copy)
{
	std::cout << "Dog " << this->_type << " copy constructor called" << std::endl;
	*this = copy;
}

Dog::~Dog(void)
{
	std::cout << "Dog " << this->_type << " destructor called" << std::endl;
}

Dog   &Dog::operator=(Dog const &rhs)
{
	this->_type = rhs._type;
	std::cout << "Dog " << this->_type << " copy assignement '=' called" << std::endl;
	return (*this);
}

void	Dog::makeSound(void)
{
	std::cout << this->_type << " WOUF!!" << std::endl;
}

std::ostream	&operator<<(std::ostream &out, const Dog &i)
{
	out << "Dog of type " << i.get_type() << " making this noise :" << std::endl;
	return (out);
}