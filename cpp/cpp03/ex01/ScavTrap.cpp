#include "ScavTrap.hpp"
#include "ClapTrap.hpp"

ScavTrap::ScavTrap(void)
{
	this->_health_pts = max_health;
	this->_energy_pts = max_energy;
	this->_attack_dmg = attack_dmg;
	this->_name_class = "ScavTrap";
	std::cout << _name_class << " void constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	this->_health_pts = max_health;
	this->_energy_pts = max_energy;
	this->_attack_dmg = attack_dmg;
	this->_name_class = "ScavTrap";
	std::cout << _name_class << " name constructor called" << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const &copy) : ClapTrap(copy)
{
	std::cout << _name_class << " copy constructor called" << std::endl;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << _name_class << " destructor called" << std::endl;
}

std::string	ScavTrap::get_name_class(void) const
{
	return (this->_name_class);
}

std::ostream	&operator<<(std::ostream &out, const ScavTrap &i)
{
	out << i.get_name_class() << " " << i.get_name() << " got " << i.get_health();
	out << " health points and " << i.get_energy() << " energy" << std::endl;
	return (out);
}