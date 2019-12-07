cmake_minimum_required(VERSION 3.8)

project("sample")

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(sample sample.cpp)

target_link_libraries(sample PUBLIC FuzzyTech)
target_include_directories(sample PUBLIC
                           "../src"
                           "../src/fuzzyset"
                           )

