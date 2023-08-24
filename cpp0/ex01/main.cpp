#include "Contact.hpp"
#include "PhoneBook.hpp"

int main(int argc, char **argv)
{

	if (argc > 1)
		return (0);


	PhoneBook phonebook;
	int index = 0;

	std::cout << argv[0] << std::endl;


	std::string input;
	while (1)
	{
		std::cout << "Enter command 'ADD', 'SEARCH' or 'EXIT'" << std::endl;
		getline(std::cin, input);

		if (input == "EXIT")
		{
			std::cout << "EXIT" << std::endl;
			return (0);
		}
		else if (input == "ADD")
		{
			phonebook.add_contact(phonebook.contact[index], index);
		}
		else if (input == "SEARCH")
		{
			phonebook.search_contact(phonebook);
		}
		else
		{
			std::cout << "Invalid input, try again" << std::endl;
		}
	}
	
}