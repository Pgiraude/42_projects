#include "Animal.hpp"

Animal::Animal(void) : _type("default")
{
	std::cout << "Animal void constructor called" << std::endl;
}

Animal::Animal(std::string type) : _type(type)
{
    if (type.empty())
        this->_type = "default";
	std::cout << "Animal " << this->_type << " constructor called" << std::endl;
}


Animal::Animal(Animal const &copy)
{
	std::cout << "Animal " << this->_type << " copy constructor called" << std::endl;
	*this = copy;
}

Animal::~Animal(void)
{
	std::cout << "Animal " << this->_type << " destructor called" << std::endl;
}

Animal   &Animal::operator=(Animal const &rhs)
{
	this->_type = rhs._type;
	std::cout << "Animal " << this->_type << " copy assignement '=' called" << std::endl;
	return (*this);
}

void	Animal::makeSound(void)
{
	std::cout << "Random sound of animal?!" << std::endl;
}

std::ostream	&operator<<(std::ostream &out, const Animal &i)
{
	out << "Animal of type " << i.get_type() << " making this noise :" << std::endl;
	return (out);
}