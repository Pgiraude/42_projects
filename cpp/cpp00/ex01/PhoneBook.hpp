
#ifndef PHONEBOOK_H
    #define PHONEBOOK_H

#include "Contact.hpp"
#include <stdlib.h>
class PhoneBook
{

    public:
        void	search_contact(PhoneBook);
        void	add_contact(Contact&, int&);
        Contact contact[8];
        int index;

};


#endif