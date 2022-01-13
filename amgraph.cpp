#include <iostream>
#include <vector>

#include "amgraph.h"

using VertexPtr = std::unique_ptr<Vertex>;

static std::vector<VertexPtr> createVertexList(unsigned short int size)
{
    std::vector<VertexPtr> vertices;
    for (unsigned short int i = 0; i < size; i++) {
        vertices.push_back(newVertex(i + 1));
    }
    return vertices;
}

int main()
{
    std::vector<VertexPtr> vertices = createVertexList(10);

    Matrix graphMatrix(vertices.size(), vertices.size());

    unsigned int startId = 1;
    unsigned int endId = 2;

    // Vertex with id 1 creates edge to 2
    graphMatrix.set(startId - 1, endId - 1, std::move(createEdge(startId, endId, 0)));
    auto edge = graphMatrix.get(startId - 1, endId - 1);

    std::cout << edge.get()->startId << " -> " << edge.get()->endId << std::endl;
    
    return 0;
}
