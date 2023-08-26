#include "Contact.hpp"
#include "PhoneBook.hpp"

int main(int argc, char **argv)
{
	PhoneBook phonebook;

	if (argc > 1)
		return (0);
	argv[0] = NULL;
	std::string input;
	int index = 0;
	for (int i = 0 ; i <= 7 ; i++)
		phonebook.contact[i].full = 0;
	while (1)
	{
		std::cout << "-----------------------------------------" << std::endl;
		std::cout << "Enter command 'ADD', 'SEARCH' or 'EXIT' :" << std::endl;
		getline(std::cin, input);
		if (input == "EXIT")
			return (0);
		else if (input == "ADD")
			phonebook.add_contact(phonebook.contact[index], index);
		else if (input == "SEARCH")
			phonebook.search_contact(phonebook);
		else
			std::cout << "Invalid input, try again" << std::endl;
	}
}