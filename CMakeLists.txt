cmake_minimum_required(VERSION 2.8)
project (Goodreads)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(SOURCES src/Main.cpp
            src/Book.cpp)

set(HEADERS src/Book.h)

add_executable(Goodreads ${SOURCES} ${HEADERS})
