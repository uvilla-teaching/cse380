#include <vector>

void hello_pybind();
double bessel_j0(double x);
void bessel_j0(const std::vector<double> & x, std::vector<double> & y);