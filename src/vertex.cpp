#include "../include/vertex.h"
#include <memory>

namespace graph {

Vertex::Vertex(unsigned int vid) :id(vid) {}

std::unique_ptr<Vertex> create_vertex(unsigned int id)
{
    return std::make_unique<Vertex>(id);
}

} // namespace graph
