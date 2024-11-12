all: matmat.exe matmat1.exe matmat2.exe matmat3.exe

matmat.exe: main.cpp
	icc -DNDEBUG -O0 -g -p main.cpp -o matmat.exe

matmat1.exe: main1.cpp
	icc -DNDEBUG -O0 -g -p main1.cpp -o matmat1.exe

matmat2.exe: main2.cpp
	icc -DNDEBUG -O0 -g -p main2.cpp -o matmat2.exe

matmat3.exe: main3.cpp
	icc -DNDEBUG -O0 -g -p main3.cpp -o matmat3.exe

.PHONY: clean
clean: clean-profile
	rm -rf *.exe

clean-profile:
	rm gmon.out

