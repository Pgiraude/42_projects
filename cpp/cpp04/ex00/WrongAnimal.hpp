#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP


#include <iostream>

class WrongAnimal
{       
	public:
		WrongAnimal(void);
        WrongAnimal(std::string type);
		WrongAnimal(WrongAnimal const &copy);
		~WrongAnimal(void);

        std::string	get_type(void) const;

		
        WrongAnimal	&operator=(WrongAnimal const &rhs);
        void    makeSound(void);

	protected:
		std::string _type;
};

std::ostream    &operator<<(std::ostream &out, const WrongAnimal &i);


#endif