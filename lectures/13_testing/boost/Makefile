CPP := icpc
BOOST_INC :=${TACC_BOOST_INC}
BOOST_LIB := ${TACC_BOOST_LIB}

all: ex1.exe ex2.exe ex3.exe ex4.exe

%.exe: %.cpp
	${CPP} -o $@ -I${BOOST_INC} $< -L${BOOST_LIB} -lboost_unit_test_framework

.PHONY: clean

clean:
	rm -rf *.exe
