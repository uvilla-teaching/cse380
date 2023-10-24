#include "CSRMatrix.hpp"

#include<iostream>
#include<cassert>

void generate_triplet(int n, int & nnz, int *& i, int *& j, double *& val)
{
    // This function is bug free :)
    nnz = 3*n - 2;
    i = new int[nnz];
    j = new int[nnz];
    val = new double[nnz];

    int counter(0);
    //Fill the diagonal
    for(int irow(0); irow < n; ++irow)
    {
        i[counter] = irow;
        j[counter] = irow;
        if ( (irow == 0) || (irow == n-1) )
            val[counter] = 1.;
        else
            val[counter] = 2.;
        counter++;
    }

    //Fill upper diagonal
    for(int irow(0); irow < n-1; ++irow)
    {
        i[counter] = irow;
        j[counter] = irow+1;
        val[counter] = -1.;
        counter++;
    }


    //Fill lower diagonal
    for(int irow(0); irow < n-1; ++irow)
    {
        i[counter] = irow+1;
        j[counter] = irow;
        val[counter] = -1.;
        counter++;
    }

    assert(counter == nnz);
}

int main(int argc, char *argv[])
{
if (argc != 2 )
{
    std::cout << "Usage `main n`, where `n` is the number of rows/cols."<<std::endl;
    return 1;
}

int nrows = std::atoi(argv[1]);

int nnz;
int *i, *j;
double *val;

// Generate the nonzero entries of the finite difference discretization of 1D Laplacian with Newmann BC
generate_triplet(nrows, nnz, i, j, val);

CSRMatrix A(nrows, nrows);
A.Fill(nnz, i,j, val);

double * x = new double[nrows];
for(int i(0); i < nrows; ++i) x[i] = 1.;

double * y = new double[nrows];

A.Mult(x,y);

// x is in the null space of A, so y should be all-zeros
for(int i(0); i < nrows; ++i) assert( std::abs(y[i]) < 1e-12);

//Instanciate a matrix B with the same non-zero pattern as A
CSRMatrix B(nrows, nrows);
B.copyCSRStructureFromOther(A);

delete[] i;
delete[] j;
delete[] val;

delete x;
delete y;

return 0;

}