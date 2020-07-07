#include "IdentityMatrix.h"

//parameterized constructor which calls parameterized constructor of SquareMatrix
IdentityMatrix::IdentityMatrix(int order) :SquareMatrix(order)
{
    //setting the matrix as an identity matrix

    for ( unsigned int i = 1; i <= order; i++)
    {
        for ( unsigned int j = 1; j <= order; j++)
        {
            if (i == j)
                element(i, j) = 1;
            else
                element(i, j) = 0;

        } // first for loop ends
    } // second for loop ends

} // function ends


IdentityMatrix::~IdentityMatrix()  // destructor
{
} //function ends
