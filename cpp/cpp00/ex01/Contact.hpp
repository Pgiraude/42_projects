
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

		int			fill_data(std::string);
		std::string	get_private_info(std::string);
	
	private:
		std::string _first_name;
		std::string _last_name;
		std::string _nickname;
		std::string _phone_number;
		std::string _darkest_secret;
		std::string	_full;
		



};


#endif