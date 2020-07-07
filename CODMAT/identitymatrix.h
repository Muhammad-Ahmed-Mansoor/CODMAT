#ifndef IDENTITYMATRIX_H
#define IDENTITYMATRIX_H
#include "SquareMatrix.h"
class IdentityMatrix :   // IdentityMatrix inherited from Square Matrix with public mode of inheritance
    public SquareMatrix
{
    public://public access modifier
    IdentityMatrix(int);   // paramterised constructor
    ~IdentityMatrix();    // destructor
};
#endif// IDENTITYMATRIX_H

