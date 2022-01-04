const std::string BLANK_SPACE("\u200c");

void usage(std::string name)
{
    std::cout << name << '\n';
    std::cout << '\t' << name << " arquivo" << std::endl;
}

void err_open(std::string file)
{
    std::cerr << "coudln't open: " << file << std::endl;
}

std::string new_name(char old_name[], std::string new_name)
{
    std::string folder(old_name);
    std::string name(old_name);

    int pos = folder.find_last_of('/') + 1;

    folder.erase(pos, folder.length());
    name.erase(0, pos);

    folder.append(new_name);
    folder.append(name);
    return folder;
}
