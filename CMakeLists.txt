cmake_minimum_required(VERSION 3.16)

project(unwindStack)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
# Don't use e.g. GNU extension (like -std=gnu++11) for portability
set(CMAKE_CXX_EXTENSIONS OFF)

find_package(LibElf REQUIRED)
find_package(LibDwarf REQUIRED)
message(STATUS "libdwarf found: ${LIBDWARF_FOUND}")
message(STATUS "libdwarf include dirs: ${LIBDWARF_INCLUDE_DIRS}")
message(STATUS "libdwarf libraries: ${LIBDWARF_LIBRARIES}")

message(STATUS "libelf found: ${LIBELF_FOUND}")
message(STATUS "libelf include dirs: ${LIBELF_INCLUDE_DIRS}")
message(STATUS "libelf libraries: ${LIBELF_LIBRARIES}")

set(PROJECT_SOURCES
    main.cpp
    backward.cpp
)

add_executable(${PROJECT_NAME} ${PROJECT_SOURCES})

target_link_libraries(${PROJECT_NAME} PUBLIC
    ${LIBDWARF_LIBRARIES}
    ${LIBELF_LIBRARIES}
)

