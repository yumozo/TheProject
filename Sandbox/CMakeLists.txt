cmake_minimum_required(VERSION 3.25.1)
project(sandbox)

# set(CMAKE_CXX_STANDARD 17)

# Vars
set(INC_DIR "${CMAKE_CURRENT_LIST_DIR}/include")
set(SRC_DIR "${CMAKE_CURRENT_LIST_DIR}/src")

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
# Preprocessor definitions
add_compile_definitions(TP_PLATFORM_WINDOWS)

# Fetch vendors content
FetchContent_Declare(spdlog GIT_REPOSITORY https://github.com/gabime/spdlog.git GIT_TAG v1.11.0)
FetchContent_MakeAvailable(spdlog)

# Project
add_executable(Sandbox
${SRC_DIR}/main.cpp
)
# Additional include directories
target_include_directories(Sandbox PRIVATE
  ${CMAKE_SOURCE_DIR}/TheProject/src
  ${spdlog_SOURCE_DIR}/include
)
# Include files from TheProject
include_directories(${CMAKE_SOURCE_DIR}/TheProject)
target_link_libraries(Sandbox
    TheProject
)                             

install(TARGETS Sandbox
    RUNTIME DESTINATION bin
)

# set_target_properties(main
#     PROPERTIES
#     ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
#     LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
#     RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
# )