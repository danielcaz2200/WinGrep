# WinGrep
## Recreation of the Linux/Unix Grep command as a standalone C++ command line utility, utilizing C++20 standard libraries.
This is a C++ implementation of a simplified `grep` command-line tool that allows you to search for regular expression patterns within files and directories.

This project was implemented using modern C++ libraries, including ```std::format```, ```std::regex```, and ```std::filesystem```

### Usage
Usage: ```./grep <regex pattern> <filename> -<options>```

### Options
- `-i`: Ignore case and perform a case-insensitive search.
- `-o`: Only print the matched string in the input file.
- `-v`: Prints out all lines that do not match the specified pattern.
- `-r`: Recurses through the filesystem looking for matches. This allows you to search within files across subdirectories.

### Building
This project was developed using MinGW's GCC/G++ compiler.
A CMakeLists.txt file is provided to generate a Makefile for building the project with the Make utility.

An example usage:
```
mkdir build
cd build
cmake ..
make
./grep
```