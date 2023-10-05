#ifndef ANIMAL_HPP
#define ANIMAL_HPP


#include <iostream>

class Animal
{       
	public:
		Animal(void);
        Animal(std::string type);
		Animal(Animal const &copy);
		~Animal(void);

        std::string	get_type(void) const;

		
        Animal	&operator=(Animal const &rhs);
        void    makeSound(void);

	protected:
		std::string _type;
};

std::ostream    &operator<<(std::ostream &out, const Animal &i);


#endif