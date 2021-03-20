cmake_minimum_required(VERSION 3.17)
project(otus_bulk)

set(CMAKE_CXX_STANDARD 17)

add_executable(otus_bulk
        main.cpp
        writer/Writer.h
        writer/Console/ConsoleWriter.cpp
        writer/File/FileWriter.cpp
        batcher/Batcher.cpp batcher/Batcher.h)

include_directories(${CMAKE_SOURCE_DIR})