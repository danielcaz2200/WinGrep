#include <filesystem>
#include <format>
#include <regex>
#include "grep.hpp"
#include "grep_utils.hpp"

void Grep::compile_regex(const std::string &pattern, std::regex &compiled_pattern)
{
    // Compile string as regex object
    try
    {
        if (_ignore_case)
        {
            // Do pattern matching without regard to case
            compiled_pattern = std::regex(pattern, std::regex::icase);
        }
        else
        {
            compiled_pattern = std::regex(pattern);
        }
    }
    catch (const std::regex_error &e)
    {
        // Invalid string supplied for regex
        std::cerr << "Error converting inputted string to regex\n";
        throw std::runtime_error("Error converting inputted string to regex\n");
    }
}

bool Grep::file_exists(const std::string &file_name) const
{
    return std::filesystem::exists(file_name);
}

bool Grep::directory_exists(const std::string &directory_name) const
{
    return std::filesystem::is_directory(directory_name);
}

void Grep::search()
{
    if (!recursive_search)
    {
        file_search();
    }
    else
    {
        recursive_search(_init_path);
    }
}

void Grep::file_search()
{
    std::string file_text = _file_reader.read_file();

    // Use istringstream to iterate over each line
    std::istringstream iss(file_text);

    // Keep running count of line number
    std::size_t line_n = 0;

    for (std::string line; std::getline(iss, line);)
    {
        ++line_n;

        bool match_found = std::regex_search(line, _compiled_pattern);
        bool process = GrepUtils::process_line(_invert_match, match_found);

        if (!_only_matches)
        {
            if (std::regex_search(line.begin(), line.end(), _compiled_pattern))
            {
                std::cout << std::format("{}: {}", line_n, line) << std::endl;
            }
        }
        else
        {
            // Used to retrieve only the matched string/group
            std::smatch match;

            // Find specific matched substrings from the current line
            if (std::regex_search(line, match, _compiled_pattern))
            {
                std::cout << std::format("{}: {}", line_n, match.str(0)) << std::endl;
            }
        }
    }
}

void Grep::recursive_search(const std::filesystem::path& dir)
{
    for (const auto &entry : std::filesystem::recursive_directory_iterator(_init_path))
    {
        if (std::filesystem::is_directory(entry)) {
            recursive_search(entry.path());
        } else {

        }
    }
}

Grep::Grep(const std::string &pattern,
           const std::string &file_or_dir,
           const std::unordered_set<std::string> &optional_args) : _pattern(pattern),
                                                                   _file_or_dir(file_or_dir),
                                                                   _optional_args(optional_args),
                                                                   _file_reader(file_or_dir),
                                                                   _ignore_case(false),
                                                                   _only_matches(false),
                                                                   _invert_match(false),
                                                                   _recursive(false),
                                                                   _init_path()
{
    // Include optional arguments
    if (_optional_args.find("-i") != _optional_args.end())
    {
        _ignore_case = true;
    }

    if (_optional_args.find("-o") != _optional_args.end())
    {
        _only_matches = true;
    }

    if (_optional_args.find("-v") != _optional_args.end())
    {
        _invert_match = true;
    }

    if (_optional_args.find("-r") != _optional_args.end())
    {
        _recursive = true;
    }

    // Compiles regex pattern supplied by user
    compile_regex(_pattern, _compiled_pattern);

    // Case where file was not able to be located on local filesystem
    if (!_recursive)
    {
        if (!file_exists(file_or_dir))
        {
            throw std::invalid_argument(std::format("File not found: {}", file_or_dir));
        }
    }
    else
    {
        if (!directory_exists(file_or_dir))
        {
            throw std::invalid_argument(std::format("Directory not found: {}", file_or_dir));
        }
        else
        {
            // Set initial path to given directory (after testing it exists)
            _init_path = _file_or_dir;
        }
    }
}