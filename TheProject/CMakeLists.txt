include(FetchContent)
cmake_minimum_required(VERSION 3.25.1)
project(theproject)

# set(CMAKE_CXX_STANDARD 17)
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

# Vars
set(INC_DIR "${CMAKE_CURRENT_LIST_DIR}/include")
set(SRC_DIR "${CMAKE_CURRENT_LIST_DIR}/src")
set(SRC_TP_DIR "${CMAKE_CURRENT_LIST_DIR}/src/TheProject")
# Settings
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(GLFW_BUILD_DOCS     OFF CACHE INTERNAL "")
set(GLFW_BUILD_TESTS    OFF CACHE INTERNAL "")
set(GLFW_BUILD_EXAMPLES OFF CACHE INTERNAL "")
# Preprocessor definitions
add_compile_definitions(TP_PLATFORM_WINDOWS)
add_compile_definitions(TP_BUILD_DLL)
add_compile_definitions(TP_ENABLE_ASSERTS)
# Fetch vendors content
FetchContent_Declare(spdlog GIT_REPOSITORY https://github.com/gabime/spdlog.git GIT_TAG v1.11.0)
FetchContent_Declare(glfw GIT_REPOSITORY https://github.com/glfw/glfw.git GIT_TAG 3.3.8)
FetchContent_MakeAvailable(spdlog glfw)

# Project
add_library(TheProject SHARED
    ${SRC_TP_DIR}/application.cpp
    ${SRC_TP_DIR}/log.cpp
    ${SRC_DIR}/Platform/Windows/win_window.cpp
)
# PCH
target_precompile_headers(TheProject PUBLIC
    ${SRC_DIR}/tppch.h
)
# Additional include directories
target_include_directories(TheProject PRIVATE
    ${spdlog_SOURCE_DIR}/include
    ${glfw_SOURCE_DIR}/include
    ${SRC_TP_DIR}
    ${SRC_TP_DIR}/Events
)
target_link_libraries(TheProject
    glfw
    opengl32
    ${CMAKE_DL_LIBS}
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