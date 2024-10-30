#include "Matrix.hpp"

#include <iostream>

int main()
{
    Matrix matrix1( 3, 3 );
    matrix1( 0, 0 ) = 1;
    matrix1(0 , 1 ) = 2;
    matrix1( 0, 2 ) = 3;

    matrix1( 1, 0 ) = 4;
    matrix1(1 , 1 ) = 5;
    matrix1( 1, 2 ) = 6;

    matrix1( 2, 0 ) = 7;
    matrix1(2 , 1 ) = 8;
    matrix1( 2, 2 ) = 9;

    Matrix matrix2( 3, 3 );
    matrix2( 0, 0 ) = 9;
    matrix2(0 , 1 ) = 8;
    matrix2( 0, 2 ) = 7;

    matrix2( 1, 0 ) = 6;
    matrix2(1 , 1 ) = 5;
    matrix2( 1, 2 ) = 4;

    matrix2( 2, 0 ) = 3;
    matrix2(2 , 1 ) = 2;
    matrix2( 2, 2 ) = 1;

    const Matrix resultAdd = matrix1 + matrix2;
    std::cout << "Wynik dodawania:\n";
    resultAdd.print();

    const Matrix resultSub = matrix1 - matrix2;
    std::cout << "Wynik odejmowania:\n";
    resultSub.print();

    const Matrix resultMul = matrix1 * matrix2;
    std::cout << "Wynik mnozenia:\n";
    resultMul.print();

    Matrix matrix3( 3, 3 );
    matrix3( 0, 0 ) = 10;
    matrix3(0 , 1 ) = 10;
    matrix3( 0, 2 ) = 10;

    matrix3( 1, 0 ) = 3;
    matrix3(1 , 1 ) = 20;
    matrix3( 1, 2 ) = -8;

    matrix3( 2, 0 ) = 10;
    matrix3(2 , 1 ) = 15;
    matrix3( 2, 2 ) = 10;

    const double determinant = matrix3.determinant();
    std::cout << "\nWyznacznik macierzy matrix3: " << determinant << '\n';

    return 0;
}
