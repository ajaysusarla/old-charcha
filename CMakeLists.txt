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

## Dependencies ##
# Curses
find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})
include_directories(core-lib)
include_directories(ui-lib)
## Subdirectories ##
add_subdirectory(core-lib)
add_subdirectory(ui-lib)


add_executable(charcha
        main.c
)

target_link_libraries(charcha
  charcha_core_lib
  charcha_ui_lib
  ${CURSES_LIBRARIES}
)


if (MAKE_TESTS)
        add_subdirectory(tests)
endif()
