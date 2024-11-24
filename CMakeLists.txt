project(ToneGenerator)
cmake_minimum_required(VERSION 3.22)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(tone_gen tone_gen.cpp)
target_link_libraries(tone_gen PUBLIC iirosc)
target_include_directories(tone_gen PUBLIC .)

add_subdirectory(lib)
