#include <iostream>
#include <fstream>

#include "bs.h"

int main(int argc, char* argv[])
{
    if (argc != 2)
    {
        usage("unfucker");
        return EXIT_FAILURE;
    }

    std::ifstream code(argv[1]);

    if (!code.is_open())
    {
        err_open(argv[1]);
        return EXIT_FAILURE;
    }

    std::ofstream unfucked_code(new_name(argv[1], "un"));

    std::string line;
    while (getline(code, line))
    {
        int pos = line.find(BLANK_SPACE);
        if (pos != std::string::npos) line.erase(pos, BLANK_SPACE.length());
        unfucked_code << line << '\n';
    }

    code.close();
    unfucked_code.close();

    return EXIT_SUCCESS;
}
