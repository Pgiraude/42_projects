#include "Cat.hpp"

Cat::Cat(void) : AAnimal("Cat")
{
	std::cout << "Cat VOID constructor called" << std::endl;
	_brain = new Brain;
}

Cat::Cat(Cat const &copy) : AAnimal(copy)
{
	std::cout << "Cat of type " << this->_type << " COPY constructor called" << std::endl;
	this->_brain = new Brain(*copy._brain);
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
		if (this->_brain != NULL)
			delete this->_brain;
		this->_brain = new Brain(*rhs._brain);
	}
	return (*this);
}

void	Cat::makeSound(void) const
{
	std::cout << this->_type << " MEOW!!" << std::endl;
}

std::string Cat::getIdeas(int pos)
{
	if (pos >= 100)
	{
		std::cout << this->_type << " brain is too small to have more than 100 ideas" << std::endl;
		return ("");
	}
    return (this->_brain->getIdeas(pos));
}

void    Cat::setIdeas(std::string ideas ,int pos)
{
	this->_brain->setIdeas(ideas, pos);
}

std::ostream	&operator<<(std::ostream &out, const Cat &i)
{
	out << "Cat of type " << i.getType() << " making this noise :" << std::endl;
	i.makeSound();
	return (out);
}