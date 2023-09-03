#include <iostream>
#include <fstream>

std::string	replace_occurence(std::string str, std::string to_find, std::string replace)
{
	size_t start_pos = 0;
    while((start_pos = str.find(to_find, start_pos)) != std::string::npos)
	{
        str.replace(start_pos, to_find.length(), replace);
        start_pos += replace.length();
	}
	return (str);
}


int main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cout << "need 3 arguments, try again!" << std::endl;
		return (1);
	}
	std::string filename = argv[1];
	std::string to_find = argv[2];
	std::string replace = argv[3];

	if (filename.empty())
	{
		std::cout << "'filename' is empty" << std::endl;
		return (2);
	}
	if (to_find.empty())
	{
		std::cout << "'to find' is empty" << std::endl;
		return (3);
	}
	if (replace.empty())
	{
		std::cout << "'replace' is empty" << std::endl;
		return (4);
	}
	std::ifstream ifs;
	ifs.open(filename.c_str());
	if (!ifs.is_open())
	{
		std::cout << "Error opening file " << filename << std::endl;
		return (0);
	}
	
	std::string	line;
	std::string	text;

	while (getline(ifs, line))
	{
		line = replace_occurence(line, to_find, replace);
		text += line;
		text += '\n';
	}

	std::string replace_file = filename + ".replace";
	std::ofstream ofs(replace_file.c_str());
	ofs << text;

}