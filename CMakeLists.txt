cmake_minimum_required(VERSION 3.8)
project(CS225GradeCalculator)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp graphics.h graphics.cpp ASCIIcalculator.txt ASCIIcs225.txt ASCIIgrade.txt)
add_executable(CS225GradeCalculator ${SOURCE_FILES})