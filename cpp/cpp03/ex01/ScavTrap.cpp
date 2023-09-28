#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) : _name("unknown")
{
    _health_pts = this->max_health;
	std::cout << "ScavTrap void constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name)
{
	clap
	 _health_pts(max_health), _energy_pts(max_energy), _attack_dmg(20)
	std::cout << "ScavTrap name constructor called" << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const &copy)
{
	std::cout << "ScavTrap copy constructor called" << std::endl;
	*this = copy;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "ScavTrap destructor called" << std::endl;
}

std::ostream	&operator<<(std::ostream &out, const ScavTrap &i)
{
	out << "ClapTrap " << i.get_name() << " got " << i.get_health();
	out << " health points and " << i.get_energy() << " energy" << std::endl;
	return (out);
}