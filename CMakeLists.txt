cmake_minimum_required(VERSION 3.19)

project(unwindStack)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
# Don't use e.g. GNU extension (like -std=gnu++11) for portability
set(CMAKE_CXX_EXTENSIONS OFF)

include(FetchContent)

# Also requires one of: libbfd (gnu binutils), libdwarf, libdw (elfutils)
FetchContent_Declare(backward
    GIT_REPOSITORY https://github.com/bombela/backward-cpp
    GIT_TAG master  # or a version tag, such as v1.6
    SYSTEM          # optional
)
FetchContent_MakeAvailable(backward)

set(PROJECT_SOURCES
    main.cpp
    backward.cpp
)

add_executable(${PROJECT_NAME} ${PROJECT_SOURCES})

# Add Backward to your target
# (either Backward::Interface, Backward::Object, or Backward::Backward)
target_link_libraries(${PROJECT_NAME} PUBLIC
    Backward::Interface
)

