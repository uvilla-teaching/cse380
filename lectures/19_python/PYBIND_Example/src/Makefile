CXX := g++
GSL_BASE_DIR := $(TACC_GSL_DIR)
PYBIND_INCLUDE_DIR := $(python3 -m pybind11 --includes)

bessel.so: bessel.o
	$(CXX) -shared -o bessel.so bessel.o -L$(GSL_BASE_DIR)/lib -lgsl -lgslblas

bessel.o: bessel.cpp bessel.hpp
	$(CXX) -std=c++11 -I$(GSL_BASE_DIR)/include -I$(PYBIND_INCLUDE_DIR) -fPIC -c bessel.cpp

.PHONY: echo_pybind
echo_pybind:
	echo $(PYBIND_INCLUDE_DIR)
