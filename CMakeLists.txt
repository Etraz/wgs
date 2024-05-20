cmake_minimum_required(VERSION 3.22)
project(wgs)

set(CMAKE_CXX_STANDARD 20)
add_subdirectory(code)
add_executable(local ${HEADERS} local.cpp)
target_link_libraries(local
        wgs_components
        wgs_connection
        wgs_edges
        wgs_factories
        wgs_game
        #wgs_server
        )