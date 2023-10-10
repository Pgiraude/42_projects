#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>

class Bureaucrat
{
	Bureaucrat(void);
	Bureaucrat(std::string name);
	Bureaucrat(Bureaucrat const &copy);
	~Bureaucrat(void);

	void	getName(void);
	void	getGrade(void);

	const std::string	_name;
	int					_grade;
};

#endif