cmake_minimum_required(VERSION 3.19)
project(RadixTrie)

set(CMAKE_CXX_STANDARD 17)
include_directories(${PROJECT_SOURCE_DIR}/module/SimpleTrieTemplate)

add_subdirectory("module/SimpleTrieTemplate")
add_executable(RadixTrie
        include/Parameters.h
        src/RadixTrie.cpp
        test/test.cpp)
