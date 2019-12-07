cmake_minimum_required (VERSION 3.8)

project ("FuzzyTechLib")

add_subdirectory("src")
add_subdirectory("test_sample")

add_library(FuzzyTech STATIC 
    ${fuzzy_tech_sources}
    ${fuzzy_tech_headers}
    )

add_subdirectory("lib/googletest")
add_subdirectory("autotests")
