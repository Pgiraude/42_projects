#include "Contact.hpp"
#include "PhoneBook.hpp"


std::string	process_string(std::string str)
{
	std::string new_str;

	if (str.length() > 10)
	{
		new_str = str.substr(0, 9);
		new_str += ".";
		return (new_str);
	}
	else if (str.length() == 10)
		return (str);
	else
	{
		for (std::size_t i = 10; i > str.length() ; i--)
			new_str += " ";
		new_str += str;
		return (new_str);
	}
}

void	print_contact(PhoneBook phonebook)
{
	std::string input;

	while (1)
	{
		std::cout << "Enter contact index to print" << std::endl;
		getline(std::cin, input);
		if (input == "EXIT")
		{
			std::cout << "EXIT SEARCH A CONTACT" << std::endl;
			return ;
		}
		else if (atoi(input.c_str()) < 1 || atoi(input.c_str()) > 8)
		{
			std::cout << "Invalid input, try a number between 1 and 8" << std::endl;
		}
		else if (phonebook.contact[atoi(input.c_str()) - 1]._first_name.empty())
		{
			std::cout << "This contact is empty, try again" << std::endl;
		}
	}
}

void	PhoneBook::search_contact(PhoneBook phonebook)
{
	int	index;

	index = 0;
	if (phonebook.contact[0]._first_name.empty())
	{
		std::cout << "PhoneBook is empty" << std::endl;
		return ;
	}
	while (!phonebook.contact[index]._first_name.empty() && index <= 7)
	{
		std::cout << "|----------|----------|----------|----------|" << std::endl;
		std::cout << "|" << "         " << index + 1;
		std::cout << "|" << process_string(phonebook.contact[index]._first_name);
		std::cout << "|" << process_string(phonebook.contact[index]._last_name);
		std::cout << "|" << process_string(phonebook.contact[index]._nickname) << "|" << std::endl;
		index++;
	}
	std::cout << "|----------|----------|----------|----------|" << std::endl;

	print_contact(phonebook);
}

void	PhoneBook::add_contact(Contact &contact, int &index)
{
	if (index == 8)
	    index = 0;
	std::cout << "Contact n° " << index + 1 << std::endl;
	if (contact.first_name() == 1)
		return ;
	if (contact.last_name() == 1)
		return ;
	if (contact.nickname() == 1)
		return ;
	if (contact.phone_number() == 1)
		return ;
	if (contact.darkest_secret() == 1)
		return ;
	std::cout << "Contact n° " << index + 1 << " succesfully added" << std::endl;
	index++;
}