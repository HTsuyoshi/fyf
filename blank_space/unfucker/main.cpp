#include <iostream>
#include <fstream>

std::string BLANK_SPACE("\u200c");

std::string new_name(char old_name[])
{
    std::string name("un");
    name.append(old_name);
    return name;
}

int main(int argc, char* argv[])
{
    if (argc != 2) {
        std::cout << "Usage:\n";
        std::cout << "\t./unfucker arquivo" << std::endl;
        return EXIT_FAILURE;
    }

    std::ifstream code(argv[1]);

    if (!code.is_open())
    {
        std::cerr << "coudln't open the file:" << argv[1] << std::endl;
        return EXIT_FAILURE;
    }

    std::ofstream unfucked_code(new_name(argv[1]));

    std::string line;
    while (getline(code, line))
    {
        int pos = line.find(BLANK_SPACE);
        if (pos != std::string::npos)
        {
            line.erase(pos, BLANK_SPACE.length());
        }
        unfucked_code << line << '\n';
    }

    code.close();
    unfucked_code.close();

    return EXIT_SUCCESS;
}
