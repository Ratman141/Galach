cmake_minimum_required(VERSION 3.28.3)
project(Galach 
    VERSION 0.1.0 
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

SET(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib)

add_library(LEXER src/lexer.cpp)
set_target_properties(LEXER PROPERTIES PREFIX "")
target_include_directories(LEXER PUBLIC src/include)

add_library(INTERPRETER src/interpreter.cpp)
set_target_properties(INTERPRETER PROPERTIES PREFIX "")
target_include_directories(INTERPRETER PUBLIC src/include)

add_executable(Galach src/main.cpp)

target_link_libraries(Galach PRIVATE
    LEXER
    INTERPRETER
)
