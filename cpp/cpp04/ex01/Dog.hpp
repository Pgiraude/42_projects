#ifndef DOG_HPP
# define DOG_HPP

# include <iostream>
# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal
{       
	public:
		Dog(void);
		Dog(Dog const &copy);
		~Dog(void);

		
        Dog	&operator=(Dog const &rhs);
        void    makeSound(void) const;

		std::string	getIdeas(int pos);
		void		setIdeas(std::string ideas ,int pos);
	
	private:
		Brain *_brain;

};

std::ostream    &operator<<(std::ostream &out, const Dog &i);


#endif