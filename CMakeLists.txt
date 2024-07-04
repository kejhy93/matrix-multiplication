cmake_minimum_required(VERSION 3.5)

project(semestralka LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

include_directories(${PROJECT_SOURCE_DIR}/src)
include_directories(${PROJECT_SOURCE_DIR}/lib)
include_directories(${PROJECT_SOURCE_DIR}/test)
add_executable(test_matrix test/test_Matrix.cpp src/Matrix.cpp)
add_executable(test_matrixMultiplication test/test_MatrixMultiplication.cpp src/MatrixMultiplication.cpp src/Matrix.cpp)

target_link_libraries(test_matrix Threads::Threads)
target_link_libraries(test_matrixMultiplication Threads::Threads)

file(GLOB SOURCES main.cpp ${PROJECT_SOURCE_DIR}/src/*.cpp)

add_executable(MatrixMult ${SOURCES})

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)
target_link_libraries(MatrixMult Threads::Threads)


if ( CMAKE_CXX_COMPILER_ID MATCHES "Clang|AppleClang|GNU" )
    target_compile_options( MatrixMult PRIVATE -Wall -Wextra -Wunreachable-code -Wpedantic -g)
endif()
if ( CMAKE_CXX_COMPILER_ID MATCHES "MSVC" )
    target_compile_options( MatrixMult PRIVATE /W4 )
endif()


if (${CMAKE_VERSION} VERSION_GREATER 3.5)
  set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT tests)
endif()


include(CTest)

enable_testing()
add_test(
  NAME test_matrix 
  COMMAND $<TARGET_FILE:test_matrix>)
add_test(
  NAME test_matrixMultiplication 
  COMMAND $<TARGET_FILE:test_matrixMultiplication>)