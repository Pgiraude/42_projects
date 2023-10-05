#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>

class Animal
{       
	public:
		Animal(void);
        Animal(std::string type);
		Animal(Animal const &copy);
		virtual ~Animal(void);

        std::string	getType(void) const;

        Animal	&operator=(Animal const &rhs);
        virtual void    makeSound(void) const;

	protected:
		std::string _type;
};

std::ostream    &operator<<(std::ostream &out, const Animal &i);


#endif