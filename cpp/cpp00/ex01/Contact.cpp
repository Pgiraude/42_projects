#include "Contact.hpp"
#include "PhoneBook.hpp"


Contact::Contact(void)
{
	// std::cout << "Constructeur" << std::endl;
	return ;
}

Contact::~Contact(void)
{
	// std::cout << "Destructeur" << std::endl;
	return ;
}

std::string	Contact::get_contact(std::string str)
{
	if (str == "first_name")
		return (this->_first_name);
	if (str == "last_name")
		return (this->_last_name);
	if (str == "nickname")
		return (this->_nickname);
	if (str == "phone_number")
		return (this->_phone_number);
	if (str == "darkest_secret")
		return (this->_darkest_secret);
	return ("you fuck up");
}

int check_string(std::string word, int (*function)(int))
{
	int i;

	i = 0;
	if (word.empty())
		return (1);
	while (word[i])
	{
		if (!function(word[i]))
			return (1);
		i++;
		if ((word[i] == ' ' || word[i] == '-' || word[i] == '\'')
			&& (word[i + 1] && function(word[i + 1])))
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
		{
			std::cout << "Invalid input, try again" << std::endl;
			std::cout << "-----------------------------------------" << std::endl;
		}
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
		{
			std::cout << "Invalid input, try again" << std::endl;
			std::cout << "-----------------------------------------" << std::endl;
		}
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
		{
			std::cout << "Invalid input, try again" << std::endl;
			std::cout << "-----------------------------------------" << std::endl;
		}
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
		else if (check_string(input, std::isdigit) == 0)
		{
			this->_phone_number = input;
			return (0);
		}
		else
		{
			std::cout << "Invalid input, try again" << std::endl;
			std::cout << "-----------------------------------------" << std::endl;
		}
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
		else if (check_string(input, std::isprint) == 0)
		{
			this->_darkest_secret = input;
			return (0);
		}
		else
		{
			std::cout << "Invalid input, try again" << std::endl;
			std::cout << "-----------------------------------------" << std::endl;
		}
	}
}
