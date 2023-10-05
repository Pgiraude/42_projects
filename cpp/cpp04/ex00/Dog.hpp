#ifndef DOG_HPP
#define DOG_HPP


#include "Animal.hpp"

class Dog : public Animal
{       
	public:
		Dog(void);
		Dog(Dog const &copy);
		~Dog(void);

        std::string	get_type(void) const;

		
        Dog	&operator=(Dog const &rhs);
        void    makeSound(void);

};

std::ostream    &operator<<(std::ostream &out, const Animal &i);


#endif