#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) : _health_pts(_max_health), _energy_pts(_max_energy), _attack_dmg(_set_attack_dmg), _name("unknown"), _name_class("ClapTrap"), _m_health(_max_health)
{
	std::cout << "ClapTrap void constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _health_pts(_max_health), _energy_pts(_max_energy), _attack_dmg(_set_attack_dmg), _name(name), _name_class("ClapTrap"), _m_health(_max_health)
{
	if (name.empty())
		this->_name = "unknown";
	std::cout << "ClapTrap name constructor called" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const &copy) : _health_pts(copy._health_pts), _energy_pts(copy._energy_pts), _attack_dmg(copy._attack_dmg), _name(copy._name), _name_class(copy._name_class), _m_health(copy._m_health)
{
	std::cout << "ClapTrap copy constructor called" << std::endl;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "ClapTrap destructor called" << std::endl;
}

ClapTrap   &ClapTrap::operator=(ClapTrap const &rhs)
{
	if (this != &rhs)
	{
		this->_name = rhs._name;
		this->_health_pts = rhs._health_pts;
		this->_energy_pts = rhs._energy_pts;
		this->_attack_dmg = rhs._attack_dmg;
		this->_m_health = rhs._m_health;
	}
	return (*this);
}



void	ClapTrap::attack(const std::string& target)
{
	std::cout << this->_name_class << " " << this->_name;
	if (this->_health_pts <= 0)
	{
		std::cout << " is dead so... Can't attack " << target << std::endl;
		return ;
	}
	else if (this->_energy_pts <= 0)
	{
		std::cout << " is out of energy so... Can't attack " << target << std::endl;
		return ;
	}
	std::cout << " attack " << target << ", causing ";
	std::cout << this->_attack_dmg << " points of damage!" << std::endl;
	this->_energy_pts--;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << _name_class << " " << this->_name << " take " << amount << " damage! ";
	if (this->_health_pts <= 0)
		std::cout  << this->_name << " was already dead anyway..." << std::endl;
	else if ((this->_health_pts - amount) <= 0)
		std::cout << this->_name << " didn't survive the attack..." << std::endl;
	else
		std::cout << std::endl;
	this->_health_pts -= amount;
	if (this->_health_pts < 0)
		this->_health_pts = 0;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	int amt = amount;
	unsigned int h_pts = this->_health_pts;
	unsigned int m_h_pts = this->_m_health;

	std::cout << this->_name_class << " " << this->_name;
	if (this->_health_pts <= 0)
		std::cout << " is dead... Too late for repairing." << std::endl;
	else if (this->_energy_pts <= 0)
		std::cout << " has no energy left. No repair possible!" << std::endl;
	else if (this->_health_pts == this->_m_health)
		std::cout << " is already at max health points. What are you traying to repair?" << std::endl;
	else if (h_pts + amount >= m_h_pts)
	{
		std::cout << " is repaired to full health!" << std::endl;
		this->_health_pts = this->_m_health;
		this->_energy_pts--;
	}
	else
	{
		std::cout << " is repaired gaining " << amt << " health points." << std::endl;
		this->_health_pts += amt;
		this->_energy_pts--;
	}

}

std::string	ClapTrap::get_name(void) const
{
	return (this->_name);
}

std::string	ClapTrap::get_name_class(void) const
{
	return (this->_name_class);
}

int	ClapTrap::get_health(void) const
{
	return (this->_health_pts);
}

int	ClapTrap::get_energy(void) const
{
	return (this->_energy_pts);
}

std::ostream	&operator<<(std::ostream &out, const ClapTrap &i)
{
	out << i.get_name_class() << " " << i.get_name() << " got " << i.get_health();
	out << " health points and " << i.get_energy() << " energy" << std::endl;
	return (out);
}
