#include "file_reader.hpp"
#include <format>
#include <sstream>

FileReader::FileReader(const std::string &file_or_dir) : _file_or_dir(file_or_dir) {}

FileReader::~FileReader()
{
    if (_file.is_open())
    {
        _file.close();
    }
}

std::string FileReader::read_file()
{
    // Open fstream member
    _file.open(_file_or_dir, std::ios_base::in);
    std::stringstream buffer;

    if (!_file.is_open())
    {
        throw std::runtime_error(
            std::format("Failed to open file: {}", _file_or_dir));
    }

    // Read file into sstream buffer
    buffer << _file.rdbuf();

    _file.close();

    return buffer.str();
}

std::string FileReader::get_file_or_dir() const {
    return _file_or_dir;
}

void FileReader::set_file_or_dir(const std::string& file_or_dir) {
    _file_or_dir = file_or_dir;
}
