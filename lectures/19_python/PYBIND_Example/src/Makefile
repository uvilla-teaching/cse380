CXX := icpc 
GSL_BASE_DIR := $(TACC_GSL_DIR)

bessel.so: bessel.o
	$(CXX) -shared -o bessel.so bessel.o -L$(GSL_BASE_DIR)/lib -lgsl -lgslcblas

bessel.o: bessel.cpp bessel.hpp
	$(CXX) -std=c++11 -I$(GSL_BASE_DIR)/include $(shell python3 -m pybind11 --includes) -fPIC -c bessel.cpp

.PHONY: echo_pybind clean
echo_pybind:
	python3 -m pybind11 --includes

clean:
	rm -rf bessel.o
	rm -rf bessel.so
