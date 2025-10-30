cmake_minimum_required(VERSION 3.28)
project(dataStructure)

set(CMAKE_CXX_STANDARD 17)

add_executable(dataStructure_main main.cpp
        hash.cpp
        hash.h
        stackl.cpp
        stackl.h)

add_executable(linkedList_main
        linked_list/llMain.cpp
        linked_list/linkedList.cpp
        linked_list/linkedList.h
)
add_executable(stack LinearLinked_stack/stackmain.cpp
        LinearLinked_stack/stack.cpp

)
