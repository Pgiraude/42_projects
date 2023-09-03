#include <iostream>
#include <fstream>

std::string	replace_occurence(std::string str, std::string to_find, std::string replace, bool &changes)
{
	size_t pos = 0;

    while((pos = str.find(to_find, pos)) != std::string::npos)
	{
		str.erase(pos, to_find.length());
		str.insert(pos, replace);
        pos += replace.length();
		changes = true;
	}
	return (str);
}

int	check_init_error(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cout << "need 3 arguments, try again!" << std::endl;
		return (1);
	}
	std::string filename = argv[1];
	if (filename.empty())
	{
		std::cout << "'filename' is empty" << std::endl;
		return (2);
	}
	std::string to_find = argv[2];
	if (to_find.empty())
	{
		std::cout << "'to find' is empty" << std::endl;
		return (3);
	}
	std::string replace = argv[3];
	if (replace.empty())
	{
		std::cout << "'replace' is empty" << std::endl;
		return (4);
	}
	return (0);
}

int main(int argc, char **argv)
{
	int error;

	if ((error = check_init_error(argc, argv)) != 0)
		return (error);
	std::string filename = argv[1];
	std::string to_find = argv[2];
	std::string replace = argv[3];
	std::ifstream ifs;
	ifs.open(filename.c_str());
	if (!ifs.is_open())
	{
		std::cout << "Error opening file " << filename << std::endl;
		return (5);
	}
	std::string	line;
	std::string	text;
	bool		changes = false;
	while (getline(ifs, line))
	{
		line = replace_occurence(line, to_find, replace, changes);
		text += line;
		if (ifs.eof())
			break ;
		text += '\n';
	}
	// if (ifs.eof() && ifs.fail())
	// 	std::cout << "\\n\\0 detected" << std::endl;
	if (changes == false)
	{
		std::cout << "No occurences found : Their is nothing to change" << std::endl;
		ifs.close();
		return (0);
	}
	std::string replace_file = filename + ".replace";
	std::ofstream ofs(replace_file.c_str());
	if (!ifs.is_open())
	{
		std::cout << "Error opening file " << replace_file << std::endl;
		ifs.close();
		return (6);
	}
	ofs << text;
	ifs.close();
	ofs.close();
	return (0);
}