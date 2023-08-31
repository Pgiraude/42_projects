#include "Weapon.hpp"

Weapon::Weapon (std::string type) : _type(type)
{
    std::cout << "Weapon is " << this->_type << std::endl;
}

Weapon::~Weapon (void)
{
    std::cout << "Weapon destructor of " << this->_type << std::endl;
}

void    Weapon::setType(std::string new_type)
{
    this->_type = new_type;
}

std::string const &Weapon::getType(void)
{
    return (this->_type);
}
