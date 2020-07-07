#ifndef ROWVECTOR_H
#define ROWVECTOR_H

#include "Matrix.h"
class RowVector :public Matrix // RowVector has inherted Marix class and mode of inheritance is public.
{
public://public access modifier
    RowVector(int); // parametrized constructor
    ~RowVector(); // destructor
    RowVector& operator=(const Cmplx*); //overloaded operator
    RowVector& operator=(const RowVector&); //overloaded operator
    Cmplx& element(int n) const; //element accessor
};

#endif
