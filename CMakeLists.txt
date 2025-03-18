cmake_minimum_required(VERSION 4.0)

project(WinGrep)

SET(CMAKE_SYSTEM_NAME Windows)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -fdiagnostics-color=always -g")

set(SOURCES
    main.cpp
    grep.cpp
    grep_utils.cpp
    file_reader.cpp
)

set(HEADERS
    grep.hpp
    grep_utils.hpp
    file_reader.hpp
)

add_executable(grep ${SOURCES} ${HEADERS})