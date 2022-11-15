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
```
==58398== LEAK SUMMARY:
==58398==    definitely lost: 0 bytes in 0 blocks
==58398==    indirectly lost: 0 bytes in 0 blocks
==58398==      possibly lost: 0 bytes in 0 blocks
==58398==    still reachable: 528 bytes in 7 blocks
==58398==         suppressed: 0 bytes in 0 blocks
==58398== For lists of detected and suppressed errors, rerun with: -s
==58398== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```

### Generate suppression file
```
valgrind --leak-check=full --show-leak-kinds=all --gen-suppressions=all --log-file=main.log ./main >> main.log
cat main.log | ./parse_valgrind_suppression.sh > boost_log.supp
```
> Use carefully! Make sure you are not suppressing any error/leak in your application. Ideally, `main.cpp` should be a mininalistic code that only uses the TPL.

### Now Valgrind can run *clean*
```
valgrind --leak-check=full --show-leak-kinds=all --suppressions=boost_log.supp ./main
```

```
==59303== LEAK SUMMARY:
==59303==    definitely lost: 0 bytes in 0 blocks
==59303==    indirectly lost: 0 bytes in 0 blocks
==59303==      possibly lost: 0 bytes in 0 blocks
==59303==    still reachable: 0 bytes in 0 blocks
==59303==         suppressed: 528 bytes in 7 blocks
==59303== 
==59303== For lists of detected and suppressed errors, rerun with: -s
==59303== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```
