#ifndef COLUMNVECTOR_H
#define COLUMNVECTOR_H
#include "Matrix.h"
class ColumnVector :
    public Matrix
{
public://public access modifier
    ColumnVector(int); // parametrized constructor
    ColumnVector(Matrix);//overloaded parameterized constructor
    ~ColumnVector(); // destructor
    ColumnVector& operator=(const Cmplx*); //overloaded operator
    ColumnVector& operator=(const ColumnVector&); //overloaded operator
    ColumnVector& operator=(const Matrix&); //overloaded operator
    Cmplx& element(int n) const; //accessor for an element of a matrix
};
#endif// COLUMNVECTOR_H
