#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>

class Brain
{       
	public:
		Brain(void);
		Brain(Brain const &copy);
		~Brain(void);

        Brain	&operator=(Brain const &rhs);
		std::string _ideas[100];
};

std::ostream    &operator<<(std::ostream &out, const Brain &i);


#endif