#include <iostream>
#include <fstream>

#include "bs.h"

int main(int argc, char* argv[])
{
    std::ifstream code(argv[1]);

    if (argc != 2)
    {
        usage("fucker");
        return EXIT_FAILURE;
    }

    if (!code.is_open())
    {
        err_open(argv[1]);
        return EXIT_FAILURE;
    }

    std::ofstream fucked_code(new_name(argv[1], "fucked_"));

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
