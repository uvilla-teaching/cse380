# include <stdio.h> 
# include <gsl/gsl_sf_bessel.h> 


void hello_cffi()
{
    printf("Hello CFFI\n");
}

double bessel_j0(double x)
{
    return gsl_sf_bessel_j0 (x); 
}

void bessel_j0(double * x, double * y, int size)
{
    for(int i(0); i < size; ++i)
    y[i] = gsl_sf_bessel_j0 (x[i]);
}