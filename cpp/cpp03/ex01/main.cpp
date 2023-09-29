#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void)
{
	std::cout << "-----------test n1 unknown ScavTrap------------" <<std::endl;
	{
		ScavTrap a;
		ClapTrap b;

		a.attack("the neighbour");
		std::cout << a;
		b.attack("the cat");
		std::cout << b;
	}

	{

	}
}