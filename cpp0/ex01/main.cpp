#include "Contact.hpp"
#include "PhoneBook.hpp"

int main(int argc, char **argv)
{

    if (argc > 1)
        return (0);

    std::cout << "Enter command 'ADD', 'SEARCH' or 'EXIT'" << std::endl;
    std::cout << argv[0] << std::endl;

    

    Contact contact;
    // PhoneBook repertoir;
    std::string firstname;

    std::cin >> firstname;

    contact.first_name();
    std::cout << "First name =" << firstname << std::endl;
}