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
	int			index;

	while (1)
	{
		std::cout << "Enter contact index to print :" << std::endl;
		getline(std::cin, input);
		index = atoi(input.c_str()) - 1;
		if (input == "EXIT")
		{
			std::cout << "EXIT SEARCH A CONTACT" << std::endl;
			return ;
		}
		else if (index < 0 || index > 7)
		{
			std::cout << "Invalid input, try a number between 1 and 8" << std::endl;
		}
		else if (phonebook.contact[index].full != 1)
		{
			std::cout << "This contact is empty, try again" << std::endl;
		}
		else
		{
			std::cout << "First name : " << phonebook.contact[index].get_contact("first_name") << std::endl;
			std::cout << "Last name : " << phonebook.contact[index].get_contact("last_name") << std::endl;
			std::cout << "Nickname : " << phonebook.contact[index].get_contact("nickname") << std::endl;
			std::cout << "Phone number : " << phonebook.contact[index].get_contact("phone_number") << std::endl;
			std::cout << "Darkest secret : " << phonebook.contact[index].get_contact("darkest_secret") << std::endl;
			return ;
		}
		std::cout << "-----------------------------------------" << std::endl;
	}
}

void	PhoneBook::search_contact(PhoneBook phonebook)
{
	int	index;

	index = 0;
	if (phonebook.contact[0].full != 1)
	{
		std::cout << "PhoneBook is empty" << std::endl;
		return ;
	}
	while (phonebook.contact[index].full == 1 && index <= 7)
	{
		std::cout << "|----------|----------|----------|----------|" << std::endl;
		std::cout << "|" << "         " << index + 1;
		std::cout << "|" << process_string(phonebook.contact[index].get_contact("first_name"));
		std::cout << "|" << process_string(phonebook.contact[index].get_contact("last_name"));
		std::cout << "|" << process_string(phonebook.contact[index].get_contact("nickname")) << "|" << std::endl;
		index++;
	}
	std::cout << "|----------|----------|----------|----------|" << std::endl;

	print_contact(phonebook);
}

void	PhoneBook::add_contact(Contact &contact, int &index)
{
	Contact new_contact;

	if (contact.full == 1)
		std::cout << "Contact n° " << index + 1 << " will be erased" << std::endl;
	std::cout << "Add contact n° " << index + 1 << std::endl;
	std::cout << "-----------------------------------------" << std::endl;
	if (new_contact.first_name() == 1)
		return (new_contact.clear_contact(new_contact));
	if (new_contact.last_name() == 1)
		return (new_contact.clear_contact(new_contact));
	if (new_contact.nickname() == 1)
		return (new_contact.clear_contact(new_contact));
	if (new_contact.phone_number() == 1)
		return (new_contact.clear_contact(new_contact));
	if (new_contact.darkest_secret() == 1)
		return (new_contact.clear_contact(new_contact));
	std::cout << "Contact n° " << index + 1 << " succesfully added" << std::endl;
	contact = new_contact;
	contact.full = 1;
	if (index == 7)
	{
		std::cout << "PhoneBook is now full" << std::endl;
		index = 0;
	}
	else
		index++;
}