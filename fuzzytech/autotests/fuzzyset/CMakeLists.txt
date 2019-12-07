cmake_minimum_required(VERSION 3.8)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(fuzzy_set_tests
    ${CMAKE_CURRENT_SOURCE_DIR}/fuzzyset_auto.cpp
    PARENT_SCOPE
    )
