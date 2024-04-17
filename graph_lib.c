
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include "graph_header.h"

typedef struct my_graph{
    int num_nodes;
    bool **edges;
}graph;

graph *create_graph(int num_nodes){
    graph *g = malloc(sizeof (*g));
    if(g == NULL) return NULL;
    g->num_nodes = num_nodes;
    g->edges = calloc(g->num_nodes, sizeof(bool *));
    //g->edges = malloc(sizeof (bool *));
    if(g->edges == NULL){
        free(g);
        return NULL;
    }
    for (int i = 0; i < g->num_nodes; ++i) {
        g->edges[i] = calloc(g->num_nodes, sizeof(bool *));
        if(g->edges[i] == NULL){
            destroy_graph(g);
            return NULL;
        }
    }
    return g;
}

graph *create_graph1(int num_nodes){
    graph *g = malloc(sizeof (graph));
    g->num_nodes = num_nodes;
    g->edges = (bool **)malloc(sizeof (bool *) * num_nodes);
    /*for (int i = 0; i < num_nodes; ++i) {
        g->edges[i] = calloc(g->num_nodes, sizeof (bool));
    }*/
    for (int i = 0; i < num_nodes; ++i) {
        g->edges[i] = malloc(sizeof (bool) * num_nodes);
        for (int j = 0; j < num_nodes; ++j) {
            g->edges[i][j] = false;
        }
    }
    return g;
}

void destroy_graph(graph *g){
    if(g->edges == NULL){
        free(g);
        return;
    }
    for (int i = 0; i < g->num_nodes; ++i) {
        if(g->edges[i] != NULL){
            free(g->edges[i]);
        }
    }
    free(g->edges);
    free(g);
}
void print_graph(graph *g){
    printf("digraph {\n");
    for (int i = 0; i < g->num_nodes; ++i) {
        for (int j = 0; j < g->num_nodes; ++j) {
            if(g->edges[i][j]){
                printf("%d -> %d;\n",i , j);
            }
        }

    }
    printf("}\n");
}
bool add_edge(graph *g, unsigned int from_node, unsigned int to_node){
    if(has_edge(g, from_node, to_node)){
        return false;
    }
    g->edges[from_node][to_node] = true;
    return true;
}

bool has_edge(graph *g, unsigned int from_node, unsigned int to_node){
    return g->edges[from_node][to_node];
}