#include "HumanB.hpp"


HumanB::HumanB(std::string name) : _name(name)
{
    std::cout << "humanB name " << this->_name << std::endl;
}

HumanB::~HumanB(void)
{
    std::cout << "HumanB destructor" << std::endl;
}

void    HumanB::attack(void)
{
    std::cout << "HumanB attack whit " << this->_weapon->getType() << std::endl;
}

void    HumanB::setWeapon(Weapon &weapon)
{
    this->_weapon = &weapon;
    std::cout << "weapon is set : " << this->_weapon->getType() << std::endl;
}