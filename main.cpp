#include <iostream>
#include <string>
#include <unordered_set>
#include <format>
#include <filesystem>
#include "grep_utils.hpp"
#include "grep.hpp"

int main(int argc, char *argv[])
{
    try
    {
        if (argc < 3)
        {
            GrepUtils::print_correct_usage();
            return 1;
        }

        // Set containing optional positional args
        std::unordered_set<std::string> optional_args;

        // Pattern, file name must be arg at pos 1 and 2
        std::string pattern = argv[1];
        std::string file_or_dir = argv[2];

        if (argc > 3)
        {
            for (std::size_t i = 3; i < argc; i++)
            {
                std::string current_argument = argv[i];

                if (current_argument.compare("-i") == 0)
                {
                    // Ignore case, compare without case sensitivity
                    optional_args.insert(current_argument);
                }
                else if (current_argument.compare("-o") == 0)
                {
                    // Print only matched parts of string
                    optional_args.insert(current_argument);
                }
                else if (current_argument.compare("-v") == 0)
                {
                    // Invert: print only lines that do not match pattern
                    optional_args.insert(current_argument);
                }
                else if (current_argument.compare("-r") == 0)
                {
                    // Recurse: search across all sub directories for grepped string
                    optional_args.insert(current_argument);
                }
                else
                {
                    GrepUtils::print_correct_usage();
                    throw std::invalid_argument(std::format("Invalid argument: {}\n", current_argument));
                }
            }
        }

        // Construct instance of Grep class + perform regex search
        Grep grep(pattern, file_or_dir, optional_args);
        grep.search();
    }
    catch (const std::runtime_error &e)
    {
        std::cout << e.what() << "\n";
        return 1;
    }
    catch (const std::invalid_argument &e)
    {
        std::cout << e.what() << "\n";
        return 1;
    }

    return 0;
}
