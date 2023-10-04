#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void)
{
	std::cout << "-----------test n1 unknown ScavTrap------------" <<std::endl;
	{
		ScavTrap a;

		a.attack("the neighbour");
		a.beRepaired(5);
		std::cout << a << "-----------" << std::endl;

	}
	std::cout << std::endl << "-----------test n2 unknown ScavTrap------------" <<std::endl;
	{
		ScavTrap a;
		std::cout << "-----------" << std::endl;

		std::cout << a;
		a.guarGate();
		std::cout << a;
		a.guarGate();
		std::cout << a;
		a.guarGate();
		a.takeDamage(500);
		a.guarGate();
		std::cout << a << "-----------" << std::endl;

	}
	std::cout << std::endl << "-----------test n3 ClapTrap------------" <<std::endl;
	{
		ClapTrap b;
		std::cout << "-----------" << std::endl;
		b.attack("the cat");
		std::cout << b;

		std::cout << "-----------" << std::endl;
		ScavTrap c;
		c.attack("the cat");
		std::cout << c << "-----------" << std::endl;
	}
	std::cout << std::endl << "-----------test n4 ScavTrap name------------" <<std::endl;
	{
		ScavTrap a("Bob");
	}
	std::cout << std::endl << "-----------test n4 ScavTrap copy------------" <<std::endl;
	{
		ScavTrap a("Bob");
		a.guarGate();
		a.takeDamage(50);
		a.attack("a burglar");
		std::cout << a;
		std::cout << "-----------" << std::endl;
		ScavTrap b(a);
		std::cout << "copy = " << b;
		std::cout << "no copy take damage = ";
		a.takeDamage(10);
		std::cout << "copy repaire itself = ";
		b.beRepaired(10);
		std::cout << "copy = " << b;
		std::cout << "no copy = " << a;
		std::cout << "-----------" << std::endl;
	}
}