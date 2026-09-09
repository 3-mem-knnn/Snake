cmake_minimum_required(VERSION 3.16)

project(SnakeGame LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(snake
    main.cpp
    Game.cpp
    Snake.cpp
    Food.cpp
)

if(WIN32)
    target_sources(snake PRIVATE Console_Windows.cpp)
else()
    target_sources(snake PRIVATE Console_Linux.cpp)
endif()

if(MSVC)
    target_compile_options(snake PRIVATE /W4)
else()
    target_compile_options(snake PRIVATE -Wall -Wextra -Wpedantic)
endif()
