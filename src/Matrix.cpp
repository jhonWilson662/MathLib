/**
 * @file Matrix.cpp
 * @brief Implementación de la clase Matrix para operaciones con matrices
 * @version 1.0.0
 * @author Jhon Wilson
 * @date 2025
 * 
 * Este archivo contiene la implementación de todos los métodos
 * de la clase Matrix declarados en Matrix.h. Incluye operaciones
 * básicas con matrices como suma, multiplicación y manejo de errores.
 * La implementación sigue principios de programación orientada a objetos
 * y garantiza robustez mediante validación exhaustiva de parámetros.
 */

#include "Matrix.h"
#include <iostream>
#include <stdexcept>

/**
 * @brief Constructor - Crea una matriz de dimensiones específicas inicializada con ceros
 * 
 * @param r Número de filas
 * @param c Número de columnas
 * 
 * Inicializa una matriz con las dimensiones especificadas y todos
 * sus elementos establecidos a 0.0. Valida que las dimensiones
 * sean números positivos antes de realizar la asignación de memoria.
 * 
 * @throws std::invalid_argument Si r <= 0 o c <= 0
 */
Matrix::Matrix(int r, int c) : rows(r), cols(c) {
    // Validar dimensiones positivas
    if (r <= 0 || c <= 0) {
        throw std::invalid_argument("Matrix::Matrix - Las dimensiones deben ser positivas");
    }
    
    // Inicializar la matriz con ceros
    data.resize(rows, std::vector<double>(cols, 0.0));
}

/**
 * @brief Obtiene el valor en una posición específica de la matriz
 * 
 * @param r Índice de fila
 * @param c Índice de columna
 * @return double Valor en la posición (r, c)
 * 
 * Accede al elemento en la posición (r, c) de la matriz utilizando
 * índices base 0. Realiza validación completa de límites antes de
 * permitir el acceso a los datos.
 * 
 * @throws std::out_of_range Si r < 0, r >= rows, c < 0, o c >= cols
 */
double Matrix::get(int r, int c) const {
    // Validar índices
    if (r < 0 || r >= rows || c < 0 || c >= cols) {
        throw std::out_of_range("Matrix::get - Índice fuera de rango");
    }
    return data[r][c];
}

/**
 * @brief Establece un valor en una posición específica de la matriz
 * 
 * @param r Índice de fila
 * @param c Índice de columna
 * @param value Valor a establecer
 * 
 * Modifica el elemento en la posición (r, c) de la matriz con el
 * valor proporcionado. Realiza validación completa de límites antes
 * de permitir la modificación de los datos.
 * 
 * @throws std::out_of_range Si r < 0, r >= rows, c < 0, o c >= cols
 */
void Matrix::set(int r, int c, double value) {
    // Validar índices
    if (r < 0 || r >= rows || c < 0 || c >= cols) {
        throw std::out_of_range("Matrix::set - Índice fuera de rango");
    }
    data[r][c] = value;
}

/**
 * @brief Suma esta matriz con otra matriz
 * 
 * @param other Matriz a sumar
 * @return Matrix Nueva matriz resultante
 * 
 * Realiza la suma elemento por elemento entre esta matriz y la
 * matriz proporcionada como parámetro. Ambas matrices deben
 * tener exactamente las mismas dimensiones (mismo número de
 * filas y mismo número de columnas).
 * 
 * Complejidad temporal: O(n²) donde n es el número de elementos
 * 
 * @throws std::invalid_argument Si rows != other.rows o cols != other.cols
 */
Matrix Matrix::add(const Matrix& other) const {
    // Verificar dimensiones compatibles
    if (rows != other.rows || cols != other.cols) {
        throw std::invalid_argument("Matrix::add - Las matrices deben tener el mismo tamaño");
    }
    
    // Crear matriz resultado
    Matrix result(rows, cols);
    
    // Realizar suma elemento por elemento
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            result.data[i][j] = data[i][j] + other.data[i][j];
        }
    }
    
    return result;
}

/**
 * @brief Multiplica esta matriz por otra matriz
 * 
 * @param other Matriz a multiplicar
 * @return Matrix Nueva matriz resultante
 * 
 * Realiza la multiplicación matricial estándar entre esta matriz
 * y la matriz proporcionada. El número de columnas de esta matriz
 * debe coincidir con el número de filas de la otra matriz.
 * La matriz resultante tendrá dimensiones: rows x other.cols
 * 
 * Complejidad temporal: O(n³) para matrices cuadradas n x n
 * 
 * @throws std::invalid_argument Si cols != other.rows
 */
Matrix Matrix::multiply(const Matrix& other) const {
    // Verificar dimensiones compatibles para multiplicación
    if (cols != other.rows) {
        throw std::invalid_argument("Matrix::multiply - Dimensiones incompatibles");
    }
    
    // Crear matriz resultado (rows x other.cols)
    Matrix result(rows, other.cols);
    
    // Algoritmo de multiplicación de matrices
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < other.cols; ++j) {
            double sum = 0.0;
            for (int k = 0; k < cols; ++k) {
                sum += data[i][k] * other.data[k][j];
            }
            result.data[i][j] = sum;
        }
    }
    
    return result;
}

/**
 * @brief Imprime la matriz en la salida estándar
 * 
 * Muestra la matriz en un formato legible con cada fila en
 * una línea separada y elementos separados por espacios.
 * Esta función está diseñada principalmente para debugging
 * y no debe usarse en producción para matrices muy grandes.
 */
void Matrix::print() const {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cout << data[i][j] << " ";
        }
        std::cout << "\n";
    }
}