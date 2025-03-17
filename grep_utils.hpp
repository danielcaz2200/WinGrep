#ifndef GREP_UTILS
#define GREP_UTILS

#include <iostream>
#include <string>
#include <regex>

namespace GrepUtils
{
    void print_correct_usage();
    bool process_line(const bool &invert, const bool &match_found);
}

#endif