set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_library(iirosc iir_oscillator.cpp)
target_include_directories(iirosc PUBLIC .)
