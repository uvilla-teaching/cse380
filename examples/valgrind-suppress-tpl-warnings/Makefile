LIBS :=  -lpthread -lboost_log -lboost_system -lboost_thread -lboost_filesystem

all: main

main.o: main.cpp
	g++ -g -I$(TACC_BOOST_DIR)/include -DBOOST_ALL_DYN_LINK -o main.o -c main.cpp

main: main.o
	g++ -o main main.o -L$(TACC_BOOST_DIR)/lib $(LIBS)

supp: main
	valgrind --leak-check=full --show-leak-kinds=all --gen-suppressions=all --log-file=main.log ./main >> main.log
	cat main.log | ./parse_valgrind_suppression.sh > boost_log.supp

.PHONY: clean

clean:
	rm -rf main.o main.log
