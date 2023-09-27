#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) : _name("unknown")
{
    std::cout << "ClapTrap void constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name)
{
    std::cout << "ClapTrap name constructor called" << std::endl;
}

ClapTrap::~ClapTrap(void)
{
    std::cout << "ClapTrap destructor called" << std::endl;
}



        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
