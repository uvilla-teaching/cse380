### Switch to gcc, load boost, and valgrind
```
module swap intel gcc/7.1.0
module load boost
module load valgrind
```
### Compile and link
```
g++ -g -I$TACC_BOOST_DIR/include -D-DBOOST_ALL_DYN_LINK -o main.o -c main.cpp
g++ -o main main.o -L$TACC_BOOST_DIR/lib -lpthread -lboost_log -lboost_system -lboost_thread -lboost_filesystem
```
### Run with valgrind
```
valgrind ./main
```
#Generate suppression file
```
valgrind --leak-check=full --show-leak-kinds=all --gen-suppressions=all --log-file=main.log ./main >> main.log
cat main.log | ./parse_valgrind_suppression.sh > boost_log.supp
```

#Now Valgrind can run ~clean~
```
valgrind --leak-check=full --show-leak-kinds=all --suppressions=boost_log.supp ./main
```
