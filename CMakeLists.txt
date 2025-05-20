cmake_minimum_required(VERSION 3.2)
project(cicdtest)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
list(APPEND CMAKE_PREFIX_PATH 
    "E:/raylib/w64devkit/external"
)



set(CMAKE_C_STANDARD 23)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

find_package(raylib REQUIRED)

set(SOURCES
    ./src/main.c
)

include_directories(
    "E:/raylib/w64devkit/external/include"
    "E:/raylib/w64devkit/x86_64-w64-mingw32/include"
)

# set(HEADERS
#     ./src/animation/script.h
# )

add_executable(cicdtest ${SOURCES} ${HEADERS})

target_link_libraries(cicdtest raylib winmm gdi32 kernel32)

add_custom_target(build_and_run
    COMMAND ${CMAKE_COMMAND} --build ${CMAKE_BINARY_DIR} --target cicdtest
    COMMAND cicdtest
    DEPENDS cicdtest
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
)

add_custom_target(run
    COMMAND cicdtest
    DEPENDS cicdtest
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
)