cmake_minimum_required(VERSION 3.0)

set (CMAKE_CXX_STANDARD 17)

SET(SOURCES
    Logger.cpp
    FileLogger.cpp
    ConsoleLogger.cpp
    ComposedLogger.cpp
    NullLogger.cpp
)

add_library(Log ${SOURCES})
target_link_libraries(Log
    Threads::Threads 
)
target_include_directories(Log PUBLIC include 
    ${CMAKE_CURRENT_SOURCE_DIR} 
)