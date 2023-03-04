cmake_minimum_required(VERSION 3.25.1)
project(theproject)

# set(CMAKE_CXX_STANDARD 17)
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

# Vars
set(INC_DIR "${CMAKE_CURRENT_LIST_DIR}/include")
set(SRC_DIR "${CMAKE_CURRENT_LIST_DIR}/src")
set(SRC_TP_DIR "${CMAKE_CURRENT_LIST_DIR}/src/TheProject")

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Preprocessor definitions
add_compile_definitions(TP_PLATFORM_WINDOWS)
add_compile_definitions(TP_BUILD_DLL)

# Project
add_library(TheProject SHARED
    ${SRC_TP_DIR}/application.cpp
)

install(TARGETS TheProject
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib
)

# set_target_properties(theproject
#     PROPERTIES
#     ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
#     LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
#     RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
# )