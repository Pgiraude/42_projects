
#ifndef PHONEBOOK_H
    #define PHONEBOOK_H

#include "Contact.hpp"
#include <stdlib.h>
class PhoneBook
{

    public:
        int	search_contact(PhoneBook);
        int	add_contact(int&);
        int	print_contact(PhoneBook phonebook);

    private:
        Contact contact[8];

};


#endif