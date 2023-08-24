#include "Contact.hpp"
#include "PhoneBook.hpp"


Contact::Contact(void)
{
	std::cout << "Constructeur" << std::endl;
	return ;
}

Contact::~Contact(void)
{
	std::cout << "Destructeur" << std::endl;
	return ;
}

int check_string(std::string word, int (*function)(int))
{
	int i;

	i = 0;
	if (word[i] == ' ' || (word[i] >= 9 && word[i] <= 13))
		return (1);
	i++;
	while (word[i])
	{
		if (!function(word[i]))
			return (1);
		i++;
	}
	return (0);
}

int    Contact::first_name(void)
{
	std::string input;

	while (1)
	{
		std::cout << "Enter first name :" << std::endl;
		getline(std::cin, input);
		if (input == "EXIT")
		{
			std::cout << "EXIT ADD NEW CONTACT" << std::endl;
			return (1);
		}
		else if (check_string(input, std::isalpha) == 0)
		{
			this->_first_name = input;
			return (0);
		}
		else
			std::cout << "Invalid input, try again" << std::endl;
	}

}

int    Contact::last_name(void)
{
	std::string input;

	while (1)
	{
		std::cout << "Enter last name :" << std::endl;
		getline(std::cin, input);
		if (input == "EXIT")
		{
			std::cout << "EXIT ADD NEW CONTACT" << std::endl;
			return (1);
		}
		else if (check_string(input, std::isalpha) == 0)
		{
			this->_last_name = input;
			return (0);
		}
		else
			std::cout << "Invalid input, try again" << std::endl;
	}
}

int    Contact::nickname(void)
{
	std::string input;

	while (1)
	{
		std::cout << "Enter nickname :" << std::endl;
		getline(std::cin, input);
		if (input == "EXIT")
		{
			std::cout << "EXIT ADD NEW CONTACT" << std::endl;
			return (1);
		}
		else if (check_string(input, std::isalpha) == 0)
		{
			this->_nickname = input;
			return (0);
		}
		else
			std::cout << "Invalid input, try again" << std::endl;
	}
}

int    Contact::phone_number(void)
{
	std::string input;

	while (1)
	{
		std::cout << "Enter phone number :" << std::endl;
		getline(std::cin, input);
		if (input == "EXIT")
		{
			std::cout << "EXIT ADD NEW CONTACT" << std::endl;
			return (1);
		}
		else if (check_string(input, std::isalnum) == 0)
		{
			this->_phone_number = input;
			return (0);
		}
		else
			std::cout << "Invalid input, try again" << std::endl;
	}
}

int    Contact::darkest_secret(void)
{
	std::string input;

	while (1)
	{
		std::cout << "Enter your darkest secret :" << std::endl;
		getline(std::cin, input);
		if (input == "EXIT")
		{
			std::cout << "EXIT ADD NEW CONTACT" << std::endl;
			return (1);
		}
		else if (check_string(input, std::isalpha) == 0)
		{
			this->_darkest_secret = input;
			return (0);
		}
		else
			std::cout << "Invalid input, try again" << std::endl;
	}
}
