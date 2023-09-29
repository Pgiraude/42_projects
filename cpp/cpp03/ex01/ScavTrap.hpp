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

		void attack(const std::string& target);

		std::string	get_name_class(void) const;

	private:
		const static int	_max_health = 100;
		const static int	_max_energy = 50;
		const static int	_set_attack_dmg = 20;
		std::string         _name_class;
};

std::ostream    &operator<<(std::ostream &out, const ScavTrap &i);


#endif