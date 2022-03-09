cmake_minimum_required(VERSION 3.21.0)
# Set the project name
project(Sudocraft VERSION 0.5)
include(ExternalProject)
find_package(Git REQUIRED)

ExternalProject_Add ( noise
	GIT_REPOSITORY https://github.com/eXpl0it3r/libnoise.git
	SOURCE_DIR ${CMAKE_SOURCE_DIR}/deps/libnoise
	INSTALL_COMMAND cmake -E echo "Skipping install set."
)
#add_subdirectory(deps/libnoise)

# Add executable
file(GLOB_RECURSE SOURCES "${CMAKE_SOURCE_DIR}/src/*.cpp" "${CMAKE_SOURCE_DIR}/deps/*.cpp")
file(GLOB_RECURSE HEADERS "${CMAKE_SOURCE_DIR}/include/*.h" "${CMAKE_SOURCE_DIR}/include/*.hpp" "${CMAKE_SOURCE_DIR}/include/*.inl" "${CMAKE_SOURCE_DIR}/deps/*.h" "${CMAKE_SOURCE_DIR}/deps/*.hpp" "${CMAKE_SOURCE_DIR}/deps/*.inl")
add_executable(sudocraft ${SOURCES} ${HEADERS})
add_dependencies(sudocraft noise)

# Add configuration file
#configure_file(Sudocraft.h.in Sudocraft.h)
# Adds Directories
target_include_directories(sudocraft PUBLIC ${CMAKE_SOURCE_DIR}/include)
target_include_directories(sudocraft PUBLIC ${CMAKE_SOURCE_DIR}/deps)

# Enable support for C++ 17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

