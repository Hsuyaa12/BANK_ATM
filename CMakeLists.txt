cmake_minimum_required(VERSION 3.29)
project(Programming_Assignment_2)

set(CMAKE_CXX_STANDARD 20)

add_executable(Programming_Assignment_2 prog2.cpp
        Account.cpp
        Account.h
        Bank.cpp
        Bank.h
        ATM.cpp
        ATM.h
)
