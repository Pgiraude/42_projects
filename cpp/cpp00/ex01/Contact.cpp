#include "Contact.hpp"
#include "PhoneBook.hpp"


Contact::Contact(void)
{
	this->_full = "NO";
	return ;
}

Contact::~Contact(void)
{
	return ;
}

std::string	Contact::get_private_info(std::string str)
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
	if (str == "full")
		return (this->_full);
	if (str == "now_is_full")
	{
		this->_full = "YES";
		return (this->_full);
	}
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

int Contact::fill_data(std::string data_name)
{
	std::string input;

	while (1)
	{
		std::cout << "Enter " << data_name << " :" << std::endl;
		getline(std::cin, input);
		if (input == "EXIT")
		{
			std::cout << "EXIT ADD NEW CONTACT" << std::endl;
			return (1);
		}
		else if (std::cin.eof())
			return (2);
		if (data_name == "first_name" && check_string(input, std::isalpha) == 0)
		{
			this->_first_name = input;
			return (0);
		}
		else if (data_name == "last_name" && check_string(input, std::isalpha) == 0)
		{
			this->_last_name = input;
			return (0);
		}
		else if (data_name == "nickname" && check_string(input, std::isalpha) == 0)
		{
			this->_nickname = input;
			return (0);
		}
		else if (data_name == "phone_number" && check_string(input, std::isdigit) == 0)
		{
			this->_phone_number = input;
			return (0);
		}
		else if (data_name == "darkest_secret" && check_string(input, std::isprint) == 0)
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
