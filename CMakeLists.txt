cmake_minimum_required(VERSION 3.16.3)

# Set the project name
project(Sudocraft VERSION 0.5)
set(CMAKE_BUILD_TYPE Debug)
add_subdirectory(deps/libnoise)

# Add executable
file(GLOB_RECURSE SOURCES "${CMAKE_SOURCE_DIR}/src/*.cpp")
file(GLOB_RECURSE HEADERS "${CMAKE_SOURCE_DIR}/include/*.h" "${CMAKE_SOURCE_DIR}/include/*.hpp" "${CMAKE_SOURCE_DIR}/include/*.inl")

add_executable(sudocraft ${SOURCES} ${HEADERS})
target_compile_options(sudocraft PUBLIC "-std=c++17" "-g")

# Add configuration file
#configure_file(Sudocraft.h.in Sudocraft.h)

target_link_libraries(sudocraft PRIVATE libnoise)

# Adds Directories
target_include_directories(sudocraft PRIVATE ${CMAKE_SOURCE_DIR}/include)
target_include_directories(sudocraft PUBLIC ${CMAKE_SOURCE_DIR}/deps/libnoise/include)

# Enable support for C++ 17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

