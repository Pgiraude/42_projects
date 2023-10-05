#include "Dog.hpp"

Dog::Dog(void) : AAnimal("Dog")
{
	std::cout << "Dog VOID constructor called" << std::endl;
	_brain = new Brain;
}


Dog::Dog(Dog const &copy) : AAnimal(copy)
{
	std::cout << "Dog of type " << this->_type << " COPY constructor called" << std::endl;
	this->_brain = new Brain(*copy._brain);
}

Dog::~Dog(void)
{
	delete _brain;
	std::cout << "Dog of type " << this->_type << " DESTRUCTOR called" << std::endl;
}

Dog   &Dog::operator=(Dog const &rhs)
{
	std::cout << "Dog of type " << this->_type << " COPY '=' assignement '=' called" << std::endl;
	if (this != &rhs)
	{
		this->_type = rhs._type;
		if (this->_brain != NULL)
			delete this->_brain;
		this->_brain = new Brain(*rhs._brain);
	}
	return (*this);
}

void	Dog::makeSound(void) const
{
	std::cout << this->_type << " WOUF!!" << std::endl;
}

std::string Dog::getIdeas(int pos)
{
	if (pos >= 100)
	{
		std::cout << this->_type << " brain is too small to have more than 100 ideas" << std::endl;
		return ("");
	}
    return (this->_brain->getIdeas(pos));
}

void    Dog::setIdeas(std::string ideas ,int pos)
{
	this->_brain->setIdeas(ideas, pos);
}

std::ostream	&operator<<(std::ostream &out, const Dog &i)
{
	out << "Dog of type " << i.getType() << " making this noise :" << std::endl;
	i.makeSound();
	return (out);
}