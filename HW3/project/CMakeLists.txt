cmake_minimum_required (VERSION 3.8)


set(PROJECT project)

project(${PROJECT})

set(HEADER 
	source/rational.h
	)

set(SOURCE 
	source/main.cpp
	source/rational.cpp
	)


add_executable(${PROJECT} ${HEADER} ${SOURCE})