message(STATUS "Building core library for ${CMAKE_SYSTEM_NAME}")

# Core Library
set(CHARCHA_CORE_LIB_SRCS
        charcha.c
        net_tcp.c
        net_ssl.c
        cstring.c
        irc-core.c
        util.c
        conf.c
        conf-common.c
        conf-account.c
        utf8.c
)

source_group("Charcha Core Library" FILES ${CHARCHA_CORE_LIB_SRCS})
add_library(charcha_core_lib STATIC ${CHARCHA_CORE_LIB_SRCS})
target_link_libraries(charcha_core_lib
        ${QT_LIBRARIES}
)
