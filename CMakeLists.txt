cmake_minimum_required(VERSION 3.10)
project(LoginAppProject)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Set the output directory
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/out/build/x64-debug)

# Add the executable target
add_executable(LoginAppProject  LoginAppProject.cpp)

# Include and link the cpr library
include(FetchContent)

FetchContent_Declare(
    cpr
    GIT_REPOSITORY https://github.com/libcpr/cpr.git
    #GIT_TAG 6e4660dfdbbd3c6dd9748ecac2cce9de1d7ef94e # The latest commit at the time of writing
)

FetchContent_MakeAvailable(cpr)

target_link_libraries(LoginAppProject PRIVATE cpr::cpr)

# Copy the cpr.dll to the output directory
add_custom_command(TARGET LoginAppProject POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
    $<TARGET_FILE:cpr::cpr>
    ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})




