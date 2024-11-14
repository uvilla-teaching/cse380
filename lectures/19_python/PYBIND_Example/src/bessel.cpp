# include <stdio.h> 
# include <gsl/gsl_sf_bessel.h> 

#include <pybind11/pybind11.h>
#include <pybind11/numpy.h>
#include <vector>

void hello_pybind()
{
    printf("Hello pybind\n");
}

double bessel_j0(double x)
{
    return gsl_sf_bessel_j0 (x); 
}

void bessel_j0(const std::vector<double> & x,  std::vector<double> & y)
{
    for(int i=0; i < x.size(); ++i)
    y[i] = gsl_sf_bessel_j0 (x[i]);
}

namespace pybind11 py;
// Help function to cast a pybind array to a std::vector
std::vector<double> array_to_vector(py::array_t<double> &array) {
    py::buffer_info info = array.request();

    if (info.ndim != 1) {
        throw std::runtime_error("Array must be 1-dimensional.");
    }

    double *ptr = static_cast<double*>(info.ptr);
    std::vector<double> vec(ptr, ptr + info.shape[0]);

    return vec;
}

PYBIND11_MODULE(example, m) {
    m.def("hello_pybind", &hello_pybind, "A simple function writing on screen");
    m.def("bessel_j0", &bessel_j0, "Compute j0(x)", py::arg("x")=1.);
    m.def("bessel_j0", [](py::array_t<double> & x) {
       py::array_t<double> y(x.shape);
       bessel_j0( array_to_vector(x), array_to_vector(y) );
       return y; 
    })
}