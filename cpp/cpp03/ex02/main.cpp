#include "ClapTrap.hpp"
#include "FragTrap.hpp"

int main(void)
{
	std::cout << "-----------test n1 unknown FragTrap------------" <<std::endl;
	{
		FragTrap a;
		std::cout << "-----------" << std::endl;

		a.attack("the neighbour");
		a.HighFivesGuys();
		a.takeDamage(999);
		a.HighFivesGuys();
		std::cout << a << "-----------" << std::endl;

	}
	std::cout << std::endl << "-----------test n2 FragTrap------------" <<std::endl;
	{
		FragTrap a;
		std::cout << "-----------" << std::endl;

		a.attack("the neighbour");
		a.HighFivesGuys();
		std::cout << a;
		a.takeDamage(70);
		a.beRepaired(60);
		a.HighFivesGuys();
		std::cout << a;
		std::cout << "-----------" << std::endl;
		a.takeDamage(70);
		a.beRepaired(100);
		std::cout << a << "-----------" << std::endl;

	}
}