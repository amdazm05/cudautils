cmake_minimum_required(VERSION 3.1)
project(utilities)
option (TESTS_ENABLED "Enables testing for each utility" ON)
include_directories(
    ${PROJECT_SOURCE_DIR}/include
)

add_library(utils
    STATIC
    ${PROJECT_SOURCE_DIR}/src/fileoperations/fileoperations.cc
    ${PROJECT_SOURCE_DIR}/src/thread/threadpool.cc
)
target_include_directories(
    utils
    PUBLIC
    ${PROJECT_SOURCE_DIR}/include
)

if(TESTS_ENABLED)
    add_executable(filetest ${PROJECT_SOURCE_DIR}/tests/fileoperationtest.cc)
    add_executable(threadpooltest ${PROJECT_SOURCE_DIR}/tests/threadpooltest.cc)
    target_link_libraries(filetest  utils)
    target_link_libraries(threadpooltest  utils)
endif()
