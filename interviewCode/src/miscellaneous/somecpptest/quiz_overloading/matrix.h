/**
This is a matrix library that supports the
creation of matricies with given parameters
or from a formatted text file.
The standard operators are overloaded to work
with matrix arithmetic. Currently supported
functions include addition, scalar multiplication
of both ways (e.g. 5*A, A*5), matrix multiplication,
transposition, and checking for equality and
inequality.
Future plans currently include optimizing matrix
multiplication with Strassen's algorithm, supporting
determinants, and ultimately to extend this class
to a linear algebra toolkit.
NOTE: This implementation takes advantage of
      optimizations found in C++11/C++0x,
      particularlly move construction, so
      compile accordingly.
Author: Sanil Sampat
Date  : 2 / 2 / 12 (last update)
**/

#ifndef MATRIX_H
#define MATRIX_H
#include <iostream>
#include <fstream>
using namespace std;

class Matrix
{
    friend ostream & operator<<(ostream& output, Matrix& m);
    friend istream & operator>>(istream& input , Matrix& m);

    public:

        // constructors
        Matrix();                     // default
        Matrix(const Matrix& other);  // copy constructor
        Matrix(Matrix&& that      );  // move constructor, compile as C++11/C++0x
        Matrix(int rows, int cols );  // given row/col


        int getRowCount() const { return m_rows; }
        int getColCount() const { return m_cols; }
        void setRowCount(int rows) { m_rows = rows; }
        void setColCount(int cols) { m_cols = cols; }
        float& access(int row, int col) const;
        friend void swap(Matrix& first, Matrix& second);

        // member function
        Matrix& operator=(Matrix m);
        friend Matrix operator+  (const Matrix &lhs, const Matrix &rhs);
        friend Matrix operator*  (const float  &lhs, const Matrix &rhs);
        friend Matrix operator*  (const Matrix &rhs, const float  &lhs);
        friend Matrix operator*  (const Matrix &lhs, const Matrix &rhs);

        ~Matrix();

    private:

        int m_rows;
        int m_cols;
        float** theMatrix;
};

// non-member function
Matrix operator- (const Matrix &lhs, const Matrix &rhs);
bool   operator== (const Matrix &lhs, const Matrix &rhs);
bool   operator!= (const Matrix &lhs, const Matrix &rhs);
Matrix operator!  (const Matrix &m);


#endif // MATRIX_H
