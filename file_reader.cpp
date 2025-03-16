#include "file_reader.hpp"
#include <format>
#include <sstream>

FileReader::FileReader(const std::string& file_name): _file_name(file_name) {}

FileReader::~FileReader() {
    if (_file.is_open()) {
        _file.close();
    }
}

std::string FileReader::read_file() {
    // Open fstream member
    _file.open(_file_name, std::ios_base::in);
    std::stringstream buffer;

    if (!_file.is_open()) {
        throw std::runtime_error(
            std::format("Failed to open file: {}", _file_name)
        );
    }

    // Read file into sstream buffer
    buffer << _file.rdbuf();

    return buffer.str();
}