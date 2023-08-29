#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon weapon) : _name(name), _weapon(weapon)
{
    std::cout << this->_name << std::endl;
    std::cout << this->_weapon._type << std::endl;
}

HumanA::~HumanA(void)
{
    std::cout << "HumanA destructor" << std::endl;
}