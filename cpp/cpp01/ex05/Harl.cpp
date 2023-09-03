#include "Harl.hpp"

Harl::Harl(void)
{

}

Harl::~Harl(void)
{
	
}

void	Harl::debug(void)
{
	std::cout << "you enter DEBUG" << std::endl;
}

void	Harl::info(void)
{
	std::cout << "you enter INFO" << std::endl;
}

void	Harl::warning(void)
{
	std::cout << "you enter WARNING" << std::endl;
}

void	Harl::error(void)
{
	std::cout << "you enter ERROR" << std::endl;
}

void	Harl::complain(std::string level)
{
	void	(Harl::*f[4])(void);
	f[0] = &Harl::debug;
	f[1] = &Harl::info;
	f[2] = &Harl::warning;
	f[3] = &Harl::error;
	std::string	tab_lvl[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	for (int i = 0; i < 4; i++)
	{
		if (tab_lvl[i] == level)
		{
			(this->*f[i])();
			return ;
		}
	}
	std::cout << "Complain should take only 4 different string in argument : ";
	std::cout << "DEBUG, INFO, WARNING or ERROR" << std::endl;
}