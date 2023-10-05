#include "Brain.hpp"

Brain::Brain(void)
{
    std::cout << "Brain VOID constructor called" << std::endl;
}

Brain::Brain(Brain const &copy)
{
     std::cout << "Brain COPY constructor called" << std::endl;
    *this = copy;
}

Brain::~Brain(void)
{
    std::cout << "Brain DESTRUCTOR called" << std::endl;
}

std::string Brain::getIdeas(int pos)
{
    return (this->_ideas[pos]);
}

void    Brain::setIdeas(std::string ideas, int pos)
{
    this->_ideas[pos] = ideas;
}

Brain   &Brain::operator=(Brain const &rhs)
{
	std::cout << "Brain COPY '=' assignement '=' called" << std::endl;
	if (this != &rhs)
        for (int i = 0; i < 100; i++)
            this->_ideas[i] = rhs._ideas[i];
    return (*this);
}

