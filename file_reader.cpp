#include "file_reader.hpp"
#include <format>
#include <sstream>

FileReader::FileReader(const std::string& file_name): _file_name(file_name) {}

std::string FileReader::read_file() const {
    // Create fstream object
    std::fstream file(_file_name, std::ios::in);
    std::stringstream buffer;

    if (!file.is_open()) {
        throw std::runtime_error(
            std::format("Failed to open file: {}", _file_name)
        );
    }

    // Read file into sstream buffer
    buffer << file.rdbuf();
    file.close();

    return buffer.str();
}