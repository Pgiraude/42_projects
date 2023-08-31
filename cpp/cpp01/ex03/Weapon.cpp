#include "Weapon.hpp"

Weapon::Weapon (std::string type) : _type(type)
{
    std::cout << "Weapon " << this->_type << std::endl;
}

Weapon::~Weapon (void)
{
    std::cout << "Weapon destructor" << std::endl;
}

void    Weapon::setType(std::string new_type)
{
    this->_type = new_type;
}

std::string const &Weapon::getType(void)
{
    
}
