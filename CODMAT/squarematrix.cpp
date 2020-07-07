// including libraries
#include "SquareMatrix.h"
#include "IdentityMatrix.h"
#include"ColumnVector.h"
#include"AugmentedMatrix.h"
#include <exception>
#include<iomanip>

SquareMatrix::SquareMatrix(int order) :Matrix(order,order)  // parameterized constructor
{

} // function ends

SquareMatrix::SquareMatrix(Matrix g_matrix) : Matrix(g_matrix.get_row(), g_matrix.get_col()) //parameterized constructor
{
    *this = g_matrix;
} // function ends

SquareMatrix::~SquareMatrix() // destrcutor
{
} // function ends

SquareMatrix& SquareMatrix::operator = (const SquareMatrix& g_matrix)  //overloaded operator
{
    if (g_matrix.get_row() != get_row() || g_matrix.get_col() != get_col())
        throw exception();

    for ( unsigned int i = 1; i <= get_row(); i++)
    {
        for ( unsigned int j = 1; j <= get_col(); j++)
        {
            element(i, j) = g_matrix.element(i, j);
        } // first for loop ends
    }  // second for loop ends

    return *this;
}

SquareMatrix& SquareMatrix::operator = (const Matrix& g_matrix)  //overloaded operator
{
    if (g_matrix.get_row() != get_row() || g_matrix.get_col() != get_col())
        throw exception();

    for ( unsigned int i = 1; i <= get_row(); i++)
    {
        for ( unsigned int j = 1; j <= get_col(); j++)
        {
            element(i, j) = g_matrix.element(i, j);
        } // first for loop ends
    } // second for loop ends

    return *this;
} //function ends

SquareMatrix& SquareMatrix::operator=(const Cmplx* g_arr)  //overloaded operator
{

    for ( unsigned int i = 1; i <= get_row(); i++)
    {
        for ( unsigned int j = 1; j <= get_col(); j++)
        {
            element(i, j) = g_arr[(i - 1)*get_col() + (j - 1)];
        } // first for loop ends
    } // second for loop ends
    return *this;
} // function ends

SquareMatrix SquareMatrix::operator ^ (int n)  //overloaded operator
{
    SquareMatrix pow(get_row());
    pow = IdentityMatrix(get_row());

    for ( unsigned int i = 1; i <= n; i++)
        pow = pow * (*this);

    return pow;
} // function ends

SquareMatrix SquareMatrix::int_pow(int a, bool should_print, ostream& file)
{
    if (should_print)
    {
        print(file," "," ",(" "+to_string(a)));
        (*this ^ a).print(file, "=");
    }
    return (*this ^ a);
} // function ends

SquareMatrix SquareMatrix::inverse(bool should_print, ostream& file)
{
    if (should_print)
    {
        file << "We find the inverse by appending an identity matrix of order "<<get_row()<<" with the given matrix."<<endl;
    }

    AugmentedMatrix A(*this, IdentityMatrix(this->get_row()));
    SquareMatrix sol=A.solution(should_print, file);

    if (should_print&& !(sol==IdentityMatrix(1)))
    {
        file << "Thus:-\n"<<endl;
        print(file, " ", " ", "  -1");
        sol.print(file, "=");
    }

    return sol;
} // function ends

ColumnVector SquareMatrix::solve_equations(ColumnVector B, bool should_print, ostream& file)
{

    AugmentedMatrix A(*this, B);
    ColumnVector sol= A.solution(should_print,file);



    if (should_print&& !(sol == IdentityMatrix(1)))
    {
        file << "Thus:-\n" << endl;
        for ( unsigned int i = 1; i <= get_row(); i++)
        {
            file << "x" << i << " = " << sol.element(i).str_rect() << " = " << sol.element(i).str_polar()<< endl;
        } // for loop ends

    }

    return sol;
}

Cmplx SquareMatrix::determinant(bool should_print,ostream& file)
{
    Cmplx det = 1;

    SquareMatrix temp(get_row());
    temp = *this;

    int pivot_row;
    unsigned int curr_row, curr_col, row = get_row(), col = get_col();
    Cmplx pivot, multiplier;


    if (should_print)
    {
        file << "Given determinant is:-\n" << endl;
        temp.print_det(file);
        file << "Reducing determinant to upper triangular form through row operations:-\n " << endl;
        temp.print_det(file);
    }




    for (curr_row = 1, curr_col = 1; curr_row <= row && curr_col <= col; curr_row++, curr_col++)
    {
        pivot_row = -1;
        //first finding the pivot row
        for ( unsigned int row_iter = curr_row; row_iter <= row; row_iter++)
        {
            if (temp.element(row_iter, curr_col) != 0)
            {
                pivot_row = row_iter;
                pivot = temp.element(row_iter, curr_col);
                break;
            }

        } // for loop ends

        //swapping pivot row to current row if necessary. If no pivot found meaning remaining column already zero
        if (pivot_row == -1)
        {
            //if this situation occurs in first column it means det is zero
            if (curr_col == 1)
            {
                if (should_print)
                {
                    file << "First column is zero so Det=0."<<endl;
                }

                return 0;
            }


            continue;
        }


        else if (pivot_row != curr_row)
        {
            temp.swap_rows(pivot_row, curr_row);
            det = det*-1;
            if (should_print)
            {
                file << "Swapping Row#"<<pivot_row<<" and Row#"<<curr_row<<" :-\n" << endl;
                temp.print_det(file, ("= (" + det.str_rect() + ")"));
            }


        }

        //now dividing pivot row by pivot
        if (pivot != 1)
        {
            temp.divide_row(curr_row, pivot);
            det = det*pivot;
            if (should_print)
            {
                file << "Extracting " << pivot.str_rect() << " from Row#" << curr_row << " :-\n" << endl;
                temp.print_det(file, ("= (" + det.str_rect() + ")"));
            }

        }

        //now making all leading elements in curr col zero
        for ( unsigned int row_iter = curr_row + 1; row_iter <= row; row_iter++)
        {
            if (temp.element(row_iter, curr_col) != 0)
            {
                multiplier = temp.element(row_iter, curr_col);
                temp.add_multiple_of_row(row_iter, -1 * multiplier, curr_row);

                if (should_print)
                {
                    file << "Adding " << (-1*multiplier).str_rect()<<" times Row#" << curr_row << " to Row#" << row_iter << " :-\n" << endl;
                    temp.print_det(file, ("= (" + det.str_rect() + ")"));
                }
            }

        }
    } // end of first for loop
    if (should_print)
    {
        file << "Now the matrix is in upper triangular form so the determinant is simply the product of the diagonal entries with " << det.str_rect() << " :-\n" << endl;
        file << "Det= " << det.str_rect() << " ";
    }

    //determinant is to be now multiplied by all the diagonal entries
    for ( unsigned int i = 1; i <= row; i++)
    {

        det = det*temp.element(i, i);

        if (should_print)
        {
            file << "x " << temp.element(i, i).str_rect() << " ";
        }
    }  // first for loop ends

    if (should_print)
    {
        file << "= " << det.str_rect() << endl;
    }
    return det;
} // function ends

void SquareMatrix::print_det(ostream& file, string left, string right )
{
    unsigned int n = get_row(),len=longest_entry_len()+3;

    file << string(left.size() + 1, ' ');
    file << '|';

    for ( unsigned int j = 1; j <= n; j++)
    {
        file << setw(len) << " ";

    } // for loop ends

    file << '|' << endl;




    for ( unsigned int i = 1; i <= n; i++)
    {
        if (i == (n / 2)+1)
        {
            file << " " << left;
        }
        else
        {
            file << string(left.size() + 1, ' ');
        }

        file << '|';

        for ( unsigned int j = 1; j <= n; j++)
        {
            if (j==1)
                file <<std::left<< setw(len)<< element(i, j).str_rect();
            else
                file << std::right << setw(len) << element(i, j).str_rect();


        } // second for loop ends

        file << '|';

        if (i == (n / 2)+1)
        {
            file << " " << right<<endl;
        }
        else
        {
            file << endl;
        }

    } // for loop ends


    file << string(left.size() + 1, ' ');
    file << '|';

    for ( unsigned int j = 1; j <= n; j++)
    {
        file << setw(len) << " ";

    } // for loop ends

    file << '|' << endl << endl;

} // end function
