# Note: verify gsl module is loaded first...
# 
# This should work on Stampede2

icc -I$TACC_GSL_INC main.c mytools.c -lgsl -lgslcblas -L$TACC_GSL_LIB
