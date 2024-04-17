//
// Created by LENOVO on 4/15/2024.
//

#include <stdbool.h>

#ifndef GRAPH_GRAPH_HEADER_H
#define GRAPH_GRAPH_HEADER_H

typedef struct my_graph graph;
graph *create_graph(int num_nodes);
graph *create_graph1(int num_nodes);
void destroy_graph(graph *g);
void print_graph(graph *g);
bool add_edge(graph *g, unsigned int from_node, unsigned int to_node);
bool has_edge(graph *g, unsigned int from_node, unsigned int to_node);

#endif //GRAPH_GRAPH_HEADER_H
