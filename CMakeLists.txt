cmake_minimum_required(VERSION 3.10)

project (main)

set (CMAKE_CXX_STANDARD 23)
set (CMAKE_CXX_STANDARD_REQUIRED ON)

include(src/sources.cmake)
add_executable(main ${earTraining_SOURCES})

find_package(fmt REQUIRED)
find_package(Range-v3 REQUIRED)
find_package(SFML 2.5 COMPONENTS graphics audio window system REQUIRED)
target_link_libraries(main PRIVATE fmt::fmt range-v3 sfml-graphics sfml-audio sfml-window sfml-system)

file(COPY ${CMAKE_SOURCE_DIR}/resources
     DESTINATION ${CMAKE_BINARY_DIR})