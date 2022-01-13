#include "../include/graph.h"

#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>

#include "../include/matrix.h"
#include "../include/edge.h"

namespace graph {

Graph::Graph() {}
Graph::~Graph() {}

void Graph::add_vertex(unsigned int id)
{
    if (find_id(id) == vertex_ids.end()) {
        vertex_ids.push_back(id);
        graph_resize();
    }
}

void Graph::remove_vertex(unsigned int id)
{
    std::vector<unsigned int>::iterator it = find_id(id);
    if (it != vertex_ids.end()) {
        vertex_ids.erase(it);
        graph_resize();
    }
}

bool Graph::adjacent(unsigned int start_index, unsigned int end_index)
{
    if (!in_bounds(start_index, end_index)) return false;
    return edges.get(start_index, end_index).get() != nullptr;
}

std::vector<int> Graph::neighbors(unsigned int vertex_index)
{
    if (!in_bounds(vertex_index)) return std::vector<int>();

    std::vector<int> neighbor_indexes;
    std::cout << "edges capacity: " << edges.capacity() << std::endl;
    for (int i = 0; i < edges.capacity(); i++) {
        if (i != vertex_index && edges.get(vertex_index, i).get() != nullptr) {
            neighbor_indexes.push_back(i);
        }
    }
    return neighbor_indexes;
}

void Graph::add_edge(unsigned int start_index, unsigned int end_index)
{
    if (in_bounds(start_index, end_index) && !has_edge(start_index, end_index)) {
        edges.set(start_index, end_index, std::move(create_edge(start_index, end_index, 0)));
    }
}

void Graph::remove_edge(unsigned int start_index, unsigned int end_index)
{
    if (in_bounds(start_index, end_index) && has_edge(start_index, end_index)) {
        edges.set(start_index, end_index, std::unique_ptr<Edge>());
    }
}

std::vector<unsigned int>::iterator Graph::find_id(unsigned int id)
{
    return std::find_if(
            vertex_ids.begin(),
            vertex_ids.end(),
            [&id](const int& x) { return x == id; }
    );
}

void Graph::graph_resize()
{
    edges.resize(vertex_ids.size());
    std::cout << "edges matrix capacity is now: " << edges.capacity() << std::endl;
    /*size_t capacity = edges.capacity();
    double matrix_usage_percentage = (double)(vertex_ids.size() * 100 / capacity);

    if (matrix_usage_percentage > 75.0) {
        edges.resize(std::round(capacity + (capacity * 25.0 / 100))); // Increase by 25%
    }
    else if (matrix_usage_percentage < 25.0) {
        edges.resize(std::round(capacity - (capacity * 25.0 / 100))); // Decrease by 25%
    }*/
}

bool Graph::in_bounds(unsigned int vertex_index)
{
    return vertex_index < edges.capacity();
}

bool Graph::in_bounds(unsigned int start_index, unsigned int end_index)
{
    return in_bounds(std::max(start_index, end_index));
}

bool Graph::has_edge(unsigned int start_index, unsigned int end_index)
{
    return edges.get(start_index, end_index).get() != nullptr;
}

} // namespace graph
