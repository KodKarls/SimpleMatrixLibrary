#include "Matrix.hpp"

#include <gtest/gtest.h>

#include <sstream>

class MatrixTest : public ::testing::Test
{
    // Empty body.
};

std::string captureOutput( const Matrix& matrix )
{
    const std::stringstream buffer;

    std::streambuf* old = std::cout.rdbuf( buffer.rdbuf() );
    matrix.print();
    std::cout.rdbuf( old );

    return buffer.str();
}

TEST_F( MatrixTest, TwoParametersConstructor )
{
    // Given

    // When
    const Matrix matrix( 3, 3 );

    // Then
    EXPECT_EQ( matrix.getRows(), 3 );
    EXPECT_EQ( matrix.getColumns(), 3 );
}

TEST_F( MatrixTest, CopyConstructor )
{
    // Given
    Matrix matrix1( 2, 2 );
    matrix1(0, 0 ) = 1.0;
    matrix1(0, 1 ) = 2.0;
    matrix1(1, 0 ) = 3.0;
    matrix1(1, 1 ) = 4.0;

    // When
    Matrix matrix2( matrix1 );

    // Then
    EXPECT_EQ( matrix2.getRows(), matrix1.getRows() );
    EXPECT_EQ( matrix2.getColumns(), matrix1.getColumns() );
    EXPECT_EQ( matrix2( 0, 0 ), 1.0 );
    EXPECT_EQ( matrix2( 0, 1 ), 2.0 );
    EXPECT_EQ( matrix2( 1, 0 ), 3.0 );
    EXPECT_EQ( matrix2( 1, 1 ), 4.0 );
}

TEST_F( MatrixTest, MoveConstructor )
{
    // Given
    Matrix matrix1( 2, 2 );
    matrix1(0, 0 ) = 1.0;
    matrix1(0, 1 ) = 2.0;
    matrix1(1, 0 ) = 3.0;
    matrix1(1, 1 ) = 4.0;

    // When
    Matrix matrix2( std::move( matrix1 ) );

    // Then
    EXPECT_EQ( matrix2.getRows(), 2 );
    EXPECT_EQ( matrix2.getColumns(), 2 );
    EXPECT_EQ( matrix2( 0, 0 ), 1.0 );
    EXPECT_EQ( matrix2( 0, 1 ), 2.0 );
    EXPECT_EQ( matrix2( 1, 0 ), 3.0 );
    EXPECT_EQ( matrix2( 1, 1 ), 4.0 );

    EXPECT_EQ( matrix1.getRows(), 0 );
    EXPECT_EQ( matrix1.getColumns(), 0 );
}

TEST_F( MatrixTest, AssignmentOperator )
{
    // Given
    Matrix matrix1( 3, 3 );
    matrix1( 0, 0 ) = 1.0;

    // When
    Matrix matrix2 = matrix1;

    // Then
    EXPECT_EQ( matrix2.getRows(), matrix1.getRows() );
    EXPECT_EQ( matrix2.getColumns(), matrix1.getColumns() );
    EXPECT_EQ( matrix2( 0, 0 ), 1 );
}

TEST_F( MatrixTest, MoveAssignmentOperator )
{
    // Given
    Matrix matrix1( 2, 2 );
    matrix1(0, 0 ) = 1.0;
    matrix1(0, 1 ) = 2.0;
    matrix1(1, 0 ) = 3.0;
    matrix1(1, 1 ) = 4.0;

    // When
    Matrix matrix2( 1, 1 );
    matrix2 = std::move( matrix1 );

    // Then
    EXPECT_EQ( matrix2.getRows(), 2 );
    EXPECT_EQ( matrix2.getColumns(), 2 );
    EXPECT_EQ( matrix2( 0, 0 ), 1.0 );
    EXPECT_EQ( matrix2( 0, 1 ), 2.0 );
    EXPECT_EQ( matrix2( 1, 0 ), 3.0 );
    EXPECT_EQ( matrix2( 1, 1 ), 4.0 );

    EXPECT_EQ( matrix1.getRows(), 0 );
    EXPECT_EQ( matrix1.getColumns(), 0 );
}

TEST_F( MatrixTest, ParenthesisOperatorNotConst )
{
    // Given
    Matrix matrix( 2, 2 );

    // When
    matrix( 0, 0 ) = 1.0;
    matrix( 0, 1 ) = 2.0;

    // Then
    EXPECT_EQ( matrix(0, 0 ), 1.0 );
    EXPECT_EQ( matrix(0, 1 ), 2.0 );
}

TEST_F( MatrixTest, ParenthesisOperatorConst )
{
    // Given
    Matrix matrix( 2, 2 );

    // When
    matrix( 0, 0 ) = 1.0;
    matrix( 0, 1 ) = 2.0;

    const Matrix& constMatrix = matrix;

    // Then
    EXPECT_EQ( constMatrix(0, 0 ), 1.0 );
    EXPECT_EQ( constMatrix(0, 1 ), 2.0 );
}

TEST_F( MatrixTest, AdditionOperator )
{
    // Given
    Matrix matrix1( 2, 2 );
    matrix1( 0, 0 ) = 1.0;
    matrix1( 0, 1 ) = 2.0;
    matrix1( 1, 0 ) = 3.0;
    matrix1( 1, 1 ) = 4.0;

    Matrix matrix2( 2, 2 );
    matrix2( 0, 0 ) = 5.0;
    matrix2( 0, 1 ) = 6.0;
    matrix2( 1, 0 ) = 7.0;
    matrix2( 1, 1 ) = 8.0;

    // When
    Matrix result = matrix1 + matrix2;

    // Then
    EXPECT_EQ( result( 0, 0 ), 6.0 );
    EXPECT_EQ( result( 0, 1 ), 8.0 );
    EXPECT_EQ( result( 1, 0 ), 10.0 );
    EXPECT_EQ( result( 1, 1 ), 12.0 );
}

TEST_F( MatrixTest, SubtractionOperator )
{
    // Given
    Matrix matrix1( 2, 2 );
    matrix1( 0, 0 ) = 5.0;
    matrix1( 0, 1 ) = 6.0;
    matrix1( 1, 0 ) = 7.0;
    matrix1( 1, 1 ) = 8.0;

    Matrix matrix2( 2, 2 );
    matrix2( 0, 0 ) = 1.0;
    matrix2( 0, 1 ) = 2.0;
    matrix2( 1, 0 ) = 3.0;
    matrix2( 1, 1 ) = 4.0;

    // When
    Matrix result = matrix1 - matrix2;

    // Then
    EXPECT_EQ( result( 0, 0 ), 4.0 );
    EXPECT_EQ( result( 0, 1 ), 4.0 );
    EXPECT_EQ( result( 1, 0 ), 4.0 );
    EXPECT_EQ( result( 1, 1 ), 4.0 );
}

TEST_F( MatrixTest, MultiplicationOperator )
{
    // Given
    Matrix matrix1( 2, 2 );
    matrix1( 0, 0 ) = 1.0;
    matrix1( 0, 1 ) = 2.0;
    matrix1( 1, 0 ) = 3.0;
    matrix1( 1, 1 ) = 4.0;

    Matrix matrix2( 2, 2 );
    matrix2( 0, 0 ) = 2.0;
    matrix2( 0, 1 ) = 0.0;
    matrix2( 1, 0 ) = 1.0;
    matrix2( 1, 1 ) = 2.0;

    // When
    Matrix result = matrix1 * matrix2;

    // Then
    EXPECT_EQ( result( 0, 0 ), 4.0 );
    EXPECT_EQ( result( 0, 1 ), 4.0 );
    EXPECT_EQ( result( 1, 0 ), 10.0 );
    EXPECT_EQ( result( 1, 1 ), 8.0 );
}

TEST_F( MatrixTest, DeterminantMethod )
{
    // Given
    Matrix matrix( 2, 2 );
    matrix( 0, 0 ) = 1.0;
    matrix( 0, 1 ) = 2.0;
    matrix( 1, 0 ) = 3.0;
    matrix( 1, 1 ) = 4.0;

    // When
    const double result = matrix.determinant();
    const double expectedResult = -2.0;

    // Then
    EXPECT_EQ( result, expectedResult );
}

TEST_F( MatrixTest, SubMatrixMethod )
{
    // Given
    Matrix matrix( 3, 3 );
    matrix( 0, 0 ) = 1.0;
    matrix( 0, 1 ) = 2.0;
    matrix( 0, 2 ) = 3.0;
    matrix( 1, 0 ) = 4.0;
    matrix( 1, 1 ) = 5.0;
    matrix( 1, 2 ) = 6.0;
    matrix( 2, 0 ) = 7.0;
    matrix( 2, 1 ) = 8.0;
    matrix( 2, 2 ) = 9.0;

    // When
    Matrix subMatrix = matrix.subMatrix( 1, 1 );

    // Then
    EXPECT_EQ( subMatrix.getRows(), 2 );
    EXPECT_EQ( subMatrix.getColumns(), 2 );
    EXPECT_EQ( subMatrix( 0, 0 ), 1.0 );
    EXPECT_EQ( subMatrix( 0, 1 ), 3.0 );
    EXPECT_EQ( subMatrix( 1, 0 ), 7.0 );
    EXPECT_EQ( subMatrix( 1, 1 ), 9.0 );
}

TEST_F( MatrixTest, GetRowsMethod )
{
    // Given
    const Matrix matrix( 2, 2 );

    // When
    const int result = matrix.getRows();
    const int expectedResult = 2;

    // Then
    EXPECT_EQ( result, expectedResult );
}

TEST_F( MatrixTest, GetColumnsMethod )
{
    // Given
    const Matrix matrix( 3, 3 );

    // When
    const int result = matrix.getColumns();
    const int expectedResult = 3;

    // Then
    EXPECT_EQ( result, expectedResult );
}

TEST_F( MatrixTest, PrintMethod )
{
    // Given
    Matrix matrix( 2, 2 );
    matrix( 0, 0 ) = 1.0;
    matrix( 0, 1 ) = 2.0;
    matrix( 1, 0 ) = 3.0;
    matrix( 1, 1 ) = 4.0;

    // When
    const std::string expectedOutput = "         1          2 \n"
                                 "         3          4 \n";

    // Then
    EXPECT_EQ( captureOutput( matrix ), expectedOutput );
}

TEST_F( MatrixTest, IdentityMethod )
{
    // Given

    // When
    Matrix identity = Matrix::identity( 3 );

    // Then
    EXPECT_EQ( identity.getRows(), 3 );
    EXPECT_EQ( identity.getColumns(), 3 );
    EXPECT_EQ( identity( 0, 0 ), 1.0 );
    EXPECT_EQ( identity( 0, 1 ), 0.0 );
    EXPECT_EQ( identity( 0, 2 ), 0.0 );
    EXPECT_EQ( identity( 1, 0 ), 0.0 );
    EXPECT_EQ( identity( 1, 1 ), 1.0 );
    EXPECT_EQ( identity( 1, 2 ), 0.0 );
    EXPECT_EQ( identity( 2, 0 ), 0.0 );
    EXPECT_EQ( identity( 2, 1 ), 0.0 );
    EXPECT_EQ( identity( 2, 2 ), 1.0 );
}
