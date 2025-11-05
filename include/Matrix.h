/**
 * @file Matrix.h
 * @brief Declaración de la clase Matrix para operaciones con matrices
 * @version 1.0.0
 * @author Jhon Wilson
 * @date 2025
 * 
 * Este archivo contiene la declaración de la clase Matrix que implementa
 * operaciones matemáticas básicas con matrices, incluyendo suma, multiplicación
 * y manejo de excepciones para operaciones inválidas.
 */

#ifndef MATRIX_H
#define MATRIX_H

#include <vector>
#include <stdexcept>

/**
 * @class Matrix
 * @brief Clase que representa una matriz matemática y sus operaciones
 * 
 * La clase Matrix proporciona una implementación orientada a objetos
 * para trabajar con matrices de dimensiones arbitrarias. Incluye
 * operaciones básicas como suma y multiplicación, validación de
 * dimensiones y manejo robusto de errores mediante excepciones.
 * 
 * @note Todas las operaciones siguen los principios SOLID y promueven
 * la reutilización de código.
 * 
 * @see https://github.com/tu-usuario/MathLib para más información
 */
class Matrix {
private:
    std::vector<std::vector<double>> data;  ///< Almacenamiento interno de los datos de la matriz (fila x columna)
    int rows;                               ///< Número de filas de la matriz
    int cols;                               ///< Número de columnas de la matriz

public:
    /**
     * @brief Constructor que crea una matriz de dimensiones específicas
     * 
     * Inicializa una matriz con las dimensiones especificadas y todos
     * sus elementos establecidos a 0.0. Valida que las dimensiones
     * sean números positivos.
     * 
     * @param r Número de filas (debe ser mayor a 0)
     * @param c Número de columnas (debe ser mayor a 0)
     * @throws std::invalid_argument Si las dimensiones no son positivas
     * 
     * @code
     * Matrix m(3, 4); // Crea matriz 3x4 llena de ceros
     * @endcode
     */
    Matrix(int r, int c);

    /**
     * @brief Obtiene el valor en una posición específica de la matriz
     * 
     * Accede al elemento en la posición (r, c) de la matriz utilizando
     * índices base 0. Realiza validación de límites.
     * 
     * @param r Índice de fila (0-based)
     * @param c Índice de columna (0-based)
     * @return Valor double en la posición (r, c)
     * @throws std::out_of_range Si los índices están fuera de rango
     * 
     * @code
     * double valor = m.get(1, 2); // Obtiene valor en fila 1, columna 2
     * @endcode
     */
    double get(int r, int c) const;

    /**
     * @brief Establece un valor en una posición específica de la matriz
     * 
     * Modifica el elemento en la posición (r, c) de la matriz con el
     * valor proporcionado. Realiza validación de límites.
     * 
     * @param r Índice de fila (0-based)
     * @param c Índice de columna (0-based)
     * @param value Valor double a almacenar
     * @throws std::out_of_range Si los índices están fuera de rango
     * 
     * @code
     * m.set(0, 0, 5.5); // Establece 5.5 en la posición (0,0)
     * @endcode
     */
    void set(int r, int c, double value);

    /**
     * @brief Suma esta matriz con otra matriz
     * 
     * Realiza la suma elemento por elemento entre esta matriz y la
     * matriz proporcionada como parámetro. Ambas matrices deben
     * tener las mismas dimensiones.
     * 
     * @param other Matriz a sumar con esta matriz
     * @return Nueva matriz resultante de la suma
     * @throws std::invalid_argument Si las dimensiones no coinciden
     * 
     * @code
     * Matrix A(2,2), B(2,2);
     * Matrix C = A.add(B); // C = A + B
     * @endcode
     */
    Matrix add(const Matrix& other) const;

    /**
     * @brief Multiplica esta matriz por otra matriz
     * 
     * Realiza la multiplicación matricial entre esta matriz y la
     * matriz proporcionada. El número de columnas de esta matriz
     * debe coincidir con el número de filas de la otra matriz.
     * 
     * @param other Matriz a multiplicar con esta matriz
     * @return Nueva matriz resultante del producto
     * @throws std::invalid_argument Si las dimensiones son incompatibles
     * 
     * @pre cols == other.rows
     * 
     * @code
     * Matrix A(2,3), B(3,2);
     * Matrix C = A.multiply(B); // C = A × B (2x2)
     * @endcode
     */
    Matrix multiply(const Matrix& other) const;

    /**
     * @brief Imprime la matriz en la salida estándar
     * 
     * Muestra la matriz en un formato legible con cada fila en
     * una línea separada y elementos separados por espacios.
     * Útil para debugging y visualización rápida de resultados.
     * 
     * @code
     * m.print();
     * // Salida: 
     * // 1.0 2.0
     * // 3.0 4.0
     * @endcode
     */
    void print() const;
};

#endif