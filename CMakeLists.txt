cmake_minimum_required(VERSION 3.12)
project(otus_bulk)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

set(CMAKE_CXX_STANDARD 17)

add_executable(otus_bulk
        main.cpp
        writer/Console/ConsoleWriter.cpp
        writer/File/FileWriter.cpp
        batcher/Batcher.cpp
        bulk/Bulk.cpp)

include(CTest)
enable_testing()

include_directories(${CMAKE_SOURCE_DIR})
add_subdirectory(test)