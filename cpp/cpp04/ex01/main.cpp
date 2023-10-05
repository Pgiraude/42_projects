
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"


int main(void)
{
	std::cout << "-----------test n1 Animal------------" <<std::endl;
	{
		const Animal* dog = new Dog;

		std::cout << dog;
	}
	std::cout << std::endl << "-----------test n2 Cat------------" <<std::endl;
	{
		
	}
	std::cout << std::endl << "-----------test n3 test NormalAnimal ptr------------" <<std::endl;
	{
		
	}
	std::cout << std::endl << "-----------test n4 test WrongAnimal ptr------------" <<std::endl;
	{
		
	}
	std::cout << std::endl << "-----------test n5 test WrongAnimal without ptr------------" <<std::endl;
	{
		
	}
}