
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

		int			first_name(void);
		int			last_name(void);
		int			nickname(void);
		int			phone_number(void);
		int			darkest_secret(void);
		std::string	get_contact(std::string);
		bool		full;
	
	private:
		std::string _first_name;
		std::string _last_name;
		std::string _nickname;
		std::string _phone_number;
		std::string _darkest_secret;
		



};


#endif