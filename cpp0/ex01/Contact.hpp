
#ifndef CONTACT_H
	#define CONTACT_H

#include <string>
#include <iostream>
#include <cstring>

class Contact
{
	public:

		Contact(void);
		~Contact(void);

		int    first_name(void);
		int    last_name(void);
		int    nickname(void);
		int    phone_number(void);
		int    darkest_secret(void);
	
		std::string _first_name;
	private:
		



};


#endif