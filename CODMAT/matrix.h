#ifndef MATRIX_H
#define MATRIX_H

#include"Cmplx.h"
class RowVector;  // forward declaration of class RowVector
class SquareMatrix;
#include<iostream>

class Matrix  // class Matrix
{
private:    // private access modifier
    Cmplx *elements;
     unsigned int row;
     unsigned int col;
     unsigned int index(unsigned int i, unsigned int j)const;

public:    // public access modifier
    void print(ostream& file = std::cout, string left_str = " ", string right_str = " ",string top=" ") const;
    Matrix(unsigned int,unsigned int);  // parameterised constrcutor
    Matrix();    // default constructor
    ~Matrix();   // destructor

     unsigned int get_row() const; //row accessor
     unsigned int get_col() const; //column accessor
    Cmplx& element(unsigned int i,unsigned int j) const; //element accessor
    Matrix& operator=(const Cmplx*); //overloaded operator
    Matrix& operator=(const Matrix&); //overloaded operator

    Matrix transpose(bool should_print = false, ostream& file = std::cout); //calculates transpose
    RowVector get_row(unsigned int); //returns row
    void set_row(unsigned int, RowVector); //row mutator
    void swap_rows(unsigned int,unsigned int); //swaps two rows
    void divide_row(unsigned int, Cmplx); //divides one row with the other
    void add_multiple_of_row(unsigned int, Cmplx, unsigned int); //adds multiple of one row to the other
     unsigned int longest_entry_len() const; //accessor for longest entry

    Matrix ref(bool should_print = false, ostream& file = std::cout); //row echelon form function
    Matrix rref(bool should_print = false, ostream& file = std::cout); //reduced row echelon form function


    Matrix add(const Matrix& a, bool should_print = false, ostream& file = std::cout); //adds two matrixes

    Matrix subtract(const Matrix& a, bool should_print = false, ostream& file = std::cout); //calculates differece between two matrixes

    Matrix multiply(const Matrix& a, bool should_print = false, ostream& file = std::cout); //multiplies two matrixes


    Matrix operator + (const Matrix& a);					//overloaded operator

    Matrix operator - (const Matrix& a);				    //overloaded operator

    Matrix operator * (const Matrix& a);					//overloaded operator

    bool operator==(const Matrix&);                         //overloaded operator

};


#endif
