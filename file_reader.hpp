#ifndef FILE_READER
#define FILE_READER

#include <fstream>
#include <string>
#include <iostream>

// Defines a class for reading input text files
class FileReader
{
private:
    // Data members
    std::string _file_or_dir;
    std::fstream _file;

public:
    // Public member functions
    FileReader();
    ~FileReader();
    std::string read_file();

    // File/dir getter, setter
    std::string get_file_or_dir() const;
    void set_file_or_dir(const std::string& file_or_dir);
};

#endif