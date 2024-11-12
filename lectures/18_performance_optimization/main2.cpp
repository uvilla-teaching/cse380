#include<vector>
#include<iostream>
#include<cstdlib>
#include<cassert>

class Matrix
{
	public:
		Matrix(int nrows, int ncols):
			nrows_(nrows),
			ncols_(ncols),
			data(nrows, std::vector<double>(ncols,0))
	{
	};

		int shape(int axis)
		{
			if (axis == 0)
				return nrows_;
			else if (axis == 1)
				return ncols_;
			else
				std::cout << "Invalid axis " << std::endl;

			return -1;
		}



		inline double & entry(int irow, int jcol)
		{
			assert( (irow >= 0) && (irow < nrows_) && (jcol >= 0) && (jcol < ncols_) );
			return data[irow][jcol];

		}
        
	friend Matrix * Multiply(Matrix & A, Matrix &B);

	private:
		int nrows_;
		int ncols_;
		std::vector< std::vector<double> > data;
};

Matrix * Multiply(Matrix & A, Matrix &B)
{
    Matrix * C = new Matrix(A.nrows_, B.ncols_);

    std::vector< std::vector<double> > & Cdata(C->data);
    std::vector< std::vector<double> > & Adata(A.data);
    std::vector< std::vector<double> > & Bdata(B.data);
    double tmp;
    for (int i = 0; i < A.nrows_; ++i)
        for (auto j = 0; j < B.ncols_; ++j)
	    {
		    tmp =0.;
            	    for (auto k = 0; k < A.ncols_; ++k)
                    	tmp += Adata[i][k] * Bdata[k][j];
		    Cdata[i][j] = tmp;
	    }
    return C;
}

int main(int argc, char *argv[])
{
	assert(argc == 4);
	int A_nrows = atof(argv[1]);
	int A_ncols = atof(argv[2]);
	int B_nrows = A_ncols;
	int B_ncols = atof(argv[3]);

	Matrix A(A_nrows, A_ncols);
	Matrix B(A_ncols, B_ncols);

	for(int i(0); i < A_nrows; ++i)
		for(int j(0); j < A_ncols; ++j)
			A.entry(i,j) = static_cast<double>(i+1-j)/static_cast<double>(i+1+j);

	for(int i(0); i < B_nrows; ++i)
                for(int j(0); j < B_ncols; ++j)
                        B.entry(i,j) = static_cast<double>(i+1)/static_cast<double>(1+j);

	Matrix * C = Multiply(A,B);

	delete C;

	return 0;

}
