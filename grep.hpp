#ifndef GREP_HPP
#define GREP_HPP

#include <iostream>
#include <string>
#include <regex>
#include <unordered_set>
#include "file_reader.hpp"

class Grep
{
private:
    // Grep class data members
    std::unordered_set<std::string> _optional_args;
    std::string _pattern;
    std::string _file_or_dir;
    std::regex _compiled_pattern;

    // File/directory data members
    FileReader _file_reader;
    std::filesystem::path _init_path;

    // Default values for optional flags
    bool _ignore_case;
    bool _only_matches;
    bool _invert_match;
    bool _recursive;

    // Compile regex data type
    void compile_regex(const std::string &pattern, std::regex &compiled_pattern);

    // Check if given file_name exists in file system
    bool file_exists(const std::string &file_name) const;

    // Check if a given directory_name exists in the file system
    bool directory_exists(const std::string &directory_name) const;

public:
    // Grep class constructor
    Grep(const std::string &pattern,
         const std::string &file_or_dir,
         const std::unordered_set<std::string> &optional_args);

    // Perform main grep search functionality
    void search();

    // Perform search on specific file
    void file_search();

    // Perform recursive search
    void recursive_search(const std::filesystem::path& dir);
};

#endif