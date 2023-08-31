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

int	PhoneBook::print_contact(PhoneBook phonebook)
{
	std::string input;
	int			index;

	while (1)
	{
		std::cout << "Enter contact index to print :" << std::endl;
		getline(std::cin, input);
		index = atoi(input.c_str()) - 1;
		if (input == "EXIT")
		{
			std::cout << "EXIT SEARCH A CONTACT" << std::endl;
			return (1);
		}
		else if (std::cin.eof())
			return (2);
		else if (index < 0 || index > 7)
		{
			std::cout << "Invalid input, try a number between 1 and 8" << std::endl;
		}
		else if (phonebook.contact[index].get_private_info("full") == "NO")
		{
			std::cout << "This contact is empty, try again" << std::endl;
		}
		else
		{
			std::cout << "First name : " << phonebook.contact[index].get_private_info("first_name") << std::endl;
			std::cout << "Last name : " << phonebook.contact[index].get_private_info("last_name") << std::endl;
			std::cout << "Nickname : " << phonebook.contact[index].get_private_info("nickname") << std::endl;
			std::cout << "Phone number : " << phonebook.contact[index].get_private_info("phone_number") << std::endl;
			std::cout << "Darkest secret : " << phonebook.contact[index].get_private_info("darkest_secret") << std::endl;
			return (0);
		}
		std::cout << "-----------------------------------------" << std::endl;
	}
}

int	PhoneBook::search_contact(PhoneBook phonebook)
{
	int	index;

	index = 0;
	if (phonebook.contact[0].get_private_info("full") == "NO")
	{
		std::cout << "PhoneBook is empty" << std::endl;
		return (0);
	}
	while (index <= 7 && phonebook.contact[index].get_private_info("full") == "YES")
	{
		std::cout << "|----------|----------|----------|----------|" << std::endl;
		std::cout << "|" << "         " << index + 1;
		std::cout << "|" << process_string(phonebook.contact[index].get_private_info("first_name"));
		std::cout << "|" << process_string(phonebook.contact[index].get_private_info("last_name"));
		std::cout << "|" << process_string(phonebook.contact[index].get_private_info("nickname")) << "|" << std::endl;
		index++;
	}
	std::cout << "|----------|----------|----------|----------|" << std::endl;

	return (print_contact(phonebook));
}

int	PhoneBook::add_contact(int &index)
{
	Contact new_contact;
	int		error;

	error = 0;
	if (this->contact[index].get_private_info("full") == "YES")
		std::cout << "Contact n° " << index + 1 << " will be erased" << std::endl;
	std::cout << "Add contact n° " << index + 1 << std::endl;
	std::cout << "-----------------------------------------" << std::endl;
	error = new_contact.fill_data("first_name");
	if (error)
		return (error);
	error = new_contact.fill_data("last_name");
	if (error)
		return (error);
	error = new_contact.fill_data("nickname");
	if (error)
		return (error);
	error = new_contact.fill_data("phone_number");
	if (error)
		return (error);
	error = new_contact.fill_data("darkest_secret");
	if (error)
		return (error);
	std::cout << "Contact n° " << index + 1 << " succesfully added" << std::endl;
	this->contact[index] = new_contact;
	this->contact[index].get_private_info("now_is_full");
	if (index == 7)
	{
		std::cout << "PhoneBook is now full" << std::endl;
		index = 0;
	}
	else
		index++;
	return (0);
}