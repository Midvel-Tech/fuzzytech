cmake_minimum_required(VERSION 3.8)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_subdirectory ("fuzzyset")

set(fuzzy_tech_sources
    ${fuzzy_set_sources}
    PARENT_SCOPE
    )

set(fuzzy_tech_headers
    ${fuzzy_set_headers}
    PARENT_SCOPE
)