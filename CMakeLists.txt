cmake_minimum_required(VERSION 3.19)

project(unwindStack)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
# Don't use e.g. GNU extension (like -std=gnu++11) for portability
set(CMAKE_CXX_EXTENSIONS OFF)

find_package(libdwarf REQUIRED)
find_package(libelf REQUIRED)
message(STATUS "libdwarf found: ${libdwarf_FOUND}")
message(STATUS "libdwarf include dirs: ${libdwarf_INCLUDE_DIRS}")
message(STATUS "libdwarf libraries: ${libdwarf_LIBRARIES}")

message(STATUS "libelf found: ${libelf_FOUND}")
message(STATUS "libelf include dirs: ${libelf_INCLUDE_DIRS}")
message(STATUS "libelf libraries: ${libelf_LIBRARIES}")

set(PROJECT_SOURCES
    main.cpp
    backward.cpp
)

add_executable(${PROJECT_NAME} ${PROJECT_SOURCES})

target_link_libraries(${PROJECT_NAME} PUBLIC
    libelf::libelf
    libdwarf::libdwarf
)
