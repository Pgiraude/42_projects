#include "Zombie.hpp"

void    Zombie::announce(void)
{
    if (this->name.empty())
        std::cout << "<empty>: BraiiiiiiinnnzzzZ..." << std::endl;
    else
        std::cout << this->name << " : BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::Zombie(std::string new_name) : name(new_name)
{
    std::cout << this->name << " is built" << std::endl;
}

Zombie::~Zombie(void)
{
    std::cout << this->name << " is destroy" << std::endl;
}