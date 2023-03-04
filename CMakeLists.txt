cmake_minimum_required(VERSION 3.25.1)
project(theproject-dev)

# set(CMAKE_CXX_STANDARD 17)
# set(CMAKE_BUILD_TYPE Debug)
#   do -DCMAKE_BUILD_TYPE=Debug instead

# Set up sln projects
add_subdirectory(TheProject)
add_subdirectory(Sandbox)