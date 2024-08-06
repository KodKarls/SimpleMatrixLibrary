#pragma once

#include <vector>

class Matrix
{
public:
    Matrix( int rows, int columns );
    Matrix( const Matrix& other ) = default;
    Matrix( Matrix&& other ) noexcept;

    ~Matrix() = default;

    Matrix& operator=( const Matrix& other ) = default;
    Matrix& operator=( Matrix&& other ) noexcept;

    double& operator()( int row, int column );
    const double& operator()( int row, int column ) const;

    Matrix operator+( const Matrix& other ) const;
    Matrix operator-( const Matrix& other ) const;
    Matrix operator*( const Matrix& other ) const;

    [[nodiscard]] double determinant() const;
    [[nodiscard]] Matrix subMatrix( int excludedRow, int excludedColumn ) const;

    [[nodiscard]] int getRows() const;
    [[nodiscard]] int getColumns() const;

    void print() const;

    static Matrix identity( int size );

private:
    int m_rows;
    int m_columns;
    std::vector< std::vector< double > > m_data;
};
