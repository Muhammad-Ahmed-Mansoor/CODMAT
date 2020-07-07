#include "Matrix.h"
#include "SquareMatrix.h"
#include"RowVector.h"

// including libraries
#include<exception>
#include<cstdlib>
#include<iostream>
#include<iomanip>
using namespace std;

Matrix::Matrix(unsigned int g_row, unsigned int g_col)   // paramterised constructor
{
    row = g_row;
    col = g_col;
    elements = new Cmplx[row*col];
} //end function

Matrix::~Matrix()  // destructor
{

}//end function

Matrix::Matrix()  // default constructor
{
} //end function

 unsigned int Matrix::index(unsigned int i, unsigned int j)const    // index function
{
    return (i - 1)*col + (j - 1);
} //end function

 unsigned int Matrix::get_col() const       //column accessor function
{
    return col;
} //end function

 unsigned int Matrix::get_row() const   // row accessor function
{
    return row;
} //end function

Matrix& Matrix::operator=(const Cmplx* g_array)  //overloaded operator
{
    for ( unsigned int i = 0; i < row*col; i++)
        elements[i] = g_array[i];
    return *this;
}  //end function

Matrix& Matrix::operator=(const Matrix& g_matrix)  //overloaded operator
{
    if (g_matrix.row != row || g_matrix.col != col)
        throw exception();

    for ( unsigned int i = 0; i < row*col; i++)
        elements[i] = g_matrix.elements[i];


    return *this;
}  //end function

void Matrix::print(ostream& file  , string left_str  , string right_str, string top )const    // display function
{
    unsigned int len =longest_entry_len() + 3;


    file << string(left_str.size() + 2, ' ');
    if (col!=1)
        file << setw(len) << std::left << "__";
    else
        file << setw(len-2) << std::left << "__";
    for (int j = 2; j < col; j++)
    {
        file << setw(len) << " ";

    }
    if (col==1)
        file << "__" << std::left << top << endl;
    else
    file << std::right << setw(len) << "__" <<std::left<<top<< endl;




    file << string(left_str.size() + 1, ' ');
    file << '|';

    for (int j = 1; j <= col; j++)
    {
        file << setw(len) << " ";

    }
    file << '|' << endl;




    for (int i = 1; i <= row; i++)
    {
        if (i == (row / 2)+1)
        {
            file << " " << left_str;
        }
        else
        {
            file << string(left_str.size() + 1, ' ');
        }

        file << '|';


        for (int j = 1; j <= col; j++)
        {

            if (j == 1)
                file << std::left << setw(len) << element(i, j).str_rect();
            else
                file << std::right << setw(len) << element(i, j).str_rect();

        }


        file << '|';

        if (i == (row / 2) + 1)
        {
            file << " " << right_str << endl;
        }
        else
        {
            file << endl;
        }

    }


    file << string(left_str.size() + 1, ' ');
    file << '|';

    if (col !=1)
        file << setw(len) << std::left << "__";
    else
        file << setw(len-2) << std::left << "__";

    for (int j = 2; j < col; j++)
    {
        file << setw(len) << " ";

    }

    if (col !=1)
        file << std::right << setw(len) << "__";
    else
        file  << "__";

    file << '|' << endl << endl;
}  //end function


Cmplx& Matrix::element(unsigned int i, unsigned int j) const  //accessor for an element of a matrix
{
    if (i > row || j > col){
        throw exception();
    }

    return elements[index(i, j)];
} // end function

Matrix Matrix::transpose(bool should_print, ostream& file)   // function to find the tranpose of a matrix
{
    Matrix trans(col, row);

    for ( unsigned int i = 1; i <= trans.row; i++)
    {
        for ( unsigned int j = 1; j <= trans.col; j++)
        {
            trans.element(i, j) = element(j, i);    //swapping of rows into columns and vice versa
        }
    }

    if (should_print)
    {
        print(file, " ", " ", " t");
        trans.print(file, "=");
    }

    return trans;
} //end function

RowVector Matrix::get_row(unsigned int row_num)   // row accessor function
{
    if (row_num > row)
        throw exception();

    RowVector req_row(col);

    for ( unsigned int i = 1; i <= col; i++)
        req_row.element(i) = element(row_num, i);

    return req_row;

} //end function

void Matrix::set_row(unsigned int row_num, RowVector g_row) // row mutator function
{
    if (row_num > row)
        throw exception();
    if (g_row.get_col() > col)
        throw exception();


    for ( unsigned int i = 1; i <= col; i++)
        element(row_num, i) = g_row.element(i);


} //end function

void Matrix::swap_rows(unsigned int row1, unsigned int row2)  // swapping rows function
{
    RowVector temp(col);

    temp = get_row(row1);

    set_row(row1, get_row(row2));
    set_row(row2, temp);

    return;
} //end function

void Matrix::divide_row(unsigned int row_num, Cmplx divisor) // dividing two rows function
{
    if (row_num > row)
        throw exception();


    for ( unsigned int i = 1; i <= col; i++)
        element(row_num, i) = element(row_num, i) / divisor;

    return;
} //end function

void Matrix::add_multiple_of_row(unsigned int row1, Cmplx multiplier, unsigned int row2)  // function adding multiple of a row to another row
{
    if (row1> row || row2>row)
        throw exception();

    for ( unsigned int i = 1; i <= col; i++)
        element(row1, i) = element(row1, i) + (multiplier*element(row2, i));
}//end function

Matrix Matrix::ref(bool should_print , ostream& file ) //row echelon form function
{
    Matrix echelon(row, col);
    echelon = *this;

    int pivot_row;
    unsigned int curr_row, curr_col;
    Cmplx pivot, multiplier;

    if (should_print)
    {
        file << "The given matrix is:-\n" << endl;
        print(file);
        file << "We now apply Gauss Elimination.\n" << endl;
    }

    for (curr_row = 1, curr_col = 1; curr_row <= row && curr_col <= col; curr_row++, curr_col++)
    {
        pivot_row = -1;
        //first finding the pivot row
        for ( unsigned int row_iter = curr_row; row_iter <= row; row_iter++)
        {
            if (echelon.element(row_iter, curr_col) != 0)
            {
                pivot_row = row_iter;
                pivot = echelon.element(row_iter, curr_col);
                break;
            }

        } // for loop ends

        //swapping pivot row to current row if necessary. If no pivot found meaning already zero column
        if (pivot_row == -1)
        {
            continue;
        }
        else if (pivot_row != curr_row)
        {
            echelon.swap_rows(pivot_row, curr_row);
            if (should_print)
            {
                file << "Swapping Row#" << pivot_row << " and Row#" << curr_row << " :-\n" << endl;
                echelon.print(file, "~");
            }
        }

        //now dividing pivot row by pivot
        if (pivot != 1)
        {
            echelon.divide_row(curr_row, pivot);
            if (should_print)
            {
                file << "Dividing Row#" << curr_row << " by " << pivot.str_rect() << " :-\n" << endl;
                echelon.print(file, "~");
            }
        }

        //now making all leading elements in curr col zero
        for ( unsigned int row_iter = curr_row + 1; row_iter <= row; row_iter++)
        {
            if (echelon.element(row_iter, curr_col) != 0)
            {
                multiplier = echelon.element(row_iter, curr_col);
                echelon.add_multiple_of_row(row_iter, -1 * multiplier, curr_row);
                if (should_print)
                {
                    file << "Adding " << (-1 * multiplier).str_rect() << " times Row#" << curr_row << " to Row#" << row_iter << " :-\n" << endl;
                    echelon.print(file, "~");
                }
            }

        }
    } // end of first for loop

    //making all leading entries 1 which is automatic for square matrix but not guaranteed otherwise

    if (row != col)
    {
        for ( unsigned int i = 1; i <= row; i++)
        {
            for (unsigned int j = 1; j <= col; j++)
            {
                if (echelon.element(i, j) == 1)
                    break;
                else if (echelon.element(i, j) == 0)
                    continue;
                else
                {
                    echelon.divide_row(i, echelon.element(i, j));
                    if (should_print)
                    {
                        file << "Dividing Row#" << i << " by " << echelon.element(i, j).str_rect() << " :-\n" << endl;
                        echelon.print(file, "~");
                    }
                    break;
                }
            } // second for loop ends
        }  // first for loop ends
    }//endif
    if (should_print)
    {
        file << "Matrix is now in row echelon form.\n"<<endl;
    }

    return echelon;
}  //end function

Matrix Matrix::rref(bool should_print, ostream& file) //reduced row echelon form function
{
    Matrix red_echelon(row, col);
    red_echelon = ref(true,file);

    int pivot_col;
    unsigned int curr_row, curr_col, last_row = row;
    Cmplx  multiplier;
    bool zero_row;

    if (should_print)
    {
        file << "Now for reduced row echelon form we extend Gaussian Elimination to Gauss-Jordan Elimination.\n" << endl;
    }
    for (curr_row = row; curr_row >= 2; curr_row--)
    {
        zero_row = true;
        //finding pivot col (leading entry 1)
        for (unsigned int col_iter = col; col_iter >= 1; col_iter--)
        {
            if (zero_row && red_echelon.element(curr_row, col_iter) != 0)
            {
                zero_row = false;

            }
            if (red_echelon.element(curr_row, col_iter) == 1)
                pivot_col = col_iter;

        }
        //swapping with last row if curr_row is zero
        if (zero_row)
        {
            red_echelon.swap_rows(curr_row, last_row);
            last_row--;
            if (should_print)
            {
                file << "Swapping Row#" << last_row << " and Row#" << curr_row << " :-\n" << endl;
                red_echelon.print(file, "~");
            }
            continue;

        }



        //now making all leading elements in pivot col zero
        for (unsigned int row_iter = curr_row - 1; row_iter >= 1; row_iter--)
        {
            if (red_echelon.element(row_iter, pivot_col) != 0)
            {
                multiplier = red_echelon.element(row_iter, pivot_col);
                red_echelon.add_multiple_of_row(row_iter, -1 * multiplier, curr_row);
                if (should_print)
                {
                    file << "Adding " << (-1 * multiplier).str_rect() << " times Row#" << curr_row << " to Row#" << row_iter << " :-\n" << endl;
                    red_echelon.print(file, "~");
                }
            }

        } // end of for loop
    } // end of for loop
    if (should_print)
    {
        file << "Matrix is now in reduced row echelon form.\n" << endl;
    }

    return red_echelon;
} // end function


Matrix Matrix::operator + (const Matrix& a)							//overloaded operator
{
    if (a.get_row() != row || a.get_col() != col)
    {
        throw exception();
    }

    Matrix sum(a.get_row(), a.get_col());
    for (unsigned int i = 1; i <= sum.get_row(); i++)
    {
        for (unsigned int j = 1; j <= sum.get_col(); j++)
        {
            sum.element(i, j) = a.element(i, j) + element(i, j);
        }
    }

    return sum;
} // add function ends
Matrix Matrix::operator - (const Matrix& a)				//overloaded operator
{
    if (a.get_row() != get_row() || a.get_col() != get_col())
    {
        throw exception();
    }

    Matrix diff(a.get_row(), a.get_col());
    for (unsigned int i = 1; i <= diff.get_row(); i++)
    {
        for (unsigned int j = 1; j <= diff.get_col(); j++)
        {
            diff.element(i, j) = element(i, j) - a.element(i, j);
        }
    }

    return diff;
} // subtract function ends
Matrix Matrix::operator * (const Matrix& a)						//overloaded operator
{
    if (get_col() != a.get_row())
        throw exception();


    Matrix prod(get_row(), a.get_col());

    for (unsigned int i = 1; i <= prod.get_row(); i++)
    {
        for (unsigned int j = 1; j <= prod.get_col(); j++)
        {
            prod.element(i, j) = 0;

            for (unsigned int k = 1; k <= get_col(); k++)
            {
                prod.element(i, j) = prod.element(i, j) + (element(i, k) * a.element(k, j));
            } // first for loop ends

        } // second for loop ends
    } // third for loop ends

    return prod;
} // multiply function ends
bool Matrix::operator==(const Matrix& g_matrix)                   //overloaded operator
{
    if (g_matrix.get_row() != get_row() || g_matrix.get_col() != get_col())
        return false;

    for (unsigned int i = 1; i <= get_row(); i++)
    {
        for (unsigned int j = 1; j <= get_col(); j++)
        {
            if (element(i, j) != g_matrix.element(i, j))
                return false;
        } // first for loop ends
    } // second for loop ends

    return true;
} // end function

unsigned int Matrix::longest_entry_len() const  //accessor for longest entry
{
    unsigned int len = 0;
    for (int unsigned i = 1; i <= row; i++)
    {
        for (int unsigned j = 1; j <= col; j++)
        {
            if (element(i, j).str_rect().length() > len)
                len = element(i, j).str_rect().length();

        } // second for loop ends
    }  // first for loop ends

    return len;
} // end function

Matrix Matrix::add(const Matrix& a, bool should_print , ostream& file ) //adds two matrixes
{
    if (should_print)
    {
        print(file);
        a.print(file,"+");
        (*this + a).print(file, "=");
    }
    return (*this + a);
} // end function

Matrix Matrix::subtract(const Matrix& a, bool should_print, ostream& file) //calculates difference between two matrixes
{
    if (should_print)
    {
        print(file);
        a.print(file, "-");
        (*this - a).print(file, "=");
    }
    return (*this - a);
} // end function

Matrix Matrix::multiply(const Matrix& a, bool should_print, ostream& file) //multiplies two matrixes
{
    if (should_print)
    {
        print(file);
        a.print(file, "x");
        (*this * a).print(file, "=");
    }
    return (*this * a);
} // end function
