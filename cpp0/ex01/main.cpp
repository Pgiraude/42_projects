#include "Contact.hpp"
#include "PhoneBook.hpp"

void	add_contact(PhoneBook &phonebook)
{
	std::cout << "Contact n° " << "1" << std::endl;
	// std::string first_name;//, last_name, nickname, phone_number, darkest_secret;

	phonebook.contact[0].first_name();

}

int main(int argc, char **argv)
{

	if (argc > 1)
		return (0);


	PhoneBook directory;
	std::cout << "Enter command 'ADD', 'SEARCH' or 'EXIT'" << std::endl;
	std::cout << argv[0] << std::endl;


	std::string input;

	getline(std::cin, input);

	if (input == "EXIT")
	{
		std::cout << "EXIT" << std::endl;
		return (0);
	}
	else if (input == "ADD")
	{
		add_contact(directory);
	}
	else if (input == "SEARCH")
	{

	}
	std::cout << "First name =" << directory.contact[0]._first_name << std::endl;
}