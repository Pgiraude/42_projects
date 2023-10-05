#include "Brain.hpp"

Brain::Brain(void)
{
    std::cout << "Brain void constructor called" << std::endl;
}

Brain::Brain(Brain const &copy)
{
     std::cout << "Brain copy constructor called" << std::endl;
    *this = copy;
}

Brain::~Brain(void)
{
    std::cout << "Brain destructor called" << std::endl;
}

Brain   &Brain::operator=(Brain const &rhs)
{
	std::cout << "Brain copy assignement '=' called" << std::endl;
	if (this != &rhs)
        for (int i = 0; i < 100; i++)
            this->_ideas[i] = rhs._ideas[i];
    return (*this);
}

