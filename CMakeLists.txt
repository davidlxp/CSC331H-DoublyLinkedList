cmake_minimum_required(VERSION 3.20)
project(DoublyLinkedList)

set(CMAKE_CXX_STANDARD 14)

add_executable(DoublyLinkedList main.cpp node.h DList.cpp DList.h)
