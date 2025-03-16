#ifndef FILE_READER
#define FILE_READER

#include <fstream>
#include <string>
#include <iostream>

// Defines a class for reading input text files
class FileReader {
    private:
        // Data members
        std::string _file_name;
        std::fstream _file;
    public:
        // Public member functions
        FileReader(const std::string& file_name);
        ~FileReader();
        std::string read_file();
};

#endif