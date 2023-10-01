#ifndef FRAGTRAP
#define FRAGTRAP

#include "ClapTrap.hpp"
#include <iostream>
#include <cmath>

class FragTrap : public ClapTrap
{       
	public:
		FragTrap(void);
		FragTrap(std::string name);
		FragTrap(FragTrap const &copy);
		~FragTrap(void);

		std::string	get_name_class(void) const;

		void	HighFivesGuys(void);


	private:
		const static int	_max_health = 100;
		const static int	_max_energy = 100;
		const static int	_set_attack_dmg = 30;
};

std::ostream    &operator<<(std::ostream &out, const FragTrap &i);


#endif