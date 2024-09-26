# include <stdio.h> 
# include <gsl/gsl_sf_bessel.h> 
int main (void)
{
double x = 5.0; 
double y = gsl_sf_bessel_j0 (x); 
printf ("JO(%g) =  %.18e\n", x , y);
return(0);
}
