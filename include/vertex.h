#ifndef _VERTEX_H
#define _VERTEX_H

#include <vector>
#include <memory>

namespace graph {

struct Vertex {
    unsigned int id;
    Vertex(unsigned int vid);
};

std::unique_ptr<Vertex> create_vertex(unsigned int id);

} // namespace graph

#endif // _VERTEX_H
