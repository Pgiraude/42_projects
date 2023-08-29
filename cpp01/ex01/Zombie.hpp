#ifndef ZOMBIE_H
	#define ZOMBIE_H

#include <string>
#include <iostream>

class Zombie
{
	private:
		std::string name;

	public:
		void	announce(void);
		void	set_name(std::string name);
		
		Zombie(void);
		Zombie(std::string new_name);
		~Zombie(void);
};

Zombie	*zombieHorde(int N, std::string name);

#endif