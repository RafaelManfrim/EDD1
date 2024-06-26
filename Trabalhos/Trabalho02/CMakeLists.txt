cmake_minimum_required(VERSION 3.10)

project(RPG-SFML-ED)

set(CMAKE_CXX_STANDARD 11)

find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)

include_directories(headers)

file(GLOB SOURCES "src/*.cpp")

add_executable(rpg-sfml-ed ${SOURCES})

target_link_libraries(rpg-sfml-ed sfml-graphics sfml-window sfml-system sfml-audio)