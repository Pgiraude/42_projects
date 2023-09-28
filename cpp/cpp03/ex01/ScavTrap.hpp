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
		~ScavTrap(void);

		std::string	get_name_class(void) const;

	private:
		const static int	max_health = 100;
		const static int	max_energy = 50;
		const static int	attack_dmg = 20;
		std::string         _name_class;
};

std::ostream    &operator<<(std::ostream &out, const ScavTrap &i);


#endif