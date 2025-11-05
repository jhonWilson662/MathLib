📘 MathLib

MathLib es una librería modular en C++ orientada a objetos que implementa operaciones matemáticas básicas con matrices.

📂 Estructura del proyecto
/MathLib/
 ├── include/
 │   └── Matrix.h
 ├── src/
 │   └── Matrix.cpp
 ├── test/
 │   └── test_matrix.cpp
 ├── README.md
 ├── LICENSE
 └── CMakeLists.txt

⚙️ Funcionalidades principales

La clase Matrix implementa las siguientes operaciones:

Creación de matrices de tamaño r x c.

Acceso seguro a elementos mediante los métodos get() y set().

Suma de matrices con el método add(const Matrix& other).

Multiplicación de matrices con el método multiply(const Matrix& other).

Impresión de matrices con print().

🧪 Ejemplo de uso
#include "Matrix.h"
#include <iostream>

int main() {
    Matrix A(2, 2), B(2, 2);
    A.set(0, 0, 1); A.set(0, 1, 2);
    A.set(1, 0, 3); A.set(1, 1, 4);
    B.set(0, 0, 5); B.set(0, 1, 6);
    B.set(1, 0, 7); B.set(1, 1, 8);

    Matrix C = A.add(B);
    Matrix D = A.multiply(B);

    std::cout << "Suma:\n";
    C.print();
    std::cout << "Multiplicación:\n";
    D.print();
}

⚙️ Compilación

Puedes compilar el proyecto manualmente con:

g++ src/Matrix.cpp test/test_matrix.cpp -I include -o test_matrix
./test_matrix

🏷️ Versionado

Este proyecto utiliza Versionado Semántico (SemVer).

Ejemplo:
Tu primera versión estable sería:
git tag -a v1.0.0 -m "Primera versión estable"
git push origin v1.0.0


Si luego agregas nuevas funciones, por ejemplo, una para calcular el determinante de una matriz:

git tag -a v1.1.0 -m "Se agregó función de determinante"
git push origin v1.1.0


Si después corriges un error en la multiplicación de matrices:

git tag -a v1.1.1 -m "Corrección de bug en multiplicación"
git push origin v1.1.1

👨‍💻 Autor

Proyecto desarrollado por Jhon Wilson Gómez Zapana
