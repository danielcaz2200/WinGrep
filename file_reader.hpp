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
    public:
        // Public member functions
        FileReader(const std::string& file_name);
        std::string read_file() const;
};

#endif