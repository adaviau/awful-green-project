#ifndef FILE_LOADER_H
#define FILE_LOADER_H

#include <string>
#include <vector>
#include <game_master.h>

#include <fstream>

class FileLoader {

private:

    std::string filename;
    std::ifstream file;
    std::string word;

public:

    bool open_file( std::string );



};

#endif