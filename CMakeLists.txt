cmake_minimum_required(VERSION 3.28)
project(dataStructure)

set(CMAKE_CXX_STANDARD 17)

add_executable(dataStructure main.cpp

        hash.cpp
        hash.h)

# 链表 数据结构
add_executable(linkedList

        linked_list/linkedList.cpp
        linked_list/linkedList.h
        linked_list/llMain.cpp)