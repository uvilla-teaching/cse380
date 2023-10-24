#include "CSRMatrix.hpp"

#include <iostream>

CSRMatrix::CSRMatrix(int nrows, int ncols):
    nrows_(nrows),
    ncols_(ncols),
    owns_row_col_index_(1),
    row_index_(NULL),
    col_index_(NULL),
    v_(NULL)
    {

    }

void CSRMatrix::Fill(int nnz,const int * irow, const int * jcol, const double * vals)
{
    if( owns_row_col_index_ )
    {
        if(row_index_!= NULL)
        {
            delete[] row_index_;
            row_index_= NULL;
        }
        if(col_index_ != NULL)
        { 
            delete[] col_index_;
            col_index_= NULL;
        }
    }

    if(v_ != NULL) delete[] v_;

    _create_row_index(nnz, irow);
    col_index_ = new int[nnz];
    v_ = new double[nnz];

    owns_row_col_index_ = 1;

    int * row_counter = new int[nrows_];
    //! Set the row counter equal to row_index_
    for(int c(0); c < nrows_+1; ++c) row_counter[c] = row_index_[c];

    //Fill in entries
    for(int c(0); c < nnz; ++c)
    {
        int my_row = irow[c];
        col_index_[ row_counter[my_row] ] = jcol[c];
        v_[ row_counter[my_row] ] = vals[c];
        row_counter[my_row]++;
    }

}

void CSRMatrix::copyCSRStructureFromOther(CSRMatrix & other)
{
    if( nrows_ != other.nrows_)
        std::cout << "Non-mathcing number of rows" << std::endl;

    if( ncols_ != other.ncols_)
        std::cout << "Non-matching number of cols" << std::endl;
    
    row_index_ = other.row_index_;
    col_index_ = other.col_index_;
    v_ = new double[row_index_[other.row_index_[nrows_]]];
}

void CSRMatrix::Mult(const double * x, double * y )
{
    for(int row(0); row < nrows_; ++row)
    {
        y[row] = 0.;
        for(int c(row_index_[row]); c < row_index_[row+1]; ++c)
        y[row] += v_[c]*x[col_index_[c]];
    }
}

CSRMatrix::~CSRMatrix()
{
    if( owns_row_col_index_ )
    {
        if(row_index_!= NULL)
        {
            delete[] row_index_;
            row_index_= NULL;
        }
        if(col_index_ != NULL)
        { 
            delete[] col_index_;
            col_index_= NULL;
        }
    }

    if(v_ != NULL) delete[] v_;
}

void CSRMatrix::_create_row_index(int nnz, const int *irow)
{
    //Allocate memory
    row_index_ = new int[nrows_+1];
    //Make sure row_index_ is initialized to 0
    for(int c(0); c < nrows_+1; ++c) row_index_[c] = 0;

    //Count the non-zeros entries of each row
    for(int c(0); c < nnz; ++c) {
        row_index_[ irow[c] + 1] += 1;
    }

     

    //Perform partial sums of the non-zeros for each row
    int nnz2(0);
    for(int c(0); c < nrows_+1; ++c)
    {
        nnz2 += row_index_[c];
        row_index_[c+1] = nnz2;
    }
}