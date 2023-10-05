#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void) : _type("default")
{
	std::cout << "WrongAnimal void constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(std::string type) : _type(type)
{
    if (type.empty())
        this->_type = "default";
	std::cout << "WrongAnimal " << this->_type << " constructor called" << std::endl;
}


WrongAnimal::WrongAnimal(WrongAnimal const &copy)
{
	std::cout << "WrongAnimal " << this->_type << " copy constructor called" << std::endl;
	*this = copy;
}

WrongAnimal::~WrongAnimal(void)
{
	std::cout << "WrongAnimal " << this->_type << " destructor called" << std::endl;
}

WrongAnimal   &WrongAnimal::operator=(WrongAnimal const &rhs)
{
	this->_type = rhs._type;
	std::cout << "WrongAnimal " << this->_type << " copy assignement '=' called" << std::endl;
	return (*this);
}

void	WrongAnimal::makeSound(void)
{
	std::cout << "Random sound of WrongAnimal?!" << std::endl;
}

std::ostream	&operator<<(std::ostream &out, const WrongAnimal &i)
{
	out << "WrongAnimal of type " << i.get_type() << " making this noise :" << std::endl;
	return (out);
}