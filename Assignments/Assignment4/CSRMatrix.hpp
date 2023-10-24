
#ifndef CSRMATRIX_HPP
#define CSRMATRIX_HPP

class CSRMatrix
{
    public:
    //! Creates a nrows by ncols CSRMatrix
    CSRMatrix(int nrows, int ncols);
    //! Fills the matrix from triplet format i.e. A[ irow[k], jcol[k] ] = vals[k] for k = 0,..., nnz-1
    void Fill(int nnz,const int * irow, const int * jcol, const double * vals);
    //! Fills a new matrix with the same row_index_ and col_index_ of other, but set all values to 0.
    void copyCSRStructureFromOther(CSRMatrix & other);
    //! Performs the matrix vector multiplication y = A*x
    void Mult(const double * x, double * y );


    ~CSRMatrix();

    private:

    void _create_row_index(int nnz, const int * irow);

    int nrows_;
    int ncols_;
    int owns_row_col_index_;
    int *row_index_;
    int *col_index_;
    double *v_; 

};

#endif