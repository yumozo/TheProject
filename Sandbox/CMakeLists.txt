cmake_minimum_required(VERSION 3.25.1)
project(sandbox)

# set(CMAKE_CXX_STANDARD 17)

# Vars
set(INC_DIR "${CMAKE_CURRENT_LIST_DIR}/include")
set(SRC_DIR "${CMAKE_CURRENT_LIST_DIR}/src")

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Project
add_executable(Sandbox
  ${SRC_DIR}/main.cpp
)

include_directories(${CMAKE_SOURCE_DIR}/TheProject) # include files from TheProject
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