#ifndef TYPES_MATRIX_HPP
#define TYPES_MATRIX_HPP

#include "assert.h"
#include "iostream"
#include "memory"
#include "tuple"
#include "vector"

namespace stdmath
{

namespace matrix
{

template <class T, size_t numberOfRows, size_t numberOfColumns, bool rowMajor = true>
class MatrixXX
{
  private:
    T* data;

  public:
    MatrixXX()
    {
        data = new T[numberOfRows * numberOfColumns];
    }
    ~MatrixXX()
    {
        delete[] data;
    }
    MatrixXX(std::initializer_list<std::initializer_list<T>> lst)
    {
        // TODO: Modify the logic to also acount for Column major code
        data = new T[numberOfRows * numberOfColumns];
        assert(numberOfRows == lst.size());
        int index = 0;
        for (auto row : lst)
        {
            for (auto item : row)
            {
                data[index] = item;
                index++;
            }
        }
    }
    std::tuple<size_t, size_t> size() const
    {
        return std::make_tuple(numberOfRows, numberOfColumns);
    }
    T& operator()(size_t row, size_t col)
    {
        return data[row * numberOfColumns + col];
    }
    T operator()(size_t row, size_t col) const
    {
        return data[row * numberOfColumns + col];
    }
    size_t rows() const
    {
        return numberOfRows;
    }
    size_t cols() const
    {
        return numberOfColumns;
    }
    void resize(size_t rows, size_t cols)
    {
        assert(rows * cols == numberOfRows * numberOfColumns);
        numberOfRows = rows;
        numberOfColumns = cols;
        // TODO: What happens when the assertion fails?
    }
};

template <size_t numberOfRows, size_t numberOfColumns>
using MatrixXf = MatrixXX<float, numberOfRows, numberOfColumns>;

template <size_t numberOfRows, size_t numberOfColumns>
using MatrixXd = MatrixXX<double, numberOfRows, numberOfColumns>;

template <size_t numberOfRows>
using SquareMatrixXf = MatrixXX<float, numberOfRows, numberOfRows>;

template <size_t numberOfRows>
using SquareMatrixXd = MatrixXX<double, numberOfRows, numberOfRows>;

}  // namespace matrix

}  // namespace stdmath

#endif