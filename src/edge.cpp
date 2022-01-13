#include "../include/edge.h"
#include <memory>

namespace graph {

Edge::Edge(unsigned int id_a, unsigned int id_b, int c)
    :start_id(id_a), end_id(id_b), cost(c) {}

std::unique_ptr<Edge> create_edge(unsigned int id_a, unsigned int id_b, int cost)
{
    return std::make_unique<Edge>(id_a, id_b, cost);
}

} // namespace graph
