cmake_minimum_required(VERSION 3.21.3)
# Set the project name
project(Sudocraft VERSION 0.5)
# Add executable
set(SOURCES ${CMAKE_SOURCE_DIR}/src/Game.cpp ${CMAKE_SOURCE_DIR}/src/Character.cpp ${CMAKE_SOURCE_DIR}/src/Craft.cpp ${CMAKE_SOURCE_DIR}/src/Inventory.cpp ${CMAKE_SOURCE_DIR}/src/Item.cpp  ${CMAKE_SOURCE_DIR}/src/Tool.cpp  ${CMAKE_SOURCE_DIR}/src/Weapon.cpp ${CMAKE_SOURCE_DIR}/include/SafeData.hpp)
add_executable(sudocraft ${SOURCES})

# Add configuration file
#configure_file(Sudocraft.h.in Sudocraft.h)

# Adds Directories
target_include_directories(sudocraft PUBLIC ${CMAKE_SOURCE_DIR}/include)

# Enable support for C++ 11
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

