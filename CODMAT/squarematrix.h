#ifndef SQUAREMATRIX_H
#define SQUAREMATRIX_H
#include "Matrix.h"
#include<fstream>
#include<string>
#include<iostream>
using namespace std;
class ColumnVector;   // forward declaration of class ColumnVector

class SquareMatrix :  // class SquareMatrix is inherited from class Mode and mode of inheritance is public
        public Matrix
{
public: //public access modifier
    SquareMatrix(int);   // parametrized constructor
    SquareMatrix(Matrix);// parametrized overloaded constructor
    ~SquareMatrix();  // destructor

    SquareMatrix& operator=(const SquareMatrix&);  //overloaded calculation operator
    SquareMatrix& operator = (const Matrix&);  //overloaded calculation operator
    SquareMatrix& operator=(const Cmplx*);  //overloaded calculation operator
    SquareMatrix operator ^ (int);			//overloaded power operator

    SquareMatrix int_pow(int a, bool should_print = false, ostream& file = std::cout);
    SquareMatrix inverse(bool should_print = false, ostream& file = std::cout);
    ColumnVector solve_equations(ColumnVector, bool should_print = false, ostream& file = std::cout);
    Cmplx determinant(bool should_print=false,ostream& file=std::cout);
    void print_det(ostream& file=std::cout,string left=" ",string right=" ");
};
#endif
