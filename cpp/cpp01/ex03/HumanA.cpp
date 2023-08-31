#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) : _name(name), _weapon(&weapon)
{
    std::cout << "humanA name " << this->_name << std::endl;

    std::cout << "humanA weapon " << this->_weapon->getType() << std::endl;
}

HumanA::~HumanA(void)
{
    std::cout << "HumanA destructor" << std::endl;
}

void    HumanA::attack(void)
{
    std::cout << "HumanA attack whit " << this->_weapon->getType() << std::endl;
}