cmake_minimum_required(VERSION 3.8)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory("fuzzyset")

add_executable(main_auto
               ${fuzzy_set_tests}
               main_auto.cpp)
target_link_libraries(main_auto FuzzyTech gtest_main)
target_include_directories(main_auto PUBLIC
                           "../src"
                           )

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
enable_testing()
add_test(NAME main_auto COMMAND main_auto)