cmake_minimum_required (VERSION 3.8)


set(PROJECT project)

project(${PROJECT})

set(HEADER 
	source/string.h
	)

set(SOURCE 
	source/main.cpp
	source/string.cpp
	)


add_executable(${PROJECT} ${HEADER} ${SOURCE})