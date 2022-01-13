#ifndef _MATRIX_H
#define _MATRIX_H

#include <vector>
#include <memory>

namespace matrix {

template <typename T>
class Matrix {
private:
    std::vector<T> items;
    unsigned int rows, cols;

public:
    Matrix(unsigned int rows, unsigned int cols)
        :rows(rows), cols(cols), items(std::vector<T>(rows * cols)) {}
    Matrix()
        :rows(0), cols(0) {}
    ~Matrix(){}

    // Accessors
    std::reference_wrapper<const T> get(unsigned int x, unsigned int y)
    {
        unsigned int index = x * cols + y;
        if (index > items.capacity()) {
            // Index out of bounds
        }
        try {
            return std::cref<T>(items.at(index));
        }
        catch (std::out_of_range) {
            size_t capacity = items.capacity();
            resize(capacity + (capacity * 25 / 100));
            return get(x, y);
        }
    }

    size_t capacity() const { return items.capacity(); }

    // Manipulators
    void set(unsigned int x, unsigned int y, T item)
    {
        unsigned int index = x * cols + y;
        if (index >= items.capacity()) {
            // Index out of bounds
        }

        if (!items.at(index)) {
            // I don't like that std::move is here. Most likely
            // have to change the design of Matrix<T> to consider
            // smart pointers and other data types separately
            items.at(index) = std::move(item);
        }
    }

    void resize(size_t count)
    {
        rows = cols = count;
        items.resize(rows * cols);
    }

}; // Matrix

} // namespace matrix

#endif // _MATRIX_H
