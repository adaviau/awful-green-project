#ifndef FILE_LOADER_H
#define FILE_LOADER_H

#include <string>
#include <vector>
#include <iostream>

#include <fstream>

class FileLoader {

private:

    std::string filename;
    std::ifstream file;
    std::string word;

    std::string parse_lines( std::string );

public:

    FileLoader();
    FileLoader( std::string );

    bool open_file( std::string );
    bool open_file();

    bool close_file();



};

#endif