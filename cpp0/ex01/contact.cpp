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
	std::string first_name;

	while (1)
	{
		getline(std::cin, first_name);
		if (first_name == "EXIT")
		{
			std::cout << "EXIT ADD NEW CONTACT" << std::endl;
			return (1);
		}
		else if (check_string(first_name, std::isalpha) == 0)
		{
			this->_first_name = first_name;
			return (0);
		}
		else
			std::cout << "Invalid input, try again" << std::endl;
	}

}

int    Contact::last_name(void)
{
	std::string first_name;

	while (1)
	{
		getline(std::cin, first_name);
		if (first_name == "EXIT")
		{
			std::cout << "EXIT ADD NEW CONTACT" << std::endl;
			return (1);
		}
		else if (check_string(first_name, std::isalpha) == 0)
		{
			this->_first_name = first_name;
			return (0);
		}
		else
			std::cout << "Invalid input, try again" << std::endl;
	}
}

int    Contact::nickname(void)
{
	std::string first_name;

	while (1)
	{
		getline(std::cin, first_name);
		if (first_name == "EXIT")
		{
			std::cout << "EXIT ADD NEW CONTACT" << std::endl;
			return (1);
		}
		else if (check_string(first_name, std::isalpha) == 0)
		{
			this->_first_name = first_name;
			return (0);
		}
		else
			std::cout << "Invalid input, try again" << std::endl;
	}
}

int    Contact::phone_number(void)
{
	std::string first_name;

	while (1)
	{
		getline(std::cin, first_name);
		if (first_name == "EXIT")
		{
			std::cout << "EXIT ADD NEW CONTACT" << std::endl;
			return (1);
		}
		else if (check_string(first_name, std::isalnum) == 0)
		{
			this->_first_name = first_name;
			return (0);
		}
		else
			std::cout << "Invalid input, try again" << std::endl;
	}
}

int    Contact::darkest_secret(void)
{
	std::string first_name;

	while (1)
	{
		getline(std::cin, first_name);
		if (first_name == "EXIT")
		{
			std::cout << "EXIT ADD NEW CONTACT" << std::endl;
			return (1);
		}
		else if (check_string(first_name, std::isalpha) == 0)
		{
			this->_first_name = first_name;
			return (0);
		}
		else
			std::cout << "Invalid input, try again" << std::endl;
	}
}