all: hello-coverage.exe hello2-coverage.exe

hello.exe: hello.c
	gcc -g -o $@ $^

hello-coverage.exe: hello.c
	gcc -g --coverage -o $@ $^

hello2-coverage.exe: hello2.c
	gcc -g --coverage -o $@ $^

.PHONY: check report clean

check: hello-coverage.exe
	./hello-coverage.exe
	./hello2-coverage.exe

report: check
	#lcov --zerocounters
	lcov --directory . --capture --output-file lcov.info
	genhtml -t "Example" -o html ./lcov.info 

clean:
	rm -rf *.exe
	rm -rf *.gcno
	rm -rf *.gcda
	rm -rf html
	rm -rf lcov.info
