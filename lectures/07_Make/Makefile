foo: foo.o bar.o
	gcc -o foo foo.o bar.o

foo.o: foo.c bar.h
	gcc -c foo.c

bar.o: bar.c bar.h
	gcc -c bar.c
