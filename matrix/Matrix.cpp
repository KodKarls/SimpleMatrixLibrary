#include "Matrix.hpp"

#include <iomanip>
#include <iostream>
#include <stdexcept>

Matrix::Matrix( const int rows, const int columns ) :
        m_rows( rows ), m_columns( columns ),
        m_data( rows, std::vector< double >( columns, 0 ) )
{
    // Empty body
}

Matrix::Matrix( Matrix&& other ) noexcept :
        m_rows( other.m_rows ), m_columns( other.m_columns ),
        m_data( std::move( other.m_data ) )
{
    other.m_rows = 0;
    other.m_columns = 0;
}

Matrix& Matrix::operator=( Matrix&& other ) noexcept
{
    if( this != &other )
    {
        m_rows = other.m_rows;
        m_columns = other.m_columns;
        m_data = std::move( other.m_data );

        other.m_rows = 0;
        other.m_columns = 0;
    }

    return *this;
}

double& Matrix::operator()( const int row, const int column )
{
    if( row < 0 || row >= m_rows || column < 0 || column >= m_columns )
    {
        throw std::out_of_range( "Matrix indices out of range" );
    }

    return m_data[ row ][ column ];
}

const double& Matrix::operator()( const int row, const int column ) const
{
    if( row < 0 || row >= m_rows || column < 0 || column >= m_columns )
    {
        throw std::out_of_range( "Matrix indices out of range" );
    }

    return m_data[ row ][ column ];
}

Matrix Matrix::operator+( const Matrix& other ) const
{
    if( m_rows != other.m_rows || m_columns != other.m_columns )
    {
        throw std::invalid_argument( "Matrix dimensions must match for addition" );
    }

    Matrix result( m_rows, m_columns );
    for( int i = 0; i < m_rows; ++i )
    {
        for( int j = 0; j < m_columns; ++j )
        {
            result( i, j ) = m_data[ i ][ j ] + other.m_data[ i ][ j ];
        }
    }

    return result;
}

Matrix Matrix::operator-( const Matrix& other ) const
{
    if( m_rows != other.m_rows || m_columns != other.m_columns )
    {
        throw std::invalid_argument( "Matrix dimensions must match for subtraction" );
    }

    Matrix result( m_rows, m_columns );
    for( int i = 0; i < m_rows; ++i )
    {
        for( int j = 0; j < m_columns; ++j )
        {
            result( i, j ) = m_data[ i ][ j ] - other.m_data[ i ][ j ];
        }
    }

    return result;
}

Matrix Matrix::operator*( const Matrix& other ) const
{
    if( m_columns != other.m_rows )
    {
        throw std::invalid_argument( "Matrix dimensions must match for multiplication" );
    }

    Matrix result( m_rows, m_columns );
    for( int i = 0; i < m_rows; ++i )
    {
        for( int j = 0; j < other.m_columns; ++j )
        {
            for( int k = 0; k < m_columns; ++k )
            {
                result(i, j ) += m_data[ i ][ k ] * other.m_data[ k ][ j ];
            }
        }
    }

    return result;
}

double Matrix::determinant() const
{
    if( m_rows != m_columns )
    {
        throw std::invalid_argument( "Determinant can only be calculated for square matrices" );
    }

    if( m_rows == 1 )
    {
        return m_data[ 0 ][ 0 ];
    }

    if( m_rows == 2 )
    {
        return m_data[ 0 ][ 0 ] * m_data[ 1 ][ 1 ] - m_data[ 0 ][ 1 ] * m_data[ 1 ][ 0 ];
    }

    double determinant = 0.0;

    for( int p = 0; p < m_columns; ++p )
    {
        Matrix sub = subMatrix( 0, p );
        determinant += m_data[ 0 ][ p ] * sub.determinant() * ( ( p % 2 == 0 ) ? 1 : -1 );
    }

    return determinant;
}

Matrix Matrix::subMatrix( const int excludedRow, const int excludedColumn ) const
{
    Matrix result( m_rows - 1, m_columns - 1 );

    for( int i = 0, newRow = 0; i < m_rows; ++i )
    {
        if( i == excludedRow )
        {
            continue;
        }
        for( int j = 0, newColumn = 0; j < m_columns; ++j )
        {
            if( j == excludedColumn )
            {
                continue;
            }
            result( newRow, newColumn ) = m_data[ i ][ j ];
            ++newColumn;
        }
        ++newRow;
    }

    return result;
}

int Matrix::getRows() const
{
    return m_rows;
}

int Matrix::getColumns() const
{
    return m_columns;
}

void Matrix::print() const
{
    for( const auto& row : m_data )
    {
        for( const auto& elem : row )
        {
            std::cout << std::setw( 10 ) << elem << " ";
        }
        std::cout << '\n';
    }
}

Matrix Matrix::identity( const int size )
{
    Matrix result( size, size );

    for( int i = 0; i < size; ++i )
    {
        result( i, i ) = 1.0;
    }

    return result;
}
