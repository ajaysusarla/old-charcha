message(STATUS "Building ui library for ${CMAKE_SYSTEM_NAME}")

# UI Library
set(CHARCHA_UI_LIB_SRCS
        mainwindow.cpp
)

source_group("Charcha UI Library" FILES ${CHARCHA_UI_LIB_SRCS})
add_library(charcha_ui_lib STATIC ${CHARCHA_UI_LIB_SRCS})
target_link_libraries(charcha_ui_lib
        ${QT_LIBRARIES}
)
