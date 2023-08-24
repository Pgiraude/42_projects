#include "Contact.hpp"
#include "PhoneBook.hpp"

void	PhoneBook::search_contact(PhoneBook phonebook)
{
	int	index;

	index = 0;
	while (!phonebook.contact[index]._first_name.empty() && index <= 7)
	{
		std::cout << "|--------------------------------------|" << std::endl;
		std::cout << "|" << phonebook.contact[index]._first_name << std::endl;
		index++;
	}
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