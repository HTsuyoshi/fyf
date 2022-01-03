#include <iostream>
#include <fstream>

void usage()
{
    std::cout << "Usage:\n";
    std::cout << "\t./nome arquivo" << std::endl;
}

int main(int argc, char* argv[])
{
    if (argc != 2) {
       usage();
       return EXIT_FAILURE;
    }

    std::string file_name("fucked_");
    file_name.append(argv[1]);

    std::ifstream code(argv[1]);
    std::ofstream fucked_code(file_name);

    if (!code.is_open())
    {
        std::cerr << "coudln't open the file:" << file_name << std::endl;
        return EXIT_FAILURE;
    }

    char character;

    while (code.get(character))
    {
        if (character == '{' || character == '(')
        {
            fucked_code << "\u200C";
        }
        fucked_code << character;
    }

    code.close();
    fucked_code.close();

    return EXIT_SUCCESS;
}
