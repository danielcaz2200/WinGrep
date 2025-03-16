#ifndef GREP_HPP
#define GREP_HPP

#include <iostream>
#include <string>
#include <regex>
#include <unordered_set>
#include "file_reader.hpp"

class Grep {
    private:
        // Grep class data members
        std::unordered_set<std::string> _optional_args;
        std::string _pattern;
        std::string _file_name;
        std::regex  _compiled_pattern;
        FileReader _file_reader;

        // Default values for optional flags
        bool _ignore_case = false;
        bool _only_matches = false;
        bool _invert_match = false;

        // Compile regex data type
        void compile_regex(const std::string& pattern, std::regex& compiled_pattern);
        
        // Check if given file_name exists in file system
        bool file_exists(const std::string& file_name) const;
    public:
        // Grep class constructor
        Grep(const std::string& pattern, 
            const std::string& file_name,
            const std::unordered_set<std::string>& optional_args);
        
        // Perform main grep search functionality
        void search();
};

#endif