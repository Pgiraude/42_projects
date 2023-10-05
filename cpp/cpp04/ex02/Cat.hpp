#ifndef CAT_HPP
# define CAT_HPP


# include <iostream>
# include "AAnimal.hpp"
# include "Brain.hpp"

class Cat : public AAnimal
{       
	public:
		Cat(void);
		Cat(Cat const &copy);
		~Cat(void);

		
        Cat	&operator=(Cat const &rhs);
        void    makeSound(void) const;
		
		std::string	getIdeas(int pos);
		void		setIdeas(std::string ideas ,int pos);
	
	private:
		Brain *_brain;

};

std::ostream    &operator<<(std::ostream &out, const Cat &i);


#endif