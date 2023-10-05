#ifndef AANIMAL_HPP
# define AANIMAL_HPP

# include <iostream>

class AAnimal
{       
	public:
		AAnimal(void);
        AAnimal(std::string type);
		AAnimal(AAnimal const &copy);
		virtual ~AAnimal(void);

        std::string	getType(void) const;

        AAnimal	&operator=(AAnimal const &rhs);
        virtual void    makeSound(void) const = 0;

	protected:
		std::string _type;
};

std::ostream    &operator<<(std::ostream &out, const AAnimal &i);

#endif