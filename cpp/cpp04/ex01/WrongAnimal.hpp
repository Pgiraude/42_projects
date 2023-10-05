#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>

class WrongAnimal
{       
	public:
		WrongAnimal(void);
        WrongAnimal(std::string type);
		WrongAnimal(WrongAnimal const &copy);
		~WrongAnimal(void);

        std::string	getType(void) const;

		
        WrongAnimal	&operator=(WrongAnimal const &rhs);
        void    makeSound(void) const;

	protected:
		std::string _type;
};

std::ostream    &operator<<(std::ostream &out, const WrongAnimal &i);


#endif