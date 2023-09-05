#include "Contact.hpp"
#include "PhoneBook.hpp"


int main(int argc, char **argv)
{
	PhoneBook	phonebook;
	int			error;

	if (argc > 1)
		return (0);
	argv[0] = NULL;
	std::string input;
	int index = 0;
	while (1)
	{
		error = 0;
		std::cout << "-----------------------------------------" << std::endl;
		std::cout << "Enter command 'ADD', 'SEARCH' or 'EXIT' :" << std::endl;
		getline(std::cin, input);
		if (input == "EXIT" || std::cin.eof())
			return (0);
		else if (input == "ADD")
			error = phonebook.add_contact(index);
		else if (input == "SEARCH")
			error = phonebook.search_contact(phonebook);
		else
			std::cout << "Invalid input, try again" << std::endl;
		if (error == 2)
			return (2);
	}
}