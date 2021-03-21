cmake_minimum_required(VERSION 3.12)

set(APP_TEST bulk_test)
#project(${APP_TEST})

set(CMAKE_CXX_STANDARD 17)

set(SOURCES main.cpp test.cpp blockTest.cpp)

add_executable(${APP_TEST}
        ${SOURCES}
        ${CMAKE_SOURCE_DIR}/bulk/Bulk.h
        ${CMAKE_SOURCE_DIR}/bulk/Bulk.cpp
        ${CMAKE_SOURCE_DIR}/writer/Console/ConsoleWriter.cpp
        ${CMAKE_SOURCE_DIR}/writer/File/FileWriter.cpp
        ${CMAKE_SOURCE_DIR}/batcher/Batcher.cpp
        ${CMAKE_SOURCE_DIR}/bulk/Bulk.cpp
)

target_link_libraries(${APP_TEST} ${CONAN_LIBS_GTEST})

add_test(NAME ${APP_TEST} COMMAND $<TARGET_FILE:${APP_TEST}>)