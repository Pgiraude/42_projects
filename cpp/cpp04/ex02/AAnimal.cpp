#include "AAnimal.hpp"

AAnimal::AAnimal(void) : _type("default")
{
	std::cout << "AAnimal VOID constructor called" << std::endl;
}

AAnimal::AAnimal(std::string type) : _type(type)
{
    if (type.empty())
	{
        this->_type = "default";
	}
	std::cout << "AAnimal of type " << this->_type << " TYPE constructor called" << std::endl;
}


AAnimal::AAnimal(AAnimal const &copy) : _type(copy._type)
{
	std::cout << "AAnimal of type " << this->_type << " COPY constructor called" << std::endl;
}

AAnimal::~AAnimal(void)
{
	std::cout << "AAnimal of type " << this->_type << " DESTRUCTOR called" << std::endl;
}

AAnimal   &AAnimal::operator=(AAnimal const &rhs)
{
	if (this != &rhs)
	{
		this->_type = rhs._type;
	}
	std::cout << "AAnimal of type " << this->_type << " COPY '=' assignement '=' called" << std::endl;
	return (*this);
}

std::string	AAnimal::getType(void) const
{
	return (this->_type);
}

void	AAnimal::makeSound(void) const
{
	std::cout << "Random sound of animal?!" << std::endl;
}

std::ostream	&operator<<(std::ostream &out, const AAnimal &i)
{
	out << "AAnimal of type " << i.getType() << " making this noise :" << std::endl;
	i.makeSound();
	return (out);
}