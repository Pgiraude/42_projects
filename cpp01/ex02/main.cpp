#include <iostream>

int main(void)
{
	std::string str = "HI THIS IS BRAIN";
	std::string *stringPTR = &str;
	std::string &stringREF = str;

	std::cout << "Adresse de la string = " << &str << std::endl;
	std::cout << "Adresse de stringPTR = " << stringPTR << std::endl;
	std::cout << "Adresse de stringREF = " << &stringREF << std::endl;
	std::cout << "---------------------" <<std::endl;
	std::cout << "Valeur de la string = " << str << std::endl;
	std::cout << "Valeur poitée par stringPTR = " << *stringPTR << std::endl;
	std::cout << "Valeur poitée par stringREF = " << stringREF << std::endl;
}
