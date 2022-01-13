#ifndef _AM_GRAPH_H
#define _AM_GRAPH_H

#include <vector>
#include <memory>
#include <iterator>
#include <cstddef>

struct Vertex {
    unsigned int id;
    Vertex(unsigned int vid): id(vid) {}
};

std::unique_ptr<Vertex> newVertex(unsigned int id)
{
    return std::make_unique<Vertex>(id);
}

struct Edge {
    unsigned int startId;
    unsigned int endId;
    int cost;
    Edge(unsigned int sId, unsigned int eId, int eCost)
        :startId(sId), endId(eId), cost(eCost) {}
};

std::unique_ptr<Edge> createEdge(unsigned int startId, unsigned int endId, unsigned int cost)
{
    return std::make_unique<Edge>(startId, endId, cost);
}

class Matrix {
private:
    std::vector<std::unique_ptr<Edge>> _edges;
    unsigned int _rows, _cols;

public:
    Matrix(unsigned int rows, unsigned int cols)
        :_rows(rows), _cols(cols), _edges(std::vector<std::unique_ptr<Edge>>(rows * cols)) {}
    ~Matrix(){}

    void set(unsigned int x, unsigned int y, std::unique_ptr<Edge> edge)
    {
        if (!_edges.at(x * _cols + y)) {
            _edges.at(x * _cols + y) = std::move(edge);
        }
    }

    std::reference_wrapper<const std::unique_ptr<Edge>> get(unsigned int x, unsigned int y)
    {
        return std::cref<const std::unique_ptr<Edge>>(_edges.at(x * _cols + y));
    }
};

#endif // _AM_GRAPH_H
