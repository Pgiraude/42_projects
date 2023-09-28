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

        std::string	get_name(void) const;
        int	get_health(void) const;
        int	get_energy(void) const;

        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);

        ClapTrap	&operator=(ClapTrap const &rhs);

    protected:

        const static int    max_health = 10;
        const static int    max_energy = 10;

        int                 _health_pts;
        int                 _energy_pts;
        int                 _attack_dmg;
        std::string         _name;
    
};

std::ostream    &operator<<(std::ostream &out, const ClapTrap &i);


#endif