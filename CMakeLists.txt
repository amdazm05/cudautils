cmake_minimum_required(VERSION 3.1)
project(utilities)
set(CXX_STANDARD_REQUIRED 20)
SET(GCC_COVERAGE_COMPILE_FLAGS "-fcoroutines")
SET(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}")
option (TESTS_ENABLED "Enables testing for each utility" ON)
include_directories(
    ${PROJECT_SOURCE_DIR}/include
)

add_library(utils
    STATIC
    ${PROJECT_SOURCE_DIR}/src/fileoperations/fileoperations.cc
    ${PROJECT_SOURCE_DIR}/src/thread/threadpool.cc
    ${PROJECT_SOURCE_DIR}/src/memory/memorypool.cc
)
target_include_directories(
    utils
    PUBLIC
    ${PROJECT_SOURCE_DIR}/include
)
target_link_libraries(
    utils
    PUBLIC
    pthread
)

if(TESTS_ENABLED)
    add_executable(filetest ${PROJECT_SOURCE_DIR}/tests/fileoperationtest.cc)
    add_executable(threadpooltest ${PROJECT_SOURCE_DIR}/tests/threadpooltest.cc)
    add_executable(timertests ${PROJECT_SOURCE_DIR}/tests/testtimers.cc)
    add_executable(memorypooltest ${PROJECT_SOURCE_DIR}/tests/memorypooltest.cc)
    add_executable(coroutine ${PROJECT_SOURCE_DIR}/tests/coroutinetest.cc)
    target_link_libraries(filetest  utils)
    target_link_libraries(threadpooltest  utils)
    target_link_libraries(timertests  utils)
    target_link_libraries(memorypooltest utils)
    target_link_libraries(coroutine utils )
endif()
