cmake_minimum_required(VERSION 3.8)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(fuzzy_set_sources
    ${CMAKE_CURRENT_SOURCE_DIR}/fuzzyset.cpp
    PARENT_SCOPE
    )

set(fuzzy_set_headers
    ${CMAKE_CURRENT_SOURCE_DIR}/fuzzyset.h
    PARENT_SCOPE
)