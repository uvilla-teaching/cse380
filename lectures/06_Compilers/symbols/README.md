icc -c -g foo.c
icc -c -g bar.c

nm foo.o bar.o

icc -o -g main foo.o bar.o
