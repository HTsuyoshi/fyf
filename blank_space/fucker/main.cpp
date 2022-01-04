#include <iostream>
#include <fstream>

std::string BLANK_SPACE("\u200c");

std::string new_name(char old_name[])
{
    std::string name("fucked_");
    name.append(old_name);
    return name;
}

int main(int argc, char* argv[])
{
    if (argc != 2) {
        std::cout << "Usage:\n";
        std::cout << "\t./fucker arquivo" << std::endl;
        return EXIT_FAILURE;
    }

    std::ifstream code(argv[1]);

    if (!code.is_open())
    {
        std::cerr << "coudln't open the file:" << argv[1] << std::endl;
        return EXIT_FAILURE;
    }

    std::ofstream fucked_code(new_name(argv[1]));

    char character;
    while (code.get(character))
    {
        if (character == '{'|| character == '(') fucked_code << BLANK_SPACE;
        fucked_code << character;
    }

    code.close();
    fucked_code.close();

    return EXIT_SUCCESS;
}
