cmake_minimum_required(VERSION 3.20)
project(DoublyLinkedList)

set(CMAKE_CXX_STANDARD 14)

add_executable(DoublyLinkedList main.cpp DList.cpp DList.h DListIterator.cpp DListIterator.h node.h)
