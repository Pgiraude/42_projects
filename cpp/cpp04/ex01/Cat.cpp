#include "Cat.hpp"

Cat::Cat(void) : Animal("Cat")
{
	_brain = new Brain;
	std::cout << "Cat VOID constructor called" << std::endl;
}

Cat::Cat(Cat const &copy) : Animal(copy)
{
	_brain = copy._brain;
	std::cout << "Cat of type " << this->_type << " COPY constructor called" << std::endl;
}

Cat::~Cat(void)
{
	delete _brain;
	std::cout << "Cat of type " << this->_type << " DESTRUCTOR called" << std::endl;
}

Cat   &Cat::operator=(Cat const &rhs)
{
	if (this != &rhs)
	{
		this->_type = rhs._type;
	}
	std::cout << "Cat of type " << this->_type << " COPY '=' assignement '=' called" << std::endl;
	return (*this);
}

void	Cat::makeSound(void) const
{
	std::cout << this->_type << " MEOW!!" << std::endl;
}

std::ostream	&operator<<(std::ostream &out, const Cat &i)
{
	out << "Cat of type " << i.getType() << " making this noise :" << std::endl;
	i.makeSound();
	return (out);
}