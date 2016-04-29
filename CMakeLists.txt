project(Charcha)
cmake_minimum_required(VERSION 2.8.11)


set(CMAKE_AUTOMOC ON)
include(cmake/Modules/MacroOutOfSourceBuild.cmake)
MACRO_ENSURE_OUT_OF_SOURCE_BUILD(
    "We don't support building in source, please create a build folder elsewhere and remember to run git clean -xdf to remoev temporary files created by CMake."
)

## Options ##

# Tests
option(MAKE_TESTS "Make the tests" OFF)



add_executable(charcha charcha-main.cpp)


if (MAKE_TESTS)
        add_subdirectory(tests)
endif()
