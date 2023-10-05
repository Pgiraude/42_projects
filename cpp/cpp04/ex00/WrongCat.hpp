#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP


#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{       
	public:
		WrongCat(void);
		WrongCat(WrongCat const &copy);
		~WrongCat(void);

        std::string	get_type(void) const;

		
        WrongCat	&operator=(WrongCat const &rhs);
        void    makeSound(void);

};

std::ostream    &operator<<(std::ostream &out, const WrongCat &i);


#endif