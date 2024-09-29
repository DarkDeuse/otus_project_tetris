cmake_minimum_required(VERSION 3.21)
project(Tetris VERSION 0.0.1 LANGUAGES CXX)

include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 2.6.x)
FetchContent_MakeAvailable(SFML)

add_executable(Tetris main.cpp 
               Block.cpp
               Block.hpp
               Field.cpp
               Field.hpp
               Game.cpp
               Game.hpp
               Settings.hpp)

set_target_properties(Tetris PROPERTIES 
CXX_STANDARD 17
CXX_STANDARD_REQUIRED ON)
          
if (CMAKE_CXX_COMPILER_ID MATCHES "Clang" OR
     CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
     target_compile_options(Tetris PRIVATE 
          -g
          -Wall
          -Wextra
          -Werror
          -pedantic
     )
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
     target_compile_options(Tetris PRIVATE
          /EHsc
          /W4
          /WX
     )
endif()

target_compile_features(Tetris PUBLIC cxx_std_17)

