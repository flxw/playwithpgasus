cmake_minimum_required (VERSION 3.1)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

include_directories(../pgasus/include)
include_directories(../pgasus/src)
link_directories(../pgasus/bin)
add_executable(tasking_test tasking_test.cpp)

target_link_libraries(tasking_test
  hpinuma
  hpinuma_util
  hpinuma_msource)
