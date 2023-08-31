#include "Zombie.hpp"

Zombie test()
{
	Zombie test("function_test");

	return (test);
}


int	main(void)
{

	Zombie testmain("test_main");

	testmain = test();
	testmain.announce();

	Zombie *AAA;

	AAA = newZombie("AAA");
	AAA->announce();


	randomChump("BBB");

	Zombie *CCC;

	CCC = newZombie("CCC");
	CCC->announce();

	delete AAA;
	delete CCC;
}