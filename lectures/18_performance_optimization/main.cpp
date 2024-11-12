#include<vector>
#include<iostream>
#include<cstdlib>
#include<cassert>

class Matrix
{
	public:
		Matrix(int nrows, int ncols):
			nrows_(nrows),
			ncols_(ncols)
	{
		for(int irow(0); irow<nrows; ++irow)
			data.push_back(std::vector<double>(ncols));
	}

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



		double & entry(int irow, int jcol)
		{
			if( (irow >= 0) && (irow < nrows_) && (jcol >= 0) && (jcol < ncols_) )
				return data[irow][jcol];
			else
			{
				std::cout << "Invalid entry " << std::endl;
                                std::abort();
			}
			return data[0][0];

		}

	private:
		int nrows_;
		int ncols_;
		std::vector< std::vector<double> > data;
};

Matrix * Multiply(Matrix & A, Matrix &B)
{
    Matrix * C = new Matrix(A.shape(0), B.shape(1));
    for (int k = 0; k < A.shape(1); ++k)
        for (auto j = 0; j < B.shape(1); ++j)
            for (auto i = 0; i < A.shape(0); ++i)
                C->entry(i,j) += A.entry(i,k) * B.entry(k,j);

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
