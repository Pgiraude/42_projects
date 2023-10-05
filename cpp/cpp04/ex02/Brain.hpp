#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>

class Brain
{       
	public:
		Brain(void);
		Brain(Brain const &copy);
		~Brain(void);

		void    		setIdeas(std::string ideas, int pos);
		std::string		getIdeas(int pos);

        Brain	&operator=(Brain const &rhs);
	
	private:
		std::string _ideas[100];
};

#endif