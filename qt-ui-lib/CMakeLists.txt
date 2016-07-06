message(STATUS "Building qt based ui library for ${CMAKE_SYSTEM_NAME}")

# QT UI Library
set(CHARCHA_QT_UI_LIB_SRCS
        mainwindow.cpp
)

source_group("Charcha QT UI Library" FILES ${CHARCHA_QT_UI_LIB_SRCS})
add_library(charcha_qt_ui_lib STATIC ${CHARCHA_QT_UI_LIB_SRCS})
target_link_libraries(charcha_qt_ui_lib
        ${QT_LIBRARIES}
)
