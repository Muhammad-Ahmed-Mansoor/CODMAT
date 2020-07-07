#include "ColumnVector.h"
#include<exception>

ColumnVector::ColumnVector(int num_rows) :Matrix(num_rows,1)  // paramterized constructor with arguemnts sent to base class paramterized constructor
{
} // function ends

ColumnVector::ColumnVector(Matrix g_matrix) : Matrix(g_matrix.get_row(), 1)  // paramterized constructor with arguemnts sent to base class paramterized constructor
{
    *this = g_matrix;
} // function ends

ColumnVector::~ColumnVector()  // destructor
{
} // function ends

Cmplx& ColumnVector::element(int n) const      //accessor function for an element of a matrix
{
    return Matrix::element(n,1);

} // function ends

ColumnVector& ColumnVector::operator=(const Cmplx* g_arr) //overloaded operator
{

    for ( unsigned int i = 1; i <= get_row(); i++)
        element(i) = g_arr[i - 1];

    return *this;

} // function ends

ColumnVector& ColumnVector::operator=(const ColumnVector& g_Column) //overloaded operator
{


    if (g_Column.get_row() != get_row())
        throw exception();

    for ( unsigned int i = 1; i <= get_row(); i++)
        element(i) = g_Column.element(i);


    return *this;

} // function ends

ColumnVector& ColumnVector::operator=(const Matrix& g_Column) //overloaded operator
{


    if (g_Column.get_row() != get_row()|| g_Column.get_col()!=1)
        throw exception();

    for ( unsigned int i = 1; i <= get_row(); i++)
        element(i) = g_Column.element(i,1);


    return *this;

} // function ends
