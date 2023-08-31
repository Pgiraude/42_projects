#include <iostream>
#include <fstream>

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
        std::cout << "filename is empty" << std::endl;
        return (2);
    }
    if (to_find.empty())
    {
        std::cout << "to find is empty" << std::endl;
        return (3);
    }
    if (replace.empty())
    {
        std::cout << "replace is empty" << std::endl;
        return (4);
    }
    std::ifstream ifs("lol");
    std::ofstream ofs("test");

}