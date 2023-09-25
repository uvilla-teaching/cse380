CC := gcc
foo: foo.o bar.o
	$(CC) -o $@ $^

foo.o: foo.c bar.h
	$(CC) -c $<

bar.o: bar.c bar.h
	$(CC) -c $<
