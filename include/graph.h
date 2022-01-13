#ifndef _GRAPH_H
#define _GRAPH_H

#include <vector>
#include <memory>

#include "edge.h"
#include "vertex.h"
#include "matrix.h"

namespace graph {
using matrix::Matrix;

class Graph {
public:
    Graph();
    ~Graph();

    void add_vertex(unsigned int id);
    void remove_vertex(unsigned int id);
    bool adjacent(unsigned int start_index, unsigned int end_index);
    std::vector<int> neighbors(unsigned int id);
    void add_edge(unsigned int start_index, unsigned int end_index);
    void remove_edge(unsigned int start_index, unsigned int end_index);

private:
    Matrix<std::unique_ptr<Edge>> edges;
    std::vector<unsigned int> vertex_ids;

    std::vector<unsigned int>::iterator find_id(unsigned int id);
    void graph_resize();
    bool in_bounds(unsigned int start_index, unsigned int end_index);
    bool in_bounds(unsigned int vertex_index);
    bool has_edge(unsigned int start_index, unsigned int end_index);
};


} // namespace graph
#endif // _GRAPH_H
