
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"


int main(void)
{
	std::cout << "-----------test n1 Animal------------" <<std::endl;
	{
		Animal a("Girafe");
		std::cout << a;
	}
	std::cout << std::endl << "-----------test n2 Cat------------" <<std::endl;
	{
		Cat a;
		std::cout << a;
	}
	std::cout << std::endl << "-----------test n3 test NormalAnimal ptr------------" <<std::endl;
	{
		const Animal* meta = new Animal();
		std::cout << "-----------" << std::endl;
		const Animal* dog = new Dog();
		std::cout << "-----------" << std::endl;
		const Animal* cat = new Cat();
		std::cout << "-----------" << std::endl;
		std::cout << "Type of Dog = " << dog->getType() << " " << std::endl;
		std::cout << "Type of Cat = " <<cat->getType() << " " << std::endl;
		std::cout << "-----------" << std::endl;
		std::cout << "Sound of Cat = ";
		cat->makeSound(); //will output the cat sound!
		std::cout << "Sound of Dog = ";
		dog->makeSound();
		std::cout << "Sound of Animal = ";
		meta->makeSound();
		delete meta;
		delete dog;
		delete cat;
	}
	std::cout << std::endl << "-----------test n4 test WrongAnimal ptr------------" <<std::endl;
	{
		const WrongAnimal* meta = new WrongAnimal();
		std::cout << "-----------" << std::endl;
		const Animal* dog = new Dog();
		std::cout << "-----------" << std::endl;
		const WrongAnimal* wrongCat = new WrongCat();
		std::cout << "-----------" << std::endl;
		std::cout << "Type of Dog = " << dog->getType() << " " << std::endl;
		std::cout << "Type of WrongCat = " << wrongCat->getType() << " " << std::endl;
		std::cout << "-----------" << std::endl;
		std::cout << "Sound of Wrongcat = ";
		wrongCat->makeSound(); //will output the WrongCat sound!
		std::cout << "Sound of Dog = ";
		dog->makeSound();
		std::cout << "Sound of Wanimal = ";
		meta->makeSound();
		delete meta;
		delete dog;
		delete wrongCat;
	}
	std::cout << std::endl << "-----------test n5 test WrongAnimal without ptr------------" <<std::endl;
	{
		WrongCat cat;
		cat.makeSound();
	}
}