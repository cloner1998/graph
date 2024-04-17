#include <stdio.h>
#include "graph_header.h"


int main() {
    graph *g1 = create_graph1(5);

    add_edge(g1, 0, 1);
    add_edge(g1, 0, 3);
    add_edge(g1, 0, 0);
    add_edge(g1, 2, 4);
    add_edge(g1, 3, 4);
    add_edge(g1, 1, 3);


    print_graph(g1);
    destroy_graph(g1);

    return 0;
}
