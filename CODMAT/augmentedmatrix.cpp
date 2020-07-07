#include "augmentedmatrix.h"
#include "identitymatrix.h"
#include<iostream>
#include<exception>
#include<iomanip>
using namespace std;

AugmentedMatrix::AugmentedMatrix(SquareMatrix g_left, SquareMatrix g_right)
{
    if (g_left.get_row() == g_right.get_row())
    {
        left = new SquareMatrix(g_left.get_row());
        right = new SquareMatrix(g_right.get_row());
        *left = g_left;
        *right = g_right;
    }
    else
        throw exception();

} // end function

AugmentedMatrix::AugmentedMatrix(SquareMatrix g_left, ColumnVector g_right)
{
    if (g_left.get_row() == g_right.get_row())
    {
        left = new SquareMatrix(g_left.get_row());
        right = new ColumnVector(g_right.get_row());
        *left = g_left;
        *right = g_right;
    }
    else
        throw exception();
} // end function

AugmentedMatrix::~AugmentedMatrix()
{
}

void AugmentedMatrix::print(ostream& file, string left_str, string right_str )
{
    unsigned int rows = left->get_row(), col1 = left->get_col(), col2 = right->get_col(),
    len1 = left->longest_entry_len()+3,
    len2=right->longest_entry_len()+3;


    file << string(left_str.size() + 2, ' ');
    file << setw(len1) << std::left << "__";
    for ( unsigned int j = 2; j <= col1; j++)
    {
        file << setw(len1) << " ";

    }  // for loop ends
    file << " ";
    for ( unsigned int j = 1; j < col2; j++)
    {
        file << setw(len2) << " ";

    } // for loop ends
    file << std::right<< setw(len2) << "__" << endl;




    file << string(left_str.size() + 1, ' ');
    file << '|';

    for ( unsigned int j = 1; j <= col1; j++)
    {
        file << setw(len1) << " ";

    } // for loop ends
    file << " ";
    for ( unsigned int j = 1; j <= col2; j++)
    {
        file << setw(len2) << " ";

    }  // for loop ends
    file << '|' << endl;




    for ( unsigned int i = 1; i <= rows; i++)
    {
        if (i == (rows / 2) + 1)
        {
            file << " " << left_str;
        }
        else
        {
            file << string(left_str.size() + 1, ' ');
        }

        file << '|';


        for ( unsigned int j = 1; j <= col1; j++)
        {

            file << std::left << setw(len1) << left->element(i, j).str_rect();

        } // for loop ends
        file << ':';
        for ( unsigned int k = 1; k <= col2; k++)
        {

            file << std::right << setw(len2) << right->element(i, k).str_rect();

        }  // for loop ends

        file << '|';

        if (i == (rows / 2) + 1)
        {
            file << " " << right_str << endl;
        }
        else
        {
            file << endl;
        }

    } // for loop ends


    file << string(left_str.size() + 1, ' ');
    file << '|';
    file << setw(len1) << std::left << "__";
    for ( unsigned int j = 2; j <= col1; j++)
    {
        file << setw(len1) << " ";

    } // for loop ends
    file << " ";
    for ( unsigned int j = 1; j < col2; j++)
    {
        file << setw(len2) << " ";

    } // for loop ends
    file << std::right << setw(len2) << "__";

    file << '|' << endl << endl;
} // end function
Matrix AugmentedMatrix::solution(bool should_print  , ostream& file  )
{
    if (left->determinant() == 0)
    {
        if (should_print)
        {
            file << "It is found that:-\n"<<endl;
            left->print_det(file, " ", " = 0");
            file << "So the given problem has either no or infinite solutions." << endl;
        }
        return IdentityMatrix(1);
    }


    int pivot_row;
    unsigned int curr_row, curr_col, row = left->get_row(), col = left->get_col();;
    Cmplx pivot, multiplier;

    if (should_print)
    {
        file << "The augmented matrix for the given problem is:-\n" << endl;
        print(file);
        file << "We now apply Gauss-Jordan Elimination.\n" << endl;
    }


    //first echelon form
    for (curr_row = 1, curr_col = 1; curr_row <= row && curr_col <= col; curr_row++, curr_col++)
    {
        pivot_row = -1;
        //first finding the pivot row
        for (int row_iter = curr_row; row_iter <= row; row_iter++)
        {
            if (left->element(row_iter, curr_col) != 0)
            {
                pivot_row = row_iter;
                pivot = left->element(row_iter, curr_col);
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
            left->swap_rows(pivot_row, curr_row);
            right->swap_rows(pivot_row, curr_row);

            if (should_print)
            {
                file << "Swapping Row#" << pivot_row << " and Row#" << curr_row << " :-\n" << endl;
                print(file,"~");
            }
        }

        //now dividing pivot row by pivot
        if (pivot != 1)
        {
            left->divide_row(curr_row, pivot);
            right->divide_row(curr_row, pivot);
            if (should_print)
            {
                file << "Dividing Row#" << curr_row << " by " << pivot.str_rect() << " :-\n" << endl;
                print(file, "~");
            }
        }

        //now making all leading elements in curr col zero
        for (int row_iter = curr_row + 1; row_iter <= row; row_iter++)
        {
            if (left->element(row_iter, curr_col) != 0)
            {
                multiplier = left->element(row_iter, curr_col);
                left->add_multiple_of_row(row_iter, -1 * multiplier, curr_row);
                right->add_multiple_of_row(row_iter, -1 * multiplier, curr_row);
                if (should_print)
                {
                    file << "Adding " << (-1 * multiplier).str_rect() << " times Row#" << curr_row << " to Row#" << row_iter << " :-\n" << endl;
                    print(file, "~");
                }
            }

        } // end of third for loop
    } // end of first for loop

    //now reduced echelon form

    for (curr_row = row,curr_col=col ; curr_row >= 2 ; curr_row--,curr_col--)
    {
        for (int row_iter = curr_row - 1; row_iter >= 1; row_iter--)
        {
            if (left->element(row_iter, curr_col) != 0)
            {
                multiplier = left->element(row_iter, curr_col);
                left->add_multiple_of_row(row_iter, -1 * multiplier, curr_row);
                right->add_multiple_of_row(row_iter, -1 * multiplier, curr_row);
                if (should_print)
                {
                    file << "Adding " << (-1 * multiplier).str_rect() << " times Row#" << curr_row << " to Row#" << row_iter << " :-\n" << endl;
                    print(file, "~");
                }
            }

        }// for loop ends
    } // for loop ends

    if (should_print)
    {
        file << "Gauss Jordan Elimination Complete.\n" << endl;
    }
        return *right;
} // end function
