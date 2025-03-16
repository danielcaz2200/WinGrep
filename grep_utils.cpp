#include <string>
#include <filesystem>
#include "grep_utils.hpp"

// Print correct usage of the grep command
void GrepUtils::print_correct_usage() {
    std::cerr << "Usage: ./grep <string> <filename>\n";
    std::cerr << "Options...\n";
    std::cerr << "\t-i\t\t\tIgnore case to perform a case insensitive search.\n";
    std::cerr << "\t-o\t\t\tOnly print the matched string in the input file.\n";
    std::cerr << "\t-v\t\t\tPrints out all the lines that do not match the specified pattern.\n";
}

// Logic to process a line in the supplied text
bool GrepUtils::process_line(const bool& invert, const bool& match_found) {
    if ((!invert && match_found) || (invert && !match_found)) {
        return true;
    }
    
    return false;
}