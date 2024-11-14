CC := icc
GSL_BASE_DIR := $(TACC_GSL_DIR)
bessel.so: bessel.o
	$(CC) -shared -o bessel.so bessel.o -L$(GSL_BASE_DIR)/lib -lgsl -lgslblas

bessel.o: bessel.c bessel.h
	$(CC) -I$(GSL_BASE_DIR)/include -fFIC -c bessel.c