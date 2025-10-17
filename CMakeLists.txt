cmake_minimum_required(VERSION 3.18)
project(intvector VERSION 1.0)
set(CPP_SRCS  # all cpp source files
  intvector.cpp
  intvector_test.cpp
  catch_amalgamated.cpp
  
)
set(CMAKE_CXX_STANDARD 20)
add_executable(${PROJECT_NAME} ${CPP_SRCS})
