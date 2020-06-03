cmake_minimum_required(VERSION 3.16.3)

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")

project(findroots)

add_executable(
	findroots
	main.cpp
)
