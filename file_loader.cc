#include "file_loader.h"

FileLoader::FileLoader() {


}

FileLoader::FileLoader( std::string f_name ) {

    filename = f_name;
    
}


std::string parse_lines( std::string );



bool FileLoader::open_file( ) {

    if ( !filename.empty() )
        file.open( filename, std::fstream::in );

    return file.is_open();

}

bool FileLoader::open_file( std::string f_name ) {

    filename = f_name;
    return open_file();

}

bool FileLoader::close_file( ) {

    file.close();
    return !file.is_open();

}