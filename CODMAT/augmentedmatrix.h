#ifndef AUGMENTED_MATRIX_H
#define AUGMENTED_MATRIX_H
#include "Matrix.h"
#include "SquareMatrix.h"
#include"ColumnVector.h"
class AugmentedMatrix // class of augmented matrix
{

private:   // priavte access modifier
    SquareMatrix *left;
    Matrix *right;
public:    // public access modifier
    AugmentedMatrix(SquareMatrix,SquareMatrix); //parameterized constructor
    AugmentedMatrix(SquareMatrix, ColumnVector);//parameterized overloaded constructor
    ~AugmentedMatrix();  // destructor
    Matrix solution(bool should_print = false, ostream& file = std::cout); //solution calculating function
    void print(ostream& file=std::cout, string left_str = " ", string right_str = " "); //solution printing function

};
#endif// AUGMENTED_MATRIX_H
