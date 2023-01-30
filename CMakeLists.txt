cmake_minimum_required(VERSION 3.1)
project(s_fft)
find_package(CUDA REQUIRED)
include_directories(
    ${PROJECT_SOURCE_DIR}/include
)

add_library(utils
    STATIC
    ${PROJECT_SOURCE_DIR}/src/fileoperations/fileoperations.cc
)

add_executable(${PROJECT_NAME} ${PROJECT_SOURCE_DIR}/main/main.cc)
target_link_libraries(${PROJECT_NAME}  utils)

# FILE(
#     COPY ${PROJECT_SOURCE_DIR}/input
#     DESTINATION ${CMAKE_CURRENT_BINARY_DIR}
# )
