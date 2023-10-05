#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

# include <iostream>
# include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{       
	public:
		WrongCat(void);
		WrongCat(WrongCat const &copy);
		~WrongCat(void);

		
        WrongCat	&operator=(WrongCat const &rhs);
        void    makeSound(void) const;

};

std::ostream    &operator<<(std::ostream &out, const WrongCat &i);


#endif