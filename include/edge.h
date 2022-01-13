#ifndef _EDGE_H
#define _EDGE_H

#include <vector>
#include <memory>

namespace graph {

struct Edge {
    unsigned int start_id;
    unsigned int end_id;
    int cost;
    Edge(unsigned int id_a, unsigned int id_b, int cost);
};

std::unique_ptr<Edge> create_edge(unsigned int id_a, unsigned int id_b, int cost);

} // namespace graph 

#endif // _EDGE_H
