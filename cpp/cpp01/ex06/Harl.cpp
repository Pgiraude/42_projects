#include "Harl.hpp"

Harl::Harl(void)
{

}

Harl::~Harl(void)
{
	
}

void	Harl::debug(void)
{
	std::cout << "DEBUG is call" << std::endl;
}

void	Harl::info(void)
{
	std::cout << "INFO is call" << std::endl;
}

void	Harl::warning(void)
{
	std::cout << "WARNING is call" << std::endl;
}

void	Harl::error(void)
{
	std::cout << "ERROR is call" << std::endl;
}

void	Harl::complain(std::string level)
{
	void	(Harl::*f[4])(void);
	f[0] = &Harl::debug;
	f[1] = &Harl::info;
	f[2] = &Harl::warning;
	f[3] = &Harl::error;
	std::string	tab_lvl[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int choice = 0;
	for (int i = 0; i < 4; i++)
	{
		if (tab_lvl[i] == level)
			choice = i + 1;
	}
	switch (choice)
	{
		case 1:
			(this->*f[0])();
			(this->*f[1])();
			(this->*f[2])();
			(this->*f[3])();
			break ;
		case 2:
			(this->*f[1])();
			(this->*f[2])();
			(this->*f[3])();
			break ;
		case 3:
			(this->*f[2])();
			(this->*f[3])();
			break ;
		case 4:
			(this->*f[3])();
			break ;
		default:
			std::cout << "[ Probably complaining about insignificant problem ]" << std::endl;
			break ;
	}
}