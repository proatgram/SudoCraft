cmake_minimum_required(VERSION 3.16.3)

# Set the project name
project(Sudocraft VERSION 0.5)
set(CMAKE_BUILD_TYPE Debug)
add_subdirectory(deps/libnoise)

set(CPACK_GENERATOR "TGZ" "DEB" "RPM")
set(CPACK_PACKAGE_NAME "SudoCraft")
set(CPACK_PACKAGE_VERSION 0.5)

EXECUTE_PROCESS(COMMAND uname -m COMMAND tr -d '\n' OUTPUT_VARIABLE ARCHITECTURE)

set(CPACK_DEBIAN_PACKAGE_ARCHITECTURE ${ARCHITECTURE})
set(CPACK_DEBIAN_PACKAGE_DEPENDS "libstdc++6 (>= 10.3.0-1ubuntu1~20.04), libc6 (>= 2.31-0ubuntu9.7), libgcc1 (>= 1:10.3.0-1ubuntu1~20.04)")  
set(CPACK_PACKAGE_CONTACT "tgh6407@gmail.com")
set(CPACK_DEBIAN_PACKAGE_MAINTAINER "Timothy Hutchins")
set(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_CURRENT_SOURCE_DIR}/COPYING")
set(CPACK_RESOURCE_FILE_README "${CMAKE_CURRENT_SOURCE_DIR}/README.md")
set(CPACK_DEBIAN_FILE_NAME DEB-DEFAULT)
set(CPACK_PACKAGE_NAME "${PROJECT_NAME}")

set(CPACK_PACKAGE_INSTALL_DIRECTORY ${CPACK_PACKAGE_NAME})

set(CPACK_SOURCE_IGNORE_FILES "build/;/build/;//.git;.git;")

# Add executable
file(GLOB_RECURSE SOURCES "${CMAKE_SOURCE_DIR}/src/*.cpp")
file(GLOB_RECURSE HEADERS "${CMAKE_SOURCE_DIR}/include/*.h" "${CMAKE_SOURCE_DIR}/include/*.hpp" "${CMAKE_SOURCE_DIR}/include/*.inl")

add_executable(sudocraft ${SOURCES} ${HEADERS})
target_compile_options(sudocraft PUBLIC "-std=c++17" "-g")

# Add configuration file
#configure_file(Sudocraft.h.in Sudocraft.h)

target_link_libraries(sudocraft PRIVATE libnoise)

# Adds Directoriescd .. && git archive --format=tar.gz -o $(PROJECT_NAME)-$(PROJECT_VERSION).tar.gz --prefix=$(PROJECT_NAME)-$(PROJECT_VERSION)/ main && mv ../$(PROJECT_NAME)-$(PROJECT_VERSION) .)

target_include_directories(sudocraft PRIVATE ${CMAKE_SOURCE_DIR}/include)
target_include_directories(sudocraft PUBLIC ${CMAKE_SOURCE_DIR}/deps/libnoise/include)

# Custom targets

add_custom_target(dist cpack -G TGZ && cpack -G TBZ2 && cpack -G ZIP && cpack -G RPM && cpack -G DEB)
# Enable support for C++ 17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

install (TARGETS sudocraft RUNTIME DESTINATION "bin" COMPONENT applications)
include (CPack)
