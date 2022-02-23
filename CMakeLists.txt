cmake_minimum_required(VERSION 3.16.3)
project(lazy-put)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(lazy-write)

set(Mdp $ENV{HOME}/bin/mdp)
if(EXISTS ${Mdp})
	add_custom_command(
		COMMAND ${Mdp} lazy-put.md && touch lazy-put.cpp
		DEPENDS lazy-put.md
		WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}
		OUTPUT ${PROJECT_SOURCE_DIR}/lazy-put.cpp
	)
endif()
	

add_executable(lazy-put ${PROJECT_SOURCE_DIR}/lazy-put.cpp)
target_link_libraries(lazy-put lazy-write)
target_link_libraries(lazy-put stdc++fs)

