#include "Matrix.h"
#include <iostream>

Matrix::Matrix(int r, int c) : rows(r), cols(c) {
    data.resize(rows, std::vector<double>(cols, 0.0));
}

double Matrix::get(int r, int c) const {
    if (r >= rows || c >= cols || r < 0 || c < 0) 
        throw std::out_of_range("Índice fuera de rango");
    return data[r][c];
}

void Matrix::set(int r, int c, double value) {
    if (r >= rows || c >= cols || r < 0 || c < 0) 
        throw std::out_of_range("Índice fuera de rango");
    data[r][c] = value;
}

Matrix Matrix::add(const Matrix& other) const {
    if (rows != other.rows || cols != other.cols)
        throw std::invalid_argument("Las matrices deben tener el mismo tamaño");
    
    Matrix result(rows, cols);
    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j)
            result.set(i, j, get(i, j) + other.get(i, j));
    
    return result;
}

Matrix Matrix::multiply(const Matrix& other) const {
    if (cols != other.rows)
        throw std::invalid_argument("Dimensiones incompatibles para multiplicación");
    
    Matrix result(rows, other.cols);
    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < other.cols; ++j)
            for (int k = 0; k < cols; ++k)
                result.set(i, j, result.get(i, j) + get(i, k) * other.get(k, j));
    
    return result;
}

void Matrix::print() const {
    for (const auto& row : data) {
        for (double val : row) 
            std::cout << val << " ";
        std::cout << "\n";
    }
}