cmake_minimum_required (VERSION 3.8)


set(PROJECT project)

project(${PROJECT})

set(HEADER 
	source/list.h
	)

set(SOURCE 
	source/main.cpp
	source/list.cpp
	)


add_executable(${PROJECT} ${HEADER} ${SOURCE})