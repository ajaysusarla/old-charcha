message(STATUS "Building console based ui library for ${CMAKE_SYSTEM_NAME}")

# Console UI Library
set(CHARCHA_UI_LIB_SRCS
        display.c
)

source_group("Charcha Console UI Library" FILES ${CHARCHA_UI_LIB_SRCS})
add_library(charcha_ui_lib STATIC ${CHARCHA_UI_LIB_SRCS})
target_link_libraries(charcha_ui_lib
        ${CURSES_LIBRARIES}
)
