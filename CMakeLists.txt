cmake_minimum_required(VERSION 3.12)

set(APP_NAME otus_bulk)
if (DEFINED ENV{TRAVIS_BUILD_NUMBER})
    project(${APP_NAME} VERSION 0.0.$ENV{TRAVIS_BUILD_NUMBER})
else()
    project(${APP_NAME} VERSION 0.0.1)
endif()

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

set(CMAKE_CXX_STANDARD 17)

add_executable(${APP_NAME}
        main.cpp
        writer/Console/ConsoleWriter.cpp
        writer/File/FileWriter.cpp
        batcher/Batcher.cpp
        bulk/Bulk.cpp)

include(CTest)
enable_testing()

include_directories(${CMAKE_SOURCE_DIR})
add_subdirectory(test)

target_compile_options(${APP_NAME} PRIVATE -Wall -Wpedantic -Wextra -Werror)

install(TARGETS ${APP_NAME} RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)

set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")

set(CPACK_PACKAGE_CONTACT scfocus@yandex.ru)

include(CPack)