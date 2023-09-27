#ifndef CLAPTRAP
#define CLAPTRAP

#include <iostream>
#include <cmath>

class ClapTrap
{
    public:
        ClapTrap(void);
        ClapTrap(std::string name);
		ClapTrap(ClapTrap const &copy);
		~ClapTrap(void);

        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);

    private:
        std::string _name;
        int         _ealth_pts;
        int         _energy_pts;
        int         _attack_dmg;
    
};

#endif