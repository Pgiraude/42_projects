#include "Cat.hpp"

Cat::Cat(void) : Animal("Cat")
{
	std::cout << "Cat void constructor called" << std::endl;
}


Cat::Cat(Cat const &copy) : Animal(copy)
{
	std::cout << "Cat " << this->_type << " copy constructor called" << std::endl;
	*this = copy;
}

Cat::~Cat(void)
{
	std::cout << "Cat " << this->_type << " destructor called" << std::endl;
}

Cat   &Cat::operator=(Cat const &rhs)
{
	this->_type = rhs._type;
	std::cout << "Cat " << this->_type << " copy assignement '=' called" << std::endl;
	return (*this);
}

void	Cat::makeSound(void)
{
	std::cout << this->_type << " MEOW!!" << std::endl;
}

std::ostream	&operator<<(std::ostream &out, const Cat &i)
{
	out << "Cat of type " << i.get_type() << " making this noise :" << std::endl;
	return (out);
}