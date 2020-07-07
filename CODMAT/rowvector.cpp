#include "RowVector.h"
#include<exception>

RowVector::RowVector(int num_cols) :Matrix(1, num_cols)  // paramterized constructor with arguemnts sent to base class paramterized constructor
{
} //function ends


RowVector::~RowVector()  // destructor
{
} // function ends

Cmplx& RowVector::element(int n) const      //element accessor
{
    return Matrix::element(1, n);

} // function ends

RowVector& RowVector::operator=(const Cmplx* g_arr)   //overloaded operator
{

    for ( unsigned int i = 1; i <= get_col(); i++)
        element(i) = g_arr[i - 1];

    return *this;

} // function ends

RowVector& RowVector::operator=(const RowVector& g_row)   //overloaded operator
{


    if (g_row.get_col() != get_col())
        throw exception();

    for ( unsigned int i = 1; i <= get_col(); i++)
        element(i) = g_row.element(i);


    return *this;

} // function ends
