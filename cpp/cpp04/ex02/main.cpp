
#include "Cat.hpp"
#include "Dog.hpp"


int main(void)
{
	std::cout << "-----------test n1 AAnimal ptr------------" <<std::endl;
	{
		const AAnimal *dog = new Dog;

		std::cout << *dog;
	}
}