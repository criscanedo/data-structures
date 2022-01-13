#include <iostream>
#include <vector>

#include "../include/graph.h"

using graph::Graph;

int main()
{
    std::vector<int> vertex_ids = { 1, 2, 3, 4, 5 };

    Graph graph;

    unsigned int start_index = 0;
    unsigned int end_index = 1;
    graph.add_vertex(vertex_ids[start_index]);
    graph.add_vertex(vertex_ids[end_index]);
    graph.add_vertex(vertex_ids[3]);
    graph.add_vertex(vertex_ids[4]);
    graph.add_vertex(vertex_ids[5]);
    graph.add_edge(start_index, end_index);
    graph.add_edge(start_index, 3);
    graph.add_edge(start_index, 4);
    graph.add_edge(start_index, 5);

    std::cout << "Neighbors of " << start_index << std::endl;
    for (int index : graph.neighbors(start_index)) {
        std::cout << index << std::endl;
    }

    return 0;
}
