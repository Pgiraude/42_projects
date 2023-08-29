#include "Zombie.hpp"

void    Zombie::set_name(std::string name)
{
    this->name = name;
}

void    Zombie::announce(void)
{
    if (this->name.empty())
        std::cout << "<unknown>: BraiiiiiiinnnzzzZ..." << std::endl;
    else
        std::cout << this->name << " : BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::Zombie(void)
{
    std::cout << "unknown zommbie is built" << std::endl;
}

Zombie::Zombie(std::string new_name) : name(new_name)
{
    std::cout << this->name << " is built" << std::endl;
}

Zombie::~Zombie(void)
{
    std::cout << this->name << " is destroy" << std::endl;
}