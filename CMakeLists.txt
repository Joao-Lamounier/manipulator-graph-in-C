cmake_minimum_required(VERSION 3.26)
project(untitled1 C)

set(CMAKE_C_STANDARD 11)

add_executable(untitled1
        graph_list/graph_list.h
        graph_list/graph_list.c
        utils/utils.h
        main.c
        utils/utils.c
        node/node.c
        graph_matrix/graph_matrix.c
        queue/queue.c
        queue/queue.h)
