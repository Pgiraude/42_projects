#ifndef CAT_HPP
#define CAT_HPP


#include "Animal.hpp"

class Cat : public Animal
{       
	public:
		Cat(void);
		Cat(Cat const &copy);
		~Cat(void);

        std::string	get_type(void) const;

		
        Cat	&operator=(Cat const &rhs);
        void    makeSound(void);

};

std::ostream    &operator<<(std::ostream &out, const Cat &i);


#endif