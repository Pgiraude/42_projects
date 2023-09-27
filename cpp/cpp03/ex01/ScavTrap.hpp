#ifndef SCAVTRAP
#define SCAVTRAP

#include "ClapTrap.hpp"
#include <iostream>
#include <cmath>

class ScavTrap : public ClapTrap
{       
    public:
        ScavTrap(void);
        ScavTrap(std::string name);
        ScavTrap(ScavTrap const &copy);


        const static int max_health = 100;
        const static int max_energy = 50;

    private:
        std::string _name;
};

std::ostream    &operator<<(std::ostream &out, const ClapTrap &i);


#endif