#ifndef TREINO_GRAFOS_UTILS_H
#define TREINO_GRAFOS_UTILS_H

#include <stdio.h>
#include <stdbool.h>

#define LENGTH 10

#define ANSI_COLOR_BLACK   "\x1b[30m"
#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_WHITE   "\x1b[37m"
#define ANSI_COLOR_RESET   "\x1b[0m"

int collect_int();

void best_representation(int n_vertex, int n_edge);

void color(int _color);

#endif //TREINO_GRAFOS_UTILS_H
