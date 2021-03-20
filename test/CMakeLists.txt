cmake_minimum_required(VERSION 3.12)

set(APP_TEST bulk-test)
project(${APP_TEST})

set(CMAKE_CXX_STANDARD 17)

set(SOURCES test.cpp)

add_executable(${APP_TEST}
        ${SOURCES}
        ../bulk/Bulk.h
        ../bulk/Bulk.cpp
        ../writer/Console/ConsoleWriter.cpp
        ../writer/File/FileWriter.cpp
        ../batcher/Batcher.cpp
        ../bulk/Bulk.cpp
)

target_link_libraries(${APP_TEST} ${CONAN_LIBS_GTEST})

add_test(NAME ${APP_TEST} COMMAND $<TARGET_FILE:${APP_TEST}>)