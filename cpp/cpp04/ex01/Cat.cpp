#include "Cat.hpp"

Cat::Cat(void) : Animal("Cat")
{
	
	std::cout << "Cat VOID constructor called" << std::endl;
	_brain = new Brain;
}

Cat::Cat(Cat const &copy) : Animal(copy)
{
	std::cout << "Cat of type " << this->_type << " COPY constructor called" << std::endl;
	_brain = copy._brain;
}

Cat::~Cat(void)
{
	delete _brain;
	std::cout << "Cat of type " << this->_type << " DESTRUCTOR called" << std::endl;
}

Cat   &Cat::operator=(Cat const &rhs)
{
	std::cout << "Cat of type " << this->_type << " COPY '=' assignement '=' called" << std::endl;
	if (this != &rhs)
	{
		this->_type = rhs._type;
		this->_brain = new Brain(*rhs._brain);
	}
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